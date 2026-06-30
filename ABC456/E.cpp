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
  int n,m;
  cin >> n >> m;
  vvi edge(n);

  REP(_,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].pb(v);
    edge[v].pb(u);
  }
  REP(i,n)edge[i].pb(i);

  int w;
  cin >> w;
  vector<string> s(n);
  REP(i,n)cin >> s[i];

  vvi visited(n,vi(w));
  vvi fin(n,vi(w));

  auto dfs = [&](int v, int d, auto dfs) -> bool{
    visited[v][d]=1;

    for(auto nv: edge[v]){
      if(s[nv][(d + 1)%w] == 'x')continue;

      if(fin[nv][(d + 1)%w])continue;

      if(visited[nv][(d + 1)%w]){
        return true;
      }
      if(dfs(nv, (d+1)%w, dfs))return true;
    }

    fin[v][d]=1;

    return false;
  };

  REP(i,n){
    if(s[i][0]=='x')continue;
    if(dfs(i,0,dfs)){
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;

}



int main(){
  int t;
  cin >> t;
  REP(_,t)solve();
}

