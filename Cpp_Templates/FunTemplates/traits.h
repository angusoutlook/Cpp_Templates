#pragma once

#include <stddef.h>
#include <iostream>



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
	static Acct const zero ;
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