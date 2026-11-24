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
  vvi edge(2*n-1,vi());

  REP(i,n-1){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].pb(i+n);
    edge[i+n].pb(u);
    edge[v].pb(i+n);
    edge[i+n].pb(v);
  }

  vi c(n);
  REP(i,n)cin >> c[i];

  vi dist(2*n-1);
  auto dfs = [&](auto dfs, int v, int p=-1) -> void{
    for(auto nv: edge[v]){
      if(nv==p)continue;
      dist[nv] = dist[v]+1;
      dfs(dfs,nv,v);
    }
  };

  dfs(dfs,0);
  int s = max_element(ALL(dist)) - dist.begin();
  REP(i,2*n-1)dist[i]=0;  
  dfs(dfs,s);
  int d = *max_element(ALL(dist));
  int t = max_element(ALL(dist)) - dist.begin();

  vi vs;
  int u;
  auto dfs3 = [&](auto dfs3, int v, int p, int dst) -> bool{
    vs.pb(v);
    if(v == dst){
      //REP(i,vs.size())cout << vs[i] << (i==vs.size()-1 ? "\n" : " ");
      u = vs[vs.size()/2];
      return true;
    }
    for(auto nv : edge[v]){
      if(nv == p)continue;
      if(dfs3(dfs3,nv,v,dst))return true;
    }
    vs.pop_back();
    return false;
  };

  dfs3(dfs3,s,-1,t);

  //cout << s << " " << t << " "  << d << " " << u << endl;

  map<int, int> tot;
  auto dfs2 = [&](auto dfs2, int v, int p, int dep, map<int,int> &mp) -> void {
    if(dep == d/2){
      tot[c[v]]++;
      mp[c[v]]++;
    }
    for(auto nv: edge[v])if(nv != p)dfs2(dfs2,nv,v,dep+1,mp);
  };

  ll ans=0;
  for(auto v: edge[u]){
    map<int,int> mp;
    dfs2(dfs2,v,u,1,mp);
    for(auto [k,v]: mp){
      ans -= (ll)v*(v-1)/2;
    }
  }
  //cout << ans << endl;
  for(auto [k,v]: tot){
    //cout << k << " " << v << endl;
    ans += (ll)v*(v-1)/2;
  }

  cout << ans << endl;
}

