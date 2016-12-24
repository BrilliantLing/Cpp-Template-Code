#ifndef TYPE_RECOGNITION_H
#define TYPE_RECOGNITION_H

#include"BasicType.h"
#include"ClassType.h"
#include"CompoundType.h"
#include"EnumType.h"

template<typename T>
class Type
{
public:
	enum
	{
		IsBasicType = BasicType<T>::Yes,
		IsPointerType = CompoundType<T>::Ptr,
		IsArrayType = CompoundType<T>::Array,
		IsReferenceType = CompoundType<T>::Ref,
		IsFunctionType = CompoundType<T>::Func,
		IsPointerMemberType = CompoundType<T>::PtrMem,
		IsEnumType = EnumType<T>::Yes,
		IsClassType = ClassType<T>::Yes
	};
};

#endif // !TYPE_RECOGNITION_H

