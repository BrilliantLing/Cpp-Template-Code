#ifndef DUO_T_H
#define DUO_T_H

#include"Duo.h"

template<int N,typename T>
class DuoT
{
public:
	typedef	void	ResultT;

};

template<typename A,typename B>
class DuoT<1, Duo<A, B>>
{
public:
	typedef	A		ResultT;

};

template<typename A,typename B>
class DuoT<2, Duo<A, B>>
{
public:
	typedef	B		ResultT;

};

template<typename A,typename B,typename C>
class DuoT<1, Duo<A, Duo<B, C>>>
{
public:
	typedef A		ResultT;

};

template<typename A,typename B,typename C>
class DuoT<2, Duo<A, Duo<B, C>>>
{
public:
	typedef B		ResultT;

};

template<int N, typename A, typename B, typename C>
class DuoT<N, Duo<A, Duo<B, C>>>
{
public:
	typedef typename DuoT<N-1, Duo<B, C>>::ResultT ResultT;
};


#endif // !DUO_T_H
