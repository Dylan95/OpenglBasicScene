#include "GlWindow.hpp"
//
#include "util.hpp"
//
#include <unordered_set>
#include <unordered_map>
#include <stack>
//
//#include <DisplayGL.hpp>
/*#include <Mesh.hpp>
#include <Program.hpp>
#include <LambertTexProgram.hpp>
#include <LambertBasicProgram.hpp>
#include <Texture.hpp>
//#include <SceneObject.hpp>
#include <importExport.hpp>
//
#include <Renderer.hpp>
//
#include "glm/glm.hpp"
#include "glm/mat4x4.hpp"*/

//extern string workingDirectory;
//bool isFirstFrame = true;


/*GlWindow::GlWindow(int W, int H, const char* name = NULL){
	countTemp = 0;
	//
	//renderer.viewports.push_back(this->viewport);
	//
	win = glfwCreateWindow(
		W, H, name, NULL, NULL
	);
	glfwMakeContextCurrent(win);
	assert(win != NULL);
	//
	//viewport = new Viewport();
	//renderer.viewports.push_back(this->viewport);
}


void GlWindow::resize(int X,int Y,int W,int H) {
	viewport->camera.setAspect((float) W / (float) H);
	glViewport(0, 0, W, H);
	//draw();
}

//event handlers:

void GlWindow::draw() {
	glViewport(0, 0, W, H);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//viewport->render();
	countTemp ++;
}*/

//other methods














































/*layer0->objects.add(new SceneObject(
	"mr smith",
	new Shader(workingDirectory + "\\res\\basicShader"),
	new Mesh(
		(vec3 *) scene->mMeshes[0]->mVertices, 
		meshTexCoords2D(scene->mMeshes[0]),
		(vec3 *) scene->mMeshes[0]->mNormals,
		scene->mMeshes[0]->mNumVertices, 
		Array<uint>(meshTriangleIndices(scene->mMeshes[0]), scene->mMeshes[0]->mNumFaces * 3),
		BOT_DYNAMIC, BOT_STATIC_INTERLEAVED, BOT_STATIC_INTERLEAVED, BOT_STATIC
	),
	new dcg::Texture(workingDirectory + "\\res\\bricks.jpg"),
	TransRot(vec3(0.0f, 0.0f, 3.0f), vec3(TO_RADIANS(0.0f), TO_RADIANS(0.0f), 0.0f), vec3(1.0f, 1.0f, 1.0f))
));*/
//
/*shader = Shader(workingDirectory + "\\res\\basicShader");
//
meshTransform = 
	Transform(vec3(0.0f, 0.0f, 3.0f), vec3(TO_RADIANS(0.0f), TO_RADIANS(0.0f), 0.0f), vec3(1.0f, 1.0f, 1.0f));
mesh = Mesh(
	(vec3 *) scene->mMeshes[0]->mVertices, 
	meshTexCoords2D(scene->mMeshes[0]),
	(vec3 *) scene->mMeshes[0]->mNormals,
	scene->mMeshes[0]->mNumVertices, 
	Array<uint>(meshTriangleIndices(scene->mMeshes[0]), scene->mMeshes[0]->mNumFaces * 3),
	BOT_DYNAMIC, BOT_STATIC_INTERLEAVED, BOT_STATIC_INTERLEAVED, BOT_STATIC
);
tex = dcg::Texture(workingDirectory + "\\res\\bricks.jpg");*/
//
//drawGroups[0].first = &shader;
//drawGroups[0].second.push_back(&sceneObj);
//
/*camera = Camera(TO_RADIANS(100.0f), 640.0f/480.0f, 0.1f, 100.0f, 
	TransRot(vec3(0.0f, 0.0f, 0.0f), PI * 0.0f, UP, vec3(1.0f, 1.0f, 1.0f), true, true, true));
	
	
	
	
	
	
	
	
//GlWindow::GlWindow(int X, int Y, int W, int H, const char* name = NULL){
//	init(W, H);
//}

GlWindow* GlWindow::copy(){
	GlWindow* gl = new GlWindow(x(), y(), w(), h(), label());
	//gl->show();
	//gl->make_current();
	//gl->context(this->context());
	return(gl);
}
	
	










Texture* GlWindow::loadMeshTexture(aiMesh* mesh){
	Texture* result;
	int matIndex = mesh->mMaterialIndex;
	aiMaterial* mat = scene->mMaterials[mesh->mMaterialIndex];
	int numTextures = mat->GetTextureCount(aiTextureType_DIFFUSE);
	aiString path;
	unordered_map<string, Texture*>::iterator pathsIt;
	//
	if(numTextures == 0){
		result = NULL;
	}
	else{
		if(mat->GetTexture(aiTextureType_DIFFUSE, 0, &path) != AI_SUCCESS){
			cerr << "fatal error loading texture of the mesh named \"" 
				<< mesh->mName.C_Str() << "\".  Exiting.\n\n";
			exit(-1);
		}
		if(numTextures > 1){
			cout << "model loading warning: the mesh named \"" << mesh->mName.C_Str() << "\" has multiple textures "
			"associated with it.  This program does not support rendering multiple textures per mesh."
			"texture 0 will be used.  The rest will be ignored.\n\n";
		}
		//
		pathsIt = texturePaths.find(string(path.C_Str()));
		if(pathsIt == texturePaths.end()){
			result = new Texture(workingDirectory + "\\" + string(path.C_Str()));
			texturePaths.insert(pair<string, Texture*>(
				string(path.C_Str()), 
				result
			));
		}
		else{
			result = pathsIt->second;
		}
	}
	//
	return(result);
	return(NULL);
}




//embedded textures don't seem to be associated with specific meshes.
//I'm not sure what to do with these.
void GlWindow::loadEmbeddedTextures(){
	for(uint i = 0; i < scene->mNumTextures; i++){
		aiTexture* t = scene->mTextures[i];
		int numPixels;
		TexturePixel* rgba;
		//
		numPixels = (t->mWidth * t->mHeight);
		if(t->mHeight == 0){
			cout << "texture loading warning: embedded texture " << i << " could not be loaded "
				"because it appears to be a compressed file type.  The texture has been ignored\n\n";
			embeddedTextures.push_back(NULL);
		}
		else{
			rgba = (TexturePixel *) malloc(sizeof(TexturePixel) * numPixels);
			for(int i = 0; i < numPixels; i++){
				rgba[i].r = t->pcData[i].r;
				rgba[i].g = t->pcData[i].g;
				rgba[i].b = t->pcData[i].b;
				rgba[i].a = t->pcData[i].a;
			}
			embeddedTextures.push_back(new Texture((byte_t *) rgba, t->mWidth, t->mHeight));
		}
	}
}




void GlWindow::loadNodeTree(Layer* layer0){
	stack<aiNode*> nodeStack;
	if(scene->mRootNode != NULL){
		nodeStack.push(scene->mRootNode);
		while(! nodeStack.empty()){
			aiNode* curr = nodeStack.top(); nodeStack.pop();
			//
			loadData(curr, layer0);
		}
	}
}

//for the meshes that aren't in the "aiNode" tree.
void GlWindow::loadIsolatedMeshes(Layer* layer0){
	TransRot meshTrans(
		vec3(0.0f, 0.0f, 0.0f),
		glm::quat(0.0f, 0.0f, 0.0f, 0.0f),
		vec3(1.0f, 1.0f, 1.0f), 
		true, true, true
	);
	Texture* tex = new dcg::Texture(workingDirectory + "\\res\\bricks.jpg");//temporary
	//
	for(uint i = 0; i < scene->mNumMeshes; i++){
		vector<Mesh*> meshes;
		stringstream name;
		Mesh* mesh = makeMesh(scene->mMeshes[i]);
		//
		name << "mesh_" << i;
		meshes.push_back(mesh);
		layer0->objects.add(new SceneObject(
			name.str(), meshTrans, shaderTextured, tex, meshes
			//name.str(), meshTrans, shaderUntextured, NULL, mesh
		));
	}
}

//void loadMeshData(Layer* layer0){
void GlWindow::loadData(aiNode* node, Layer* layer0){
	vector<Mesh*> meshes;
	if(node->mNumMeshes == 0){
		cerr << "mesh import error: assimp node named \"" << node->mName.C_Str() 
			<< "\" has no meshes.  Exiting.";
		return;
		//exit(-1);
	}
	else{
		if(node->mNumMeshes > 1){
			cout << "mesh import warning: assimp node named \"" << node->mName.C_Str()
				<< "\" has more than one mesh.  Only mesh 0 will be used.";
		}
		for(uint i = 0; i < scene->mNumMeshes; i++){
			aiMesh* meshData = scene->mMeshes[node->mMeshes[0]];
			meshes.push_back(makeMesh(meshData));
		}
	}
	//
	TransRot meshTrans(node->mTransformation, true, false, true);
	//
	//Texture* tex = loadMeshTexture(meshData);
	Texture* tex = new dcg::Texture(workingDirectory + "\\res\\bricks.jpg");
	//
	if(tex == NULL){//no texture for the mesh.
		layer0->objects.add(new SceneObject(
			"mr smith", meshTrans, shaderUntextured, NULL, meshes
		));
	}
	else{
		layer0->objects.add(new SceneObject(
			"mr smith", meshTrans, shaderTextured, tex, meshes
		));
	}
}

Mesh* GlWindow::makeMesh(aiMesh* meshData){
	vec3* verts = (vec3*) meshData->mVertices;
	vec2* texCoords = meshTexCoords2D(meshData);
	vec3* normals = (vec3*) meshData->mNormals;
	int numVerts = meshData->mNumVertices;
	Array<uint> indices = Array<uint>(
		meshTriangleIndices(scene->mMeshes[0]), scene->mMeshes[0]->mNumFaces * 3
	);
	return(new Mesh(
		verts, texCoords, normals, numVerts, indices,
		BOT_DYNAMIC, BOT_STATIC_INTERLEAVED, BOT_STATIC_INTERLEAVED, BOT_STATIC
	));
	return(NULL);
}











void GlWindow::setup(){
	initializeGlew();
	//Fl::gl_visual(FL_RGB | FL_DEPTH);//initialize fltk for use with opengl.
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//
	//load initial scene.
	//scene = loadScene(workingDirectory + "res\\table4_1.blend");
	scene = loadScene(workingDirectory + "res\\monkey3.obj");
	//scene = loadScene(workingDirectory + "res\\ducky.obj");
	//
	//viewport = new Viewport();
	//renderer.viewports.push_back(this->viewport);
	//
	shaderTextured = new LambertTexShader();
	//shader->init(workingDirectory + "\\res\\basicShader_noTexture");
	shaderTextured->init(workingDirectory + "\\res\\basicShader");
	//
	shaderUntextured = new LambertBasicShader();
	shaderUntextured->init(workingDirectory + "\\res\\basicShader_noTexture");
	//
	TransRot meshTrans(
		vec3(0.0f, 0.0f, 5.0f), 
		vec3(TO_RADIANS(0.0f), TO_RADIANS(0.0f), 0.0f), 
		vec3(1.0f, 1.0f, 1.0f)
	);
	Mesh* mesh = new Mesh(
		(vec3 *) scene->mMeshes[0]->mVertices, 
		meshTexCoords2D(scene->mMeshes[0]),
		(vec3 *) scene->mMeshes[0]->mNormals,
		scene->mMeshes[0]->mNumVertices, 
		Array<uint>(meshTriangleIndices(scene->mMeshes[0]), scene->mMeshes[0]->mNumFaces * 3),
		BOT_DYNAMIC, BOT_STATIC_INTERLEAVED, BOT_STATIC_INTERLEAVED, BOT_STATIC
	);
	dcg::Texture* tex = new dcg::Texture(workingDirectory + "\\res\\bricks.jpg");
	//
	Layer* layer0 = new Layer("the only layer so far");
	//
	layer0->objects.add(new SceneObject(
		"mr smith", meshTrans, shaderTextured, tex, mesh
		//"mr smith", meshTrans, shaderUntextured, NULL, mesh
	));
	loadNodeTree(layer0);
	loadIsolatedMeshes(layer0);
	//
	renderer.addLayer(layer0);
}





*/
