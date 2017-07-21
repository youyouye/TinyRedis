#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

namespace yye{

class noncopyable
{
protected:
	noncopyable() = default;
	~noncopyable() = default;
private:
	noncopyable(const noncopyable&) = delete;
	void operator=(const noncopyable&) = delete;
};

}



#endif
