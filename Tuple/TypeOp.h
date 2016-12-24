#ifndef TYPE_OP_H
#define TYPE_OP_H

template<typename T>
class TypeOp
{
public:
	typedef	T			ArgT;
	typedef	T			BareT;
	typedef T	const	ConstT;
	typedef T&			RefT;
	typedef T&			RefBareT;
	typedef const	T&	RefConstT;

};

template<typename T>
class TypeOp<T const>
{
public:
	typedef T	const	ArgT;
	typedef T			BareT;
	typedef T	const	ConstT;
	typedef const	T&	RefT;
	typedef T&			RefBareT;
	typedef	const	T&	RefConstT;

};

template<typename T>
class TypeOp<T&>
{
public:
	typedef T&			ArgT;
	typedef	typename	TypeOp<T>::BareT	BareT;
	typedef const	T&	ConstT;
	typedef T&			RefT;
	typedef	typename	TypeOp<T>::BareT&	RefBareT;
	typedef	const	T&	RefConstT;

};

template<>
class TypeOp<void>
{
public:
	typedef	void			ArgT;
	typedef void			BareT;
	typedef	const	void	ConstT;
	typedef void			RefT;
	typedef	void			RefBareT;
	typedef	void			RefConstT;
};



#endif // !TYPE_OP_H

