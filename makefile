pexe : FluentCasToMesh.o
	g++ -o pexe FluentCasToMesh.o

FluentCasToMesh.o : FluentCasToMesh.cpp
	g++ -c -O2 FluentCasToMesh.cpp

.PHONY : clean
clean :
	del pexe.exe FluentCasToMesh.o