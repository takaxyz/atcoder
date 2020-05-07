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
  int n,m;
  cin >> n >> m;

  vector<vector<ll>> v(3, vector<ll>(n));
  REP(i,n)cin >> v[0][i] >> v[1][i] >> v[2][i];

  ll ans=-1;
  REP(i,8){
    vector<pair<ll, int>> arr;
    REP(j,n){
      ll tmp=0;
      REP(k,3){
        if(i>>k & 1){
          tmp += v[k][j];
        }else{
          tmp -= v[k][j];
        }
      }
      arr.push_back(make_pair(tmp, j));
    }
    sort(ALL(arr));
    reverse(ALL(arr));

    ll x=0;
    ll y=0;
    ll z=0;

    REP(j,m){
      x+= v[0][arr[j].second];
      y+= v[1][arr[j].second];
      z+= v[2][arr[j].second];
    }
    ans=max(ans,abs(x)+abs(y)+abs(z));
  }
  cout << ans << endl;
}


