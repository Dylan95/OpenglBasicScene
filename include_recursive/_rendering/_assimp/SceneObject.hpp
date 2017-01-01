#ifndef SCENE_OBJECT_INCLUDED
#define SCENE_OBJECT_INCLUDED

#include "util.hpp"

#include "Mesh.hpp"

namespace glob{

using namespace dcg;

class SceneObject{
private:
	//s_ptr<Program> program;
	ShaderGroup shaders;
	s_ptr<Texture2D> tex;
	vector<w_ptr<Mesh>> meshes;
public:
	s_ptr<Transform> trans;
public:
	vector<s_ptr<SceneObject>> children;

public:
	SceneObject(
		ShaderGroup shaders,
		s_ptr<Transform> trans, 
		s_ptr<Texture2D> tex, 
		vector<w_ptr<Mesh>> meshes,
		Context& context
	) : 
		shaders(shaders),
		trans(trans),
		tex(tex),
		meshes(meshes)
	{}

	void drawTextured(){
		float modelVal[16];
		glGetUniformfv(shaders.texture->GLObject::id, 0, modelVal);
		glGetUniformfv(shaders.texture->GLObject::id, 1, modelVal);
		glGetUniformfv(shaders.texture->GLObject::id, 2, modelVal);
		//
		if(tex){
			assert(shaders.texture->isBound());
			assert(tex->isBound());
			glGetUniformfv(shaders.texture->GLObject::id, 0, modelVal);
			glGetUniformfv(shaders.texture->GLObject::id, 1, modelVal);
			glGetUniformfv(shaders.texture->GLObject::id, 2, modelVal);
			shaders.texture->update(*trans);
			glGetUniformfv(shaders.texture->GLObject::id, 0, modelVal);
			glGetUniformfv(shaders.texture->GLObject::id, 1, modelVal);
			glGetUniformfv(shaders.texture->GLObject::id, 2, modelVal);
			for(auto m : meshes){
				cout << "draw\n";
				m.lock()->bind(true);
				m.lock()->draw(true);
			}
			glGetUniformfv(shaders.texture->GLObject::id, 0, modelVal);
			glGetUniformfv(shaders.texture->GLObject::id, 1, modelVal);
			glGetUniformfv(shaders.texture->GLObject::id, 2, modelVal);
		}
	}
	void drawUntextured(){
		assert(shaders.basic->isBound());
		shaders.basic->update(*trans);
		for(auto m : meshes){
			m.lock()->bind(false);
			m.lock()->draw(false);
		}
	}
};



}


#endif

































/*
   
SceneObject(){}

//SceneObject(string name, TransRot transform, Shader* shader, Texture* texture, vector<Mesh*> meshes){   
   
   
SceneObject(string name, TransRot transform, Shader* shader, Mesh* mesh){
	this->name = name;
	this->transform = transform;
	//
	this->shader = shader;
	this->texture = NULL;
	this->mesh = mesh;
}

~SceneObject(){
	children.release();
}
	
	
	
	
	
	
	
*/



