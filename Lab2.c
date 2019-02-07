#include <stdio.h>
#include "CBLAS/include/cblas.h"
#include <stdlib.h>



void init_matrix(int n, double* A){

	int i, j;
	for(i = 0; i<n; i++){
		
		for(j=0; j<n; j++){

			*(A + i * n+j) = rand()/( RAND_MAX * 1.0);
		}

	}

}




void unoptimized_dgemm(int n, double* A, double* B , double* C ){

	int i,j;
	int k;
	for( i =0; i < n; ++i){

		
		for( j=0; j<n; ++j){

			double cij = C[i+j*n]; 
			for( k=0; k<n; k++){

				cij+= A[i+k*n]* B[k+j*n]; 
			}

			C[i+j*n] = cij;
		}

	}

}

void compare_matrix(int n, double* A1, double* A2){

	
	int i, j;
	double d1, d2;
	
	for(i =0; i <n; i++){
	

		for(j=0; j<n; j++){
			d1 = *(A1 + i*n + j);
			d2 = *(A2 + i*n + j);

			if(fabs(d2-d1)/(d2)> 1e-6){
				printf("ERROR: %f(my)<>%f(dgemm)\n", d1,d2);
				exit(1);
			}
		}

	}

	printf("Correct result! :-) \n");

}

int main()
{
	   
  double mat1[100];
  double mat2[100];
  double mat3[100];
  double *(admat1) = &mat1;
  double * admat2 = &mat2;
  double * admat3 = &mat3;
  
  init_matrix(5, admat1);
  init_matrix(5, admat2);
  init_matrix(5, admat3);

  unoptimized_dgemm(10, admat1,admat2,admat3);
  compare_matrix(10, admat1,admat2); 


	   
}
