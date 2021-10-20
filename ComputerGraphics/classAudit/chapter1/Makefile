# this target will compile all the files
CC = g++
C = cpp

CFLAGS = -g

# LDFLAGS   = -L /usr/lib64/ -lglut -lGL -lGLU -lOpenImageIO -lm	#compiler can't find lOpenImageIO (ongoing issue 8/17/2021)
LDFLAGS   = -L /usr/lib64/ -lglut -lGL -lGLU -lm

PROJECT = imgview

${PROJECT}: ${PROJECT}.o
	$(CC) ${CFLAGS} -o ${PROJECT} ${PROJECT}.o ${LDFLAGS}

${PROJECT}.o: ${PROJECT}.${C}
	${CC} ${CFLAGS} -c ${PROJECT}.${C}

clean:
	rm -f core.* *.o *~ ${PROJECT}
