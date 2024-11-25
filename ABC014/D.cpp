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

using mint = modint1000000007;
// using mint = modint998244353;

// past201912-open K

struct LCA {
  int sz;
  vi dep;
  vvi edge;
  vvi dp;

  int logN;
  LCA(int n): sz(n),dep(n), edge(n) {
    logN = 1;
    while((1 << logN) <= n)logN++;
    dp.assign(logN, vi(n,-1));
  }

  void add(int src, int dst){
    edge[src].pb(dst);
    edge[dst].pb(src);
  }

  void dfs(int v, int p, int d){
    dp[0][v] = p;
    dep[v] = d;
    for(auto x: edge[v]){
      if(x==p)continue;
      dfs(x, v, d+1);
    }
  }

  void build(int root=0){
    dfs(root,-1,0);
    REP(i,logN-1)REP(j,sz){
      if(dp[i][j] == -1)dp[i+1][j] = -1;
      else dp[i+1][j] = dp[i][dp[i][j]];
    }
  }
  int query(int u, int v){
    if(dep[u] < dep[v])swap(u,v);
    REP(i,logN){
      if((dep[u] - dep[v]) >> i & 1){
        u = dp[i][u];
      }
    }

    if(u==v)return u;
    for(int i = logN-1; i >= 0; i--){
      if(dp[i][u] != dp[i][v]){
        u = dp[i][u];
        v = dp[i][v];
      }
    }
    return dp[0][u];

  }

  int solve(int u,int v){
    int p = query(u,v);
    //cout << "  " << p << endl;
    return dep[u] + dep[v] - dep[p]*2 + 1;

  }
};

int main(){
  int n;
  cin >> n;

  LCA lca(n);
  REP(i,n-1){
    int x,y;
    cin >> x >> y;
    x--; y--;
    lca.add(x,y);
  }
  lca.build();

  int q;
  cin >> q;
  while(q--){
    int a,b;
    cin >> a >> b;
    a--; b--;
    cout << lca.solve(a,b) << endl;
  }

}

