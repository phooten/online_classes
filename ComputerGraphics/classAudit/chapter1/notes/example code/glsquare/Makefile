CC		= g++
C		= cpp

CFLAGS		= -g

ifeq ("$(shell uname)", "Darwin")
  LDFLAGS     = -framework Foundation -framework GLUT -framework OpenGL -lOpenImageIO -lm
else
  ifeq ("$(shell uname)", "Linux")
		LDFLAGS   = -L /usr/lib64/ -lglut -lGL -lGLU -lm
		# LDFLAGS   = -L /c/Users/parke/AppData/Local/Packages/CanonicalGroupLimited.UbuntuonWindows_79rhkp1fndgsc/LocalState/rootfs/home/koffee_linux/vcpkg/installed/x64-linux/share/ -lglut -lGL -lGLU -lOpenImageIO -lm
		# LDFLAGS   = -L /usr/lib64/ -lglut -lGL -lGLU -lOpenImageIO -lm 	# ORIGINAL
  endif
endif

PROJECT		= glsquare

${PROJECT}:	${PROJECT}.o
	${CC} ${CFLAGS} -o ${PROJECT} ${PROJECT}.o ${LDFLAGS}

${PROJECT}.o:	${PROJECT}.${C}
	${CC} ${CFLAGS} -c ${PROJECT}.${C}

clean:
	rm -f core.* *.o *~ ${PROJECT}
