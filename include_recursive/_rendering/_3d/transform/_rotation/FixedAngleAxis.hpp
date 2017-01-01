#ifndef DCG_FIXED_ANGLE_AXIS_INCLUDED
#define DCG_FIXED_ANGLE_AXIS_INCLUDED

#include "util.hpp"
#include <cmath>

#include "Vec3.hpp"

namespace glob{

//an angle axis where the axis can't change.
class FixedAngleAxis : public BuildNode_t<quat>{
	typedef BuildNode_Assign<float> Float;

public:
	bool isLocal;//does not effect other variables whatsoever
	//
	Float angle;//radians
	const vec3 axis;

public:
	FixedAngleAxis(bool isLocal, float angle, vec3 axis) :
		isLocal(isLocal),
		angle(angle),
		axis(axis)
	{
		this->angle.addTarget(this);
	}
	
private:
	virtual quat makeBuildVal(){
		return(glm::angleAxis(angle.get(), axis));
	}
};

}


#endif


