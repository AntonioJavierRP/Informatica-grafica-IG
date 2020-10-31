# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= bin/practica1

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuración
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I.
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut

# definicion del compilador
#
CC = g++

# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : obj/practica1.o obj/objects3D.o
	$(CC) -o $@ $(CXXFLAGS) obj/practica1.o obj/objects3D.o $(LDFLAGS)

obj/practica1.o: src/practica1.cc include/vertex.h include/objects3D.h
	g++ -o $@ $(CXXFLAGS) -c src/practica1.cc -Iinclude

obj/objects3D.o: src/objects3D.cpp include/objects3D.h
	g++ -o $@ $(CXXFLAGS) -c src/objects3D.cpp -Iinclude


#
#
clean:
	rm -f obj/*.o
	rm -f $(TARGETS)

#
#
redo:
	touch src/*.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f obj/*.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *

