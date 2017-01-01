#ifndef DCG_GL_WINDOW_INCLUDED
#define DCG_GL_WINDOW_INCLUDED

#include "util.hpp"

namespace glob{

/*#include <main.hpp>
//
#include <assimp/scene.h>
//
#include "Camera.hpp"
#include "Renderer.hpp"
//
#include "GLFW/glfw3.hpp"

// OPENGL WINDOW CLASS
class GlWindow{
public:
	//GLFWmonitor* monitor;
	//GLFWwindow* mode;
	GLFWwindow* win;
	//
	s_ptr<Viewport> viewport;
	//
	int countTemp;//todo: remove eventually.  used for debugging purposes only.
private:
	//bool b_viewportReady;
	//bool b_firstFrame;

public:
	GlWindow(s_ptr<Viewport> viewport, int W, int H, const char* name);

	void draw();

	void resize(int X,int Y,int W,int H);
};*/

}

#endif




































/*#include <main.hpp>
//
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Gl_Window.H>
//
#include <FL/Fl_Button.H>
#include <FL/Fl_Value_Slider.H>
//
#include <assimp/scene.h>
//
#include "Camera.hpp"
#include "Renderer.hpp"

// OPENGL WINDOW CLASS
class GlWindow : public Fl_Gl_Window {
public:
	//Camera* camera;
	//
	Viewport* viewport;//todo: fix.  continue here
	//
	int countTemp;//todo: remove eventually.  used for debugging purposes only.
private:
	bool b_viewportReady;

public:
	GlWindow(int W, int H, const char* name);
	GlWindow(int X, int Y, int W, int H, const char* name);

	GlWindow* copy();

private:
	GlWindow(GlWindow* original);

	void resize(int X,int Y,int W,int H);

	//event handlers:

    void draw();

	//other methods

	void init(int W, int H);

	void setup();

	void loadNodeTree(Layer* layer0);

	//for the meshes that aren't in the "aiNode" tree.
	void loadIsolatedMeshes(Layer* layer0);

	//embedded textures don't seem to be associated with specific meshes.
	//I'm not sure what to do with these.
	void loadEmbeddedTextures();

	//void loadMeshData(Layer* layer0){
	void loadData(aiNode* node, Layer* layer0);

	Mesh* makeMesh(aiMesh* meshData);

	Texture* loadMeshTexture(aiMesh* mesh);

	void initializeGlew();
};*/
