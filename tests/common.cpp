#include "common.hpp"
#include <iostream>
#include <boost/asio/consign.hpp>
#include <boost/asio/co_spawn.hpp>

#include <boost/test/unit_test.hpp>

namespace net = boost::asio;

struct run_callback {
   std::shared_ptr<boost::redis::connection> conn;
   boost::redis::operation op;
   boost::system::error_code expected;

   void operator()(boost::system::error_code const& ec) const
   {
      std::cout << "async_run: " << ec.message() << std::endl;
      //BOOST_CHECK_EQUAL(ec, expected);
      conn->cancel(op);
   }
};

void
run(
   std::shared_ptr<boost::redis::connection> conn,
   boost::redis::config cfg,
   boost::system::error_code ec,
   boost::redis::operation op)
{
   conn->async_run(cfg, {}, run_callback{conn, op, ec});
}

#ifdef BOOST_ASIO_HAS_CO_AWAIT
auto start(net::awaitable<void> op) -> int
{
   try {
      net::io_context ioc;
      net::co_spawn(ioc, std::move(op), [](std::exception_ptr p) {
         if (p)
            std::rethrow_exception(p);
      });
      ioc.run();

      return 0;

   } catch (std::exception const& e) {
      std::cerr << "start> " << e.what() << std::endl;
   }

   return 1;
}

#endif // BOOST_ASIO_HAS_CO_AWAIT
