#include<iostream>
#include<algorithm>
using namespace std;


// Este algoritmo solo llama a la función 'sort' encontrada en la biblioteca
// estándar de C++

int main(){
	cout << "Ingrese cantidad de elementos a ordenar" << endl;
	int n1;
	cin >> n1;
	cout << "Ingrese elementos a ordenar" << endl;
	int *v = new int[n1];
	for(int i=0; i<n1; i++){
		cin >> v[i];
	}

	sort(v,v+n1);

	for(int i=0; i<n1; i++){
		cout << v[i] << " "; 
	}
}