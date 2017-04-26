#pragma once

#include <iostream>
#include "templateInPratice.h"
#include <iostream>
#include <typeinfo>

template<typename T>
void print_typeof(T const &);



template <typename T>
void print_typeof(T const & x)
{
	std::cout << typeid(x).name() << std::endl;
}


template void print_typeof<double>(double const &);

template <typename T> class myClassA {
private:
	T value_;
public:
	myClassA() :value_() {}
	myClassA<T>& operator=(myClassA<T> const &);

};

template myClassA<int>::myClassA();


template <typename T> void clear(T const& p) {
	//*p=0;
}

template <typename T> void core(T const& p) {
	clear(p);
}

template <typename T> void middle(typename T::Index p) {
	core(p);
}

template <typename T> void shell(T const& env) {
	typename T::Index i;
	middle<T>(i);
}

class Client {
public:
	typedef int Index;
};

//Client main_client;

// basics/tracer.hpp
class SortTracer {
private:
	int value; // 用来排序的整数
	int generation; // 此追踪器的生成个数
	static long n_created; // 构造函数被调用的次
	static long n_destroyed; // 析构函数被调用的次
	static long n_assigned; // 赋值次数
	static long n_compared; // 比较次数
	static long n_max_live; // 同一时间最多存在几个 objects
							// 重新计算「同一时间最多存在几个 objects」
	static void update_max_live() {
		if (n_created - n_destroyed > n_max_live) {
			n_max_live = n_created - n_destroyed;
		}
	}
public:
	static long creations() {
		return n_created;
	}
	static long destructions() {
		return n_destroyed;
	}
	static long assignments() {
		return n_assigned;
	}
	static long comparisons() {
		return n_compared;
	}
	static long max_live() {
		return n_max_live;
	}
public:
	// 构造函数（ constructor）
	SortTracer(int v = 0) : value(v), generation(1) {
		++n_created;
		update_max_live();
		std::cerr << "SortTracer #" << n_created
			<< ", created generation " << generation
			<< " (total: " << n_created - n_destroyed
			<< ')' << std::endl;
	}
	// copy 构造函数（ copy constructor）
	SortTracer(SortTracer const& b)
		: value(b.value), generation(b.generation + 1) {
		++n_created;
		update_max_live();
		std::cerr << "SortTracer #" << n_created
			<< ", copied as generation " << generation
			<< " (total: " << n_created - n_destroyed
			<< ')' << std::endl;
	}
	// 析构函数（ destructor）
	~SortTracer() {
		++n_destroyed;
		update_max_live();
		std::cerr << "SortTracer generation " << generation
			<< " destroyed (total: "
			<< n_created - n_destroyed << ')' << std::endl;
	}
	// 赋值（ assignment）
	SortTracer& operator= (SortTracer const& b) {
		++n_assigned;
		std::cerr << "SortTracer assignment #" << n_assigned
			<< " (generation " << generation
			<< " = " << b.generation
			<< ')' << std::endl;
		value = b.value;
		return *this;
	}
	// 比较（ comparison）
	friend bool operator < (SortTracer const& a,
		SortTracer const& b) {
		++n_compared;
		std::cerr << "SortTracer comparison #" << n_compared
			<< " (generation " << a.generation
			<< " < " << b.generation
			<< ')' << std::endl;
		return a.value < b.value;
	}
	int val() const {
		return value;
	}
};


long SortTracer::n_created = 0; 
long SortTracer::n_destroyed = 0;
long SortTracer::n_max_live = 0;
long SortTracer::n_assigned = 0;
long SortTracer::n_compared = 0;