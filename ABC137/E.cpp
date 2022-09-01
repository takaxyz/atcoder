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
const int MOD = 1e9 + 7;

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
vector< T > bellman_ford(Edges< T > &edges, int V, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(V, INF);
  dist[s] = 0;
  for(int i = 0; i < V - 1; i++) {
    for(auto &e : edges) {
      if(dist[e.src] == INF) continue;
      dist[e.to] = min(dist[e.to], dist[e.src] + e.cost);
    }
  }
  for(auto &e : edges) {
    if(dist[e.src] == INF) continue;
    if(dist[e.src] + e.cost < dist[e.to]) return vector< T >();
  }
  return dist;
}


void dfs(int s, vi &visited, vvi &e){
  visited[s] = 1;
  for(auto v: e[s]){
    if(visited[v])continue;
    dfs(v, visited, e);
  }
}


int main(){
  int n,m,p;
  cin >> n >> m >> p;

  Edges<int> es;

  vvi to(n, vi());
  vvi ot(n, vi());

  REP(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--; c -= p;
    es.emplace_back(a,b,-c);
    to[a].emplace_back(b);
    ot[b].emplace_back(a);
  }

  vi visited1(n);
  vi visited2(n);

  dfs(0, visited1, to);
  dfs(n-1, visited2, ot);

  Edges<int> es2;
  for(auto e: es){
    if(visited1[e.to] && visited2[e.to] && visited1[e.src] && visited2[e.src]){
      es2.emplace_back(e.src, e.to, e.cost);
    }
  }


  auto dist = bellman_ford(es2,n,0);

  if(dist.size()==0){
    cout << -1 << endl;
  }else if(dist[n-1]<0){
    cout << -dist[n-1] << endl;
  }else{
    cout << 0 << endl;
  }


}


