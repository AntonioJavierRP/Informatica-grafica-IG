# MAKEFILE - PR�CTICA 2
#
# Antonio Javier Rodr�guez P�rez
#
TARGETS= bin/practica3

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I.
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut


# Orden por defecto

default : $(TARGETS)


# Programa principal

$(TARGETS) : obj/practica3.o lib/libFiguras.a
	g++ -o $@ $(CXXFLAGS) obj/practica3.o -lFiguras $(LDFLAGS) -Llib

obj/practica3.o: src/practica3.cc 
	g++ -o $@ $(CXXFLAGS) -c src/practica3.cc -Iinclude


# Objeto3D

obj/objeto3D.o: src/objeto3D.cpp include/objeto3D.h
	g++ -o $@ $(CXXFLAGS) -c src/objeto3D.cpp -Iinclude

# O3D

obj/O3D.o: src/O3D.cpp include/O3D.h
	g++ -o $@ $(CXXFLAGS) -c src/O3D.cpp -Iinclude

# Cubo

obj/cubo.o: src/cubo.cpp include/cubo.h
	g++ -o $@ $(CXXFLAGS) -c src/cubo.cpp -Iinclude

# Tetraedro

obj/tetraedro.o: src/tetraedro.cpp include/tetraedro.h
	g++ -o $@ $(CXXFLAGS) -c src/tetraedro.cpp -Iinclude

# PoligonoR

obj/poligonoR.o: src/poligonoR.cpp include/poligonoR.h
	g++ -o $@ $(CXXFLAGS) -c src/poligonoR.cpp -Iinclude

# PlyReader

obj/file_ply_stl.o: src/file_ply_stl.cc include/file_ply_stl.h
	g++ -o $@ $(CXXFLAGS) -c src/file_ply_stl.cc -Iinclude

obj/ply_reader.o: src/ply_reader.cpp include/ply_reader.h
	g++ -o $@ $(CXXFLAGS) -c src/ply_reader.cpp -Iinclude

# Modelado revolucion

obj/revolucion.o: src/revolucion.cpp include/revolucion.h
	g++ -o $@ $(CXXFLAGS) -c src/revolucion.cpp -Iinclude



# Cilindro
obj/cilindro.o: src/cilindro.cpp include/cilindro.h
	g++ -o $@ $(CXXFLAGS) -c src/cilindro.cpp -Iinclude

# Vaso
obj/vaso.o: src/vaso.cpp include/vaso.h
	g++ -o $@ $(CXXFLAGS) -c src/vaso.cpp -Iinclude

# Vaso Invertido
obj/vaso_inv.o: src/vaso_inv.cpp include/vaso_inv.h
	g++ -o $@ $(CXXFLAGS) -c src/vaso_inv.cpp -Iinclude	

# Cono
obj/cono.o: src/cono.cpp include/cono.h
	g++ -o $@ $(CXXFLAGS) -c src/cono.cpp -Iinclude		

# Tubo
obj/tubo.o: src/tubo.cpp include/tubo.h
	g++ -o $@ $(CXXFLAGS) -c src/tubo.cpp -Iinclude		

# Piramide
obj/piramide.o: src/piramide.cpp include/piramide.h
	g++ -o $@ $(CXXFLAGS) -c src/piramide.cpp -Iinclude	

# Esfera
obj/esfera.o: src/esfera.cpp include/esfera.h
	g++ -o $@ $(CXXFLAGS) -c src/esfera.cpp -Iinclude	

# micro

obj/micro.o: src/micro.cpp include/micro.h include/cubo.h
	g++ -o $@ $(CXXFLAGS) -c src/micro.cpp -Iinclude	

# Parte de arriba

obj/partearriba.o: src/partearriba.cpp include/partearriba.h
	g++ -o $@ $(CXXFLAGS) -c src/partearriba.cpp -Iinclude	

# bloque

obj/bloque.o: src/bloque.cpp include/bloque.h
	g++ -o $@ $(CXXFLAGS) -c src/bloque.cpp -Iinclude	

# Parte media

obj/partemedia.o: src/partemedia.cpp include/partemedia.h
	g++ -o $@ $(CXXFLAGS) -c src/partemedia.cpp -Iinclude	


# Cuerpo

obj/cuerpo.o: src/cuerpo.cpp include/cuerpo.h
	g++ -o $@ $(CXXFLAGS) -c src/cuerpo.cpp -Iinclude	

# Base

obj/base.o: src/base.cpp include/base.h
	g++ -o $@ $(CXXFLAGS) -c src/base.cpp -Iinclude	

# Regulador de Watt

obj/regulador.o: src/regulador.cpp include/regulador.h
	g++ -o $@ $(CXXFLAGS) -c src/regulador.cpp -Iinclude	


# LibFiguras

lib/libFiguras.a: obj/objeto3D.o obj/O3D.o obj/cubo.o obj/tetraedro.o obj/poligonoR.o obj/ply_reader.o obj/file_ply_stl.o obj/revolucion.o obj/piramide.o obj/cilindro.o obj/vaso.o obj/vaso_inv.o obj/cono.o obj/tubo.o obj/esfera.o obj/micro.o obj/partearriba.o obj/bloque.o obj/partemedia.o obj/cuerpo.o obj/base.o obj/regulador.o
	ar rvs lib/libFiguras.a obj/objeto3D.o obj/O3D.o obj/cubo.o obj/tetraedro.o obj/poligonoR.o obj/ply_reader.o obj/file_ply_stl.o obj/revolucion.o  obj/cilindro.o obj/vaso.o obj/vaso_inv.o obj/cono.o obj/tubo.o obj/piramide.o obj/esfera.o obj/micro.o obj/partearriba.o obj/bloque.o obj/partemedia.o obj/cuerpo.o obj/base.o obj/regulador.o



#
#
clean:
	rm -f obj/*.o lib/*
	rm -f $(TARGETS)

#
#
redo:
	touch src/*.cc
	make
