// Victor Gordan Tutorial: https://www.youtube.com/watch?v=KG9ZXKaJWwY&list=PLPaoO-vpZnumdcb4tZc4x5Q-v7CkrQ6M-&index=4
// Left off: Tutorial 4
//


#include<GL/glew.h>
//#include<glad/glad.h>	//original
//#include<GLFW/glfw3.h>	//original
#include"MeGlWindow.h"

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

/*
void sendDataToOpenGL() {
	GLfloat verts[] =
	{
		+0.0f, +0.0f,		// Position
		+1.0f, +0.0f, 0.0f,	// RGB
		+1.0f, +1.0f,
		+1.0f, +0.0f, 0.0f,
		-1.0f, +1.0f,
		+1.0f, +0.0f, 0.0f,
		-1.0f, -1.0f,
		+1.0f, +0.0f, 0.0f,
		+1.0f, -1.0f,
		+1.0f, +0.0f, 0.0f,
	};

	GLuint vertexBufferID;
	glGenBuffers(1, &vertexBufferID);										// Creates name of a buffer for data 
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);							// Assigns bind pount to buffer just created
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);	// sends user data to buffer through bind point
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);	// tells arrtibute array 0 which values to take from verts for position
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 2)); // tells arrtibute array 1 which values to take from verts for position

	GLushort indices[] = { 0,1,2, 0,3,4 };									// order in which to draw vertices
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


}

void MeGlWindow::initializeGL(){
	glewInit();
	sendDataToOpenGL();
}


void MeGlWindow::paintGL() {

}
*/