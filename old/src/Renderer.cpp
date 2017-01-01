#include "Renderer.hpp"

//typedef LinkedHashTable_P<SceneObject> SceneObjectTable;

//using dcg::hashing::LinkedHashMap;
//using dcg::hashing::Node;

//Renderer renderer;
	
//public:

/*Viewport::Viewport(Camera* camera) {
	this->camera = camera;
	//activeLayers.resize(renderer.getNumLayers());
}

void Viewport::render(){
	for(ShaderMatrix::Iterator* shaderIt = activeObjects.begin(); 
		shaderIt != activeObjects.end(); 
		shaderIt = shaderIt->next)
	{
		shaderIt->data.key->bind();
		//
		for(TextureMap::Iterator* textureIt = shaderIt->data.value->begin(); 
			textureIt != shaderIt->data.value->end(); 
			textureIt = textureIt->next)
		{
			if(textureIt->data.key != NULL){
				textureIt->data.key->bind();
			}
			//
			for(MeshMap::Iterator* meshIt = textureIt->data.value->begin(); 
				meshIt != textureIt->data.value->end(); 
				meshIt = meshIt->next)
			{
				shaderIt->data.key->update(meshIt->data.value->transform, camera);
				meshIt->data.key->Draw();
			}
		}
	}
}

bool Viewport::containsLayer(uint index){
	return(activeLayers[index]);
}

void Viewport::changeLayer(uint index){
	Layer* layer = renderer.getLayer(index);
	if(activeLayers[index]){
		for(LinkedHashTable_P<SceneObject>::Iterator* it = layer->objects.begin();
			it != layer->objects.end();
			it = it->next)
		{
			unordered_map<string, SceneObjectTable>::iterator tableIt = activeObjectNames.find(it->data->name);
			if(tableIt == activeObjectNames.end()){ exit(-1); }
			tableIt->second.remove(it->data);
			//
			activeObjects.removeSceneObject(it->data);
		}
	}
	else{
		for(LinkedHashTable_P<SceneObject>::Iterator* it = layer->objects.begin();
			it != layer->objects.end();
			it = it->next)
		{
			SceneObjectTable table = activeObjectNames[it->data->name];
			table.add(it->data);
			//
			activeObjects.addSceneObject(it->data);
		}
	}
	activeLayers[index] = ! activeLayers[index];
}

void Viewport::addLayer(){
	//activeLayers.push_back(false);
}

void Viewport::addObject(SceneObject* obj){
	//activeObjects.addSceneObject(obj);
}

void Viewport::removeObject(SceneObject* obj){
	//activeObjects.removeSceneObject(obj);
}

//end is NULL.
SceneObjectTable::Iterator* Viewport::findName_begin(string name){
	return(activeObjectNames.find(name)->second.begin());
}

//public:

Renderer() {}

void changeLayer(SceneObject* obj, Layer* newLayer){
	//SceneObjectTable* table;
	//
	for(list<Viewport*>::iterator it = viewports.begin(); it != viewports.end(); it++){
		if((*it)->activeLayers.contains(obj->layer)){
			(*it)->activeObjects.removeSceneObject(obj);
		}
		if((*it)->activeLayers.contains(newLayer)){
			(*it)->activeObjects.removeSceneObject(obj);
		}
	}
	//
	obj->layer->objects.remove(obj);
	newLayer->objects.add(obj);
	obj->layer = newLayer;
}
	
//end is NULL.
SceneObjectTable::Iterator* findName_begin(string name){
	return(objectNames.find(name)->second.begin());
}

*/
