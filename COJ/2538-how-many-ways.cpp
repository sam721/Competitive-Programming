#include <bits/stdc++.h>
using namespace std;
int n, A[1010];
const int M = (int)(1e9);
bool mark[3][1010];
int memo[3][1010];
int dp(int pos, int sum){
	if(pos == n) return sum == 0;
	int& ans = memo[sum][pos];
	if(mark[sum][pos]) return ans;
	mark[sum][pos] = true;
	int a1 = dp(pos + 1, sum);
	int a2 = dp(pos + 1, (sum + A[pos])%3);
	return ans = (a1 + a2)%M;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &A[i]); A[i] %= 3;
	}
	printf("%d\n", (dp(0,0)-1+M)%M);
	return 0;
}