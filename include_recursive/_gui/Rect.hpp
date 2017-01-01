#ifndef DCG_RECT_INCLUDED
#define DCG_RECT_INCLUDED

#include "util.hpp"

namespace glob{

template<typename T>
struct Rect{
	T x;
	T y;
	T W;
	T H;

	Rect() {}

	Rect(T x, T y, T W, T H){
		this->x = x;
		this->y = y;
		this->W = W;
		this->H = H;
	}

	T top(){ return(y + H); }
	T right(){ return(x + W); }
};

typedef Rect<int> RectI;
typedef Rect<float> RectF;

}

#endif
