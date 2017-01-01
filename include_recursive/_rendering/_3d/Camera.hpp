#ifndef CAMERA_INCLUDED_H
#define CAMERA_INCLUDED_H

#include "util.hpp"

#include "Transform.hpp"
//#include <main.hpp>
//#include <TransRot.hpp>

namespace glob{

using namespace dcg;

//class Transform;

class Camera{
public:
	s_ptr<Transform> trans;
	bool flipY;//renders the image upside down.
	
private:
	float fov;
	float aspect;
	float zNear;
	float zFar;
	glm::mat4 projection;

public:
	Camera(
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

	Camera(float aspect, s_ptr<Transform> trans, bool flipY)
		: Camera(
			3.14 * 5.0f / 9.0f, 
			aspect, 
			.1f,
			10000.0f,
			trans,
			flipY
		) 
	{}

	//View * Projection
	glm::mat4x4 getViewProjection(){
		vec3 up = flipY ? -trans->up() : trans->up();
		return (
			projection * lookAt(trans->pos.get(), 
								trans->pos.get() + trans->forward(),
								up)
		);
	}

	void setFov(float fov){
		this->fov = fov;
		resetProjection();
	}
	void setAspect(float aspect){
		this->aspect = aspect;
		resetProjection();
	}
	void setZNear(float zNear){
		this->zNear = zNear;
		resetProjection();
	}
	void setZFar(float zFar){
		this->zFar = zFar;
		resetProjection();
	}

	inline float getFov()		{ return(fov); }
	inline float getAspect()	{ return(aspect); }
	inline float getZNear()		{ return(zNear); }
	inline float getZFar()		{ return(zFar); }

private:
	void resetProjection(){ projection = glm::perspective(fov, aspect, zNear, zFar); }
};

}

#endif























/*



void setAspect(float aspect){
	perspectiveMatrix[0] = fFrustumScale / (w / (float)h);
	perspectiveMatrix[5] = fFrustumScale;
	glUniformMatrix4fv(perspectiveMatrixUnif, 1, GL_FALSE, perspectiveMatrix);
}

//aspect: width / height
//Camera(float fov, float aspect, float zNear, float zFar, Transform transform)
//
//Camera(float fov, float aspect, float zNear, float zFar, TransRot transform, bool flipY);
//Camera(float aspect, TransRot transform, bool flipY);
//


//
//Rect<int> screenRect;
//bool isEnabled;



*/





