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

int main(){
  int n,m;
  cin >> n >> m;
  scc_graph g(n);

  vvi edge(n);
  REP(_,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    g.add_edge(u,v);
    edge[u].pb(v);
  }

  vvi scc = g.scc();
  int sz = scc.size();

  vi id(n);
  REP(i,sz){
    for(auto v: scc[i])id[v]=i;
  }

  vi dp(sz);
  int ans = 0;
  for(int i = sz-1; i>=0; i--){
    if(scc[i].size()>1){
      dp[i]=1;
    }else{
      for(auto v: edge[scc[i][0]])dp[i] |= dp[id[v]];
    }
    if(dp[i])ans += scc[i].size();
  }
  cout << ans << endl;

}

