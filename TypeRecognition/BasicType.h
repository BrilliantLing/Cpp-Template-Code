#ifndef BASIC_TYPE_H
#define BASIC_TYPE_H

template<typename T>
class BasicType
{
public:
	enum { Yes = 0, No = 1 };
};

#define MK_BASIC_TYPE(T)						\
	template<>									\
	class BasicType<T>							\
	{											\
		public:									\
			enum { Yes = 1, No = 0 };			\
	};

MK_BASIC_TYPE(bool)
MK_BASIC_TYPE(char)
MK_BASIC_TYPE(signed char)
MK_BASIC_TYPE(unsigned char)
MK_BASIC_TYPE(wchar_t)

MK_BASIC_TYPE(signed short)
MK_BASIC_TYPE(unsigned short)
MK_BASIC_TYPE(signed int)
MK_BASIC_TYPE(unsigned int)
MK_BASIC_TYPE(signed long)
MK_BASIC_TYPE(unsigned long)
MK_BASIC_TYPE(signed long long)
MK_BASIC_TYPE(unsigned long long)

MK_BASIC_TYPE(float)
MK_BASIC_TYPE(double)
MK_BASIC_TYPE(long double)

#endif // !BASIC_TYPE_H

