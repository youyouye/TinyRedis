/*
 * Thread.h
 *
 *  Created on: Jul 21, 2017
 *      Author: moocos
 */

#ifndef THREAD_H_
#define THREAD_H_

#include "noncopyable.h"

#include <functional>
#include <memory>
#include <pthread.h>

namespace yye
{

class Thread : noncopyable{
public:
	typedef std::function<void ()> ThreadFunc;
	  explicit Thread(const ThreadFunc&, const std::string& name = std::string());
	#ifdef __GXX_EXPERIMENTAL_CXX0X__
	  explicit Thread(ThreadFunc&&, const std::string& name = std::string());
	#endif
	  // FIXME: make it movable in C++11
	  ~Thread();

	  void start();
	  int join(); // return pthread_join()

	  bool started() const { return started_; }
	  // pthread_t pthreadId() const { return pthreadId_; }
	  pid_t tid() const { return *tid_; }
	  const std::string& name() const { return name_; }

	  static int numCreated() { return numCreated_.get(); }

	 private:
	  void setDefaultName();

	  bool       started_;
	  bool       joined_;
	  pthread_t  pthreadId_;
	  std::shared_ptr<pid_t> tid_;
	  ThreadFunc func_;
	  std::string     name_;

	  static AtomicInt32 numCreated_;

};

}


#endif /* THREAD_H_ */
