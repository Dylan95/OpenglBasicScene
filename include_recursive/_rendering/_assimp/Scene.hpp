#ifndef GLOB_SCENE_INCLUDED
#define GLOB_SCENE_INCLUDED

#include "util.hpp"

#include <stack>

#include "Mesh.hpp"
#include "SceneObject.hpp"

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/Exporter.hpp>
#include <assimp/cexport.h>
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

namespace glob{

//todo: materials
class Scene{
private:
	//the importer owns the data that it loads.
	//todo: remove as a field, and keep it only in the constructor,
	//    and load all data from the aiScene*.
	Assimp::Importer importer;
	aiScene* scene;
public:
	vector<s_ptr<Mesh>> meshes;
	s_ptr<SceneObject> root;

public:
	Scene(Context& context, ShaderGroup& shaders, string filename){
		aiScene* scene = loadScene(filename);
		//
		for(aiMesh* m : PtrRange<aiMesh*>(scene->mMeshes, scene->mNumMeshes)){
			meshes.emplace_back(new Mesh(context, shaders, m));
		}
		//
		//root
		std::stack<std::pair<w_ptr<SceneObject>, aiNode*>> s;
		root = makeObjFromNode(context, shaders, scene->mRootNode);
		s.push(std::pair<w_ptr<SceneObject>, aiNode*>(root, scene->mRootNode));
		while(! s.empty()){
			auto curr = s.top(); s.pop();
			w_ptr<SceneObject> objCurr = curr.first;
			aiNode* nodeCurr = curr.second;
			//
			for(aiNode* childNode : PtrRange<aiNode*>(nodeCurr->mChildren, nodeCurr->mNumChildren)){
				s_ptr<SceneObject> childObj = makeObjFromNode(context, shaders, nodeCurr);
				objCurr.lock()->children.push_back(childObj);
				s.push(std::pair<w_ptr<SceneObject>, aiNode*>(childObj, childNode));
			}
		}
	}

private:
	aiScene* loadScene(string filename){
		aiScene* newScene = const_cast<aiScene*>(importer.ReadFile(filename,
			aiProcess_Triangulate			| 
			aiProcess_GenSmoothNormals		| 
			aiProcess_FlipUVs
		));
		if(!newScene || newScene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !newScene->mRootNode) {
			cout << "ERROR::ASSIMP::" << importer.GetErrorString() << endl;
			newScene = NULL;
			exit(-1);
		}
		return(newScene);
	}

	s_ptr<SceneObject> makeObjFromNode(
		Context& context, 
		ShaderGroup& shaders, 
		aiNode* node
	){
		vector<w_ptr<Mesh>> meshRefs;
		for(uint i : PtrRange<uint>(node->mMeshes, node->mNumMeshes)){
			meshRefs.push_back(meshes[i]);
		}
		return(make_shared<SceneObject>(
			shaders,
			make_shared<Transform>(),
			s_ptr<Texture2D>(),
			meshRefs,
			context
		));
	}
};

}

#endif
