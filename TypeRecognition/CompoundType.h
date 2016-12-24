#ifndef COMPOUND_TYPE_H
#define COMPOUND_TYPE_H

template<typename T>
class IsFunction 
{
private:
	typedef char One;
	typedef struct { char c[2]; } Two;
	template<typename U> static One test(...);
	template<typename U> static Two test(U(*)[1]);

public:
	enum { Yes = sizeof(IsFunction<T>::test<T>(0)) == 1 };
	enum { No = !Yes };
};

template<typename T>
class IsFunction<T&>
{
public:
	enum { Yes = 0 };
	enum { No = !Yes };
};

template<>
class IsFunction<void>
{
public:
	enum { Yes = 0 };
	enum { No = !Yes };
};

template<>
class IsFunction<const void>
{
public:
	enum { Yes = 0 };
	enum { No = !Yes };
};

template<typename T>
class CompoundType
{
public:
	enum { Ptr = 0, Ref = 0, Array = 0, Func = IsFunction<T>::Yes, PtrMem = 0 };
	typedef T BaseType;
	typedef T BottomType;
	typedef CompoundType<void> Class;
};

template<typename T>
class CompoundType<T&>
{
public:
	enum { Ptr = 0, Ref = 1, Array = 0, Func = 0, PtrMem = 0 };
	typedef T BaseType;
	typedef typename CompoundType<T>::BottomType BottomType;
	typedef CompoundType<void> ClassType;
};

template<typename T>
class CompoundType<T*>
{
public:
	enum { Ptr = 1, Ref = 0, Array = 0, Func = 0, PtrMem = 0 };
	typedef T BaseType;
	typedef typename CompoundType<T>::BottomType BottomType;
	typedef CompoundType<void> ClassType;
};

template<typename T,size_t N>
class CompoundType<T[N]>
{
public:
	enum { Ptr = 0, Ref = 0, Array = 1, Func = 0, PtrMem = 0 };
	typedef T BaseType;
	typedef typename CompoundType<T>::BottomType BottomType;
	typedef CompoundType<void> ClassType;
};

template<typename T>
class CompoundType<T[]>
{
public:
	enum { Ptr = 0, Ref = 0, Array = 1, Func = 0, PtrMem = 0 };
	typedef T BaseType;
	typedef typename CompoundType<T>::BottomType BottomType;
	typedef CompoundType<void> ClassType;
};

template<typename T,typename C>
class CompoundType<T C::*>
{
public:
	enum { Ptr = 0, Ref = 0, Array = 0, Func = 0, PtrMem = 1 };
	typedef T BaseType;
	typedef typename CompoundType<T>::BottomType BottomType;
	typedef C ClassType;
};

template<typename R>
class CompoundType<R()>
{
public:
	enum { Ptr = 0, Ref = 0, Array = 0, Func = 1, PtrMem = 0 };
	typedef R BaseType();
	typedef R BottomType();
	typedef CompoundType<void> ClassType;
};

template<typename R,typename P1>
class CompoundType<R(P1)>
{
public:
	enum { Ptr = 0, Ref = 0, Array = 0, Func = 1£¬PtrMem = 0 };
	typedef R BaseType(P1);
	typedef R BottomType(P1);
	typedef CompoundType<void> ClassType;
};

template<typename R,typename P1>
class CompoundType<R(P1, ...)>
{
public:
	enum { Ptr = 0, Ref = 0, Array = 0, Func = 1, PtrMem = 0 };
	typedef R BaseTpe(P1);
	typedef R BottomType(P1);
	typedef CompoundType<void> ClassType;
};

#endif // !COMPOUND_TYPE_H
