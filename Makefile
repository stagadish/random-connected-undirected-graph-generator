########################################
##
## Makefile
## LINUX compilation 
##
##############################################





#FLAGS
C++FLAG = -g -std=c++0x -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.

#Default run ARGS
ARGS = 1000


#Rule for .cpp files
# .SUFFIXES : .cpp.o 

.cpp.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@




#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 



#Programs
ALL_OBJ = TestRandomGraph.o
PROGRAM = TestRandomGraph
$(PROGRAM): $(ALL_OBJ)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
		make $(PROGRAM)

randomGraph: 	
		./$(PROGRAM) ${ARGS}



#Clean obj files

clean:
	(rm -f *.o; rm -f TestRandomGraph)



(:
