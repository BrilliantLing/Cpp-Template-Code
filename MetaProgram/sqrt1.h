#ifndef SQRT1_H
#define SQRT1_H

template<int N,int L=0, int H=N>
class Sqrt
{
public:
	enum { mid = (L + H + 1) / 2 };
	enum { result = (N < mid*mid) ? Sqrt<N, L, mid - 1>::result : Sqrt<N, mid, H>::result };
};

template<int N,int M>
class Sqrt<N, M, M>
{
public:
	enum { result = M };
};

#endif // !SQRT_H
