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
  int n;
  cin >> n;
  vvi edge(n);
  vector<P> e;
  REP(_,n-1){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].pb(v);
    edge[v].pb(u);
    e.emplace_back(u,v);
  }

  vi f(n);

  vi r(n);

  int cnt = 0; 
  auto dfs = [&](int v, int p, auto dfs) -> int {
    f[v] = cnt++;
    int ret = f[v];
    for(auto nv: edge[v]){
      if(nv == p)continue;

      ret = dfs(nv, v, dfs);
    }
    r[f[v]] = ret;
    return ret;
  };

  dfs(0,-1,dfs);

//  REP(i,n)cout << f[i] << (i == n-1 ? "\n": " ");
//  REP(i,n)cout << r[i] << (i == n-1 ? "\n": " ");
  fenwick_tree<ll> fw(n);
  REP(i,n)fw.add(i,1);
  ll sum = n;
  int q;
  cin >> q;
  REP(_,q){
    int t;
    cin >> t;
    if(t == 1){
      int x,w;
      cin >> x >> w;
      x--;
      fw.add(f[x], w);
      sum += w;
    }else{
      int y;
      cin >> y;
      y--;
      int v = max(f[e[y].first], f[e[y].second]);

      cout << abs(sum - fw.sum(v, r[v]+1) * 2) << endl;
    }
  }
}

