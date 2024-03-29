#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

using mint = modint998244353;

mint dp[101][101][101][101];

int main(){
  int n;
  cin >> n;
  vi a(n);
  REP(i,n)cin >> a[i];

  FOR(i,1,101)dp[0][0][i][0] = 1;

  REP(i,n)REP(j,i+1)FOR(k,1,101)REP(l,100){
    // 選ばない
    dp[i+1][j][k][l] += dp[i][j][k][l];

    //選ぶ
    dp[i+1][j+1][k][(l + a[i])%k] += dp[i][j][k][l];
  }

  mint ans = 0;
  FOR(i,1,101)ans += dp[n][i][i][0];

  cout << ans.val() << endl;

  
}

