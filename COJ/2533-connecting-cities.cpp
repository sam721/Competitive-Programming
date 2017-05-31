#include <bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
class edge{
public:
	int u, v, w;
	edge(){}
	edge(int a, int b, int c){
		u = a; v = b; w = c;
	}
	bool operator<(const edge& other) const{
		return w < other.w;
	}
};
edge E[100010];
int p[2010];
int find(int x){
	if(x == p[x]) return x;
	return p[x] = find(p[x]);
}
void join(int x, int y){
	p[find(x)] = find(y);
}
int n, m, c;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &m, &c);
		for(int i = 1; i <= n; i++) p[i] = i;
		for(int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			E[i] = edge(u, v, w);
		}
		if(n == 1){
			printf("0\n");
			continue;
		}
		sort(E, E + m);
		LL ans = (LL)n * (LL)c;
		LL mst = 0LL;
		int comps = n;
		for(int i = 0; i < m; i++){
			int u, v, w;
			u = E[i].u; v = E[i].v; w = E[i].w;
			if(find(u) == find(v)) continue;
			join(u, v);
			mst += w;
			comps--;
			ans = min(ans, mst + ((comps == 1) ? (0) : ((LL)c*(LL)comps)));
		}
		printf("%lld\n", ans);
	}
	return 0;
}