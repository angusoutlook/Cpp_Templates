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
	int value; // �������������
	int generation; // ��׷���������ɸ���
	static long n_created; // ���캯�������õĴ�
	static long n_destroyed; // �������������õĴ�
	static long n_assigned; // ��ֵ����
	static long n_compared; // �Ƚϴ���
	static long n_max_live; // ͬһʱ�������ڼ��� objects
							// ���¼��㡸ͬһʱ�������ڼ��� objects��
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
	// ���캯���� constructor��
	SortTracer(int v = 0) : value(v), generation(1) {
		++n_created;
		update_max_live();
		std::cerr << "SortTracer #" << n_created
			<< ", created generation " << generation
			<< " (total: " << n_created - n_destroyed
			<< ')' << std::endl;
	}
	// copy ���캯���� copy constructor��
	SortTracer(SortTracer const& b)
		: value(b.value), generation(b.generation + 1) {
		++n_created;
		update_max_live();
		std::cerr << "SortTracer #" << n_created
			<< ", copied as generation " << generation
			<< " (total: " << n_created - n_destroyed
			<< ')' << std::endl;
	}
	// ���������� destructor��
	~SortTracer() {
		++n_destroyed;
		update_max_live();
		std::cerr << "SortTracer generation " << generation
			<< " destroyed (total: "
			<< n_created - n_destroyed << ')' << std::endl;
	}
	// ��ֵ�� assignment��
	SortTracer& operator= (SortTracer const& b) {
		++n_assigned;
		std::cerr << "SortTracer assignment #" << n_assigned
			<< " (generation " << generation
			<< " = " << b.generation
			<< ')' << std::endl;
		value = b.value;
		return *this;
	}
	// �Ƚϣ� comparison��
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