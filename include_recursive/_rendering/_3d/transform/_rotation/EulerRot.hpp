#ifndef GLOB_EULER_ROT_INCLUDED
#define GLOB_EULER_ROT_INCLUDED

#include "util.hpp"

#include "AngleAxis.hpp"
#include "FixedAngleAxis.hpp"

#include <cmath>

namespace glob{

class EulerRot : public Rot{
public:
	FixedAngleAxis x, y, z;

public:
	EulerRot(float x, float y, float z) : 
		x(false, x, vec3(1.0f, 0.0f, 0.0f)),
		y(false, y, vec3(0.0f, 1.0f, 0.0f)),
		z(false, z, vec3(0.0f, 0.0f, 1.0f))
	{
		this->x.addTarget(this);
		this->y.addTarget(this);
		this->z.addTarget(this);
	}

	virtual void apply(float angle, vec3 axis){
		quat q = getBuildVal();
		q = q * angleAxis(angle, axis);
		vec3 euler = eulerAngles(q);
		x.angle.set(euler.x);
		y.angle.set(euler.y);
		z.angle.set(euler.z);
	}

private:
	virtual quat makeBuildVal(){
		return(
			x.getBuildVal() * 
			y.getBuildVal() * 
			z.getBuildVal()
		);
	};
};

}

#endif






