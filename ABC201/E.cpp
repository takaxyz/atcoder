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
  vector edge(n,vector<pair<int,ll>>());

  REP(_,n-1){
    int u,v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    edge[u].emplace_back(v,w);
    edge[v].emplace_back(u,w);
  }

  vector<ll> dist(n);
  auto dfs = [&](int v, int p, ll d, auto dfs) -> void{
    dist[v] = d;
    for(auto [nv, w]: edge[v]){
      if(nv==p)continue;
      dfs(nv, v, d^w, dfs);
    }
  };

  dfs(0,-1,0,dfs);


  mint ans = 0;
  REP(i,n)ans += dist[i];

  REP(i,60){
    vi cnt(2);
    FOR(j,1,n){
      cnt[dist[j] >> i & 1]++;
    }
    ans += mint((1LL << i)) * cnt[0] * cnt[1];
  }
  cout << ans.val() << endl;
}

