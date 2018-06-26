#made by NPC

all: People.o Staff.o Student.o Teacher.o Source.o
	g++ People.o Staff.o Student.o Teacher.o Source.o -o Q12.exe
People.o: People.cpp
	g++ -c People.cpp
Staff.o: Staff.cpp
	g++ -c Staff.cpp
Teacher.o: Teacher.cpp
	g++ -c Teacher.cpp
Source.o:	Source.cpp
	g++ -c Source.cpp
clear: 
	/bin/rm *.o
