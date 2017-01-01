#ifndef DCG_LAMBERT_BASIC_SHADER_INCLUDED
#define DCG_LAMBERT_BASIC_SHADER_INCLUDED

#include "util.hpp"

namespace glob{

//for .\res\basicShader_noTexture vertex and fragment shaders.
class LambertBasicProgram : public Program{
	mat4 model;
	mat4 viewProjection;

public:
	LambertBasicProgram(s_ptr<ProgramTarget> target, string filename)
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
				NamedAttrib("normal", 3, GL_FLOAT, GL_FALSE)
			},
			vector<string>{"MVP", "Model", "lightDirection"}
		) 
	{}

	//void update(Transform& transform, Camera* camera){
	void update(){
		glm::mat4 mvp = viewProjection * model;
		//
		Program::setUniform(0, mvp);//temp
		Program::setUniform(1, model);
		Program::setUniform(2, vec3(0.0f, -1.0f, 0.0f));
	}

	//void update(Transform& transform, Camera* camera){
	void update(Transform& transform){
		this->model = transform.getBuildVal();
	}

	//void update(Transform& transform, Camera* camera){
	void update(Camera& camera){
		this->viewProjection = camera.getViewProjection();
	}

	/*//void update(Transform& transform, Camera* camera){
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
	}*/
};

}

#endif
