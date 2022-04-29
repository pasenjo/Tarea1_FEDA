#include<iostream>
using namespace std;

void imprimir_vector(int *vec, int n){
	for(int i=0; i<n; i++){
		cout << vec[i] << " ";
	}
}

int *quicksort(int *vec, int first, int last){
	int i = first;
	int j = last;

	int p = (vec[i]+vec[j])/2;

	// la idea es recorrer la lista hasta que i y j sean iguales, o i>j
	while(i<j){
		// Iterar hasta que vec[i] sea menor que p
		while(vec[i]<p){
			i++;
		}
		while(vec[j]>p){
			j--;
		}

		// Si i<=j entonces los índices se cruzaron !!! ta bn esto¿
		if(i<=j){
			int aux = vec[j];
			vec[j] = vec[i];
			vec[i] = aux;

			i++;
			j--;
		}
	}

	// Si el primer elemento es menor que nuestro nuevo final, entonces iteramos nuevamente
	if(first<j){
		vec = quicksort(vec,first,j);
	}

	// Similar para cuando el último elemento de la lista es mayor que el nuevo inicio
	// 
	if(last>i){
		vec = quicksort(vec,i,last);
	}

	return vec;
}

int main(){
	cout << "Ingrese tamaño de lista a ordenar" << endl;
	int n1;
	cin >> n1;
	cout << "Ingrese números a ordenar" << endl;
	int *vec = new int[n1];
	for(int i=0; i<n1; i++){
		cin >> vec[i];
	}
	vec = quicksort(vec,0,n1-1);
	imprimir_vector(vec,n1);
}


