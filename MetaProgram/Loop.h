#ifndef LOOP_H

template<typename T,int dim>
class DotMultiply
{
public:
	static T result(T* a, T* b)
	{
		return (*a) * (*b) + DotMultiply<T, dim - 1>::result(a + 1, b + 1);
	}
};

template<typename T>
class DotMultiply<T, 1>
{
public:
	static T result(T* a, T* b)
	{
		return (*a) * (*b).;
	}
};

#endif // !LOOP_H
