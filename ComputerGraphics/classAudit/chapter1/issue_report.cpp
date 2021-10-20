// Purpose of this txt file:
//     to record issues and ongoing problems in hopes to assist if encountered again.

//--- Problem Statement -------------------------------------------------------//
//  Status: OPEN
//  Date: August 17, 2021
//
//      koffee_linux@DESKTOP-B3NFO4J:/mnt/c/Users/parke/Desktop/Coding/github/Computer-Graphic-Images-Class/Chapter 1/notes/example code/glsquare$ make glsquare
//      g++ -g -c glsquare.cpp
//      g++ -g -o glsquare glsquare.o -L /usr/lib64/ -lglut -lGL -lGLU -lOpenImageIO -lm
//      /usr/bin/ld: cannot find -lOpenImageIO
//      collect2: error: ld returned 1 exit status
//      make: *** [Makefile:17: glsquare] Error 1
//
//  SOLUTION:
//        UPDATE(August 18, 2021):
//              taking out '-lOpenImageIO' allows the program to compile, and doesn't
//              apear to have any issues.
//        UPDATE (August 19, 2021):
//              Couldn't get OpenimageIO linked to gcc without using CMake files, which I 
//              don't even want to touch right now. I got it linked on visual studios but
//              I'm not sure I want to learn how to debug things from there just yet. plus 
//              I want to stay on linux as long as I can. I spent ~12 hours trying to find a  
//              work around. 
//
//              Some of the commands I used: 
//              Makefile: -I/home/koffee/vcpkg/packages/openimageio_x64-linux/include/ (This worked, -L and -l didn't)
//              -DCMAKE_TOOLCHAIN_FILE=/home/koffee/vcpkg/scripts/buildsystems/vcpkg.cmake"
//              Linked OpenImageIO to usr/bin/ bc thats where I thought the compiler was:
//             	sudo ln -s /home/koffee/vcpkg/packages/openimageio_x64-linux/include/OpenImageIO/ /usr/bin/
//
//              ls -l -t /usr/bin/
//	            total 149140
//          	lrwxrwxrwx 1 root   root          70 Aug 19 13:50  OpenImageIO -> /home/koffee/vcpkg/packages/openimageio_x64-linux/include/OpenImageIO/
//              
//              
// Copied from:
//
//----------------------------------------------------------//


//--- Problem Statement -------------------------------------------------------//
//  Status: CLOSED
//  Date: August 16, 2021
//
//     I was having issues running a basic openGL file from the linux
//     app downloaded through windows. It said "freeglut (./firstOpenGlApp): failed to open display 'localhost:0.0'".
//     After downloading ' openimageIO ' and ' OpenGL ', I had to download VxSrv for windows
//     and run it, then add a line in the .bashrc file as seen below.
//
//  SOLUTION:
//     Install Ubuntu through the Windows store
//
//     Enable rendering of GUI applications from Ubuntu/WLSS in Windows using a Windows X-server
//
//     Install VxSrv on Windows
//     On Ubuntu/WLSS open .bashrc and add the following lines to the end, then save file and restart:
//     # tell GUI display to use the Windows X-server listening on localhost:0.0
//     export DISPLAY=localhost:0.0
//     # make rendering happen on the Windows side of things rather than Ubuntu
//     export LIBGL_ALWAYS_INDIRECT=1
//     Install libraries needed for openGL dev:
//     sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
//
// Copied from: https://gist.github.com/campenr/9ca59c70a82044b5f1d8638967a5411d
//  - campenr/openGL_on_WLSS.md on github
//----------------------------------------------------------//
