#include"shaderClass.h"

// Reads a text file and outputs a string with everything in the text file
std::string get_file_contents(const char* filename) {
	std::ifstream in(filename, std::ios::binary);	// in() (aka: input) -> opens file for reading as binary rather than text

	if (in) {
		std::string contents;					// char* array where txt file is stored
		in.seekg(0, std::ios::end);				// sets the pos of the next character to be extracted from the input stream
		contents.resize(in.tellg());			// resize the string to a length of (tellg() returns position of current character)
		in.seekg(0, std::ios::beg);				// goes back to beginning 
		in.read(&contents[0], contents.size());	
		in.close();								
		return(contents);						
	}
	throw(errno);
}

// Constructor that build the Shader Program from 2 different shaders
Shader::Shader(const char* vertexFile, const char* fragmentFile) {
	// Store code in file as strings
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	// Convert shader source strings into char arrays
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// Vertex Shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);	// Gets refrence to Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);	// Attach Vertex Shader source to the Vertex Shader Object
	glCompileShader(vertexShader);							// Compile the Vertex Shader into machine code

	// Fragment Shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);		// Gets reference to Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);		// Attach Fragment Shader source to the Fragment Shader Object
	glCompileShader(fragmentShader);								// Compile the Vertex Shader into machine code

	// Shader Program
	ID = glCreateProgram();					// Create Shader Program Object and get its reference
	glAttachShader(ID, vertexShader);		// Attach vertex/fragment shaders to shader program
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);						// Wrap-up/link all the shaders together into the Shader Program

	// Cleanup
	glDeleteShader(vertexShader);			// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(fragmentShader);

}

// Activates the Shader Program
void Shader::Activate(){
	glUseProgram(ID);
}

// Deletes the Shader Program
void Shader::Delete(){
	glDeleteProgram(ID);
}