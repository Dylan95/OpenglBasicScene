#ifndef DCG_MESH_BUFFERS_INCLUDED
#define DCG_MESH_BUFFERS_INCLUDED

#include "dcg/dcg.hpp"

#include <memory>

//#include "util.hpp"
//#include "c_ptr.hpp"

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/Exporter.hpp>
#include <assimp/cexport.h>
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include "util.hpp"
//#include "gloc/gloc.hpp"

//#include "Program.hpp"
//#include "LambertTexProgram.hpp"
//#include "LambertBasicProgram.hpp"

//#include "VertexArray.hpp"
//#include "IndexedVAO.hpp"

//#include "VBO.hpp"
//#include "VBO_Single.hpp"

#include "ShaderGroup.hpp"

namespace glob{

//class Mesh : VBOGroup{
class Mesh{
	aiMesh* mesh;
	//
	s_ptr<IBO> indices;
	//
	VBOGroup vbos;
	//
	s_ptr<IndexedVAO> vaoUntextured;
	s_ptr<IndexedVAO> vaoTextured;

public:
	Mesh(
		Context& context,
		ShaderGroup shaders,
		aiMesh* mesh
	) :
		mesh(mesh)
	{
		c_ptr<BufferAccessor> posAccessor;
		c_ptr<BufferAccessor> texAccessor;
		c_ptr<BufferAccessor> normAccessor;
		//
		indices = make_shared<IBO>(
			context,
			meshTriangleIndices()
		);
		//
		vbos.addVBO(make_shared<VBO_Single<vec3>>(
			context,
			makePositions(),
			Buffer_Mutable::Usage::Frequency::STATIC
		));
		posAccessor.reset(vbos.getAccessor(vbos.getNumAccessors() - 1));
		if(hasTexCoords()){
			vbos.addVBO(make_shared<VBO_Single<vec2>>(
				context,
				makeTexCoords(),
				Buffer_Mutable::Usage::Frequency::STATIC
			));
			texAccessor.reset(vbos.getAccessor(vbos.getNumAccessors() - 1));
		}
		vbos.addVBO(make_shared<VBO_Single<vec3>>(
			context,
			makeNormals(),
			Buffer_Mutable::Usage::Frequency::STATIC
		));
		normAccessor.reset(vbos.getAccessor(vbos.getNumAccessors() - 1));
		//
		vector<VertexArray::Attachment> attachments;
		if(hasTexCoords()){
			vaoTextured = make_shared<IndexedVAO>(
				context,
				vector<VertexArray::Attachment>({
					VertexArray::Attachment(
						shaders.texture->getAttrib(0), 
						*posAccessor
					),
					VertexArray::Attachment(
						shaders.texture->getAttrib(1), 
						*texAccessor
					),
					VertexArray::Attachment(
						shaders.texture->getAttrib(2), 
						*normAccessor
					)
				}),
				indices
			);
		}
		vaoUntextured = make_shared<IndexedVAO>(
			context,
			vector<VertexArray::Attachment>({
				VertexArray::Attachment(
					shaders.basic->getAttrib(0), 
					*posAccessor
				),
				VertexArray::Attachment(
					shaders.basic->getAttrib(1), 
					*normAccessor
				)
			}),
			indices
		);
		//
		indices->buffer(Buffer_Mutable::Usage::Frequency::STATIC);
		buffer();
	}

	s_ptr<IBO> getIndices(){ return(indices); }

	bool hasTexCoords(){ return(mesh->mNumUVComponents != 0); }

	void assign(size_t index, vector<DIter> iters, size_t numElems){
		vbos.assign(index, iters, numElems);
		buffer();
	}
	void insert(size_t index, vector<DIter> iters, size_t numElems){
		vbos.insert(index, iters, numElems);
		buffer();
	}
	void remove(size_t index, size_t numElems){
		vbos.remove(index, numElems);
		buffer();
	}

	void bind(bool b_textured){
		if(b_textured){
			assert(vaoTextured);
			vaoTextured->bind();
		}
		else{
			vaoUntextured->bind();
		}
	}
	void draw(bool b_textured){
		if(b_textured){
			assert(vaoTextured);
			vaoTextured->draw();
		}
		else{
			vaoUntextured->draw();
		}
	}

private:
	void buffer(){
		if(hasTexCoords()){
			vbos.buffer(vector<Buffer_Mutable::Usage::Frequency>({
				Buffer_Mutable::Usage::Frequency::STATIC,
				Buffer_Mutable::Usage::Frequency::STATIC,
				Buffer_Mutable::Usage::Frequency::STATIC
			}));
		}
		else{
			vbos.buffer(vector<Buffer_Mutable::Usage::Frequency>({
				Buffer_Mutable::Usage::Frequency::STATIC,
				Buffer_Mutable::Usage::Frequency::STATIC
			}));
		}
	}
	
	s_ptr<vector<uint>> meshTriangleIndices(){
		s_ptr<vector<uint>> results(new vector<uint>(sizeof(uint) * mesh->mNumFaces * 3));
		for (uint i = 0; i < mesh->mNumFaces; i++){
			assert(mesh->mFaces[i].mNumIndices == 3);
			results->push_back(mesh->mFaces[i].mIndices[0]);
			results->push_back(mesh->mFaces[i].mIndices[1]);
			results->push_back(mesh->mFaces[i].mIndices[2]);
		}
		return(results);
	}

	s_ptr<c_vector<vec3>> makePositions(){
		vec3* begin = (vec3*) mesh->mVertices;
		return(make_shared<c_vector<vec3>>(begin, begin + mesh->mNumVertices));
	}

	s_ptr<c_vector<vec2>> makeTexCoords(){
		if(mesh->mNumUVComponents[0] == 0){
			return(NULL);
		}
		//
		s_ptr<c_vector<vec2>> results = make_shared<c_vector<vec2>>();
		//
		//assert(mesh->mNumUVComponents[0] != 0);//todo: continue here.  Jumps mysteriously, stack return address?
		for (	aiVector3D* texture = mesh->mTextureCoords[0]; 
				texture < mesh->mTextureCoords[0] + mesh->mNumVertices; 
				texture++){
			results->push_back(vec2(texture->x, texture->y));
		}
		return(results);
	}

	s_ptr<c_vector<vec3>> makeNormals(){
		vec3* begin = (vec3*) mesh->mNormals;
		return(make_shared<c_vector<vec3>>(begin, begin + mesh->mNumVertices));
	}
};

}

#endif





























/*s_ptr<vector<vec3>> makePositions(){
		vec3* begin = (vec3*) mesh->mVertices;
		s_ptr<vector<vec3>> results = make_shared<vector<vec3>>();
		for(vec3* it = begin; it != begin + mesh->mNumVertices; it++){
			results->push_back(*it);
		}
		return(results);
	}

	s_ptr<vector<vec2>> makeTexCoords(){
		if(mesh->mNumUVComponents[0] == 0){
			return(NULL);
		}
		//
		s_ptr<vector<vec2>> results = make_shared<vector<vec2>>();
		//
		//assert(mesh->mNumUVComponents[0] != 0);//todo: continue here.  Jumps mysteriously, stack return address?
		for (	aiVector3D* texture = mesh->mTextureCoords[0]; 
				texture < mesh->mTextureCoords[0] + mesh->mNumVertices; 
				texture++){
			results->push_back(vec2(texture->x, texture->y));
		}
		return(results);
	}

	s_ptr<vector<vec3>> makeNormals(){
		vec3* begin = (vec3*) mesh->mVertices;
		s_ptr<vector<vec3>> results = make_shared<vector<vec3>>();
		for(vec3* it = begin; it != begin + mesh->mNumVertices; it++){
			results->push_back(*it);
		}
		return(results);
	}*/

	/*s_ptr<vector<vec3>> makePositions(){
		return(s_ptr<vector<vec3>>(new vector<vec3>({
			vec3(0.0f, -1.0f, -1.0f),
			vec3(1.0f, 0.0f, 1.0f),
			vec3(0.0f, 1.0f, 1.0f)
		})));
	}

	s_ptr<vector<vec2>> makeTexCoords(){
		return(s_ptr<vector<vec2>>(new vector<vec2>({
			vec2(-1.0f, -1.0f),
			vec2(0.0f, 1.0f),
			vec2(1.0f, 1.0f)
		})));
	}

	s_ptr<vector<vec3>> makeNormals(){
		return(s_ptr<vector<vec3>>(new vector<vec3>({
			vec3(0.0f, -1.0f, -1.0f),
			vec3(1.0f, 0.0f, 1.0f),
			vec3(0.0f, 1.0f, 1.0f)
		})));
	}*/











/*
   
   


//class Mesh : VBOGroup{
class MeshTextured : public Mesh{
	s_ptr<VBOGroup> vbos;

public:
	MeshTextured(
		Context& context, 
		aiMesh* mesh, 
		s_ptr<LambertTexProgram> program
	) :
		vbos(make_shared<VBOGroup>(
			context,
			vector<VBOGroup::BuildGroup>({
				VBOGroup::BuildGroup(
					false, 
					DArray((byte_t*) mesh->mVertices, sizeof(vec3), mesh->mNumVertices), 
					Buffer_Mutable::Usage::Frequency::STATIC
				),
				VBOGroup::BuildGroup(
					false, 
					DArray::make<vec2>(*(meshTexCoords2D(mesh))), 
					Buffer_Mutable::Usage::Frequency::STATIC
				),
				VBOGroup::BuildGroup(
					false, 
					DArray((byte_t*) mesh->mNormals, sizeof(vec3), mesh->mNumVertices), 
					Buffer_Mutable::Usage::Frequency::STATIC
				),
			})
		)),
		Mesh(
			context,
			mesh, 
			vector<VertexArray::Attachment>({
				VertexArray::Attachment(program->getAttrib(0), vbos->makeAccessor(0)),
				VertexArray::Attachment(program->getAttrib(1), vbos->makeAccessor(1)),
				VertexArray::Attachment(program->getAttrib(2), vbos->makeAccessor(2)),
			}),
			program
		)
	{}

private:
	//todo: return vector instead.
};

//class Mesh : VBOGroup{
class MeshUntextured : public Mesh{
	s_ptr<VBOGroup> vbos;

public:
	MeshUntextured(
		Context& context, 
		aiMesh* mesh, 
		s_ptr<LambertBasicProgram> program
	) :
		vbos(make_shared<VBOGroup>(
			context,
			vector<VBOGroup::BuildGroup>({
				VBOGroup::BuildGroup(
					false, 
					DArray((byte_t*) mesh->mVertices, sizeof(vec3), mesh->mNumVertices), 
					Buffer_Mutable::Usage::Frequency::STATIC
				),
				VBOGroup::BuildGroup(
					false, 
					DArray((byte_t*) mesh->mNormals, sizeof(vec3), mesh->mNumVertices), 
					Buffer_Mutable::Usage::Frequency::STATIC
				),
			})
		)),
		Mesh(
			context,
			mesh, 
			vector<IndexedVAO::Attachment>({
				VertexArray::Attachment(program->getAttrib(0), vbos->makeAccessor(0)),
				VertexArray::Attachment(program->getAttrib(1), vbos->makeAccessor(1)),
			}),
			program
		)
	{}
};










   
   
   indexedVAO = make_shared<IndexedVAO>(
			context, 
			attachments,
			make_shared<IBO>(
				context,
				meshTriangleIndices(mesh),
				Buffer_Mutable::Usage::Frequency::STATIC
			)
		)
   
   
   
   
   
   
   
   Mesh(
	SplitVAO::BuildGroup positions, 
	SplitVAO::BuildGroup texCoords, 
	SplitVAO::BuildGroup normals, 
	ElemArrayBuff indices
) : SplitVAO(
	vector<SplitVAO::BuildGroup>({positions, texCoords, normals}), 
	indices
)
{}*/
/*Mesh(
	SplitVAO::BuildGroup positions,
	SplitVAO::BuildGroup texCoords,
	SplitVAO::BuildGroup normals,
	size_t numVerts,
	ElemArrayBuff indices
) : VBOGroup(
	vector<VBOGroup>({positions, texCoords, normals),
	indices
)
{}*/






//non-interleaved buffer attribs become interleaved.
/*void bufferAttribs_interleave(vector<unsigned short> attribIndices){
	vao->bufferAttribs_interleave(attribIndices);
}
//interleaved attribs become non-interleaved
void bufferAttribs_seperate(vector<unsigned short> attribIndices){
	vao->bufferAttribs_seperate(attribIndices);
}
//dynamic to streaming or vice versa.
void bufferAttribs_streaming_Dynamic(unsigned short attribIndex, BOT newBot){
	vao->bufferAttribs_streaming_Dynamic(attribIndex, newBot);
}
void bufferAttribs_streaming_Dynamic(vector<pair<unsigned short, BOT>> changes){
	vao->bufferAttribs_streaming_Dynamic(changes);
}*/



/*vao = u_ptr<VAO>(new VAO(
		vector<Attrib>({
			Attrib::make<vec3, float>(
				GL_FLOAT, 0, positions, GL_FALSE, positionsType),
			Attrib::make<vec2, float>(
				GL_FLOAT, 1, texCoords, GL_FALSE, texCoordsType),
			Attrib::make<vec3, float>(
				GL_FLOAT, 2, normals, GL_FALSE, normalsType)
		}),
		numVerts, 
		indices, 
		indicesType
	));*/








