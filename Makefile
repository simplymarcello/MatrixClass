# Created by Marcello Martins on 04/20/2015
# Last modified on 04/21/2015 

# @file makefile #

##########################
##						##
## Makefile				##
## LINUX compilation 	##
##						##
##########################




#FLAGS
C++FLAG = -g -std=c++11 -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.





#Rule for .cpp files
# .SUFFIXES : .cpp.o 

.cpp.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@




#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#FIRST PROGRAM
ALL_OBJ=TestMatrix.o
PROGRAM=TestMatrix
$(PROGRAM): $(ALL_OBJ)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
	make $(PROGRAM)

#Clean obj files

clean:
	(rm -f *.o;)



(:
