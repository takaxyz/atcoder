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
const int MOD = 1e9 + 7;

struct edge {
  int to;
  int cost;
  edge(int to, int cost): to(to), cost(cost){};
};

pair<vi, vector<ll>> dijkstra(vector<vector<edge>> &g, int s, vector<ll>& a) {

  vector<int> dist(g.size(), INF);
  vector<ll> val(g.size(), 0);
  priority_queue< P, vector<P >, greater< P > > que;
  dist[s]=0;
  que.emplace(dist[s],s);

  while(!que.empty()) {
    auto [cost, idx] = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] == next_cost){
        chmax(val[e.to], val[idx] + a[e.to]);
        continue;
      }else if(dist[e.to] > next_cost){
        val[e.to] = val[idx] + a[e.to];
        dist[e.to] = next_cost;
        que.emplace(dist[e.to], e.to);
      }
    }
  }
  return {dist, val};
}


int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  REP(i,n)cin >> a[i];
  vector<vector<edge>> graph(n, vector<edge>());

  REP(i,n)REP(j,n){
    char c;
    cin >> c;
    if(c=='Y'){
      graph[i].pb({j,1});
    }
  }

  vvi dd(n);
  vector<vector<ll>> vv(n);
  REP(i,n){
    auto [d, val] = dijkstra(graph, i, a);
    dd[i] = d;
    vv[i] = val;
  }

  int q;
  cin >> q;
  REP(_,q){
    int u,v;
    cin >> u >> v;
    u--; v--;
    
    if(dd[u][v]==INF){
      cout << "Impossible" << endl;
      continue;
    }else{
      cout << dd[u][v] << " "  << a[u] + vv[u] << endl;
    }
  }
}

