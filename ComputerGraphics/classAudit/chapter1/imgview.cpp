/*
    Date: August 15, 2021 -> August 18, 2021
    Class:  CPSC 6040
    Assignment: Homework problem 1 - imgview
    Coder: Parker Hooten

    General Information and Requirements:
      - cube.ppm should be used to test the program, followed by teapot.jpg, and other
        images in different sizes and formats.
      - should be built to look like "imgview cube.ppm" from the command line
      - things to keep in mind:
          - use a class for pixel and or images
          - contiguous memory allocation
          - encapsulate some expected functionality for future use

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
*/
//
//   Sample OpenGL/GLUT Program to draw a square and save to an image File
//   using the OpenImageIO API
//
//   Program opens a window and draws a colored square on a white background
//
//   Display window saved to a file with 'w' keypress
//
//   Colors cycle through R, Y, G, C, B, M with 'c' keypress
//   Program quits when either 'q' or ESC key is pressed
//
//   CPSC 4040/6040            Ioannis Karamouzas
//
//   usage: gloiio
//

#include <OpenImageIO/imageio.h>
#include <iostream>

#ifdef __APPLE__
#  pragma clang diagnostic ignored "-Wdeprecated-declarations"
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

using namespace std;
OIIO_NAMESPACE_USING

// window dimensions
#define WIDTH 600
#define HEIGHT 600

static int icolor = 0;

/*
    Routine to write the current framebuffer to an image file
*/
void writeimage() {
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    int channels = 4;

    //unsigned char pixmap[4 * w * h];
    unsigned char* pixmap = new unsigned char[channels * w * h];
    string outfilename;

    // get a filename for the image. The file suffix should indicate the image file
    // type. For example: output.png to create a png image file named output
    cout << "enter output image filename: ";
    cin >> outfilename;

    // create the oiio file handler for the image
    //ImageOutput* outfile = ImageOutput::create(outfilename);
    std::unique_ptr<ImageOutput> outfile = ImageOutput::create(outfilename);
    if (!outfile) {
        cerr << "Could not create output image for " << outfilename << ", error = " << geterror() << endl;
        return;
    }

    // get the current pixels from the OpenGL framebuffer and store in pixmap
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, pixmap);

    // open a file for writing the image. The file header will indicate an image of
    // width w, height h, and 4 channels per pixel (RGBA). All channels will be of
    // type unsigned char
    ImageSpec spec(w, h, channels, TypeDesc::UINT8);
    if (!outfile->open(outfilename, spec)) {
        cerr << "Could not open " << outfilename << ", error = " << geterror() << endl;
        return;
    }

    // write the image to the file. All channel values in the pixmap are taken to be
    // unsigned chars
    // Gets saved: C:\Users\parke\source\repos\General_OpenGL\General_OpenGL
    if (!outfile->write_image(TypeDesc::UINT8, pixmap)) {
        cerr << "Could not write image to " << outfilename << ", error = " << geterror() << endl;
        return;
    }
    else
        cout << "Square is stored" << endl;

    // close the image file after the image is written
    if (!outfile->close()) {
        cerr << "Could not close " << outfilename << ", error = " << geterror() << endl;
        return;
    }
}

/*
    Routine to read a given image file name and project it to the screen
*/
void readimage() {
    string infilename;
    int xres;
    int yres;
    int channels;

    cout << "enter output image filename: ";
    cin >> infilename;

    auto in = ImageInput::open(infilename);
    //std::unique_ptr<ImageInput> in = ImageInput::open(infilename);
    if (!in) {
        cerr << "Could not create output image for " << infilename << ", error = " << geterror() << endl;
        return;
    }

    const ImageSpec& spec = in->spec();
    xres = spec.width;
    yres = spec.height;
    channels = spec.nchannels;

    std::vector<unsigned char> pixels(xres * yres * channels);

    in->read_image(TypeDesc::UINT8, &pixels[0]);
    in->close();


    //glDrawPixels(xres, yres, GL_RGBA, GL_UNSIGNED_BYTE, &pixels);
    /*int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    int channels = 4;

    //unsigned char pixmap[4 * w * h];
    unsigned char* pixmap = new unsigned char[channels * w * h];


    // create the oiio file handler for the image
    //ImageOutput* outfile = ImageOutput::create(outfilename);
    std::unique_ptr<ImageOutput> outfile = ImageOutput::create(outfilename);
    if (!outfile) {
        cerr << "Could not create output image for " << outfilename << ", error = " << geterror() << endl;
        return;
    }

    // get the current pixels from the OpenGL framebuffer and store in pixmap
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, pixmap);

    // open a file for writing the image. The file header will indicate an image of
    // width w, height h, and 4 channels per pixel (RGBA). All channels will be of
    // type unsigned char
    ImageSpec spec(w, h, channels, TypeDesc::UINT8);
    if (!outfile->open(outfilename, spec)) {
        cerr << "Could not open " << outfilename << ", error = " << geterror() << endl;
        return;
    }

    // write the image to the file. All channel values in the pixmap are taken to be
    // unsigned chars
    // Gets saved: C:\Users\parke\source\repos\General_OpenGL\General_OpenGL
    if (!outfile->write_image(TypeDesc::UINT8, pixmap)) {
        cerr << "Could not write image to " << outfilename << ", error = " << geterror() << endl;
        return;
    }
    else
        cout << "Square is stored" << endl;

    // close the image file after the image is written
    if (!outfile->close()) {
        cerr << "Could not close " << outfilename << ", error = " << geterror() << endl;
        return;
    }
    */
}

//
//   Sample OpenGL/GLUT Program to draw a square and save to an image File
//   using the OpenImageIO API
//
//   Program opens a window and draws a colored square on a white background
//
//   Display window saved to a file with 'w' keypress
//
//   Colors cycle through R, Y, G, C, B, M with 'c' keypress
//   Program quits when either 'q' or ESC key is pressed
//
//   CPSC 4040/6040            Ioannis Karamouzas
//
//   usage: gloiio
//

#include <OpenImageIO/imageio.h>
#include <iostream>

#ifdef __APPLE__
#  pragma clang diagnostic ignored "-Wdeprecated-declarations"
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

using namespace std;
OIIO_NAMESPACE_USING

// window dimensions
#define WIDTH 600
#define HEIGHT 600

static int icolor = 0;

/*
    Routine to write the current framebuffer to an image file
*/
void writeimage() {
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    int channels = 4;

    //unsigned char pixmap[4 * w * h];
    unsigned char* pixmap = new unsigned char[channels * w * h];
    string outfilename;

    // get a filename for the image. The file suffix should indicate the image file
    // type. For example: output.png to create a png image file named output
    cout << "enter output image filename: ";
    cin >> outfilename;

    // create the oiio file handler for the image
    //ImageOutput* outfile = ImageOutput::create(outfilename);
    std::unique_ptr<ImageOutput> outfile = ImageOutput::create(outfilename);
    if (!outfile) {
        cerr << "Could not create output image for " << outfilename << ", error = " << geterror() << endl;
        return;
    }

    // get the current pixels from the OpenGL framebuffer and store in pixmap
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, pixmap);

    // open a file for writing the image. The file header will indicate an image of
    // width w, height h, and 4 channels per pixel (RGBA). All channels will be of
    // type unsigned char
    ImageSpec spec(w, h, channels, TypeDesc::UINT8);
    if (!outfile->open(outfilename, spec)) {
        cerr << "Could not open " << outfilename << ", error = " << geterror() << endl;
        return;
    }

    // write the image to the file. All channel values in the pixmap are taken to be
    // unsigned chars
    // Gets saved: C:\Users\parke\source\repos\General_OpenGL\General_OpenGL
    if (!outfile->write_image(TypeDesc::UINT8, pixmap)) {
        cerr << "Could not write image to " << outfilename << ", error = " << geterror() << endl;
        return;
    }
    else
        cout << "Square is stored" << endl;

    // close the image file after the image is written
    if (!outfile->close()) {
        cerr << "Could not close " << outfilename << ", error = " << geterror() << endl;
        return;
    }
}

/*
    Routine to read a given image file name and project it to the screen
*/
void readimage() {
    string infilename;
    int xres;
    int yres;
    int channels;

    cout << "enter output image filename: ";
    cin >> infilename;

    auto in = ImageInput::open(infilename);
    //std::unique_ptr<ImageInput> in = ImageInput::open(infilename);
    if (!in) {
        cerr << "Could not create output image for " << infilename << ", error = " << geterror() << endl;
        return;
    }

    const ImageSpec& spec = in->spec();
    xres = spec.width;
    yres = spec.height;
    channels = spec.nchannels;

    std::vector<unsigned char> pixels(xres * yres * channels);

    in->read_image(TypeDesc::UINT8, &pixels[0]);
    in->close();


    //glDrawPixels(xres, yres, GL_RGBA, GL_UNSIGNED_BYTE, &pixels);
    /*int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    int channels = 4;

    //unsigned char pixmap[4 * w * h];
    unsigned char* pixmap = new unsigned char[channels * w * h];


    // create the oiio file handler for the image
    //ImageOutput* outfile = ImageOutput::create(outfilename);
    std::unique_ptr<ImageOutput> outfile = ImageOutput::create(outfilename);
    if (!outfile) {
        cerr << "Could not create output image for " << outfilename << ", error = " << geterror() << endl;
        return;
    }

    // get the current pixels from the OpenGL framebuffer and store in pixmap
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, pixmap);

    // open a file for writing the image. The file header will indicate an image of
    // width w, height h, and 4 channels per pixel (RGBA). All channels will be of
    // type unsigned char
    ImageSpec spec(w, h, channels, TypeDesc::UINT8);
    if (!outfile->open(outfilename, spec)) {
        cerr << "Could not open " << outfilename << ", error = " << geterror() << endl;
        return;
    }

    // write the image to the file. All channel values in the pixmap are taken to be
    // unsigned chars
    // Gets saved: C:\Users\parke\source\repos\General_OpenGL\General_OpenGL
    if (!outfile->write_image(TypeDesc::UINT8, pixmap)) {
        cerr << "Could not write image to " << outfilename << ", error = " << geterror() << endl;
        return;
    }
    else
        cout << "Square is stored" << endl;

    // close the image file after the image is written
    if (!outfile->close()) {
        cerr << "Could not close " << outfilename << ", error = " << geterror() << endl;
        return;
    }
    */
}


/*
   Display Callback Routine: clear the screen and draw a square
   This routine is called every time the window on the screen needs
   to be redrawn, like if the window is iconized and then reopened
   by the user, and when the window is first created. It is also
   called whenever the program calls glutPostRedisplay()
*/
void drawSquare() {
    // red, yellow, green, cyan, blue, magenta
    float colors[6][3] = { {1, 0, 0}, {1, 1, 0}, {0, 1, 0},
      {0, 1, 1}, {0, 0, 1}, {1, 0, 1} };

    // specify window clear (background) color to be opaque white
    //glClearColor(1, 1, 1, 1);
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);  // clear window to background color

    // set the drawing color
    glColor3f(colors[icolor][0], colors[icolor][1], colors[icolor][2]);

    // draw the square
    glBegin(GL_POLYGON);
    glVertex2i(100, 100);
    glVertex2i(100, 500);
    glVertex2i(500, 500);
    glVertex2i(500, 100);
    glEnd();

    // flush the OpenGL pipeline to the viewport
    glFlush();
}

/*
   Keyboard Callback Routine: 'c' cycle through colors, 'q' or ESC quit,
   'w' write the framebuffer to a file.
   This routine is called every time a key is pressed on the keyboard
*/
void handleKey(unsigned char key, int x, int y) {

    switch (key) {
    case 'c':		// 'c' - cycle to next color
    case 'C':
        icolor = (icolor + 1) % 6;
        glutPostRedisplay();
        break;

    case 'r':       // 'r' - read a file name provided by the user
    case 'R':
        readimage();
        break;

    case 'w':
    case 'W':
        writeimage();
        break;

    case 'q':		// q - quit
    case 'Q':
    case 27:		// esc - quit
        exit(0);

    default:		// not a valid key -- just ignore it
        return;
    }
}

/*
   Reshape Callback Routine: sets up the viewport and drawing coordinates
   This routine is called when the window is created and every time the window
   is resized, by the program or by the user
*/
void handleReshape(int w, int h) {
    // set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // define the drawing coordinate system on the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
}

/*
   Main program to draw the square, change colors, and wait for quit
*/
int main(int argc, char* argv[]) {

    // start up the glut utilities
    glutInit(&argc, argv);

    // create the graphics window, giving width, height, and title text
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("HW 1");

    // set up the callback routines to be called when glutMainLoop() detects
    // an event
    glutDisplayFunc(drawSquare);	  // display callback
    glutKeyboardFunc(handleKey);	  // keyboard callback
    glutReshapeFunc(handleReshape); // window resize callback

    // Routine that loops forever looking for events. It calls the registered
    // callback routine to handle each event that is detected
    glutMainLoop();
    return 0;
}
