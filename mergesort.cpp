#include<iostream>
using namespace std;

void imprimir_vector(int *vec, int n){
	for(int i=0; i<n; i++){
		cout << vec[i] << " ";
	}
}

int *ing_vector(int n){
	int *vec = new int[n];
	cout << "ingrese elementos a ordenar: " << endl;
	for(i=0;i<n;i++){
		cin >> vec[i];
	}
	return vec;
}

// Creamos algoritmo que mezcla dos listas ordenadas, y nos entrega una lista concatenando
// de manera secuencial los elementos de menor a mayor, comparando entre los inicios de 
// cada lista
int *Mezclar_En_Orden(int *v1, int *v2, int n1, int n2){
	int *vec = new int[n1+n2];
	int j1 = 0;
	int j2 = 0;
	for(int i=0; i<n1+n2;i++){
		if(v1[j1]<v2[j2]){
			vec[i]=v1[j1];
			j1 = j1+1;
		}
		else{
			vec[i]=v2[j2];
			j2 = j2+1;
		}
	}
	return vec;
}


// Aplicamos algoritmo MergeSort
int *mergesort(int *vec, int n){
	// Definimos el caso base de la recursión
	if(n<=1){
		return vec;
	}

	// Dividimos nuestro vector en dos mitades
	int *v1 = new int[n/2];
	int *v2 = new int[n-n/2];
	for(int i=0;i<n/2;i++){
		v1[i]=vec[i];
	}
	for(int i=0; i<n-n/2; i++){
		v2[i]=vec[i+n/2];
	}

	// A cada mitad le aplicamos la recursión
	v1 = mergesort(v1,n/2);
	v2 = mergesort(v2,n-n/2);

	// Creamos un vector resultante de aplicar la mezcla en orden de los vectores 
	// previamente ordenados
	vec = Mezclar_En_Orden(v1,v2,n/2,n-n/2);

	return vec;

}

int main(){
	cout << "ingrese cantidad de datos a ordenar" << endl;
	int n1;
	cin >> n1;
	int *u;
	u=ing_vector(n1);
	u = mergesort(u,n1);
	imprimir_vector(u,n1);

