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
  vector<ll> a(n);
  REP(i,n)cin >> a[i];

  vector edge(n, vector<pair<int,ll>>());
  REP(_,m){
    int u,v;
    ll b;
    cin >> u >> v >> b;
    u--; v--;
    edge[u].pb({v,b+a[v]});
    edge[v].pb({u,b+a[u]});
  }

  vector<ll> dist(n,LINF);
  dist[0] = a[0];

  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que;
  que.emplace(dist[0],0);

  while(!que.empty()){
    auto [cost, v] = que.top();
    que.pop();
    if(dist[v] < cost)continue;
    for(auto [to, c]: edge[v]){
      auto next_cost = cost + c;

      if(dist[to] <= next_cost)continue;

      dist[to] = next_cost;
      que.emplace(dist[to], to);
    }
  }

  FOR(i,1,n)cout << dist[i] << endl;


}

