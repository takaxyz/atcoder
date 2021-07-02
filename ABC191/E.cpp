#include <bits/stdc++.h>
using namespace std;

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

const int INF = numeric_limits< int >::max();
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
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}




int main(){
  int n,m;
  cin >> n >> m;
  WeightedGraph<int> g1(n), g2(n);
  REP(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    g1[a].push_back({a,b,c});
    g2[b].push_back({b,a,c});
  }

  REP(i,n){
    int ans = INF;
    for(auto e: g1[i]){
      if(e.to==i){
        chmin(ans, e.cost);
      }
    }

    vi dist1 = dijkstra(g1, i);
    vi dist2 = dijkstra(g2, i);

    // cout << i << endl;
    // REP(j, dist1.size()){
    //   cout << dist1[j] << (j==dist1.size()-1 ? "\n" : " ");
    // }
    // REP(j, dist2.size()){
    //   cout << dist2[j] << (j==dist2.size()-1 ? "\n" : " ");
    // }
    REP(j,n){
      if(i==j)continue;
      if(dist1[j] != INF && dist2[j]!=INF){
        chmin(ans, dist1[j]+dist2[j]);
      }
    }
    if(ans == INF)ans=-1;
    cout << ans << endl;
  }
}

