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
using mint = modint998244353;

int main(){
  int n;
  cin >> n;
  vvi edge(n);
  REP(i,n-1){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb(b);
    edge[b].pb(a);
  }

  auto dfs = [&](auto dfs, int v, int p) -> vector<vector<mint>> {
    vector<vector<mint>> dp(2, vector<mint>(2,0));

    dp[0][0]=1;
    dp[1][1]=1;

    for(auto nv : edge[v]){
      if(nv==p)continue;
      auto ret = dfs(dfs, nv, v);
      vector<vector<mint>> ndp(2, vector<mint>(dp[0].size() + ret[0].size() - 1,0));

      REP(i, dp[0].size()){
        REP(j, ret[0].size()){
          ndp[0][i+j] += dp[0][i] * ret[0][j];
          ndp[0][i+j] += dp[0][i] * ret[1][j];
          ndp[1][i+j] += dp[1][i] * ret[0][j];
          if(i+j>0)ndp[1][i+j-1] += dp[1][i] * ret[1][j];
        }
      }
      swap(ndp, dp);
    }

    return dp;
  };

  auto dp = dfs(dfs, 0, -1);

  FOR(i,1,n+1){
    cout << (dp[0][i] + dp[1][i]).val() << endl;

  }
}

