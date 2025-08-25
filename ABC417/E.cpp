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

void solve(){
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  x--;y--;
  vvi edge(n,vi());
  REP(_,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].pb(v);
    edge[v].pb(u);
  }
  REP(i,n)sort(ALL(edge[i]));

  vi root;
  vi visited(n);
  auto dfs = [&](int v, int p, auto dfs) -> void {
    visited[v] = 1;
    root.pb(v);
    if(v == y){
      REP(i,root.size())cout << root[i] + 1 << (i==(int)root.size()-1 ? "\n" : " ");
    }

    for(auto nv: edge[v]){
      if(nv==p)continue;
      if(visited[nv])continue;
      dfs(nv,v,dfs);
    }
    root.pop_back();
  };

  dfs(x,-1,dfs);

}

int main(){
  int t;
  cin >> t;
  REP(_,t)solve();
}

