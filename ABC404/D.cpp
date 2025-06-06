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
  vector<ll> c(n);
  REP(i,n)cin >> c[i];
  vvi p(n);
  REP(i,m){
    int k;
    cin >> k;
    REP(j,k){
      int a;
      cin >> a;
      a--;
      p[a].pb(i);
    }
  }

  vi v(m);

  ll ans = LINF;
  auto dfs = [&](int x, ll cost, auto dfs) -> void {
    if(x==n){
      REP(i,m)if(v[i]<2)return;
      chmin(ans, cost);
      return;
    }
    REP(i,3){
      ll nc = cost + c[x] * i;
      for(auto a: p[x])v[a] += i;
      dfs(x+1, nc, dfs);
      for(auto a: p[x])v[a] -= i;
    }
  };

  dfs(0, 0, dfs);
  cout << ans << endl;
}

