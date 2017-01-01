#ifndef DCG_ANGLE_VALUE_INCLUDED
#define DCG_ANGLE_VALUE_INCLUDED

#include "util.hpp"
#include <cmath>

namespace glob{

//a value that can be stored as radians or degrees, and is truncated to 1 rotation.
class AngleValue{
private:
	bool b_radians;
	float val;

public:
	AngleValue(bool b_radians, float val) : b_radians(b_radians), val(val) {}

	void setRadians(float val){
		b_storeRadians = true;
		this->val = val;
	}
	void setDegrees(float val){
		b_storeRadians = false;
		this->val = val;
	}
	
	float getRadians(){
		return(b_radians ? val : (val * PI / 180));
	}
	float getDegrees(){
		return(b_radians ? val : (val * 180 / PI));
	}

	void truncate(){
		float minAngle = 0.0f;
		float maxAngle = b_storeRadians ? (2*PI) : 360.0f;
		//
		if (angle >= maxAngle) {
			angle = fmod(angle, maxAngle);
		}
		else if (angle < 0){
			angle = maxAngle - fmod(abs(angle), maxAngle);
		}
	}
};

}

#endif
