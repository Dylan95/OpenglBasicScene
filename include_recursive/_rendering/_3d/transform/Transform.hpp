#ifndef TRANSFORM_INCLUDED_H
#define TRANSFORM_INCLUDED_H

#include "util.hpp"


#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/Exporter.hpp>
#include <assimp/cexport.h>
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include "Rot.hpp"
#include "QuatRot.hpp"
#include "EulerRot.hpp"

namespace glob{

using namespace glm;
using namespace dcg;

class Transform : public BuildNode_t<mat4x4>{
public:
	Vec3 pos;
	s_ptr<Rot> rot;
	Vec3 scale;

public:
	Transform(vec3 pos, s_ptr<Rot> rot, vec3 scale) :
		pos(pos), rot(rot), scale(scale)
	{
		this->pos.addTarget(this);
		this->rot->addTarget(this);
		this->scale.addTarget(this);
	}
	
	Transform() : 
		Transform(
			vec3(0.0f, 0.0f, 0.0f),
			make_shared<QuatRot>(),
			vec3(0.0f, 0.0f, 0.0f)
		)
	{}

	//

	void rotateAroundPoint(vec3 point, float angle, glm::vec3 axisDirection){
		axisDirection = glm::normalize(axisDirection);
		pos = point + rotateVector(pos.get() - point, -angle, axisDirection);
		rot->apply(angle, axisDirection);
	}

	vec3 toLocal(vec3 vec){
		return(rot->getBuildVal() * vec);
	}
	vec3 toGlobal(vec3 vec){
		return(vec * rot->getBuildVal());
	}

	vec3 right(){
		return(toGlobal(vec3(1, 0, 0)));
	}
	vec3 up(){
		return(toGlobal(vec3(0, 1, 0)));
	}
	vec3 forward(){
		return(toGlobal(vec3(0, 0, 1)));
	}

	//

	void translateLocal(vec3 change){
		pos = pos.get() + toLocal(change);
	}
	void translateGlobal(vec3 change){
		pos = pos.get() + change;
	}
	
	void scaleF(float f){
		this->scale = this->scale.get() * f;
	}
	void scaleLocal(vec3 scale){
		this->scale = this->scale.get() * toLocal(scale);
	}
	void scaleGlobal(vec3 scale){
		this->scale = this->scale.get() * scale;
	}
	
private:
	virtual mat4x4 makeBuildVal(){
		return(
			glm::translate(pos.get()) *
			toMat4(rot->getBuildVal()) *
			glm::scale(scale.get())
		);
	}
};

}

#endif



























/*


string toString(){
	stringstream stream;
	stream << 
		"transform:"
		"\n\tposition:	" << vec3ToString(pos) << 
		"\n\trotation:	" << quatToString(q) << 
		"\n\trotation as angle axis\n\t\t: " << angle(q) << ", " << vec3ToString(axis(q)) << 
		"\n\tscale:	    " << vec3ToString(scale) <<
		"\n//\n\tforward:  " << vec3ToString(forward()) << 
		"\n\tright:	    " << vec3ToString(right()) << 
		"\n\tup:        " << vec3ToString(up()) << endl;
	return(stream.str());
}

void rotateGlobal(quat quat_){
	//modelMatrix = toMat4(quat_) * modelMatrix;
	q = q * quat_;
	//q = quat_ * q;
	b_modelMatrixOutdated = true;
	b_qMatrixOutdated = true;
}


void setPos(glm::vec3 pos) {
	this->pos = TRANSFORM_HANDEDNESS(pos);
}
//
void setRot(glm::quat q) {
	this->q = q;
}
void setRot(float angle, glm::vec3 axis) { setRot(angleAxis(angle, axis)); }
void setRot(glm::vec3 rot) { setRot(quat(rot)); }
//
void setScale(vec3 scale) {
	this->scale = TRANSFORM_HANDEDNESS(scale);
}

vec3 getPos() { return(TRANSFORM_HANDEDNESS(pos)); }
quat getRot() { return(q); }
vec3 getScale() { return(TRANSFORM_HANDEDNESS(scale)); }
	
   
Transform(const vec3& pos, const quat& q, const vec3& scale) :
	pos(pos), q(q), scale(scale)
{}

Transform(aiMatrix4x4 matrix){
	aiVector3t<float> scaling;
	aiQuaterniont<float> rotation;
	aiVector3t<float> position;
	matrix.Decompose(scaling, rotation, position);
	this->scale = glm::vec3(scaling.x, scaling.y, scaling.z);
	this->pos = glm::vec3(position.x, position.y, position.z);
	this->q = glm::quat(rotation.w, rotation.x, rotation.y, rotation.z);
}


*/

