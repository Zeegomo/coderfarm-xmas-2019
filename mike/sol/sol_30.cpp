#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin>>n;
	vector<int> sol(1e6+5);

	for(int i = 0; i <n; i++){
		int a;
		cin>>a;
		sol[a]++;
	}
	int q; cin>>q;
	for(int i = 1; i < 1e6+5; i++){
		sol[i] += sol[i-1];
	}
	int e = 0;
	while(q--) {
		int a, b, c;
		cin>>a>>b>>c;
		e = e ^ sol[c];
		cout<<e<<"\n";
	}
}
