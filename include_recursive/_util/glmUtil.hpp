#ifndef DCG_GLM_UTIL_INCLUDED
#define DCG_GLM_UTIL_INCLUDED

#include <sstream>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

#include "dcg/dcg.hpp"

namespace glob{

std::string quatToString(glm::quat q);

std::string vec2ToString(glm::vec2 v2);

std::string vec3ToString(glm::vec3 v3);

glm::vec3 rotateVector(glm::vec3 vec, float angle, glm::vec3 axis);

}

#endif


