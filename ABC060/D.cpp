#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  ll N,W;
  cin >> N >> W;

  vector<vector<ll>> v(4, vector<ll>());
  vector<vector<ll>> vsum(4, vector<ll>());

  ll w1;
  REP(i,N){
    ll ww,vv;
    cin >> ww >> vv;

    if(i==0){
      w1=ww;
    }
    v[ww-w1].push_back(vv);
  }

  REP(i,4){
    sort(v[i].begin(),v[i].end(),::greater<ll>());
  }

  REP(i,4){
    vsum[i].push_back(0);
  }
  REP(i,4){
    REP(j,v[i].size()){
      vsum[i].push_back(vsum[i][j]+v[i][j]);
    }
  }


  ll ans = -1;
  REP(i1,vsum[0].size()){
    REP(i2,vsum[1].size()){
      REP(i3,vsum[2].size()){
        REP(i4,vsum[3].size()){
          if((ll)i1*1 + (ll)i2*2 + (ll)i3*3 + (ll)i4*4 + (w1-1)*(i1+i2+i3+i4) > W)continue;
          ans = max(ans, vsum[0][i1]+vsum[1][i2]+vsum[2][i3]+vsum[3][i4]);
        }
      }
    }
  }
  cout << ans << endl;
}

