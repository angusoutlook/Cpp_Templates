#pragma once


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

