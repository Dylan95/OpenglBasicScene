#ifndef GLOB_ROT_INCLUDED
#define GLOB_ROT_INCLUDED

#include "util.hpp"

#include "AngleAxis.hpp"

#include <cmath>

namespace glob{

class Rot : public BuildNode_t<quat>{
public:
	Rot() {}

	virtual void apply(float angle, vec3 axis) = 0;

private:
	virtual quat makeBuildVal() = 0;
};

}

#endif








































/*






	string toString(){
		stringstream stream;
		stream << "angle axes:";
		for (size_t i = 0; i < angleAxes.size(); i++){
			stream << "\n\t" << i << ": " 
				<< vec3ToString(angleAxes[i].getAxis()) << ": " << angleAxes[i].getAngle();
		}
		stream << "additional rotation: \n\tas quaternion: " << quatToString(additionalRotation)
			<< "as angle axis: " << vec3ToString(glm::axis(additionalRotation)) << ": " 
			<< glm::angle(additionalRotation);
		return(stream.str());
	}

*/


