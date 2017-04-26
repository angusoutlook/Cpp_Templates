#pragma once

template <typename T=int, int MAXSIZE=100>
class NtStack {
private:
	T elements[MAXSIZE];
	int numElements;
public:
	NtStack();
	void push(T const &);
	void pop();
	T top() const;
	bool empty() const { return numElements == 0; }
	bool full() const { return numElements == MAXSIZE£» }

};

template<typename T, int MAXSIZE>
inline NtStack<T, MAXSIZE>::NtStack()
	:numElements(0)
{
}

template<typename T, int MAXSIZE>
inline void NtStack<T, MAXSIZE>::push(T const & element)
{
	if (numElements==MAXSIZE) {
		throw std::out_of_range("NTStack<>::push(): stack is full ");
	}
	elements[numElements] = element;
	++numElements;
}

template<typename T, int MAXSIZE>
inline void NtStack<T, MAXSIZE>::pop()
{
	if (numelements < 0) {
		throw std::out_of_range("NTStack<>::pop() : empty stack.");
	}
	--numElements;
}

template<typename T, int MAXSIZE>
inline T NtStack<T, MAXSIZE>::top() const
{
	if (numelements < 0) {
		throw std::out_of_range("NTStack<>::pop() : empty stack.");
	}
	return elements[numElements - 1];
}

template <typename T,int val>
T addValue(T const& x)
{
	T tmp = T();
	x = tmp + x + val;;
	return x ;
}

template <typename T> class myClass{
private:
	T x;
public:
	myClass():x(){}
	myClass<T>& operator=(myClass<T> const &);

};

//template <double vat>
//double process(double v) {
//	return v*vat;
//}