#include <bits/stdc++.h>
using namespace std;

struct random_boy{
  mt19937 rng;
  uniform_int_distribution<int> gen;
  random_boy() : rng(chrono::steady_clock::now().time_since_epoch().count()){}
  random_boy(int seed) : rng(seed){}

  int rand32() { return gen(rng);}
  
  // return value in [l, r]
  int rand32_in(int l, int r){
    // to avoid breaking things
    if(l > r) swap(l, r);
    return rand32() % (r - l + 1) + l;
  }

  long long int rand64(){ 
    long long int x = rand32();
    x <<= 32;
    x+=rand32();
    return x;
  }

  // return value in [l, r]
  long long int rand64_in(long long int l, long long int r){
    // to avoid breaking things
    if(l > r) swap(l, r);
    return rand32() % (r - l + 1) + l;
  }
};

int main(int argc, char** argv) {
  if(argc != 4)
    return 1;

  int n, k, seed;
  n = stoi(argv[1]);
  k = stoi(argv[2]);
  seed = stoi(argv[3]);
  
  random_boy randy(seed);
    
  cout << n << " " << k << "\n";
  for(int i = 0; i < n; i++){
    cout << randy.rand32_in(0, 10) << " ";
  }
  cout << "\n";
}