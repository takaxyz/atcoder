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
  int n,k;
  cin >> n >> k;
  vvi edge(n,vi());
  REP(i,n-1){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].pb(v);
    edge[v].pb(u);
  }
  vi a(n);
  REP(i,n)cin >> a[i];

  auto dfs = [&](int v, int p, auto dfs) -> vvi{
    vvi dp(2,vi(k+1,-INF));

    dp[0][0]=0;
    dp[1][1]=a[v];

    for(auto nv: edge[v]){
      if(nv == p)continue;
      vvi old(2,vi(k+1,-INF));
      swap(old,dp);

      vvi dp_nv = dfs(nv,v,dfs);

      REP(i,k+1)REP(j,k+1){
        if(i+j > k)continue;

        if(old[0][i] != -INF && dp_nv[0][j] != -INF)chmax(dp[0][i+j],old[0][i] + dp_nv[0][j]);
        if(old[0][i] != -INF && dp_nv[1][j] != -INF)chmax(dp[0][i+j],old[0][i] + dp_nv[1][j]);
        if(old[1][i] != -INF && dp_nv[0][j] != -INF)chmax(dp[1][i+j],old[1][i] + dp_nv[0][j]);
      }
    }

    return dp;

  };

  vvi dp = dfs(0,-1,dfs);
  int ans = max(dp[0][k], dp[1][k]);

  cout << (ans == -INF ? -1 : ans) << endl;


}

