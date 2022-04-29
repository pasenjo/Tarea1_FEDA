	#include <iostream>
	using namespace std;

	void imprimir_matriz(int **mat, int n, int m, bool sd){
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


	void mult_matriz(){
		int n1,m1,n2,m2;
		cout << "Ingrese numero de filas de la matriz 1: ";
		cin >> n1;
		cout << "Ingrese numero de columnas de la matriz 1: ";
		cin >> m1;
		cout << "Ingrese numero de filas de la matriz 2: ";
		cin >> n2;
		cout << "Ingrese numero de columnas de la matriz 2: ";
		cin >> m2;



		if(m1==n2){
			//cout << "No es posible esta multiplicacion";
			cout << "Ingrese valores matriz 1 (por fila)";
			int **mat1 = new int*[n1];


	    	for(int i=0; i<n1; i++){
		    	mat1[i] = new int[m1];
		    }

		    for(int i=0; i<n1; i++){
			    for(int j=0; j<m1; j++){
				    cin >> mat1[i][j];
			    }
		    }

		    cout << "Ingrese valores matriz 2 (por fila)";
			int **mat2 = new int*[m2];


	    	for(int i=0; i<m2; i++){
		    	mat2[i] = new int[n2];
		    }

		    for(int i=0; i<m2; i++){
			    for(int j=0; j<n2; j++){
				    cin >> mat2[i][j];
			    }
		    }


		    int **res = new int*[n1];

		    for(int i=0; i<n1; i++){
		    	res[i] = new int[m2];
		    }

		    for(int i=0; i<n1; i++){
		    	for(int j=0; j<m2; j++){
		    		res[i][j]=0;
		    		for(int l=0; l<m1; l++){
		    			res[i][j]= res[i][j]+mat1[i][l]*mat2[j][l];
		    		}

		    	}
		    }

			bool sd;
			cout << "¿Desea visualizar su matriz? (si quiere visualizarla, ingrese un 1; caso contrario";
			cin >> sd;

			imprimir_matriz(res,n1,m2,sd);

		}

		else{
			cout << "No es posible la multiplicación" << endl;
		}



	}


	int main(){
		mult_matriz();
	}





































