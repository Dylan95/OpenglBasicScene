#include "OffscreenRenderer.hpp"
//
#include "Renderer.hpp"
#include "Camera.hpp"

//extern Renderer renderer;//from Renderer.cpp

//public



/*OffscreenRenderer::OffscreenRenderer(
	uint W, 
	uint H, 
	Transform cameraOrientation, 
	vector<bool> activeLayers
) :
	W(W),
	H(H)
{
	fb = new FrameBuffer(W, H);
	//readIndex = 0;
	//renderIndex = 1;
	//
	Camera* camera = new Camera((float)W / (float)H, cameraOrientation, true);
	viewport = new Viewport(camera);
	renderer.viewports.push_back(this->viewport);
	for(uint i = 0; i < activeLayers.size(); i++){
		if(activeLayers[i]){
			//adds objects in layer 0 to the viewport.
			viewport->changeLayer(i);
		}
	}
}

byte_t* OffscreenRenderer::render(){
	byte_t* result;
	//
	fb->bind();
	{
		glViewport(0, 0, W, H);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		viewport->render();
	}
	result = fb->read();
	fb->unbind();
	//
	return(result);
}

void OffscreenRenderer::resize(int W, int H){
	this->W = W;
	this->H = H;
	viewport->camera->setAspect((float)W / H);
	fb->resize(W, H);
}*/

















/*


OffscreenRenderer::OffscreenRenderer(
	uint W, unsigned int H, 
	TransRot cameraOrientation, vector<bool> activeLayers
){	
	this->W = W;
	this->H = H;
	//
	fb = new FrameBuffer(W, H);
	//readIndex = 0;
	//renderIndex = 1;
	//
	Camera* camera = new Camera((float)W / (float)H, cameraOrientation, true);
	viewport = new Viewport(camera);
	renderer.viewports.push_back(this->viewport);
	for(uint i = 0; i < activeLayers.size(); i++){
		if(activeLayers[i]){
			//adds objects in layer 0 to the viewport.
			viewport->changeLayer(i);
		}
	}
}


*/
