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

using mint = modint1000000007;
// using mint = modint998244353;

int main(){
  int n;
  string s;
  cin >> n >> s;

  // dp[i][j]: i文字目まででpiより大きい未使用の数がj個の個数
  vector dp(n, vector<mint>(n));

  REP(i,n)dp[0][i] = 1;
  
  REP(i,n-1){
    vector<mint> sum(n+1);
    REP(j,n)sum[j+1] = sum[j]+dp[i][j];

    if(s[i] == '<'){

      // dp[i+1][0] = dp[i][1] + ... + dp[i][n-1-i];
      // dp[i+1][1] = dp[i][2] + ... + dp[i][n-1-i];
      REP(j,n){
        dp[i+1][j] = sum[n-i] - sum[j+1];
      }
    }else{
      // dp[i+1][3] = dp[i][3] + ... + dp[i][0];
      REP(j,n){
        dp[i+1][j] = sum[j+1];
      }
    }
  }

  // REP(i,n)REP(j,n){
  //   printf("%d %d %d\n",i,j,dp[i][j].val());
  // }

  cout << dp[n-1][0].val() << endl;

}

