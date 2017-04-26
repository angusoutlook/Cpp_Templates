#pragma once


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

