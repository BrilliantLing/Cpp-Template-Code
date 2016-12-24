#ifndef DUO_H
#define DUO_H

template<typename T1,typename T2>
class Duo
{
public:
	typedef T1 Type1;
	typedef T2 Type2;
	enum { N = 2 };

private:
	T1	value1;
	T2	value2;

public:
	Duo() :value1(), value2()
	{

	}

	Duo(const T1& a, const T2& b)
		:value1(a), value2(b)
	{

	}

	template<typename U1,typename U2>
	Duo<T1, T2>& operator=(const Duo<U1, U2>& d)
	{
		value1 = d.value1;
		value2 = d.value2;
		return *this;
	}

	T1& v1()
	{
		return value1;
	}

	const T1& v1()const
	{
		return value1;
	}

	T2& v2()
	{
		return value2;
	}

	const T2& v2()const
	{
		return value2;
	}

};

template<typename T1, typename T2, typename U1, typename U2>
bool operator==(const Duo<T1, T2>& d1, const Duo<U1, U2>& d2)
{
	return d1.v1() == d2.v1() && d1.v2() == d2.v2();
}

template<typename T1,typename T2,typename U1,typename U2>
bool operator!=(const Duo<T1, T2>& d1, const Duo<U1, U2>& d2)
{
	return !(d1 == d2);
}

template<typename T1,typename T2>
Duo<T1, T2> MakeDuo(const T1& a, const T2& b)
{
	return Duo<T1, T2>(a, b);
}

template<typename A,typename B,typename C>
class Duo<A, Duo<B, C>>
{
public:
	typedef A			T1;
	typedef Duo<B, C>	T2;
	enum { N = Duo<B, C>::N + 1 };

private:
	T1					value1;
	T2					value2;

public:
	Duo() :value1(), value2()
	{

	}

	Duo(const T1& a, const T2& b)
		:value1(a), value2(b)
	{

	}

	template<typename U1, typename U2>
	Duo<T1, T2>& operator=(const Duo<U1, U2>& d)
	{
		value1 = d.value1;
		value2 = d.value2;
		return *this;
	}

	T1& v1()
	{
		return value1;
	}

	const T1& v1()const
	{
		return value1;
	}

	T2& v2()
	{
		return value2;
	}

	const T2& v2()const
	{
		return value2;
	}
};

template<typename A>
class Duo<A, void>
{
public:
	typedef		A		T1;
	typedef		void	T2;
	enum { N = 1 };

private:
	T1			value1;

public:
	Duo() :value1()
	{

	}

	Duo(const T1& a) :value1(a)
	{

	}

	T1& v1()
	{
		return value1;
	}

	const T1& v1()const
	{
		return value1;
	}

	void v2()
	{

	}

	void v2()const
	{

	}
};

#endif // !DUO_H

