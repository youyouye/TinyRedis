/*
 * CurrentThread.h
 *
 *  Created on: Jul 21, 2017
 *      Author: moocos
 */

#ifndef CURRENTTHREAD_H_
#define CURRENTTHREAD_H_

#include <stdint.h>

namespace yye
{

namespace CurrentThread
{
extern __thread int t_cachedTid;
extern __thread char t_tidString[32];
extern __thread int t_tidStringLength;
extern __thread const char* t_threadName;
void cacheTid();

inline int tid()
{
  if (__builtin_expect(t_cachedTid == 0, 0))
  {
    cacheTid();
  }
  return t_cachedTid;
}

inline const char* tidString() // for logging
{
  return t_tidString;
}

inline int tidStringLength() // for logging
{
  return t_tidStringLength;
}

inline const char* name()
{
  return t_threadName;
}

bool isMainThread();

void sleepUsec(int64_t usec);

}

}

#endif /* CURRENTTHREAD_H_ */
