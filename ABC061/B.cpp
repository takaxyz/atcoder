#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  map<int,int> mp;
  int n,m;
  cin >> n >> m;
  REP(i,m){
    int a,b;
    cin >> a >> b;
    mp[a]++;mp[b]++;
  }
  FOR(i,1,n+1){
    cout << mp[i] << endl;
  }

}



