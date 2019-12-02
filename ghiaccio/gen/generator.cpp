#include <bits/stdc++.h>

using namespace std;

struct random_boy{
 	mt19937 rng;
 	uniform_int_distribution<int> gen;
 	random_boy() : rng(chrono::steady_clock::now().time_since_epoch().count()){}
 	random_boy(int seed) : rng(seed){}

 	int rand32() { return gen(rng);}
  
	// return value in [l, r]
	int rand_in(int l, int r){
		// to avoid breaking things
		if(l > r) swap(l, r);
	return rand32() % (r - l + 1) + l;
	}
};

int main(int argc, char** argv) {
	if(argc != 5) {
		return 1;
	}
	int n, w, seed, m;
	n = stoi(argv[1]);
	m = stoi(argv[2]);
	seed = stoi(argv[3]);
	w = stoi(argv[4]);
  
	random_boy randy(seed);

	if(seed == -1){
  		cout<<"8 9 4"<<endl
      		<<"7 2 5 0"<<endl
      		<<"8 4 3 1"<<endl
      		<<"6 5 2 0"<<endl
      		<<"6 4 10 0"<<endl
      		<<"1 4 1 1"<<endl
      		<<"1 5 3 0"<<endl
      		<<"2 3 4 0"<<endl
      		<<"2 4 6 1"<<endl
      		<<"4 5 4 1"<<endl;
  	} else{
	  	int k = randy.rand_in(0, n*(1e4));
   		cout << n << " " << m << " " << k << endl;
    		for(int i = 2; i <= n; i++){
     			cout << i << " " << randy.rand_in(1, i-1);
      			if(w != -1) {
        			cout << " " << randy.rand_in(1, 1e4) <<" ";
        			if(w == 0) {
          				cout << 0;
        			} else if (w == 2){
          				cout << 1;
        			} else {
          				cout << randy.rand_in(0, 1);
        			}
      			}
      			cout<<" \n";
    		}
    		for (int i = 0; i < m-n +1; i++) {
      			cout << randy.rand_in(1, n) << " "<< randy.rand_in(1, n);
      			if(w != -1) {
        			cout << " " << randy.rand_in(1, 1e4) <<" ";
        			if(w == 0) {
          				cout << 0;
        			} else if (w == 2){
          				cout << 1;
        			} else {
         				 cout << randy.rand_in(0, 1);
        			}
      			}
      			cout<<" \n";
    		}
  	}
}
