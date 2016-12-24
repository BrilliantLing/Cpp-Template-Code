#include"TypeRecognition.h"
#include<iostream>

using std::cout;
using std::endl;

class MyClass
{

};

void MyFunction()
{

}

enum E { e1 };

template<typename T>
void check()
{
	if (Type<T>::IsBasicType)
	{
		cout << "Basic Type" << endl;
	}
	else if (Type<T>::IsPointerType)
	{
		cout << "Pointer Type" << endl;
	}
	else if (Type<T>::IsReferenceType)
	{
		cout << "Reference Type" << endl;
	}
	else if (Type<T>::IsArrayType)
	{
		cout << "Array Type" << endl;
	}
	else if (Type<T>::IsFunctionType)
	{
		cout << "Function Type" << endl;
	}
	else if (Type<T>::IsPointerMemberType)
	{
		cout << "Pointer Member Type" << endl;
	}
	else if (Type<T>::IsEnumType)
	{
		cout << "Enum Type" << endl;
	}
	else if(Type<T>::IsClassType)
	{
		cout << "Class Type" << endl;
	}
}

template<typename T>
void Check(T)
{
	check<T>();
	if (Type<T>::IsPointerType || Type<T>::IsPointerMemberType)
	{
		check<typename CompoundType<T>::BaseType>();
	}
}

int main()
{
	cout << "int:"<<endl;
	check<int>();

	cout << "int&:" << endl;
	check<int&>();

	cout << "char[42]:" << endl;
	check<char[42]>();

	cout << "MyClass:" << endl;
	check<MyClass>();

	cout << "Pointer to Enum:" << endl;
	E* ptr = 0;
	Check(ptr);

	cout << "42:" << endl;
	Check(42);

	cout << "MyFunction():" << endl;
	Check(MyFunction);

	cout << "Member Pointer to Array:" << endl;
	char(MyClass::* memptr)[] = 0;
	Check(memptr);

	return 0;
}