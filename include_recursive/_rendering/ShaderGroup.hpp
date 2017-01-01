#ifndef DCG_SHADER_GROUP_INCLUDED
#define DCG_SHADER_GROUP_INCLUDED

#include "util.hpp"
#include "LambertTexProgram.hpp"
#include "LambertBasicProgram.hpp"

namespace glob{

//a collection of all shaders.
class ShaderGroup{
public:
	const s_ptr<LambertTexProgram> texture;
	const s_ptr<LambertBasicProgram> basic;

	/*ShaderGroup(s_ptr<LambertTexProgram> texture, s_ptr<LambertBasicProgram> basic) : 
		texture(texture),
		basic(basic)
	{}*/

	//arguments: the filesystem paths to the vertex and fragment shaders
	ShaderGroup(s_ptr<ProgramTarget> target, string texturePath, string basicPath) : 
		//texture(new LambertTexProgram(target, texturePath))
		texture(new LambertTexProgram(target, texturePath)),
		basic(new LambertBasicProgram(target, basicPath))
	{}
};

}

#endif


