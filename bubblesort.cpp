#include<iostream>
using namespace std;

void imprimir_vector(int *vec, int n){
	for(int i=0; i<n; i++){
		cout << vec[i] << " ";
	}
}


// Creamos algotiymo asociado al bubblesort
int *orden_mio(){
	int n1;
	cout << "ingrese cantidad de elementos a ordenar: ";
	cin >> n1;
	int *vec = new int[n1];

	cout << "ingrese cada componente del arreglo que desee ordenar: " << endl;
	for(int i=0; i<n1; i++){
		cin >> vec[i];
	}

	//Creamos variable auxiliar en caso de necesitarse, para guardar valores que
	//podrían sernos útiles

	int aux;

	//Recorremos la lista, y vamos comparando elemento a elemento.
	// Si encontramos un valor menor al inicial, lo cambiamos de posición
	// y luego volvemos al inicio, y revisamos la lista nuevamente.
	for(int i=1; i<n1;i++){
		for(int j=0;j<n1-1;j++){
			if(vec[j]>vec[j+1]){
				aux=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=aux;
			}	
		}
			
	}

	imprimir_vector(vec,size(vec));
	return vec;
}

int main(){
	int *v= orden_mio();
}