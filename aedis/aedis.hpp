/* Copyright (c) 2019 Marcelo Zimbres Silva (mzimbres@gmail.com)
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <aedis/net.hpp>
#include <aedis/command.hpp>
#include <aedis/resp3/type.hpp>
#include <aedis/resp3/read.hpp>
#include <aedis/resp3/adapt.hpp>
#include <aedis/resp3/error.hpp>
#include <aedis/resp3/serializer.hpp>
#include <aedis/resp3/response_traits.hpp>
#include <aedis/resp3/client.hpp>

/** \mainpage
  
    Introduction

    - \subpage overview
    - \subpage installation
    - \subpage examples

    Reference

    - \subpage enums
    - \subpage classes
    - \subpage functions
    - \subpage operators
 */

//---------------------------------------------------------
// Pages

/** \page overview Overview
 *
 *  Aedis provides low-level communication with a Redis server over
 *  its native protocol RESP3. Some of its featues are
 *
 *  - First class support to STL containers and C++ built-in types.
 *  - Support for pipelining, transactions and TLS.
 *  - Serialization and de-serialization of your own types.
 *  - First class support to async programming through ASIO.
 */

/** \page examples Examples
 *
    \b Basics: Focuses on small code snippets that show basic usage of
    the library, for example: how to make a request and read the
    response, how to deal with keys that may not exist, etc.

    - intro.cpp

      Some commands are sent to the Redis server and the responses are
      printed to screen.

    - key_expiration.cpp
      
      Shows how to use \c std::optional to deal with keys that may
      have expired or do not exist.

    - nested_response.cpp
      
      Shows how to read responses to commands that cannot be
      translated in a C++ built-in type like std::string or STL
      containers.

    - subscriber.cpp

      Shows how channel subscription works at a low level.

    - sync.cpp
      
      Shows hot to use the Aedis synchronous api.

    - redis_client.cpp

      Shows how to use and experimental high level redis client that
      keeps a long lasting connections to a redis server.

    \b STL \b Containers: Many of the Redis data structures can be
    directly translated in to STL containers, below you will find some
    example code. For a list of Redis data types see
    https://redis.io/topics/data-types.

    - hashes.cpp

      Shows how to read Redis hashes in a \c std::map, \c
      std::unordered_map and \c std::vector.

    - lists.cpp

      Shows how to read Redis lists in \c std::list,
      \c std::deque, \c std::vector. It also illustrates basic serialization.

    - sets.cpp

      Shows how to read Redis sets in a \c std::set, \c std::unordered_set
      and \c std::vector.

    \b Customization \b points: Shows how de/serialize user types
    avoiding copies. This is particularly useful for low latency
    applications.

    - serialization.cpp

      Shows how to de/serialize your own non-aggregate data-structures.

    - response_adapter.cpp

      Customization point for users that want to de/serialize their
      own data-structures.

    \b Asynchronous \b servers: Contains some non-trivial examples
    servers that interact with users and Redis asynchronously over
    long lasting connections using a higher level API.

    - echo_server.cpp

      Shows the basic principles behind asynchronous communication
      with a database in an asynchronous server. In this case, the
      server is a proxy between the user and the database.

    - chat_room.cpp

      Shows how to build a scalable chat room that scales to
      millions of users.
 */

/** \page installation Installation
 *
 *  This library is header only. To install it run
 *
 *  ```cpp
 *  $ sudo make install
 *  ```
 *
 *  or copy the include folder to the location you want.  You will
 *  also need to include the following header in one of your source
 *  files e.g. `aedis.cpp`
 *
 *  ```cpp
 *  #include <aedis/impl/src.hpp>
 *  ```
 */

//---------------------------------------------------------
// Groups

/** \defgroup enums Enumerations
 *  \brief Enumerations defined by this library.
 */


/** \defgroup classes Classes
 *  \brief Classes defined by this library.
 */


/** \defgroup functions Free functions
 *  \brief All functions defined by this library.
 */


/** \defgroup operators Operators
 *  \brief Operators defined in Aedis
 */