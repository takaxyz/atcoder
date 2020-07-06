#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

//const ll INF=(ll)1e19;
const int INF=(1<<29);

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dist(n, vector<int>(n, INF));
  REP(i,n)dist[i][i]=0;

  REP(i,m){
    int a,b,t;
    cin >> a >> b >> t;
    a--;b--;
    dist[a][b]=t;
    dist[b][a]=t;
  }

  REP(i,n)REP(j,n)REP(k,n){
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }

  int ans=INF;
  REP(i,n){
    int tmp=0;
    REP(j,n){
      if(i==j)continue;

      chmax(tmp, dist[i][j]);
    }
    chmin(ans,tmp);
  }
  cout << ans << endl;

}

