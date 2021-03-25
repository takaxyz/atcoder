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

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

struct edge{
  int to;
  int cost;
  int k;
};

int main(){
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  x--; y--;
  vector<vector<edge>> G(n);

  REP(i,m){
    int a,b,t,k;
    cin >> a >> b >> t >> k;
    a--; b--;
    G[a].push_back({b,t,k});
    G[b].push_back({a,t,k});
  }

  priority_queue<P, vector<P>, greater<P>> q;
  vector<ll> dist(n,LINF);
  dist[x]=0;

  q.push({0,x});

  while(!q.empty()){
    P p = q.top();
    q.pop();
    int v = p.second;
    int d = p.first;

    if(dist[v] < d)continue;

    for(auto e: G[v]){
      ll nd;
      if(dist[v] % e.k == 0){
        nd = dist[v] + e.cost;
      }else{
        nd = dist[v] + e.k - dist[v] % e.k + e.cost;
      }
      if(nd < dist[e.to]){
        dist[e.to] = nd;
        q.push({dist[e.to], e.to});
      }
    }

  }

  cout << (dist[y]==LINF ? -1 : dist[y]) << endl;

}

