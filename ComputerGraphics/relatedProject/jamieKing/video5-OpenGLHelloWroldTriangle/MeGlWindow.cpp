// #include<gl\glew.h>
#include <MeGIWindow.h>

void MeGlWindow::initializeGL(){
    glewInit();

    GLfloat verts[] = 
    {
        +0.0f, +1.0f,
        -1.0f, -1.0f, 
        +1.0f, -1.0f
    };

    GLuint myBufferID;
    glGenBuffers(1, &myBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, myBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts),
        verts, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);


}

void MeGlWindow::paintGL(){
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // glClearColor(1, 0, 0, 1);
    // glClear(GL_COLOR_BUFFER_BIT);

}