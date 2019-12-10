#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin>>n;
	vector<int> v(n);
	for(int &i : v)
		cin>>i;
	vector<vector<int>> vv;
	vv.push_back(v);
	int q; cin>>q;
	int e = 0;
	while(q--) {
		int a;
		cin>>a;
		if(a == 1) {
			int a, b, c;
			cin>>a>>b>>c;
			auto o = vv[a-1];
			o[b-1] = c;
			sort(o.begin(), o.end());
			vv.push_back(o);
		} else {
			int a,b; cin>>a>>b;
			auto ind = upper_bound(vv[a-1].begin(), vv[a-1].end(), b)-vv[a-1].begin();
			e = ind;
			cout<<e<<'\n';
		}
	}
}
