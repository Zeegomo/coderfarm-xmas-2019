#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;

using ll = long long;

const int MN = 100000;
const int MINW = 0;
const int MAXW = 100000;

struct Edge{
	int v;
	int w;
	bool r; //copper
};

int n,m,k,s,t;
vector<Edge> g[MN];
ll vis[MN];

bool feas(int m){
	for(int i=0; i<=n; ++i)vis[i]=(ll)MAXW*(ll)MN;
	queue<pair<int,int> > q;
	q.push({0,s});
	vis[s]=0;
	while(!q.empty()){
		int p=q.front().second;
		int d=q.front().first;
		q.pop();
		if(d>vis[p])continue;
		if(p==t&&d<=k)return 1;
		if(d>=k)continue;
		for(auto i:g[p]){
			if( (i.w<=m||(!i.r)) && vis[i.v]>d+i.w ){
				vis[i.v]=d+i.w;
				q.push({d+i.w,i.v});
			}
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;//>>s>>t;
	s=1;t=n;
	int mi=0,ma=MINW;
	for(int i=0; i<m; ++i){
		int u,v,w;
		bool r;
		cin>>u>>v>>w>>r;
		mi=min(mi,w);
		ma=max(ma,w);
		g[u].push_back({v,w,r});
		g[v].push_back({u,w,r});
	}
	int lb=mi-1,ub=ma+1,m;
	while(lb<ub-1){
		m=(lb+ub)/2;
		if(feas(m))ub=m;
		else lb=m;
	}
	if(ub==ma+1)
		cout<<-1<<endl;
	else
		cout<<ub<<endl;
	return 0;
}
