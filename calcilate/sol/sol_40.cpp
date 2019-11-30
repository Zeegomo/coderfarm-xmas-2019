#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<vector<ll>> memo(4005, vector<ll>(805, -1));
vector<int> cost(4005);

int calc_cost(int a, int b){
	int sol = 0;
	for(int i = a; i <= b; i++)
		sol += cost[i];
	return sol;
}

ll dp(int i, int k){
	if(i == 1)
		return calc_cost(0, 0)*calc_cost(0, 0);
	if(k == 1)
		return calc_cost(0, i-1)*calc_cost(0, i-1);
	if(memo[i][k] != -1)
		return memo[i][k];
	ll best = 1e18;
	for(int j = 1; j < i; j++){
		best = min(best, dp(j, k-1)+calc_cost(j, i-1)*calc_cost(j, i-1));
	}
	return memo[i][k] = best;
}

int main(){
	int n, k;
	cin>>n>>k;
	for(int &i : cost)
		cin>>i;
	/*for(int i = 1; i < n; i++){
		cost[i] = v[i];
		cost[i] += cost[i-1];
	}*/
	cout<<dp(n, k);
}