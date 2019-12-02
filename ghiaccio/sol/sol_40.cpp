#include <bits/stdc++.h>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &g, int start, int end){
	vector<int> dist(g.size(), 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dist[start] = 0;
	q.push({0, start});
	while(!q.empty()){
		auto p = q.top();q.pop();
		if(p.second == end)
			return p.first;
		for(auto e : g[p.second]){
			if(dist[e.first] > p.first+e.second){
				dist[e.first] = p.first+e.second;
				q.push({p.first+e.second, e.first});
			}
		}
	}
	return dist[end];
}


int main(){
	int n, m, k;
	cin>>n>>m>>k;
	vector<vector<pair<int, int>>> g(n);
	for(int i = 0; i < m; i++){
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		a--; b--;
		if(d){
			g[a].push_back({b, c});
			g[b].push_back({a, c});
		}else{
			g[a].push_back({b, c});
			g[b].push_back({a, c});
		}
	}
	int res = dijkstra(g, 0, n-1);
	if(res <= k)
		cout << 0 << " " << res;
	else
		cout << -1;
}
