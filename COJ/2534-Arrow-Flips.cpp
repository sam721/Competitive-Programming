#include <bits/stdc++.h>
using namespace std;
char S[100010];
int f(int n, int k, char c){
	int li = 0, ans = 1;
	for(int i = 0; i < n; i++){
		if(S[i] == c) k--;
		while(k < 0){
			if(S[li++] == c) k++;
		}	
		ans = max(ans, i - li + 1);
	}
	return ans;
}
int main(){
	int n, k;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %s", &k, S);
		n = strlen(S);
		printf("%d\n", max(f(n, k, '<'), f(n, k, '>')));
	}
	return 0;
}