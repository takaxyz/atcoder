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

int main(){
  int n,m;
  ll k;
  cin >> n >> m  >> k;
  vector<ll> a(n);
  REP(i,n)cin >> a[i];

  vector<vector<ll>> cost(n, vector<ll>(m+1));
  REP(i,n){
    ll mx = 0;
    ll mi = LINF;
    REP(j,m){
      chmin(mi, a[i+j]);
      chmax(mx, a[i+j]);
      cost[i][j+1] = k + (mx-mi)*(j+1);
    }
  }

  // REP(i,n)REP(j,m){
  //   cout << i << " " << j+1 << " " << cost[i][j+1] << endl;
  // }

  vector<ll> dp(n+1,LINF);
  dp[0] = 0;
  REP(i,n){
    FOR(j, max(i-m+1,0), i+1){
      //printf("dp[%d]: dp[%d](%lld) + cost[%d][%d](%lld)\n", i+1,j,dp[j], j,i-j+1,cost[j][i-j+1]);
      chmin(dp[i+1],dp[j] + cost[j][i-j+1]);
    }
  }


  // REP(i,n+1){
  //   cout << i << " " << dp[i] << endl;
  // }
  cout << dp[n] << endl;


}

