#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  vector<int> v(6);
  REP(i,6)cin >> v[i];

  sort(v.begin(),v.end());
  cout << v[3] << endl;
}

