#include <bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
int A[10];
int P[10], B[10], n;
bool used[10];
bool f(){
	memset(used, false, sizeof(used));
	for(int i = 0; i < n; i++) B[i] = P[i];
	for(int i = 0; i < n; i++){
		if(A[i] == 0 && used[B[0]]) return false;
		if(A[i] == 0) return true;
		while(used[B[A[i]]]){
			B[A[i]] = (B[A[i]]+1)%n;
		}
		used[B[A[i]]] = true;
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			A[i] = i;
			scanf("%d", &P[i]);
		}
		int ans = 0;
		do{
			ans += f();
		}while(next_permutation(A, A + n));
		printf("%d\n", ans);
	}
	return 0;
}