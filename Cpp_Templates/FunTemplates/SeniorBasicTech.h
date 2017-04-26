#pragma once

#include <deque>
#include <stdexcept>
#include <memory>
#include <typeinfo>

template <typename T>
void printcoll(T const& coll){
	typename T::const_iterator pos;
	typename T::const_iterator end(coll.end());

	for (pos = coll.begin(); pos != end; ++pos)
	{
		std::cout << *pos << ' ';
	}

	std::cout << std::endl;

}

//class Base {
//public:
//	void exit() {};
//};
//
//template <typename T>
//class Derived : public Base<T> {
//public:
//	void foo() {
//		//exit();
//		Base<T>::exit();
//	}
//};

template <typename T,
	template <typename ELEM,
		typename ALLOC=std::allocator<ELEM> >
			class CONT = std::deque >
class stack {
private:
	CONT<T> elements;
public:
	void push(T const &);
	void pop();
	T top() const ;
	bool empty() const {
		return elements.empty();
	}

	template <typename T2, template<typename ELEM2,
		typename ALLOC = std::allocator<ELEM2> >
		class CONT2>
		stack<T, CONT>& operator=(stack<T2, CONT2> const &);
	
};


template <typename T,template<typename ELEM, typename ALLOC=std::allocator<ELEM> > class CONT>
void stack<T,CONT>::push(T const & elem) {
	elements.push_back(eleme);
}

template <typename T,template<typename,typename> class CONT>
void stack<T,CONT>::pop() {
	if (elements.empty()) {
		throw std::out_of_range("stack<>::pop(): empty stack.");
	}
	elements.pop_back();
}

template <typename T,template<typename,typename> class CONT>
T stack<T,CONT>::top() const  {
	if (elements.empty()) {
		throw std::out_of_range("stack<>::top(): empty stack.");
	}
	return elements.back();
}

template <typename T,template<typename,typename> class CONT>
template <typename T2,template<typename,typename> class CONT2>
stack<T, CONT>&
stack<T, CONT>::operator=(stack<T2, CONT2> const &rhs) {
	if ((void*)this == (void*)&rhs)
		return *this;
	stack<T2, CONT2> tmp(rhs);
	elements.clear();
	while (!tmp.empty()) {
		elements.push_front(tmp.top());
		tmp.pop();
	}
	return *this;
}


template <typename T>
void ref(T const& x)
{
	std::cout << "x in ref(T const&): "
		<< typeid(x).name() << std::endl;
}
template <typename T>
void nonref(T x)
{
	std::cout << "x in nonref(T): "
		<< typeid(x).name() << std::endl;
}
