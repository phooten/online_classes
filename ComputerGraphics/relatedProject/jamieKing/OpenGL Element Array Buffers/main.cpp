
/*
#include<gl/glew.h>

int main() {
	glewinit();

	return 0;
}
*/


//#include<qt\qapplication.h> // jamie king used this
#include<GL/glew.h>
//#include<glad/glad.h>
#include<glfw/glfw3.h>
#include"meglwindow.h"
#include<iostream>
using namespace std;


int main(int argc, char* argv[]) {
	//glewInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(800, 800, "blank", NULL, NULL);
	if (window == NULL) {
		std::cout << "failed to create glfw window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	
	
	while (!glfwWindowShouldClose(window)) {	// window should only be destroyed if window is closed
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(window);	//takes care of all glfw events
		glfwPollEvents();			// need to tell open gl to poll for events i.e. window being resized
	}
	

	glfwDestroyWindow(window);
	glfwTerminate();
	
 }
 