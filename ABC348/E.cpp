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
  vector<ll> c(n);
  REP(i,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb(b);
    edge[b].pb(a);
  }
  ll sum=0;
  REP(i,n){
    cin >> c[i];
    sum += c[i];
  }

  map<P, ll> mp;

  auto dfs = [&](int v, int p=-1, auto dfs) -> ll {
    ll ret = c[v];
    for(auto nv: edge[v]){
      if(nv==p)continue;
      ret += dfs(nv,v,dfs);
    }
    return mp[make_pair(p,v)] =ret;
  };

  dfs(0,-1,dfs);

  // for(auto [k,v]: mp){
  //   cout << k.first << " " << k.second <<  " " << v << endl;
  // }

  vector<ll> ans(n);
  auto dfs2 = [&](int v, int p, auto dfs2) -> void {
    for(auto nv: edge[v]){
      if(nv==p)continue;
      ans[nv] = ans[v] + sum - mp[{v,nv}] * 2;
      dfs2(nv,v,dfs2);
    }

  };

  dfs2(0,-1,dfs2);

  ll mi = LINF;
  int s = -1;
  REP(i,n){
    // cout << i << " " << ans[i] << endl;
    if(mi > ans[i]){
      s = i;
      mi = ans[i];
    }
  }

  auto dfs3 = [&](int v, int p, ll d, auto dfs3) -> ll {
    ll ret = d * c[v];
    for(auto nv: edge[v]){
      if(nv==p)continue;
      ret += dfs3(nv,v,d+1, dfs3);
    }
    return ret;
  };

  cout << dfs3(s,-1,0,dfs3) << endl;



}

