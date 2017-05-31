#include <bits/stdc++.h>
using namespace std;
int n;
long double p, q;
long double Q[110][110];
long double L[110][110], U[110][110];
long double I[110][110];
long double V[110], Y[110];
int P[110];
void lu(){
	for(int i = 0; i < n; i++) P[i] = i;
	for(int i = 0; i < n; i++){
		L[i][i] = 1.0;
		for(int j = 0; j < n; j++){
			U[i][j] = Q[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		long double piv = U[i][i];
		for(int j = i + 1; j < n; j++){
			long double mji = U[j][i]/piv;
			L[j][i] = mji;
			for(int k = 0; k < n; k++){
				U[j][k] = U[j][k] - mji*U[i][k];
			}
		}
	}
}
long double S[110][110];
void solve(int c){
	for(int i = 0; i < n; i++){
		Y[i] = V[i];
		for(int j = 0; j < i; j++){
			Y[i] = Y[i] - L[i][j]*Y[j];
		}
	}
	for(int i = n - 1; i >= 0; i--){
		I[i][c] = Y[i];
		for(int j = i + 1; j < n; j++){
			I[i][c] = I[i][c] - U[i][j]*I[j][c];
		}
		I[i][c] /= U[i][i];
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %Lf %Lf", &n, &p, &q);
		n--;
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) Q[i][i] = 0.0;
		p /= 100.0; q /= 100.0;
		for(int i = 0; i < n; i++){
			if(i + 1 < n) Q[i][i+1] = p;
			if(i - 1 >= 0) Q[i][i-1] = q;
			Q[i][i] = 1.0 - p - q;
		}
		Q[0][0] += q;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) Q[i][j] = 1.0 - Q[i][j];
				else Q[i][j] = -Q[i][j];
			}
		}
		lu();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++) V[j] = 0.0;
			V[i] = 1.0;
			solve(i);
		}
		long double ans = 0.0;
		for(int i = 0; i < n; i++) ans += I[0][i];
		printf("%.10Lf\n", ans);
	}	
	return 0;
}