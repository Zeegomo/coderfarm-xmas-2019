#include <bits/stdc++.h>
using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &g, int start, int end, int m){
	vector<int> dist(g.size(), 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dist[start] = 0;
	q.push({0, start});
	while(!q.empty()){
		auto p = q.top();q.pop();
		if(p.second == end)
			return p.first;
		for(auto e : g[p.second]){
			if(e.second < 0 && e.second < -m)
				continue;
			if(e.second < 0)
				e.second = -e.second;
			if(dist[e.first] > p.first+e.second){
				dist[e.first] = p.first+e.second;
				q.push({p.first+e.second, e.first});
			}
		}
	}
	return dist[end];
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.sync_with_stdio();
	int n, mm, k;
	cin>>n>>mm>>k;
	vector<vector<pair<int, int>>> g(n);
	for(int i = 0; i < mm; i++){
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		a--; b--;
		if(!d){
			g[a].push_back({b, c});
			g[b].push_back({a, c});
		}else{
			g[a].push_back({b, -c});
			g[b].push_back({a, -c});
		}
	}
	int l, r, m;
	l = 0;
	r = 1e4+1;
	m = -1;
	int best = -1;
	int res = 0;
	while(1){
		if(m == (l+r)/2)
			break;
		m = (l+r)/2;
		int rr = dijkstra(g, 0, n-1, m);
		if(rr <= k){
			best = m;
			res = rr;
			r = m;
		}else{
			l = m;
		}
	}
	if(best > -1)
		cout<<best<<" " << res;
	else
		cout << best;
}
