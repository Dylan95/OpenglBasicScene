/*#include <windowFunctions.hpp>

extern Camera camera;
extern Transform meshTransform;
//
extern GLuint program;
extern GLint matrixUniform;

//

//float aspectRatio;//camera needs access to this variable, use extern. y/x

//bad, causes error, I don't understand why.
void windowCloseCallback(GLFWwindow *window){
	checkError("window close callback: "); system("pause");
	glfwDestroyWindow(window);
	CHECK
}

void windowResizeCallback(GLFWwindow *window, int w, int h){
	mat4x4 matrix;
	//
	//glUseProgram(program);
	matrixUniform = glGetUniformLocation(program, "worldToScreenMatrix");
	camera.setAspect((float)w / h);
	matrix = camera.GetViewProjection() * meshTransform.calculateModel();//MVP: model <- view <- projection.
	glUniformMatrix4fv(matrixUniform, 1, GL_FALSE, &(matrix[0][0]));
	//glUseProgram(0);
	//
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

void glfwErrorCallback(int errorNum, const char *error){
	std::printf("glfw error: %d: %s", errorNum, error);
	system("pause");
}*/
