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

struct Edge{
  int to;
  ll cost;
};

int main(){
  int n,q;
  cin >> n >> q;
  vector edge(n+1,vector<Edge>());

  vector<ll> sum(n+1);
  REP(i,n){
    ll a;
    cin >> a;
    edge[i].pb({(i+1)%n,a});
    edge[(i+1)%n].pb({i,a});
    sum[i+1] = sum[i]+a;
  }
  REP(i,n){
    ll b;
    cin >> b;
    edge[i].pb({n,b});
    edge[n].pb({i,b});
  }

  vector<ll> dist(n+1,LINF);
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que;
  dist[n]=0;
  que.emplace(0,n);

  while(!que.empty()){
    auto [d, v] = que.top();
    que.pop();
    
    if(dist[v] < d)continue;
    for(auto &e: edge[v]){
      ll next_cost = d + e.cost;
      if(dist[e.to] <= next_cost)continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }



  REP(_,q){
    int s,t;
    cin >> s >> t;
    s--; t--;

    ll ans = dist[s] + dist[t];

    if(t != n){
      chmin(ans, sum[t]-sum[s]);
      chmin(ans, sum[n] - sum[t] + sum[s]);
    }
    
    cout << ans << endl;

  }

}

