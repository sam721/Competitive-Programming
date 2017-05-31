#include <bits/stdc++.h>
using namespace std;
int n;
double p, q;
double Q[110][110];
double L[110][110], U[110][110];
int P[110];
void lu(){
	for(int i = 0; i < n; i++) P[i] = i;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			U[i][j] = A[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		double piv = U[i][i];
		for(int j = i + 1; j < n; j++){
			double mji = U[j][i]/piv;
			L[j][i] = mji;
			for(int k = 0; k < n; k++){
				U[j][k] = U[j][k] - mji*U[i][k];
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%.2lf ", L[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%.2lf ", U[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %lf %lf", &n, &p, &q);
		p /= 100.0; q /= 100.0;
		for(int i = 0; i < n - 1; i++){
			if(i + 1 < n) Q[i][i+1] = p;
			if(i - 1 >= 0) Q[i][i-1] = q;
			Q[i][i] = 1.0 - p - q;
		}
		Q[n-1][n-1] = 1.0 - p - q;
		lu();
	}	
}