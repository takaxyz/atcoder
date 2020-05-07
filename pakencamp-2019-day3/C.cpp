#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int n, m;
  cin >> n >> m;
  int a[105][105];

  REP(i,n)REP(j,m)cin >> a[i][j];

  ll ans=0;
  REP(i,m)FOR(j,i+1,m){
    ll sum=0;
    REP(k,n){
      sum += max(a[k][i], a[k][j]);
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
}

