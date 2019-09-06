#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  int n,m;

  cin >> n;
  vector<int> t(n);
  int sum=0;
  REP(i,n){
    cin >> t[i];
    sum += t[i];
  }
  cin >> m;
  REP(i,m){
    int p,x;
    cin >> p >> x;
    p--;
    cout << sum - t[p] + x << endl;
  }
  
}

