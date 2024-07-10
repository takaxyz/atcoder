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

  vector edge(n,vector<pair<int, ll>>());

  ll ans=0;
  REP(_,n-1){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    ans += c;
    a--; b--;
    edge[a].pb({b,c});
    edge[b].pb({a,c});
  }
  
  ans <<= 1;

  vector<ll> d(n);
  auto dfs = [&](int v, int p, auto dfs) -> void {
    for(auto [nv, c] : edge[v]){
      if(nv == p)continue;
      d[nv] = d[v] + c;
      dfs(nv,v,dfs);
    }
  };

  dfs(0,-1,dfs);
  int v1 = -1;
  ll mx = -1;
  REP(i,n){
    if(mx < d[i]){
      v1 = i;
      mx = d[i];
    }
  }

  REP(i,n)d[i]=0;
  dfs(v1, -1, dfs);
  mx = -1;
  REP(i,n){
    if(mx < d[i]){
      mx = d[i];
    }
  }

  ans -= mx;

  cout << ans << endl;


  


}

