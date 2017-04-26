#pragma once

#include <vector>
#include <stdexcept>
#include <deque>




template <typename T,typename CONT=std::deque<T> >class Stack {
private:
	CONT elements;
public:
	//Stack(Stack<T> const &);
	//Stack<T>& operator= (Stack<T> const& rhs) ;
	void push(T const &);
	T pop();
	T top() const;
	bool empty() const {
		return elements.empty();
	}

	template <typename T2,typename CONT2> Stack<T,CONT>& operator= (Stack<T2,CONT2> const &);
};

template <typename T,typename CONT>
	template<typename T2,typename CONT2>
	Stack<T,CONT>& 
	Stack<T,CONT>::operator= (Stack<T2,CONT2> const& rhs)
	{
		if ((void*)this == (void*)&rhs) {
			return *this;
		}

		Stack<T2> tmp(rhs);
		elements.clear();
		while (!tmp.empty()) {
			elements.push_front(tmp.top());
			tmp.pop();
		}

		return *this;
}

//template<typename T>
//inline Stack<T>::Stack(Stack<T> const &)
//{
//	
//}

//
//template<typename T>
//inline Stack<T>& Stack<T>::operator=(Stack<T> const & rhs)
//{
//	elements.clear();
//
//	return T;
//	
//}

template<typename T,typename CONT>
inline void Stack<T,CONT>::push(T const & element)
{
	elements.push_back(element);
}



template<typename T,typename CONT>
inline T Stack<T,CONT>::pop()
{
	if (elements.empty()) {
		throw std::out_of_range("Stack<>::pop::empty stack");
	}

	T element = elements.back();
	elements.pop_back();
	return element;
}

template<typename T,typename CONT>
inline T Stack<T,CONT>::top() const
{
	if (elements.empty()) {
		throw std::out_of_range("Stack<>::top:: empty stack");
	}
	return elements.back();
}


template<>
class Stack<std::string> {
private:
	std::deque<std::string> elements;
public:
	void push(std::string const &);
	void pop();
	std::string top() const;
	bool empty() const {
		return elements.empty();
	}
};

void Stack<std::string>::push(std::string const & element)
{
	elements.push_back(element);
}

void Stack<std::string>::pop()
{
	if (elements.empty()) {
		throw std::out_of_range("Stack<>::pop::empty stack");
	}
	elements.pop_back();

}

std::string Stack<std::string>::top() const
{
	if (elements.empty()) {
		throw std::out_of_range("Stack<>::pop::empty stack");
	}
	return elements.back();

}

template <typename T,typename CONT=std::vector<T> >
class Stackv2 {
private:
	CONT elements;
public:
	void push(T const &);
	void pop();
	T top() const;
	bool empty() const { return elements.empty(); }
};

template<typename T, typename CONT>
inline void Stackv2<T, CONT>::push(T const & element)
{
	elements.push_back(element);
}

template<typename T, typename CONT>
inline void Stackv2<T, CONT>::pop()
{
	if (elements.empty()) {
		throw std::out_of_range("Stackv1<>::pop(): empty stack");
	}
	elements.pop_back();
}

template<typename T, typename CONT>
inline T Stackv2<T, CONT>::top() const
{
	if (elements.empty()) {
		throw std::out_of_range("Stackv1<>::top: emtpy stack");
	}
	return elements.back();
}



//
//
//template <typename T, typename CONT = std::deque<T> >
//class Stackv3 {
//private:
//	CONT elems; // Ԫ��
//public:
//	void push(T const&); // push Ԫ��
//	void pop(); // pop Ԫ��
//	T top() const; // ���� stack �Ķ���Ԫ��
//	bool empty() const { // stack �Ƿ�Ϊ��
//		return elems.empty();
//	}
//	// ��Ԫ������Ϊ T2�� stack��ֵ
//	template <typename T2, typename CONT2>
//	Stackv3<T, CONT>& operator= (Stackv3<T2, CONT2> const&);
//};
//
//
//template <typename T, typename CONT>
//template <typename T2, typename CONT2>
//Stack<T, CONT>&
//Stack<T, CONT>::operator= (Stackv3<T2, CONT2> const& op2)
//{
//	if ((void*)this == (void*)&op2) { // �ж��Ƿ�ֵ���Լ�
//		return *this; // ��ע����� p47֮��Ӣ�İ濱��41
//	}
//	Stackv3<T2, CONT2> tmp(op2); // ���� op2��һ�ݿ���
//	elems.clear(); // �Ƴ���������Ԫ��
//	while (!tmp.empty()) { // ��������Ԫ��
//		elems.push_front(tmp.top());
//		tmp.pop();
//	}
//	return *this;
//}



template <typename T> inline T const& max(T const &a, T const& b) {
	return a < b ? b : a;
}


inline int const& max(int const&a, int const& b) {
	return a < b ? b : a;
}

template <typename T> inline T const& max(T const &a, T const& b, T const& c) {
	return ::max(::max(a, b), c);
}

template <typename T> inline T* const& max(T* const& a, T*const& b) {
	return *a < *b ? b : a;
}

inline char const* const& max(char const* const&a, char const* const& b) {
	return strcmp(a, b) < 0 ? b : a;
}

//template <typename T> inline T const& max(T const &a, T const& b, T const& c) {
//	return ::max(::max(a, b), c);
//}