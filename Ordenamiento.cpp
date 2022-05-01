#include<iostream>

#include<algorithm>
using namespace std;

void imprimir_vector(long long *vec, int n){
	for(int i=0; i<n; i++){
		cout << vec[i] << " ";
	}
	cout << endl;
}



long long *crear_lista(int n){
	// reserva la memoria
	long long *vec = new long long [n]; //cantidad de elementos n
	
	// Algoritmo para crear listas aleatorias
	srand(time(NULL));
	for(int i=0 ; i<n ; i++){
			vec[i]=rand()%100000;
		
	}
	return vec;
}



// Algoritmo Bubblesort

long long *orden_mio(long long *vec, int n1){

	int aux;
	for(int i=1; i<n1;i++){
		for(int j=0;j<n1-1;j++){
			if(vec[j]>vec[j+1]){
				aux=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=aux;
			}	
		}
			
	}
	return vec;
}



// Mergesort

long long *Mezclar_En_Orden(long long *v1, long long *v2, int n1, int n2){
	long long *vec = new long long[n1+n2];
	int j1 = 0;
	int j2 = 0;
	for(int i=0; i<n1+n2;i++){
		if (j1<n1 and j2<n2){
			if(v1[j1]<v2[j2]){
				vec[i]=v1[j1];
				j1++;
			}
			else{
				vec[i]=v2[j2];
				j2++;
			}
		}
		else if(j1>=n1){
			vec[i]=v2[i-n1];
		}
		else{
			vec[i]=v1[i-n2];
		}
		
	}
	return vec;
}


long long *mergesort(long long *vec, int n){
	if(n<=1){
		return vec;
	}

	long long *v1 = new long long[n/2];
	long long *v2 = new long long[n-n/2];
	for(int i=0;i<n/2;i++){
		v1[i]=vec[i];
	}
	for(int i=0; i<n-n/2; i++){
		v2[i]=vec[i+n/2];
	}

	v1 = mergesort(v1,n/2);
	v2 = mergesort(v2,n-n/2);

	vec = Mezclar_En_Orden(v1,v2,n/2,n-n/2);

	return vec;

}




// Quicksort


long long *quicksort(long long *vec, int first, int last){
	int i = first;
	int j = last;
	int p = (vec[i]+vec[j])/2;

	while(i<j){
		while(vec[i]<p){
			i++;
		}
		while(vec[j]>p){
			j--;
		}

		if(i<=j){
			int aux = vec[j];
			vec[j] = vec[i];
			vec[i] = aux;

			i++;
			j--;
		}
	}

	if(first<j){
		vec = quicksort(vec,first,j);
	}

	if(last>i){
		vec = quicksort(vec,i,last);
	}

	return vec;
}

int main(){
	int n;
	cout << "Ingrese cantidad de elementos que desea ordenar: ";
	cin >> n;
	cout << endl;
	long long *v = new long long[n];
	v=crear_lista(n);
	//cout << "Lista que se ordenará" << endl;
	//imprimir_vector(v,n);

	//cout << endl;
	long long *res = new long long[n];


	//clock_t start_time1;
    //clock_t final_time1;
    //double total_time1;
   // start_time1 = clock();

	//res=orden_mio(v,n);

	//final_time1 = clock();
    //total_time1 = ((double)(final_time1 - start_time1)) / CLOCKS_PER_SEC;

    //cout << "Lista ordenada usando Bubblesort" << endl;
    
	//imprimir_vector(res,n);
	//cout << endl;
	//cout << "Tiempo de ejecución Bubblesort: " << total_time1 << " segundos" << endl;





	clock_t start_time2;
    clock_t final_time2;
    double total_time2;
    start_time2 = clock();

	res=mergesort(v,n);

	final_time2 = clock();
    total_time2 = ((double)(final_time2 - start_time2)) / CLOCKS_PER_SEC;

    //cout << "Lista ordenada usando Mergesort" << endl;
	//imprimir_vector(res,n);
	cout << endl;

	cout << "Tiempo de ejecución Mergesort: " << total_time2 << " segundos" << endl;	




	clock_t start_time3;
    clock_t final_time3;
    double total_time3;
    start_time3 = clock();

	res=quicksort(v,0,n-1);


	final_time3 = clock();
    total_time3 = ((double)(final_time3 - start_time3)) / CLOCKS_PER_SEC;

    //cout << "Lista ordenada usando Quicksort" << endl;
	//imprimir_vector(res,n);
	cout << endl;

	cout << "Tiempo de ejecución Quicksort: " << total_time3 << " segundos" << endl;




	clock_t start_time4;
    clock_t final_time4;
    double total_time4;
    start_time4 = clock();
	
	sort(v,v+n);


	final_time4 = clock();
    total_time4 = ((double)(final_time4 - start_time4)) / CLOCKS_PER_SEC;


    //cout << "Lista ordenada usando sort" << endl;
	//imprimir_vector(v,n);
	cout << endl;

	cout << "Tiempo de ejecución Sort: " << total_time4 << " segundos" << endl;


}
























