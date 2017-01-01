#ifndef DCG_SHADER_MATRIX_INCLUDED
#define DCG_SHADER_MATRIX_INCLUDED

#include "util.hpp"



#endif














/*

//#include <LinkedHashTable.hpp>
//#include <LinkedHashMap.hpp>
//#include <hashFunctions.hpp>
//
#include <Program.hpp>
#include <Texture.hpp>
//#include <Mesh.hpp>
#include <SceneObject.hpp>//SceneObject and Layer classes

//using dcg::PointerMap;
//using dcg::hash_table::Node;

//typedef PointerMap<Mesh, SceneObject>				MeshMap;
//typedef PointerMap<Texture, MeshMap>				TextureMap;

//not just a hash map matrix because the value is a hash table.
class ShaderMatrix : public LinkedHashMap_P<Shader, TextureMap*>{
public:
	ShaderMatrix() {
		init(dcg::hash_table::DEFAULT_NUM_BUCKETS);
	}

	ShaderMatrix(size_t numBuckets){
		init(numBuckets);
	}

	void removeSceneObject(SceneObject* obj){
		MeshMap* m;
		TextureMap* t;
		//
		if(find(t, obj->shader)){
			if(t->find(m, obj->texture)){
				for(vector<Mesh*>::iterator it = obj->meshes.begin(); it != obj->meshes.end(); it++){
					m->remove(*it);
				}
				if(m->getSize() == 0){ t->remove(obj->texture); }
			}
			if(t->getSize() == 0){ remove(obj->shader); }
		}
	}

	//only adds it if it doesn't already contain it.
	void addSceneObject(SceneObject* obj){
		MeshMap* m;
		TextureMap* t;
		//
		if(! find(t, obj->shader)){
			t = new TextureMap();
			add(obj->shader, t);

		}
		if(! t->find(m, obj->texture)){
			m = new MeshMap();

			t->add(obj->texture, m);
		}
		for(vector<Mesh*>::iterator it = obj->meshes.begin(); it != obj->meshes.end(); it++){
			m->add(*it, obj);
		}

	}

	bool containsSceneObject(SceneObject* obj){
		MeshMap* m;
		TextureMap* t;

		//
		if(find(t, obj->shader)){
			if(t->find(m, obj->texture)){
				return(m->contains(obj->meshes[0]));
			}
		}
		return(false);
	}
};


*/
