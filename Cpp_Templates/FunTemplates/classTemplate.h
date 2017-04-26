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
//	CONT elems; // 元素
//public:
//	void push(T const&); // push 元素
//	void pop(); // pop 元素
//	T top() const; // 传回 stack 的顶端元素
//	bool empty() const { // stack 是否为空
//		return elems.empty();
//	}
//	// 以元素类型为 T2的 stack赋值
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
//	if ((void*)this == (void*)&op2) { // 判断是否赋值给自己
//		return *this; // 译注：请见 p47之「英文版勘误」41
//	}
//	Stackv3<T2, CONT2> tmp(op2); // 创建 op2的一份拷贝
//	elems.clear(); // 移除所有现有元素
//	while (!tmp.empty()) { // 复制所有元素
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