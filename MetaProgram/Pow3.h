#ifndef POW3_H
#define POW3_H
template<int N>
class Pow3
{
public:
	enum { Result = 3 * Pow3<N - 1>::Result };
};

template<>
class Pow3<0>
{
public:
	enum { Result = 1 };
};
#endif // !POW3_H
