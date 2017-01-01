#include "glmUtil.hpp"

#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "dcg/dcg.hpp"

using namespace dcg;
using namespace std;
using namespace glm;

string quatToString(glm::quat q){
	stringstream stream;
	stream << "(x: " << q.x << ", y: " << q.y << ", z: " << q.z << ", w: " << q.w << ")";
	return(stream.str());
}

string vec2ToString(vec2 v2){
	stringstream stream;
	stream << "(" << v2.x << ", " << v2.y << ")";
	return(stream.str());
}

string vec3ToString(vec3 v3){
	stringstream stream;
	stream << "(" << v3.x << ", " << v3.y << ", " << v3.z << ")";
	return(stream.str());
}

inline vec3 rotateVector(vec3 vec, float angle, vec3 axis){
	//vec4 result = glm::rotate(quat(angle, axis.x, axis.y, axis.z), v3);
	//return(vec3(result.x, result.y, result.z) * result.w);
	//return(glm::rotate(direction, angle, axis) * vec3(0, 0, 1));
	//glm::normalize(axis);
	return(angleAxis(angle, normalize(axis)) * vec);
}


