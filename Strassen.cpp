#include<iostream>
using namespace std;

long long **crear_matriz_cuadrada(int n){
	// reserva la memoria
	long long **mat = new long long *[n]; //cantidad de fila n
	for(int i=0 ; i<n ; i++ ){
		//cada fila se rellena con una columna m
		mat[i]= new long long [n];
	}

	// Algoritmo para crear matrices aleatorias
	srand(time(NULL));
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			mat[i][j]=rand()%100000;
		}
	}
	return mat;
}



//Creamos algoritmo para imprimir matrices

void imprimir_matriz(long long **mat, long long n, long long m, bool sd){
	if(sd == 1){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
	else{
		cout << " ";
	}
}

// Creamos función para sumar matrices
long long **suma_matriz(long long **M1, long long **M2, long long n){
	long long **suma = new long long*[n];
	for(int i=0; i<n; i++){
		suma[i] = new long long[n];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			suma[i][j] = M1[i][j] + M2[i][j];
		}
	}
	return suma;
}



// Creamos función para restar matrices
long long **dif_matriz(long long **M1, long long **M2, long long n){
	long long **dif = new long long*[n];
	for(int i=0; i<n; i++){
		dif[i] = new long long[n];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			dif[i][j] = M1[i][j] - M2[i][j];
		}
	}
	return dif;
}

// ALGORITMO STRASSEN

long long **Strassen(long long **mat1, long long **mat2, long long n){
	// Nuestro caso base es una matriz de orden 2^1 = 2. Multiplicamos y sumamos los elementos correspondientes.
	if(n==2){
		int **res = new int*[2];
		for(int i=0; i<n; i++){
			res[i] = new int[n];
		}
		res[0][0]=mat1[0][0]*mat2[0][0] + mat1[0][1]*mat2[1][0];
		res[0][1]=mat1[0][0]*mat2[0][1] + mat1[0][1]*mat2[1][1];
		res[1][0]=mat1[1][0]*mat2[0][0] + mat1[1][1]*mat2[1][0];
		res[1][1]=mat1[1][0]*mat2[0][1] + mat1[1][1]*mat2[1][1];
		return res;
	}

	// Si la matriz es más grande, aplicamos el algoritmo recursivo.
	else{
	// Dividimos en cuatro bloques cada matriz, y los definimos de acuerdo a lo visto en clases
	long long **A = new long long*[n/2];
	long long **B = new long long*[n/2];
	long long **C = new long long*[n/2];
	long long **D = new long long*[n/2];
	long long **E = new long long*[n/2];
	long long **F = new long long*[n/2];
	long long **G = new long long*[n/2];
	long long **H = new long long*[n/2];


	for(int i=0; i<n/2; i++){
		A[i] = new long long[n/2];
		B[i] = new long long[n/2];
		C[i] = new long long[n/2];
		D[i] = new long long[n/2];
		E[i] = new long long[n/2];
		F[i] = new long long[n/2];
		G[i] = new long long[n/2];
		H[i] = new long long[n/2];
	}


	// Construimos adecuadamente cada bloque (Dividimos el problema)
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n/2; j++){
			A[i][j] = mat1[i][j];
			C[i][j] = mat1[i+n/2][j];
			B[i][j] = mat1[i][j+n/2];
			D[i][j] = mat1[i+n/2][j+n/2];
			E[i][j] = mat2[i][j];
			G[i][j] = mat2[i+n/2][j];
			F[i][j] = mat2[i][j+n/2];
			H[i][j] = mat2[i+n/2][j+n/2];
		}
	}

	// Definimos nuestros problemas auxiliares como matrices, hechas para conquistar el algoritmo

		long long **P1=new long long*[n/2];
		long long **P2=new long long*[n/2];
		long long **P3=new long long*[n/2];
		long long **P4=new long long*[n/2];
		long long **P5=new long long*[n/2];
		long long **P6=new long long*[n/2];
		long long **P7=new long long*[n/2];

	for(int i=0; i<n/2; i++){
		P1[i] = new long long[n/2];
		P2[i] = new long long[n/2];
		P3[i] = new long long[n/2];
		P4[i] = new long long[n/2];
		P5[i] = new long long[n/2];
		P6[i] = new long long[n/2];
		P7[i] = new long long[n/2];
	}

	// Aplicamos la recursividad al algoritmo
	P1 = Strassen(A,dif_matriz(F,H,n/2),n/2);
	P2 = Strassen(suma_matriz(A,B,n/2),H,n/2);
	P3 = Strassen(suma_matriz(C,D,n/2),E,n/2);
	P4 = Strassen(D,dif_matriz(G,E,n/2),n/2);
	P5 = Strassen(suma_matriz(A,D,n/2),suma_matriz(E,H,n/2),n/2);
	P6 = Strassen(dif_matriz(B,D,n/2),suma_matriz(G,H,n/2),n/2);
	P7 = Strassen(dif_matriz(A,C,n/2),suma_matriz(E,F,n/2),n/2);

	// Como ya no necesitamos nuestros bloques iniciales, liberamos el espacio de memoria asociado
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;
	delete[] F;
	delete[] G;
	delete[] H;

	// Creamos la matriz resultante
	long long **res = new long long*[n];
	for(int i=0; i<n;i++){
		res[i] = new long long[n];
	}


	//Rellenamos la matriz resultante, con las matrices armadas por el algoritmo
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n/2; j++){
			res[i][j] = dif_matriz(suma_matriz(P5,suma_matriz(P4,P6,n/2),n/2),P2,n/2)[i][j];
			res[i][j+n/2] = suma_matriz(P1,P2,n/2)[i][j];
			res[i+n/2][j] = suma_matriz(P3,P4,n/2)[i][j];
			res[i+n/2][j+n/2] = dif_matriz(dif_matriz(suma_matriz(P1,P5,n/2),P3,n/2),P7,n/2)[i][j];
		}
	}
	// Ya almacenamos lo que nos interesaba en res, asi que podemos liberar la memoria de los subproblemas
	delete[] P1;
	delete[] P2;
	delete[] P3;
	delete[] P4;
	delete[] P5;
	delete[] P6;
	delete[] P7;

	return res;
	}
}

int main(){
	long long n;
	cout << "Ingrese orden de las matrices: "<< endl;
	cin >> n;
	long long **mat1 = new long long*[n];
	long long **mat2 = new long long*[n];
	for(int i=0;i<n;i++){
		mat1[i] = new long long[n];
		mat2[i] = new long long[n];
	
	mat1=crear_matriz_cuadrada(n);


	mat2=crear_matriz_cuadrada(n);

	clock_t start_time;
    clock_t final_time;
    double total_time;
    start_time = clock();

	mat1=Strassen(mat1,mat2,n);

	final_time = clock();
    total_time = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;

	imprimir_matriz(mat1,n,n,1);
	cout << "Tiempo de ejecución multiplicacion por strassen: " << total_time << " segundos";

}


