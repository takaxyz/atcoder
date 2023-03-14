#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

int main(){
  int n, u, v;
  cin >> n >> u >> v;
  u--; v--;
  vvi edge(n);
  REP(_,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb(b);
    edge[b].pb(a);
  }

  vi d1(n,-1);
  d1[u]=0;
  
  function<void(int v)> dfs1 = [&](int v) {
    for(auto nv: edge[v]){
      if(d1[nv]!=-1)continue;
      d1[nv] = d1[v]+1;
      dfs1(nv);
    }
  };
  dfs1(u);

  // REP(i,n){
  //   cout << i << " " << d1[i] << endl;
  // }

  int ans=0;
  function<void(int v, int p, int d)> dfs2 = [&](int v, int p, int d) {
    if(edge[v].size()==1){
      if(d1[v] < d)chmax(ans, d-1);
    }
    for(auto nv: edge[v]){
      if(nv==p)continue;
      dfs2(nv,v,d+1);
    }
  };

  dfs2(v,-1,0);


  cout << ans << endl;
}

