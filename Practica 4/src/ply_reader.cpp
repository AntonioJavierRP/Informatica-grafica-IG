#include "ply_reader.h"

using namespace std;

PlyReader::PlyReader(char *file){
	vector <float> coordenadas;
	vector<int> indices;

	_file_ply archivo;
	archivo.open(file);
	archivo.read(coordenadas, indices);

	Vertices.resize(coordenadas.size()/3);
	Triangles.resize(indices.size()/3);

	for(int i = 0; i < Vertices.size() ; i++){
		Vertices[i].x = coordenadas[i*3];
		Vertices[i].y = coordenadas[i*3+1];
		Vertices[i].z = coordenadas[i*3+2];
	}

	for(int i = 0; i < Triangles.size() ; i++){
		Triangles[i].x = indices[i*3];
		Triangles[i].y = indices[i*3+1];
		Triangles[i].z = indices[i*3+2];
	}
}
