#ifndef IF_THEN_ELSE
#define IF_THEN_ELSE

template<bool C,typename TypeA,typename TypenB>
class BoolSelection;

template<typename TypeA,typename TypeB>
class BoolSelection<true, TypeA, TypeB>
{
public:
	typedef TypeA Result;
};

template<typename TypeA,typename TypeB>
class BoolSelection<false, TypeA, TypeB>
{
public:
	typedef TypeB Result;
};

#endif // !IF_THEN_ELSE
