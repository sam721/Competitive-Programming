#include <bits/stdc++.h>
using namespace std;
int t, n, p, j, f;
bool rec[510], filler[510];
int F[510], D[510];
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &n, &p, &j, &f);
		for(int i = 1; i <= n; i++){
			rec[i] = filler[i] = false;
		}
		for(int i = 0; i < j; i++){
			int x;
			scanf("%d", &x);
			rec[x] = true;
		}
		for(int i = 0; i < f; i++){
			int x;
			scanf("%d", &x);
			filler[x] = true;
		}
		int failed = 0, del = 0;
		for(int i = 1; i <= n; i++){
			if(!rec[i] && !filler[i] && i > p) F[failed++] = i;
			if(rec[i] && (filler[i] || i <= p)) D[del++] = i;
		}
		printf("%d ", failed);
		for(int i = 0; i < failed; i++) printf("%s%d", (i == 0) ? (""):(" "), F[i]); printf("\n");
		printf("%d ", del);
		for(int i = 0; i < del; i++) printf("%s%d", (i == 0) ? (""):(" "), D[i]); printf("\n");
	}
	return 0;
}