#include <bits/stdc++.h>
#define onbits(x) __builtin_popcount(x)
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
bool mark[2][1<<16 + 1];
int memo[2][1<<16 + 1];
int n, p, k;
int W[17];
int dp(int side, int msk){
	if(side == 1 && msk == 0) return 0;
	int& ans = memo[side][msk];
	if(mark[side][msk]) return ans;
	mark[side][msk] = true;
	ans = INF;
	if(side == 0){
		int mw = -1;
		for(int i = 0; i < n; i++){
			if(!(msk & (1<<i))) continue;
			if(W[i] > k) continue;
			if(mw == -1 || W[mw] < W[i]) mw = i;
			for(int j = i + 1; j < n; j++){
				if(!(msk & (1<<j))) continue;
				if(W[i] + W[j] > k) continue;
				ans = min(ans, dp(1, msk ^ (1<<i) ^ (1<<j)) + max(W[i], W[j]));
			}
		}
		if(onbits(msk) != 1){
			ans = min(ans, dp(1, msk ^ (1<<mw)) + W[mw]);
		}
	}else{
		int mw = - 1;
		for(int i = 0; i < n; i++){
			if(msk & (1<<i)) continue;
			if(W[i] > k) continue;
			if(mw == -1 || W[mw] > W[i]) mw = i;
		}
		ans = min(ans, dp(0, msk ^ (1<<mw)) + W[mw]);
	}
	return ans;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &W[i]);
	scanf("%d %d", &p, &k);
	if(n == 1){
		if(W[0] > k || W[0] > p) printf("-1\n");
		else printf("%d\n", W[0]);
	}else{
		int T = dp(0,(1<<n)-1);
		if(T > p) printf("-1\n");
		else printf("%d\n", T);
	}
	return 0;
}