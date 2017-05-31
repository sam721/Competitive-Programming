#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define pb push_back
#define INF 10000000000000000LL
#define LL long long
using namespace std;
class edge{	
	public:
	int from, to; LL weight;
	edge(){}
	edge(int a, int b, LL c){
		from = a; to = b; weight = c;
	}
	bool operator<(const edge& other) const{
		return weight<other.weight;
	}
};
edge edges[50010];
int p[2010];
int n, m; LL c;
int find(int x){
	if(x==p[x]) return x;
	return p[x] = find(p[x]);
}
void join(int x, int y){
	int xroot = find(x), yroot = find(y);
	p[xroot] = yroot;
}
LL kruskal(bool mode){
	LL cost = mode ? (LL)n*c : 0;
	for(int i=1; i<=n; i++) p[i] = i;
	int E = 0;
	for(int i=0; i<m; i++){
		int f = edges[i].from, t = edges[i].to; LL w = edges[i].weight;
		if(find(f)==find(t)) continue;
		if(mode){
			if(cost - c + w > cost) break;
			cost = cost - c + w;
		}else{
			E++;
			cost += w;
		}
		join(f,t);
	}
	if(!mode) return (E==n-1) ? cost : INF;
	int P = find(1);
	for(int i=2; i<=n; i++){
		if(find(i)!=P) return cost;
	}
	return cost-c;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %lld", &n, &m, &c);
		for(int i=0; i<m; i++){
			scanf("%d %d %lld", &edges[i].from, &edges[i].to, &edges[i].weight);
		}
		sort(edges, edges + m);
		printf("%lld\n", min(kruskal(false), kruskal(true)));
	}
	return 0;
}