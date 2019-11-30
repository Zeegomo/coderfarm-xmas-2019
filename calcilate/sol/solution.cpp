#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int memo [4005][4005];
const int INF = 2e9+7;
int n, k;

void calcilate(int i, int jleft, int jright, int kleft, int kright, auto& cost) {
	int m = (jleft + jright) / 2;
	if(jleft > jright) return;
	ll best = INF;
	int bestk = -1;
	for(int j = kleft; j <= min(m, kright); j++) {
		auto res = memo[j][i-1];
		ll val = res + cost(j, m-1);
		if(best > val) {
			best = val;
			bestk = j;
		}
	}

	memo[m][i] = best;

	calcilate(i, jleft, m - 1, kleft, bestk, cost);
	calcilate(i, m + 1, jright, bestk, kright, cost);
}

void full(auto &cost){
	for(int i = 1; i <= n; i++){
		memo[i][1] = cost(0, i-1);
	}
	for(int i = 1; i <= k; i++){
		memo[0][i] = INF;
	}
	for (int i = 2;  i <= k; i++){
		calcilate(i, 1, n, 1, n, cost);
	}
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin>>n>>k;

	vector<int> v(n);
	for(int &i : v)
		cin>>i;

	for(int i = 1; i < n; i++){
		v[i] += v[i-1];
	}
#ifdef DBG
	for(auto &v : unf) {
		for(auto &x : v) {
			cout<<x<<' ';
		}
		cout<<'\n';
	}
#endif
	memo[0][0] = v[0]*v[0];
	// start and end inclusive
	auto cost = [&v](ll start, ll end) {
		return (v[end] - (start==0 ? 0 : v[start-1]))*(v[end] - (start==0 ? 0 : v[start-1]));
	};

	full(cost);
	cout<<memo[n][k]<<endl;
	
}
