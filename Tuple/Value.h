#ifndef VALUE_H
#define	VALUE_H

#include"TypeOp.h"
#include"DuoT.h"
#include"DuoValue.h"

template<int N,typename A,typename B>
inline
typename TypeOp<typename DuoT<N,Duo<A,B>>::ResultT>::RefT
val(Duo<A, B>& d)
{
	return DuoValue<N, Duo<A, B>>::get(d);
}

template<int N, typename A, typename B>
inline
typename TypeOp<typename DuoT<N,Duo<A,B>>::ResultT>::RefConstT
val(const Duo<A, B>& d)
{
	return DuoValue<N, Duo<A, B>>::get(d);
}

#endif // !VALUE_H

