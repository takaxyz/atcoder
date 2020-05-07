#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int N,M,R;
  cin >> N >> M >> R;

  vector<int> r(R);
  REP(i,R)cin>>r[i];

  sort(r.begin(),r.end());

  vector<vector<ll>> d(N+1, vector<ll>(N+1,INF));

  REP(i,M){
    int a,b,c;
    cin >> a >> b >> c;
    d[a][b]=c;
    d[b][a]=c;
  }
  FOR(k,1,N+1)FOR(i,1,N+1)FOR(j,1,N+1){
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }


  ll ans=INF;
  do{
    ll t=0;
    REP(i,r.size()-1){
      t+=d[r[i]][r[i+1]];
    }
    ans = min(t,ans);

  }while(next_permutation(ALL(r)));

  cout << ans << endl;

}

