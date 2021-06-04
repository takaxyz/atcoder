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

int main(){
  int N,W;
  cin >> N >> W;
  vi w(N), v(N);
  REP(i,N)cin >> w[i] >> v[i];

  vector<vector<ll>> dp(N+1, vector<ll>(100002, LINF));
  dp[0][0] = 0;
  // dp_ij: i個目までで価値jになる最小の重さ
  REP(i,N)REP(j,100002){
    if(j-v[i]>=0)chmin(dp[i+1][j], dp[i][j-v[i]] + w[i]);
    chmin(dp[i+1][j], dp[i][j]);
  }

  ll ans=0;
  // REP(i,N)REP(j,100002){
  //   printf("%d %d: %ld\n", i,j,dp[i][j]);
  // }
  REP(i,100002)if(dp[N][i] <= W)ans=i;
  cout << ans << endl;
}

