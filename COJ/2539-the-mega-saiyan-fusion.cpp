#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int A[510], S[510], n;
bool mark[510][510];
int memo[510][510];
int sum(int l, int r){
	return S[r] - S[l-1];
}
int dp(int l, int r){
	if(l == r) return 0;
	int& ans = memo[l][r];
	if(mark[l][r]) return ans;
	mark[l][r] = true;
	ans = INF;
	for(int i = l + 1; i <= r; i++){
		ans = min(ans, dp(l, i-1) + dp(i, r) + max(sum(l, i-1), sum(i, r)));
	}
	return ans;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= n; i++) S[i] = S[i-1] + A[i];
	printf("%d\n", dp(1, n));
	return 0;
}