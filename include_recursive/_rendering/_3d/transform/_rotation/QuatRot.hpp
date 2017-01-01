#ifndef GLOB_QUAT_ROT_INCLUDED
#define GLOB_QUAT_ROT_INCLUDED

#include "util.hpp"

#include "AngleAxis.hpp"

#include <cmath>

namespace glob{

class QuatRot : public Rot{
public:
	typedef BuildNode_Assign<quat> Quat;

public:
	Quat q;

public:
	QuatRot(quat q = quat()) : 
		q(q)
	{
		this->q.set(q);
		this->q.addTarget(this);
	}

	virtual void apply(float angle, vec3 axis){
		axis = glm::normalize(axis);
		q.set(q.get() * angleAxis(angle, axis));
	}

private:
	virtual quat makeBuildVal(){
		return(q.get());
	};
};

}

#endif






