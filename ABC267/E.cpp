#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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
using P = pair<ll,int>;
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
  int n,m;
  cin >> n >> m;

  vector<ll> a(n);
  REP(i,n)cin >> a[i];

  priority_queue<P, vector<P>, greater<P> > q;

  vvi edge(n, vi());
  vector<ll> c(n);
  REP(i,m){
    int u,v;
    cin >> u >> v;
    u--;v--;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
    c[u] += a[v];
    c[v] += a[u];
  }

  vi erased(n);

  REP(i,n)q.push({c[i],i});

  ll ans=0;
  while(!q.empty()){
    auto [cost, v] = q.top(); q.pop();

    if(erased[v])continue;
    chmax(ans, cost);
    erased[v]=1;
    for(auto vv: edge[v]){
      if(erased[vv])continue;
      c[vv] -= a[v];
      q.push({c[vv], vv});
    }
  }
  cout << ans << endl;
}

