#ifndef DCG_GL_UTIL_INCLUDED
#define DCG_GL_UTIL_INCLUDED


//#include "dcg/dcg.hpp"

//#include <string>

#include <GL/glew.h>
//#include <freeglut/freeglut.h>
//#include <GL/freeglut.h>
//
//#define GLFW_INCLUDE_GLU //for GLU
#include <GLFW/glfw3.h>


namespace glob{

/*void check(){
	checkError();
	system("pause");
}

void printGLData(GLenum target, std::string message){
	int data;
	glGetIntegerv(target, &data);
	cout << message << ": " << data << endl;
}
void printVersionInfo(){
	const GLubyte* renderer = glGetString (GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString (GL_VERSION); // version as a string
	printf ("Renderer: %s\n", renderer);
	printf ("OpenGL version supported %s\n", version);
}

void printMatrix(int cols, int rows, float *data){
	const int MAX_TEMP_SIZE = 32;
	for (int i = 0; i < rows; i++){
		printf("|     ");
		for (int j = 0; j < cols; j++){
			char *temp = (char *) malloc(sizeof(char) * MAX_TEMP_SIZE);
			snprintf(temp, sizeof(char) * MAX_TEMP_SIZE, "[%-.3f]", data[(j*cols) + i]);
			printf("%-12s", temp);
		}
		printf(" |\n|\n");
	}
}*/

}

#endif
