#include<iostream>
#include <fstream>
using namespace std;


void imprimir_matriz(long long **mat, int n, int m){
	
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	
}

long long **trasp(long long **mat , int n , int m){
	long long **matT = new long long *[m];
	for(int j=0 ; j<m ; j++){
		matT[j]= new long long[n];
	}

	for(int j=0 ; j<m ; j++){
		for(int i =0 ; i<n ;i++){
			matT[j][i] = mat[i][j];
		}
	}
	return matT;
}


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




long long **crear_matriz_rectangular(int n, int m){
	// reserva la memoria
	long long **mat = new long long *[n]; //cantidad de fila n
	for(int i=0 ; i<n ; i++ ){
		//cada fila se rellena con una columna m
		mat[i]= new long long [m];
	}

	// Algoritmo para crear matrices aleatorias
	srand(time(NULL));
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			mat[i][j]=rand()%100000;
		}
	}
	return mat;
}


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


// Creamos algoritmo para multiplicar matrices de manera tradicional: filas por columnas
long long **mult_matriz(long long **mat1, long long **mat2, int n1, int m1, int n2, int m2){

	long long **A = new long long*[1];
	A[1]= new long long[1];


	if(m1==n2){
		long long **mat1=crear_matriz_rectangular(n1,m1);
		long long **mat2=crear_matriz_rectangular(n2,m2);

	    long long **res = new long long*[n1];

	    for(int i=0; i<n1; i++){
	    	res[i] = new long long[m2];
	    }

	    for(int i=0; i<n1; i++){
	    	for(int j=0; j<m2; j++){
	    		res[i][j]=0;
	    		for(int l=0; l<m1; l++){
	    			res[i][j]= res[i][j]+mat1[i][l]*mat2[l][j];
	    		}

	    	}
	    }
	    return res;
	}

	else{
		cout << "No es posible la multiplicación" << endl;
	}


	return A;

}

long long **mult_matriz_opt(long long **mat1, long long **mat2, int n1, int m1, int n2, int m2){

		if(m1==n2){

		    long long **res = new long long*[n1];

		    for(int i=0; i<n1; i++){
		    	res[i] = new long long[m2];
		    }

		    for(int i=0; i<n1; i++){
		    	for(int j=0; j<m2; j++){
		    		res[i][j]=0;
		    		for(int l=0; l<m1; l++){
		    			res[i][j]= res[i][j]+mat1[i][l]*mat2[j][l];
		    		}

		    	}
		    }
		    return res;
		}

		else{
			cout << "No es posible la multiplicación" << endl;
			return new long long*[0];
		}
	}



long long **Strassen(long long **mat1, long long **mat2, long long n){
	if(n==2){
		long long **res = new long long*[2];
		for(int i=0; i<n; i++){
			res[i] = new long long[n];
		}
		res[0][0]=mat1[0][0]*mat2[0][0] + mat1[0][1]*mat2[1][0];
		res[0][1]=mat1[0][0]*mat2[0][1] + mat1[0][1]*mat2[1][1];
		res[1][0]=mat1[1][0]*mat2[0][0] + mat1[1][1]*mat2[1][0];
		res[1][1]=mat1[1][0]*mat2[0][1] + mat1[1][1]*mat2[1][1];
		return res;
	}

	else{
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

	long long **res = new long long*[n];
	for(int i=0; i<n;i++){
		res[i] = new long long[n];
	}


	for(int i=0; i<n/2; i++){
		for(int j=0; j<n/2; j++){
			res[i][j] = dif_matriz(suma_matriz(P5,suma_matriz(P4,P6,n/2),n/2),P2,n/2)[i][j];
			res[i][j+n/2] = suma_matriz(P1,P2,n/2)[i][j];
			res[i+n/2][j] = suma_matriz(P3,P4,n/2)[i][j];
			res[i+n/2][j+n/2] = dif_matriz(dif_matriz(suma_matriz(P1,P5,n/2),P3,n/2),P7,n/2)[i][j];
		}
	}
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

	int n1,m1,n2,m2,n;
	cout << "Ingrese filas primera matriz: ";
	cin >> n1;
	cout << "Ingrese columnas primera matriz: ";
	cin >> m1;
	cout << "Ingrese filas segunda matriz: ";
	cin >> n2;
	cout << "Ingrese columnas segunda matriz: ";
	cin >> m2;

	long long **mat1 = crear_matriz_rectangular(n1,m1);
	long long **mat2 = crear_matriz_rectangular(n2,m2);

	long long **res = new long long*[n1];
	for(int i=0; i<n1;i++){
		res[i] = new long long[m2];
	}


	clock_t start_time2;
    clock_t final_time2;
    double total_time2;
    start_time2 = clock();

    res = mult_matriz(mat1, mat2, n1, m1, n2, m2);

	final_time2 = clock();
    total_time2 = ((double)(final_time2 - start_time2)) / CLOCKS_PER_SEC;



	

    cout << "matriz usando algoritmo tradicional de multiplicación" << endl;
	imprimir_matriz(res,n1,m2);
	cout << endl;
	cout << "Tiempo de ejecución alg trad de mult: " << total_time2 << " segundos" << endl;

	long long**mat2T = new long long*[m2];
	for(int i=0; i<m2; i++){
		mat2T[i] = new long long[n2];
	}
	mat2T=trasp(mat2,n2,m2);

	clock_t start_time3;
    clock_t final_time3;
    double total_time3;
    start_time3 = clock();

    res = mult_matriz_opt(mat1, mat2T, n1, m1, n2, m2);

	final_time3 = clock();
    total_time3 = ((double)(final_time3 - start_time3)) / CLOCKS_PER_SEC;

    cout << "matriz usando algoritmo optimizado de multiplicación" << endl;
	imprimir_matriz(res,n1,m2);
	cout << endl;

	cout << "Tiempo de ejecución alg opt de mult: " << total_time3 << " segundos" << endl;




	//STRASSEN
	clock_t start_time;
    clock_t final_time;
    double total_time;
    start_time = clock();

    res = Strassen(mat1,mat2,n1);


	final_time = clock();
    total_time = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;

    cout << "matriz usando algoritmo Strassen" << endl;
	imprimir_matriz(res,n1,m2);
	cout << endl;

	cout << "Tiempo de ejecución Strassen: " << total_time << " segundos" << endl;
	



	std::ofstream archivo("casosprueba.txt");


	archivo << "matriz 1:\n";
    for(int i=0 ; i<n1; i++){
    	for(int j=0; j<m1; j++){
    		archivo << mat1[i][j] << " ";
    	}
    	cout << endl;
    	archivo << "\n";
    }

    archivo << "matriz 2:\n";
    for(int i=0 ; i<n2; i++){
    	for(int j=0; j<m2; j++){
    		archivo << mat2[i][j] << " ";
    	}
    	cout << endl;
    	archivo << "\n";
    }

}











