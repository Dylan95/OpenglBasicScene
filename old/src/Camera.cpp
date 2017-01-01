#include "Camera.hpp"
//
//#include <Transform.hpp>
#include <Rect.hpp>

using namespace glm;

namespace glob{

//const float CAMERA_FOV_DEFAULT = TO_RADIANS(100.0f);
//const float CAMERA_FOV_DEFAULT = 3.14f * 5.0f / 9.0f;
//const float CAMERA_FOV_DEFAULT = 100.0f;
//const float CAMERA_NEAR_DEFAULT = .1f;
//const float CAMERA_FAR_DEFAULT = 10000.0f;

/*Camera::Camera(
	float fov, 
	float aspect, 
	float zNear, 
	float zFar, 
	s_ptr<Transform> trans, 
	bool flipY
) :
	fov(fov),
	aspect(aspect),
	zNear(zNear),
	zFar(zFar),
	trans(trans),
	flipY(flipY)
{
	this->projection = glm::perspective(fov, aspect, zNear, zFar);
}


Camera::Camera(float aspect, s_ptr<Transform> trans, bool flipY)
	: Camera(
		CAMERA_FOV_DEFAULT, 
		aspect, 
		CAMERA_NEAR_DEFAULT,
		CAMERA_FAR_DEFAULT,
		trans,
		flipY
	) 
{}

glm::mat4x4 Camera::getViewProjection(){
	vec3 up = flipY ? -trans->up() : trans->up();
	return (
		projection * lookAt(trans->pos.get(), 
							trans->pos.get() + trans->forward(),
							up)
	);
}
*/
}







































//aspect: width / height
//Camera(float fov, float aspect, float zNear, float zFar, Transform transform)
/*Camera::Camera(float fov, float aspect, float zNear, float zFar, TransRot transform, bool flipY = false){
	init(fov, aspect, zNear, zFar, transform, flipY);
}

Camera::Camera(float aspect, TransRot transform, bool flipY = false){
	init(CAMERA_FOV_DEFAULT, aspect, CAMERA_NEAR_DEFAULT, CAMERA_FAR_DEFAULT, transform, flipY);
}

//

//View * Projection
glm::mat4x4 Camera::getViewProjection() {
	vec3 up = flipY ? -transform.up() : transform.up();
	return (
		projection * lookAt(transform.getPos(), 
							transform.getPos() + transform.forward(),
							up)
	);
}

//

void Camera::setFov(float fov){
	this->fov = fov;
	projection = perspective(fov, aspect, zNear, zFar);
}

void Camera::setAspect(float aspect){
	*//*perspectiveMatrix[0] = fFrustumScale / (w / (float)h);
	perspectiveMatrix[5] = fFrustumScale;
	glUniformMatrix4fv(perspectiveMatrixUnif, 1, GL_FALSE, perspectiveMatrix);*//*
	this->aspect = aspect;
	projection = perspective(fov, aspect, zNear, zFar);
}

void Camera::setZNear(float zNear){
	projection = perspective(fov, aspect, zNear, zFar);
}

void Camera::setZFar(float zFar){
	projection = perspective(fov, aspect, zNear, zFar);
}*/
