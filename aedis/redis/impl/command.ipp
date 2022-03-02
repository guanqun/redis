/* Copyright (c) 2019 Marcelo Zimbres Silva (mzimbres@gmail.com)
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <cassert>
#include <aedis/redis/command.hpp>

namespace aedis {
namespace redis {

char const* to_string(command c)
{
   assert(c != command::invalid);

   static char const* table[] = {
      "ACL",
      "APPEND",
      "ASKING",
      "AUTH",
      "BGREWRITEAOF",
      "BGSAVE",
      "BITCOUNT",
      "BITFIELD",
      "BITFIELD_RO",
      "BITOP",
      "BITPOS",
      "BLPOP",
      "BRPOP",
      "BRPOPLPUSH",
      "BZPOPMAX",
      "BZPOPMIN",
      "CLIENT",
      "CLUSTER",
      "COMMAND",
      "CONFIG",
      "DBSIZE",
      "DEBUG",
      "DECR",
      "DECRBY",
      "DEL",
      "DISCARD",
      "DUMP",
      "ECHO",
      "EVAL",
      "EVALSHA",
      "EXEC",
      "EXISTS",
      "EXPIRE",
      "EXPIREAT",
      "FLUSHALL",
      "FLUSHDB",
      "GEOADD",
      "GEODIST",
      "GEOHASH",
      "GEOPOS",
      "GEORADIUS",
      "GEORADIUS_RO",
      "GEORADIUSBYMEMBER",
      "GEORADIUSBYMEMBER_RO",
      "GET",
      "GETBIT",
      "GETRANGE",
      "GETSET",
      "HDEL",
      "HELLO",
      "HEXISTS",
      "HGET",
      "HGETALL",
      "HINCRBY",
      "HINCRBYFLOAT",
      "HKEYS",
      "HLEN",
      "HMGET",
      "HMSET",
      "HSCAN",
      "HSET",
      "HSETNX",
      "HSTRLEN",
      "HVALS",
      "INCR",
      "INCRBY",
      "INCRBYFLOAT",
      "INFO",
      "KEYS",
      "LASTSAVE",
      "LATENCY",
      "LINDEX",
      "LINSERT",
      "LLEN",
      "LOLWUT",
      "LPOP",
      "LPOS",
      "LPUSH",
      "LPUSHX",
      "LRANGE",
      "LREM",
      "LSET",
      "LTRIM",
      "MEMORY",
      "MGET",
      "MIGRATE",
      "MODULE",
      "MONITOR",
      "MOVE",
      "MSET",
      "MSETNX",
      "MULTI",
      "OBJECT",
      "PERSIST",
      "PEXPIRE",
      "PEXPIREAT",
      "PFADD",
      "PFCOUNT",
      "PFDEBUG",
      "PFMERGE",
      "PFSELFTEST",
      "PING",
      "POST",
      "PSETEX",
      "PSUBSCRIBE",
      "PSYNC",
      "PTTL",
      "PUBLISH",
      "PUBSUB",
      "PUNSUBSCRIBE",
      "RANDOMKEY",
      "READONLY",
      "READWRITE",
      "RENAME",
      "RENAMENX",
      "REPLCONF",
      "REPLICAOF",
      "RESTORE",
      "ROLE",
      "RPOP",
      "RPOPLPUSH",
      "RPUSH",
      "RPUSHX",
      "SADD",
      "SAVE",
      "SCAN",
      "SCARD",
      "SCRIPT",
      "SDIFF",
      "SDIFFSTORE",
      "SELECT",
      "SET",
      "SETBIT",
      "SETEX",
      "SETNX",
      "SETRANGE",
      "SHUTDOWN",
      "SINTER",
      "SINTERSTORE",
      "SISMEMBER",
      "SLAVEOF",
      "SLOWLOG",
      "SMEMBERS",
      "SMOVE",
      "SORT",
      "SPOP",
      "SRANDMEMBER",
      "SREM",
      "SSCAN",
      "STRALGO",
      "STRLEN",
      "SUBSCRIBE",
      "SUBSTR",
      "SUNION",
      "SUNIONSTORE",
      "SWAPDB",
      "SYNC",
      "TIME",
      "TOUCH",
      "TTL",
      "TYPE",
      "UNLINK",
      "QUIT",
      "UNSUBSCRIBE",
      "UNWATCH",
      "WAIT",
      "WATCH",
      "XACK",
      "XADD",
      "XCLAIM",
      "XDEL",
      "XGROUP",
      "XINFO",
      "XLEN",
      "XPENDING",
      "XRANGE",
      "XREAD",
      "XREADGROUP",
      "XREVRANGE",
      "XSETID",
      "XTRIM",
      "ZADD",
      "ZCARD",
      "ZCOUNT",
      "ZINCRBY",
      "ZINTERSTORE",
      "ZLEXCOUNT",
      "ZPOPMAX",
      "ZPOPMIN",
      "ZRANGE",
      "ZRANGEBYLEX",
      "ZRANGEBYSCORE",
      "ZRANK",
      "ZREM",
      "ZREMRANGEBYLEX",
      "ZREMRANGEBYRANK",
      "ZREMRANGEBYSCORE",
      "ZREVRANGE",
      "ZREVRANGEBYLEX",
      "ZREVRANGEBYSCORE",
      "ZREVRANK",
      "ZSCAN",
      "ZSCORE",
      "ZUNIONSTORE",
   };

   return table[static_cast<int>(c)];
}

std::ostream& operator<<(std::ostream& os, command c)
{
   os << to_string(c);
   return os;
}

bool has_push_response(command cmd)
{
   switch (cmd) {
      case command::subscribe:
      case command::unsubscribe:
      case command::psubscribe:
      return true;

      default:
      return false;
   }
}

} // redis
} // aedis
