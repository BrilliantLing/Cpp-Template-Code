#ifndef DUO_VALUE_H
#define	DUO_VALUE_H

#include"DuoT.h"
#include"TypeOp.h"

template<int N,typename T>
class DuoValue
{
public:
	static void get(T&)
	{

	}
	static void get(const T&)
	{

	}
};

template<typename A,typename B>
class DuoValue<1, Duo<A,B>>
{
public:
	static A& get(Duo<A, B>& d)
	{
		return d.v1();
	}

	static const A& get(const Duo<A, B>& d)
	{
		return d.v1();
	}
};

template<typename A,typename B>
class DuoValue<2, Duo<A, B>>
{
public:
	static B& get(Duo<A, B>& d)
	{
		return d.v2();
	}

	static const B& get(const Duo<A, B>& d)
	{
		return d.v2();
	}
};

template<int N,typename A,typename B,typename C>
class DuoValue<N, Duo<A, Duo<B, C>>>
{
public:
	static
	typename TypeOp<typename DuoT<N - 1, Duo<B, C>>::ResultT>::RefT
	get(Duo<A, Duo<B, C>>& d)
	{
		return DuoValue<N - 1, Duo<B, C>>::get(d.v2());
	}

	static
	typename TypeOp<typename DuoT<N - 1, Duo<B, C>>::ResultT>::RefConstT
	get(const Duo<A,Duo<B,C>>& d)
	{
		return DuoValue<N - 1, Duo<B, C>>::get(d.v2());
	}

};

template<typename A,typename B,typename C>
class DuoValue<1, Duo<A, Duo<B, C>>>
{
public:
	static A& get(Duo<A, Duo<B, C>>& d)
	{
		return d.v1();
	}
	static const A& get(const Duo<A, Duo<B, C>>& d)
	{
		return d.v1();
	}
};

template<typename A, typename B, typename C>
class DuoValue<2, Duo<A, Duo<B, C>>>
{
public:
	static B& get(Duo<A, Duo<B, C>>& d)
	{
		return d.v2().v1();
	}
	static const B& get(const Duo<A, Duo<B, C>>& d)
	{
		return d.v2().v1();
	}
};

#endif // !DUO_VALUE_H
