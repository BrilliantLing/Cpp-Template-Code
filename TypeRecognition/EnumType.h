#ifndef ENUM_TYPE_H
#define ENUM_TYPE_H

#include"BasicType.h"
#include"CompoundType.h"

struct TwoBytes
{
	char c[2];
};

template<typename T,
		 bool converted_possible = !CompoundType<T>::Func &&
								   !CompoundType<T>::Array>
class ConsumeUDC
{
public:
	operator T()const;
};

template<typename T>
class ConsumeUDC<T, false>
{

};

template<bool converted_possible>
class ConsumeUDC<void, converted_possible>
{

};

char enum_check(bool);
char enum_check(char);
char enum_check(signed char);
char enum_check(unsigned char);
char enum_check(wchar_t);

char enum_check(signed short);
char enum_check(unsigned short);
char enum_check(signed int);
char enum_check(unsigned int);
char enum_check(signed long);
char enum_check(unsigned long);
char enum_check(signed long long);
char enum_check(unsigned long long);

char enum_check(float);
char enum_check(double);
char enum_check(long double);

TwoBytes enum_check(...);

template<typename T>
class EnumType
{
public:
	enum 
	{
		Yes = BasicType<T>::No &&
			  !CompoundType<T>::Ref &&
			  !CompoundType<T>::Ptr &&
			  !CompoundType<T>::PtrMem &&
			  sizeof(enum_check(ConsumeUDC<T>())) == 1
	};
	enum { No = !Yes };
};

#endif // !ENUM_TYPE_H

