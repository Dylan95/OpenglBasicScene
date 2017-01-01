#ifndef DCG_BOX_GROUP_INCLUDED
#define DCG_BOX_GROUP_INCLUDED

#include "util.hpp"

namespace glob{

class BoxGroup : public Fl_Group{
public:
	BoxGroup(int x, int y, int W, int H) : Fl_Group(x, y, W, H) {
		this->resizable(NULL);
	}

protected:
	void draw(){
		//fl_rectf(x(), y(), w(), h(), FL_BLUE);
		fl_rectf(x(), y(), w(), h(), this->color());
		Fl_Group::draw();
	}
};

}

#endif
