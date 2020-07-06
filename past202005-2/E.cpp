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

const ll INF=(ll)1e19;
//const int INF=(1<<30);
//const int INF=(1<<29);

int main(){
  int N,M,Q;
  cin >> N >> M >> Q;
  vector<vector<int>> edge(N+1, vector<int>());
  VI c(N+1);
  REP(i,M){
    int u,v;
    cin >> u >> v;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }
  REP(i,N)cin >> c[i+1];

  REP(i,Q){
    int t,x,y;
    cin >> t;
    if(t==1){
      cin >> x;
      cout << c[x] << endl;
      REP(j,edge[x].size()){
        c[edge[x][j]] = c[x];
      }
    }else{
      cin >> x >> y;
      cout << c[x] << endl;
      c[x]=y;
    }
  }
}

