#ifndef DCG_ANGLE_AXIS_INCLUDED
#define DCG_ANGLE_AXIS_INCLUDED

#include "util.hpp"
#include <cmath>

#include "Vec3.hpp"

namespace glob{

class AngleAxis : public BuildNode_t<quat>{
	typedef BuildNode_Assign<float> Float;

public:
	bool isLocal;//does not effect other variables whatsoever
	//
	Float angle;//radians
	Vec3 axis;

public:
	AngleAxis(bool isLocal, float angle, vec3 axis) :
		isLocal(isLocal),
		angle(angle),
		axis(axis)
	{
		this->angle.addTarget(this);
		this->axis.addTarget(this);
	}
	
private:
	virtual quat makeBuildVal(){
		return(glm::angleAxis(angle.get(), axis.get()));
	}
};

}

#endif














































/*class DualAngleAxis : private AngleAxis{
	AngleValue angle;

public:
	DualAngleAxis(bool isLocal, vec3 axis, AngleValue angle)
		: AngleAxis(isLocal, angle.getValue(), axis), angle(angle)
	{}

	
};*/

/*AngleAxis(bool isLocal, float angle, vec3 axis){
	this->isLocal = isLocal;
	this->angle = angle;
	this->axis = axis;
}
AngleAxis(bool isLocal, AngleValue angle, vec3 axis) :
	isLocal(isLocal),

	axis(axis)
{}*/
