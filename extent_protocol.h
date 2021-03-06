// extent wire protocol

#ifndef extent_protocol_h
#define extent_protocol_h

#include "rpc.h"

class extent_protocol {
 public:
  typedef int status;
  typedef unsigned long long extentid_t;
  enum xxstatus { OK, RPCERR, NOENT, IOERR , EXIST, DUPINUM };
  enum rpc_numbers {
    put = 0x6001,
    get =0x6002,
    getattr=0x6003,
    remove
  };

  struct attr {
    unsigned int atime;
    unsigned int mtime;
    unsigned int ctime;
    unsigned int size;
  };
};

inline unmarshall &
operator>>(unmarshall &u, extent_protocol::attr &a)
{
  u >> a.atime;
  u >> a.mtime;
  u >> a.ctime;
  u >> a.size;
  return u;
}

inline marshall &
operator<<(marshall &m, extent_protocol::attr a)
{
  m << a.atime;
  m << a.mtime;
  m << a.ctime;
  m << a.size;
  return m;
}

#endif 
