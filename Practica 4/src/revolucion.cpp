#include "revolucion.h"

Revolucion::Revolucion(){}

Revolucion::Revolucion(vector <_vertex3f> puntos_ply){
	this->Revolucionar(puntos_ply,20);
}

void Revolucion::Revolucionar(vector <_vertex3f> perfil, int nlados){
	_vertex3f auxiliar,down,up;
	nlados--;
	bool tapa_arriba = false, tapa_abajo = false;

	float alpha = 0;

	float alpha_aux = 2*PI/(float)nlados;


	if(perfil[0].x == 0 ){
		tapa_arriba = true;
		up = perfil[0];
		perfil.erase(perfil.begin());		// Elimino el vértice de la tapa de arriba para insertarlo despues ya que no 
	}										// queremos que revolucione los vértices centrales(ya que seria repetirlo)

	if(perfil[perfil.size()-1].x == 0){
		tapa_abajo = true;
		down = perfil[perfil.size()-1];
		perfil.erase(perfil.end());			// Hacemos lo mismo con el vertice de la tapa de abajo.
	}



// Habrá tantos puntos totales como los del perfil multiplicado por el nº de lados que va a tener la figura, y le
// sumamos dos por los dos extra puntos centrales de cada tapa:
	Vertices.resize(nlados*perfil.size());		

	for(int i = 0; i < nlados; i++){				// Empezamos obteniendo los puntos por revolucion.
		for(int j = 0; j < perfil.size();j++){

      		auxiliar.x =  perfil[j].x * cos(alpha);
      		auxiliar.z =  perfil[j].x * sin(alpha);
      		auxiliar.y  = perfil[j].y;
      		Vertices[(perfil.size()*i)+j] = auxiliar;
    	}
		alpha += alpha_aux;
  	}

  	if(tapa_arriba)
  		Vertices.push_back(up);
  	if(tapa_abajo)
  		Vertices.push_back(down);

  


// Ahora tenemos que asignar los triangulos.(Los puntos de los triángulos se pondrán en sentido contrario a las agujas del reloj).


	int punto=0;
	int max = nlados*perfil.size() ;
	for(int i = 0 ; i < nlados ; i++){
		for(int j=0 ; j < perfil.size()-1 ; j++){
			punto = (perfil.size()*i)+j;
			Triangles.push_back( _vertex3i( punto, ( punto+perfil.size()+1 )%max, (punto+perfil.size())%max ) ); 		// Triangulo de arriba.
			Triangles.push_back( _vertex3i( punto, punto+1, ( punto+perfil.size()+1 ) % max) ); 						// Triangulo de abajo.
	 	}
	}


// Triangulos de las tapas:
	if(tapa_abajo)
		for(int i = 0 ; i < nlados ; i++){
	 		Triangles.push_back(_vertex3i( (i+1)*(perfil.size())-1, Vertices.size()-1, ( ((i+1)*(perfil.size())-1)+perfil.size() )% max ));			// Triangulos de la cara de abajo.
		}

	if(tapa_abajo && tapa_arriba)
		for(int i = 0 ; i < nlados ; i++){
	 		Triangles.push_back(_vertex3i( Vertices.size()-2, i*perfil.size(), ( ((i+1)*(perfil.size()) )% max )) );								// Triangulos de la cara de arriba cuando tambien está presente la de abajo.
		}

	if(!tapa_abajo && tapa_arriba)
		for(int i = 0 ; i < nlados ; i++){
	 		Triangles.push_back(_vertex3i( Vertices.size()-1, i*perfil.size(), ( ((i+1)*(perfil.size()) )% max )) );								// Triangulos de la cara de arriba cuando no existe la de abajo.
		}

			
}


void Revolucion::RevolucionarSeccion(vector <_vertex3f> perfil, int nlados, float alfa, float beta){
	_vertex3f auxiliar,down,up;
	bool tapa_arriba = false, tapa_abajo = false;
	nlados--;
	float alpha = (alfa*PI)/180;			// Alfa y beta estan en grados y hay que pasarlas a radianes.
	float beta_a = ((PI*beta)/180)-alpha;	// Pasamos beta a radianes.
	float alpha_aux = beta_a/(float)nlados;		
	


	if(perfil[0].x == 0 ){
		tapa_arriba = true;
		up = perfil[0];
		perfil.erase(perfil.begin());		// Elimino el vértice de la tapa de arriba para insertarlo despues ya que no 
	}										// queremos que revolucione los vértices centrales(ya que seria repetirlo)

	if(perfil[perfil.size()-1].x == 0){
		tapa_abajo = true;
		down = perfil[perfil.size()-1];
		perfil.erase(perfil.end());			// Hacemos lo mismo con el vertice de la tapa de abajo.
	}



// Habrá tantos puntos totales como los del perfil multiplicado por el nº de lados que va a tener la figura, y le
// sumamos dos por los dos extra puntos centrales de cada tapa:
	Vertices.resize(nlados*perfil.size());		

	for(int i = 0; i < nlados; i++){				// Empezamos obteniendo los puntos por revolucion.
		for(int j = 0; j < perfil.size();j++){

      		auxiliar.x =  perfil[j].x * cos(-alpha);
      		auxiliar.z =  perfil[j].x * sin(-alpha);
      		auxiliar.y  = perfil[j].y;
      		Vertices[(perfil.size()*i)+j] = auxiliar;
    	}
		alpha += alpha_aux;
  	}

	for(int i = 0; i < perfil.size(); i++){
		auxiliar.x = perfil[i].x*cos(-alpha);
		auxiliar.z = perfil[i].x*sin(-alpha);
		auxiliar.y  = perfil[i].y;
		Vertices.push_back(auxiliar);
	}

  	if(tapa_arriba)
  		Vertices.push_back(up);
  	if(tapa_abajo)
  		Vertices.push_back(down);

  


// Ahora tenemos que asignar los triangulos.(Los puntos de los triángulos se pondrán en sentido contrario a las agujas del reloj).
	int lados = nlados;
	if(alfa > 0)
		lados--;

	int punto=0;
	for(int i = 0 ; i < nlados ; i++){
		for(int j=0 ; j < perfil.size()-1 ; j++){
			punto = (perfil.size()*i)+j;
			Triangles.push_back( _vertex3i( punto, ( punto+perfil.size()+1 ), (punto+perfil.size()) ) ); 		// Triangulo de arriba.
			Triangles.push_back( _vertex3i( punto, punto+1, ( punto+perfil.size()+1 ) ) ); 						// Triangulo de abajo.
	 	}
	}
	

// Triangulos de las tapas:
	if(tapa_abajo)
		for(int i = 0 ; i < nlados ; i++){
	 		Triangles.push_back(_vertex3i( (i+1)*(perfil.size())-1, Vertices.size()-1, ( ((i+1)*(perfil.size())-1)+perfil.size() ) ));			// Triangulos de la cara de abajo.
		}

	if(tapa_abajo && tapa_arriba)
		for(int i = 0 ; i < nlados ; i++){
	 		Triangles.push_back(_vertex3i( Vertices.size()-2, i*perfil.size(), ( ((i+1)*(perfil.size()) ) )) );								// Triangulos de la cara de arriba cuando tambien está presente la de abajo.
		}

	if(!tapa_abajo && tapa_arriba)
		for(int i = 0 ; i < nlados ; i++){
	 		Triangles.push_back(_vertex3i( Vertices.size()-1, i*perfil.size(), ( ((i+1)*(perfil.size()) ) )) );								// Triangulos de la cara de arriba cuando no existe la de abajo.
		}
}
