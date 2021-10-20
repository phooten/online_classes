#ifndef ME_GL_WINDOW.H
#define ME_GL_WINDOW.H
#include <QtOpenGL\qglwidget>

class MeGlWindow : public QGLWidget {
    public:
    private:
        void initializeGL();
        void paintGL();
}

#endif