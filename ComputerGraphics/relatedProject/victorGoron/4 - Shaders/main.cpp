#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"



// Vertices coordinates
GLfloat vertices[] = {
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,	// Lower left corner
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,		// Lower right corner
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,	// Upper corner
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,	// Inner left
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,	// Inner right
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f		// Inner down
};

// Indices for vertices order
GLuint indices[] = {
	0, 3, 5,	// Lower left triangle
	3, 2, 4,	// Lower right triangle
	5, 4, 1 // Upper triangle
};



int main(){
	// Initial and Setup
	glfwInit();														// Initialize GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);					// Tell GLFW version of OpenGL: 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// Tell GLFW using CORE profile: only have the modern functions

	// Create window
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);	// Create GLFWwindow object of 800 x 800 pixels
	if (window == NULL)	{													// Error check if the window fails to create
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);											// Introduce window into current context

	gladLoadGL();					//Load GLAD so it configures OpenGL
	glViewport(0, 0, 800, 800);		// Specify viewport of OpenGL in the Window: goes from x = 0, y = 0, to x = 800, y = 800
	
	
	// Generates Shader object
	Shader shaderProgram("default.vert", "default.frag");	// orange: (204, 77, 5)


	// Generates Vertex Array Object
	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));	// Generates Vertex Buffer Object and links it to vertices
	EBO EBO1(indices, sizeof(indices));		// Generates Element Buffer Object and links it to indices
	VAO1.LinkVBO(VBO1, 0);					// Links VBO to VAO
	
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();


	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);				// Color of the background rgba = (18, 33, 43, 255)
		glClear(GL_COLOR_BUFFER_BIT);							// Clean the back buffer and assign the new color to it
		shaderProgram.Activate();								// Tell OpenGL which Shader Program we want to use
		VAO1.Bind();											// Bind the VAO so OpenGL knows to use it
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);	// Draw primitives, number of indices, datatype of indices, index of indices
		glfwSwapBuffers(window);								// Swap the back buffer with the front buffer
		glfwPollEvents();										// Take care of all GLFW events
	}


	// Cleanup
	VAO1.Delete();					// Delete all the objects we've created
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	
	glfwDestroyWindow(window);		// Delete window before ending the program
	glfwTerminate();				// Terminate GLFW before ending the program
	
	return 0;
}