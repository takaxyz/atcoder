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
  ll y;
  cin >> n >> m >> y;

  vector edge(n+1, vector<pair<int, ll>>());
  
  REP(_,m){
    int u,v;
    ll t;
    cin >> u >> v >> t;
    u--; v--;
    edge[u].pb({v,t*2});
    edge[v].pb({u,t*2});
  }

  REP(i,n){
    ll x;
    cin >> x;
    edge[i].pb({n,x*2+y});
    edge[n].pb({i,x*2+y});
  }

  vector<ll> d(n+1,LINF);
  d[0]=0;
  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;

  q.push({0,0});

  while(q.size()){
    auto [dist, v] = q.top();
    q.pop();

    if(d[v] < dist)continue;

    for(auto [nv, c] : edge[v]){
      if(d[nv] <= dist + c)continue;

      d[nv] = dist + c;
      q.push({d[nv], nv});
    }
  }

  FOR(i,1,n)cout << d[i] / 2 << endl;


}

