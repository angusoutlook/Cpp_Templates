#pragma once

#include <memory>


//-------------------------------
//Parmeterized Declarations
//-------------------------------

template <typename T>
class List { // һ�� namespace scope class template
public:
	template <typename T2> // һ�� member function template
	List(List<T2> const&); // (���Ǹ����캯��)
};

template <typename T>
template <typename T2>
List<T>::List(List<T2> const& b) // һ�������� class ��� member function template
{

}

template <typename T>
int length(List<T> const&); // һ�� namespace scope function template

class Collection {
	template <typename T> // һ�������� class �ڵ� member class template
	class Node {
	};
	template <typename T> // ��һ�� member class template���޶���
	class Handle;
	template <typename T> // һ�������� class �ڵ� member function template
	T* alloc() { // ��ԢΪ inline

	}

};

template <typename T> // һ�������� class ��� member class template
class Collection::Handle {

};

template <typename T>
union AllocChunk {
	T object;
	unsigned char bytes[sizeof(T)];
};

template <typename T> void report_top(Stack<T> const&, int number = 10);
//template <typename T> void fill(Array<T>*, T const& = T()); // �� TΪ�ڽ����ͣ� T()Ϊ 0 �� false)

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
	void open(); //��ע�������� CupBoard class template
	class Shelf; //��ע�������� CupBoard class template
	static double total_weight; //��ע�������� CupBoard class template
	
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

template<typename T> class Box; // OK�� primary template87
//template<typename T> class Box<T>; // ERROR
template<typename T> void translate(T*); // OK�� primary template
//template<typename T> void translate<T>(T*); // ERROR


template <typename Allocator> class myList
{
	typename Allocator* allocator;
	friend typename Allocator;
};

template <typename T,
	typename T::Allocator* Allocator> class myList1;



template<int buf[5]> class Lexer; // bufʵ�ʱ����� int*
template<int* buf> class Lexer; // OK������һ���������� redeclaration��

template <template<typename X> class C> // OK
void f(C<int>* p);


//template <template<typename X> struct C> // ERROR������ʹ�ùؼ��� struct
//void f(C<int>* p);
//template <template<typename X> union C> // ERROR������ʹ�ùؼ��� union
//void f(C<int>* p);

class MyAllocator;

template <template < typename, typename = MyAllocator> class Container > class Adaptation {
	Container<int> storage;
};

template <typename T1, typename T2, typename T3, typename T4 = char, typename T5 = char> class Quintuple; // OK
template <typename T1, typename T2, typename T3 = char,	typename T4, typename T5> class Quintuple; // OK�� T4�� T5��ǰ����Ĭ��ֵ
template <typename T1 = char, typename T2, typename T3,	typename T4, typename T5> class Quintuple; // ���� T1����ӵ��Ĭ��ֵ����Ϊ T2û��Ĭ��ֵ


template<typename T = void> class Value2;
//template<typename T = int>  // ERROR��Ԥ���Ա������ظ�������
//class Value2;