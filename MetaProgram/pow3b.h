#ifndef POW3B_H
#define POW3B_H
template<int N>
class Pow3
{
public:
	static int const Result = Pow3<N - 1>::Result * 3;
};

template<>
class Pow3<0>
{
public:
	static int const Result = 1;
};
#endif // !POW3_H
