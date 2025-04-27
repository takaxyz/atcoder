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

// using mint = modint1000000007;
using mint = modint998244353;

int main(){
  int n;
  cin >> n;

  vector dp(n,vector<mint>(n));

  dp[0][0]=1;

  vector<mint> inv2(n+1);
  inv2[0]=1;
  REP(i,n)inv2[i+1] = inv2[i]/2;


  FOR(i,1,n){
    dp[i][i] = 0;
    REP(j,i)dp[i][i] += dp[i-1][j] * inv2[i-j];
    dp[i][i] /= (1-inv2[i+1]);
    dp[i][0] = dp[i][i]/2;

    FOR(j,1,i){
      dp[i][j] = dp[i][j-1]/2 + dp[i-1][j-1]/2;
    }
  }

  REP(i,n)cout << dp[n-1][i].val() << endl;

}

