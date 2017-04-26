#pragma once

#include <memory>


//-------------------------------
//Parmeterized Declarations
//-------------------------------

template <typename T>
class List { // 一个 namespace scope class template
public:
	template <typename T2> // 一个 member function template
	List(List<T2> const&); // (这是个构造函数)
};

template <typename T>
template <typename T2>
List<T>::List(List<T2> const& b) // 一个定义于 class 外的 member function template
{

}

template <typename T>
int length(List<T> const&); // 一个 namespace scope function template

class Collection {
	template <typename T> // 一个定义于 class 内的 member class template
	class Node {
	};
	template <typename T> // 又一个 member class template，无定义
	class Handle;
	template <typename T> // 一个定义于 class 内的 member function template
	T* alloc() { // 隐寓为 inline

	}

};

template <typename T> // 一个定义于 class 外的 member class template
class Collection::Handle {

};

template <typename T>
union AllocChunk {
	T object;
	unsigned char bytes[sizeof(T)];
};

template <typename T> void report_top(Stack<T> const&, int number = 10);
//template <typename T> void fill(Array<T>*, T const& = T()); // 若 T为内建类型， T()为 0 或 false)

class Value {
private:
	int value_;
public:
	Value(int x) :value_(x) {

	}
};

template <typename T>class Array {
private:
public:
};

void fill(Array<Value>*, Value) {}


void init(Array<Value>* ar)
{
	Value zero(0);

	fill(ar, zero);
	//fill(ar);
}


template <int I>
class CupBoard {
	void open(); //译注：隶属于 CupBoard class template
	class Shelf; //译注：隶属于 CupBoard class template
	static double total_weight; //译注：隶属于 CupBoard class template
	
};
template <int I>
void CupBoard<I>::open()
{

}
template <int I>
class CupBoard<I>::Shelf {

}; 

template <int I> double CupBoard<I>::total_weight = 0.0;


//-----------------------------
//virtual member functions
//-----------------------------

template <typename T> class Dynamic
{
public:
	virtual ~Dynamic();

	virtual void idel();

	//template<typename T2> virtual void copy(T2 const &); //error
};


//-----------------------------
//Linkage
//-----------------------------

int C;
class C {};
//C C;

int X;
template<typename T> class X;

struct S;
//template<typename T> class S;


//-----------------------------
//Primary Templates
//-----------------------------

template<typename T> class Box; // OK： primary template87
//template<typename T> class Box<T>; // ERROR
template<typename T> void translate(T*); // OK： primary template
//template<typename T> void translate<T>(T*); // ERROR


template <typename Allocator> class myList
{
	typename Allocator* allocator;
	friend typename Allocator;
};

template <typename T,
	typename T::Allocator* Allocator> class myList1;



template<int buf[5]> class Lexer; // buf实际被当作 int*
template<int* buf> class Lexer; // OK：这是一个再声明（ redeclaration）

template <template<typename X> class C> // OK
void f(C<int>* p);


//template <template<typename X> struct C> // ERROR：不能使用关键词 struct
//void f(C<int>* p);
//template <template<typename X> union C> // ERROR：不能使用关键词 union
//void f(C<int>* p);

class MyAllocator;

template <template < typename, typename = MyAllocator> class Container > class Adaptation {
	Container<int> storage;
};

template <typename T1, typename T2, typename T3, typename T4 = char, typename T5 = char> class Quintuple; // OK
template <typename T1, typename T2, typename T3 = char,	typename T4, typename T5> class Quintuple; // OK： T4和 T5先前已有默认值
template <typename T1 = char, typename T2, typename T3,	typename T4, typename T5> class Quintuple; // 错误： T1不能拥有默认值，因为 T2没有默认值


template<typename T = void> class Value2;
//template<typename T = int>  // ERROR：预设自变量被重复定义了
//class Value2;