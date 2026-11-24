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

  vector edge(n,vector<P>());
  vector<P> e(m);
  REP(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb({b,i});
    edge[b].pb({a,i});
    e[i] = {a,b};
  }

  vi col(n);
  vi visited(n);
  vi use(m);

  auto dfs = [&](auto dfs, int v, int p, int c) -> void{
    col[v]=c;
    visited[v]=1;

    for(auto [nv, i]: edge[v]){
      if(nv == p)continue;
      if(visited[nv])continue;
      use[i]=1;
      dfs(dfs,nv,v,c^1);
    }
  };

  dfs(dfs,0,-1,0);

  REP(i,m){
    if(use[i])continue;
    if(col[e[i].first] == col[e[i].second]){
      vi ans;
      auto dfs2 = [&](auto dfs2, int v, int p, int g) -> void{
        ans.pb(v);
        if(v == g){
          cout << ans.size() << endl;
          REP(i,ans.size())cout << ans[i] + 1 << (i == (int)ans.size()-1 ? "\n" : " ");
          return;
        }
        for(auto [nv, i]: edge[v]){
          if(nv == p)continue;
          if(use[i]==0)continue;
          dfs2(dfs2, nv, v, g);
        }
        ans.pop_back();
      };

      dfs2(dfs2, e[i].first, -1, e[i].second);
      return;
    }
  }
  cout << -1 << endl;

}




int main(){
  int t;
  cin >> t;
  REP(_,t)solve();
}

