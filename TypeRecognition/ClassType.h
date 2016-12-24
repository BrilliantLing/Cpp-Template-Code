#ifndef CLASS_TYPE_H
#define CLASS_TYPE_H

#include"EnumType.h"

template<typename T>
class ClassType
{
public:
	enum 
	{
		Yes = BasicType<T>::No &&
			  EnumType<T>::No &&
			  !CompoundType<T>::Ptr &&
			  !CompoundType<T>::Ref &&
			  !CompoundType<T>::Array &&
			  !CompoundType<T>::Func &&
			  !CompoundType<T>::PtrMem
	};
	enum { No = !Yes };
};

#endif // !CLASS_TYPE_H
