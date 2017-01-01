#ifndef DCG_LAMBERT_TEX_SHADER_INCLUDED
#define DCG_LAMBERT_TEX_SHADER_INCLUDED

#include "util.hpp"

#include "Camera.hpp"
#include "Transform.hpp"

namespace glob{

class LambertTexProgram : public Program{
	mat4 model;
	mat4 viewProjection;

public:
	LambertTexProgram(s_ptr<ProgramTarget> target, string filename)
		: Program(
			target,
			vector<s_ptr<Shader>>({
				make_shared<Shader>(
					FilesIO::fileToString(filename + ".vs"), 
					Shader::Type::VERTEX_SHADER
				),
				make_shared<Shader>(
					FilesIO::fileToString(filename + ".fs"), 
					Shader::Type::FRAGMENT_SHADER
				),
			}),
			vector<NamedAttrib>{
				NamedAttrib("position", 3, GL_FLOAT, GL_FALSE),
				NamedAttrib("texCoord", 2, GL_FLOAT, GL_FALSE),
				NamedAttrib("normal", 3, GL_FLOAT, GL_FALSE)
			},
			vector<string>({"MVP", "Model", "lightDirection"})
		) 
	{}
	//LambertTexShader() : Shader() {}

	//void update(Transform& transform, Camera* camera){
	void update(){
		Program::setUniform(2, vec3(0.0f, -1.0f, 0.0f));
	}

	//void update(Transform& transform, Camera* camera){
	void update(Transform& transform, Camera& camera){
		this->model = transform.getBuildVal();
		this->viewProjection = camera.getViewProjection();
		glm::mat4 mvp = viewProjection * model;
		//
		Program::setUniform(0, mvp);//temp
		Program::setUniform(1, model);
		Program::setUniform(2, vec3(0.0f, -1.0f, 0.0f));
	}

	//void update(Transform& transform, Camera* camera){
	void update(Transform& transform){
		this->model = transform.getBuildVal();
		glm::mat4 mvp = viewProjection * model;
		//
		Program::setUniform(0, mvp);//temp
		Program::setUniform(1, model);
	}

	//void update(Transform& transform, Camera* camera){
	void update(Camera& camera){
		this->viewProjection = camera.getViewProjection();
		glm::mat4 mvp = viewProjection * model;
		//
		Program::setUniform(0, mvp);//temp
	}
};

}

#endif
