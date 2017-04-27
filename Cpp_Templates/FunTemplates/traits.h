#pragma once

#include <stddef.h>
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stack>



template<typename T> class AccumulationTraits;

template <> class AccumulationTraits<char> {
public:
	typedef int Acct;
	static Acct const zero = 0;
};

template <> class AccumulationTraits<char*> {
public:
	typedef std::string Acct;
	static Acct const zero;
};

template <> class AccumulationTraits<short> {
public:
	typedef int Acct;
	static Acct const zero = 0;
};

template <> class AccumulationTraits<int> {
public:
	typedef long Acct;
	static Acct const zero = 0;
};

template <> class AccumulationTraits<unsigned int> {
public:
	typedef unsigned long Acct;
	static Acct const zero = 0;
};

template <> class AccumulationTraits<float> {
public:
	typedef double Acct;
	static Acct const zero;
};

template <> class AccumulationTraits<double> {
public:
	typedef double Acct;
	static Acct const zero;
	//static Acct zero(){
	//	return 0;
	//};
};

double const AccumulationTraits<float>::zero = 0.0;
double const AccumulationTraits<double>::zero = 0.0;
std::string const AccumulationTraits<char *>::zero;


template <typename T> inline typename AccumulationTraits<T>::Acct accum(T const* beg, T const* end)
{

	typedef typename AccumulationTraits<T>::Acct Acct;
	Acct total = AccumulationTraits<T>::zero;
	//Acct total = AccumulationTraits<T>::zero();
	while (beg != end) {
		total += *beg;
		++beg;
	}
	return total;
}

class SumPolicy {
public:
	template<typename T1, typename T2> static void accumulate(T1 & total, T2 const &value) {
		total += value;
	}
};

class MultPolicy {
public:
	template <typename T1, typename T2> static void accumulate(T1 & total, T2 const &value) {
		if (total == 0)
		{
			total = value;
		}
		else {
			total *= value;
		}
	}
};

class CatPolicy {
public:
	template <typename T1, typename T2> static void accumulate(T1 &tatal, T2 const &value) {
		tatal.append(value);
	}
};

template <typename T, typename Policy = SumPolicy, typename Traits = AccumulationTraits<T> > class Accum {
public:
	typedef typename Traits::Acct Acct;
	static Acct accum(T const* beg, T const* end) {
		Acct total = Traits::zero;
		while (beg != end) {
			Policy::accumulate(total, *beg);
			++beg;
		}
		return total;
	}
};

template <typename Iter>
inline typename std::iterator_traits<Iter>::value_type accum(Iter start, Iter end)
{
	typedef typename std::iterator_traits<Iter>::value_type VT;
	VT total = VT(); // assume VT() actually creates a zero value
	while (start != end) {
		total += *start;
		++start;
	}
	return total;
}


//template <typename T1,typename T2> class SumPolicy {
//public:
//	static void accumulate(T1 & total, T2 const &value) {
//		total += value;
//	}
//};
//
//template <typename T1,typename T2> class MultPolicy {
//public:
//	static void accumulate(T1 & total, T2 const &value) {
//		if (total == 0)
//		{
//			total = value;
//		}
//		else {
//			total *= value;
//		}
//	}
//};
//
//template <typename T1,typement T2> class CatPolicy {
//public:
//	static void accumulate(T1 &tatal, T2 const &value) {
//		tatal.append(value);
//	}
//};
//
//template <typename T, template<typename T1,typename T2> class Policy = SumPolicy, typename Traits = AccumulationTraits<T> > class Accum {
//public:
//	typedef typename Traits::Acct Acct;
//	static Acct accum(T const* beg, T const* end) {
//		Acct total = Traits::zero;
//		while (beg != end) {
//			Policy<Acct,T>::accumulate(total, *beg);
//			++beg;
//		}
//		return total;
//	}
//};

//template<bool use_compound_op = true>
//class SumPolicy {
//public:
//	template<typename T1, typename T2>
//	static void accumulate(T1& total, T2 const & value) {
//		total += value;
//	}
//};
//template<>
//class SumPolicy<false> {
//public:
//	template<typename T1, typename T2>
//	static void accumulate(T1& total, T2 const & value) {
//		total = total + value;
//	}
//};


//template <typename T, typename AT = AccumulationTraits<T> > class Accum {
//public:
//	static typename AT::Acct accum(T const* beg, T const* end) {
//		typename AT::Acct total = AT::zero;
//		while (beg != end) {
//			total += *beg;
//			++beg;
//		}
//		return total;
//	}
//};

//
//template <typename T> inline T accum(T const* beg, T const* end)
//{
//	T total = T();
//	while (beg != end) {
//		total += *beg;
//		++beg;
//	}
//	return total;
//}

std::iterator_traits<std::string> iter;






//-----------------------------
// type function
//-----------------------------

template <typename T> class TypeSize {
public:
	static size_t const value = sizeof(T);
};

template <typename T> class ElementT;

template <typename T> class ElementT<std::vector<T> > {
public:
	typedef T Type;
};

template <typename T> class ElementT<std::list<T> > {
public:
	typedef T Type;
};

template <typename T> class ElementT<std::stack<T> > {
public:
	typedef T Type;
};

template <typename T> void print_element_type(T const & c) {
	std::cout << "Container of " << typeid(typename ElementT<T>::Type).name() << " elements." << std::endl;
}

//template <typename C> typename Element<C>::Type sum_of_elements(C const& c);

//-----------------------------
//determine class type
//-----------------------------

template <typename T> class IsClassT {
private:
	typedef char One;
	typedef struct { char a[2]; } Two;

	template<typename C> static One test(int C::*);
	template<typename C> static Two test(...);
public:
	enum { Yes = sizeof(IsClassT<T>::test<T>(0)) == 1 };
	enum { YesNo = sizeof(IsClassT<T>::test<T>()) == 2 };
	enum { No = !Yes };
};

class MyClass {};
struct MyStruct {};
union MyUnion {};
typedef void(*MYFUNC) (void);
MYFUNC MyFunc;
enum E { e1 } e;



template <typename T> void check() {
	if (IsClassT<T>::Yes) {
		std::cout << " IsClassT " << std::endl;
	}
	else {
		std::cout << " !IsClassT " << std::endl;
	}
	if (IsClassT<T>::YesNo && IsClassT<T>::Yes) {
		std::cout << " IsClassT and !IsClassT " << std::endl;
	}
}

template <typename T> void checkT(T) {
	check<T>();
}



//----------------------------------
//Refrences Qualifiers
//----------------------------------

//template <typename T> void apply(T& arg, void(*func)(T))
//{
//	func(arg);
//	std::cout << arg << std::endl;
//}

void incr(int &a) {
	++a;
}

void print(int a) {
	std::cout << a << std::endl;
}

template <typename T> class TypeOp {
public:
	typedef T			ArgT;
	typedef T			BareT;
	typedef T const		ConstT;
	typedef T &			RefT;
	typedef T &			RefBareT;
	typedef T const &	RefConstT;
};

template <typename T> class TypeOp<T const> {
public:
	typedef T const		ArgT;
	typedef T			BareT;
	typedef T const		ConstT;
	typedef T const &	RefT;
	typedef T &			RefBareT;
	typedef T const &	RefConstT;
};

template <typename T> class TypeOp<T &> {
public:
	typedef T &								ArgT;
	typedef typename TypeOp<T>::BareT		BareT;
	typedef T const							ConstT;
	typedef T &								RefT;
	typedef typename TypeOp<T>::BareT		RefBareT;
	typedef T const &						RefConstT;
};

template <> class TypeOp<void> {
public:
	typedef void		ArgT;
	typedef void		BareT;
	typedef void const	ConstT;
	typedef void		RefT;
	typedef void		RefBareT;
	typedef void		RefConstT;
};

template <typename T> void apply(typename TypeOp<T>::RefT arg, void(*func) (T))
{
	func(arg);
}


//-------------------------
//Promotion Traits
//-------------------------

template <typename T> Array<T> operator+ (Array<T> const&, Array<T> const&);
//template <typename T1, typename T2> Array<typename Promotion<T1,T2>::ResultT> operator+ (Array<T1> const&, Array<T2> const&);

//template <typename T1, typename T2> class Promotion {
//public:
//	typedef typename IfThenElse < (sizeof(T1) > sizeof(T2)), T1, typename IfThenElse<(sizeof(T1) < sizeof(T2)), T2, void >::ResultT > ::ResultT ResultT;
//};
template <bool C, typename Ta, typename Tb> class IfThenElse;

template <typename Ta, typename Tb> class IfThenElse<true, Ta, Tb>
{
public:
	typedef Ta ResultT;
};

template <typename Ta, typename Tb> class IfThenElse<false, Ta, Tb>
{
public:
	typedef Tb ResultT;
};

//--------------------------
//Policy Traits
//--------------------------

//template<typename T> class RParam {
//public:
//	typedef typename IfThenElse<sizeof(T) <= 2 * sizeof(void*), T, T const& >::ResultT Type;
//};
//
//template <typename T> class RParam<Array<T> > {
//public:
//	typedef Array<T> const& Type;
//};

template<typename T> class RParam {
public:
	typedef typename IfThenElse<IsClassT<T>::No, T, T const&>::ResultT Type;
};

class MyClass1 {
public:
	MyClass1() {
		std::cout << "MyClass1 constructor called\n";
	}
	MyClass1(MyClass1 const &) {
		std::cout << "MyClass1 copy constructor called\n";
	}
};

class MyClass2 {
public:
	MyClass2() {
		std::cout << "MyClass2 constructor called\n";
	}
	MyClass2(MyClass2 const &) {
		std::cout << "MyClass2 copy constructor called\n";
	}
};

template <> class RParam<MyClass2> {
public:
	typedef MyClass2 Type;
};

template <typename T1, typename T2> void foo_core(typename RParam<T1>::Type p1, typename RParam<T2>::Type p2) {

}

template <typename T1, typename T2> inline void foo(T1 const & p1, T2 const & p2) {
	foo_core<T1, T2>(p1, p2);
}

template <typename T, bool Bitwise> class BitOrClassCSM;


template <typename T> class CSMtraits :public BitOrClassCSM<T, IsClassT<T>::No> {

};

//template <> class CSMtraits<MyPODType> :public BitOrClassCSM<MyPODType, true> {
//
//};


template <typename T> class BitOrClassCSM<T, false> {
public:
	static void copy(typename RParam<T>::ResultT src, T* dst) {
		*dst = src;
	}

	static void copy_n(T const* src, T* dst, size_t n) {
		for (size_t k = 0; k < n; ++k) {
			dst[k] = src[k];
		}
	}

	static void copy_init(typename RParam<T>::ResultT src, void* dst) {
		::new(dst)T(src);
	}

	static void copy_init_n(T const* src, void* dst, size_t n) {
		// 将 n份数据拷贝（ copy）到未初始化的储存空间上
		for (size_t k = 0; k < n; ++k) {
			::new((void*)((char*)dst + k)) T(src[k]);
		}
	}
	static void swap(T* a, T* b) {
		// 置换（ swap, 对调）两份资料
		T tmp(*a);
		*a = *b;
		*b = tmp;
	}

	static void swap_n(T* a, T* b, size_t n) {
		// 置换（ swap, 对调） n份资料
		for (size_t k = 0; k < n; ++k) {
			T
				tmp(a[k]);
			a[k] = b[k];
			b[k] = tmp;
		}
	}

	static void move(T* src, T* dst) {
		// 搬移（ move） 一份数据到另一份身上
		assert(src != dst);
		*dst = *src;
		src->~T();
	}
	static void move_n(T* src, T* dst, size_t n) {
		// 搬移（ move） n份数据到另 n份身上
		assert(src != dst);
		for (size_t k = 0; k < n; ++k)
		{
			dst[k] = src[k];
			src[k].~T();
		}
	}
	static void move_init(T* src, void* dst) {
		// 搬移（ move） 一份数据到未初始化储存空间上
		assert(src != dst);
		::new(dst) T(*src);
		src->~T();
	}
	static void move_init_n(T const* src, void* dst, size_t n) {
		// 搬移（ move） n份数据到未初始化储存空间上
		assert(src != dst);
		for (size_t k = 0; k < n; ++k) {
			::new((void*)((char*)dst + k)) T(src[k]);
			src[k].~T();
		}
	}
};

template <typename T>
class BitOrClassCSM<T, true> : public BitOrClassCSM<T, false> {
public:
	static void copy_n(T const* src, T* dst, size_t n) {
		// 将 n份数据拷贝（ copy）到另外的 n份数据身上
		std::memcpy((void*)dst, (void*)src, n);
	}
	static void copy_init_n(T const* src, void* dst, size_t n) {
		// 将 n份数据拷贝（ copy）到未初始化储存空间上
		std::memcpy(dst, (void*)src, n);
	}
	static void move_n(T* src, T* dst, size_t n) {
		// 搬移（ move） n份数据到另 n份身上
		assert(src != dst);
		std::memcpy((void*)dst, (void*)src, n);
	}
	static void move_init_n(T const* src, void* dst, size_t n) {
		// 搬移（ move） n份数据到未初始化储存空间上
		assert(src != dst);
		std::memcpy(dst, (void*)src, n);
	}
};


