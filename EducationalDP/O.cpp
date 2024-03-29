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

int main(){
  int n;
  cin >> n;
  vvi a(n,vi(n));
  REP(i,n)REP(j,n)cin >> a[i][j];

  map<int, mint> memo;
  vector<vector<mint>> dp(n+1,vector<mint>(1<<n));
  dp[0][0]=1;
  REP(i,n){
    REP(j, 1<<n){
      int c = __builtin_popcount(j);
      if(i != c)continue;
      REP(k,n){
        if(a[i][k] == 0)continue;
        if((j >> k) & 1)continue;

        dp[i+1][j | 1<<k] += dp[i][j];
      }
    }
  }

  cout << dp[n][(1<<n)-1].val() << endl;
}

