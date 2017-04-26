#pragma once



template<typename T> class AccumulationTraits;

template <> class AccumulationTraits<char> {
public:
	typedef int Acct;
	static Acct const zero = 0;
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
	static Acct const zero ;
};

double const AccumulationTraits<float>::zero = 0.0;
double const AccumulationTraits<double>::zero = 0.0;


template <typename T> inline typename AccumulationTraits<T>::Acct accum(T const* beg, T const* end)
{

	typedef typename AccumulationTraits<T>::Acct Acct;
	Acct total = AccumulationTraits<T>::zero;
	while (beg != end) {
		total += *beg;
		++beg;
	}
	return total;
}

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