#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<vector<ll>> memo(4005, vector<ll>(4005, -1));
vector<int> cost(4005);

int calc_cost(int start, int end){
	if(start > 0)
		return cost[end]-cost[start-1];
	return cost[end];
}

ll dp(int i, int k){
	if(i == 1)
		return calc_cost(0, 0)*calc_cost(0, 0);
	if(k == 1)
		return calc_cost(0, i-1)*calc_cost(0, i-1);
	if(memo[k][i] != -1)
		return memo[k][i];
	ll best = 1e18;
	for(int j = 1; j < i; j++){
		best = min(best, dp(j, k-1)+calc_cost(j, i-1)*calc_cost(j, i-1));
	}
	return memo[k][i] = best;
}

int main(){
	int n, k;
	cin>>n>>k;
	for(int &i : cost)
		cin>>i;
	for(int i = 1; i < n; i++){
		//cost[i] = v[i];
		cost[i] += cost[i-1];
	}
	cout<<dp(n, k);
}