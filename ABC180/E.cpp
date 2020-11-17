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
  int n;
  cin >> n;
  vi x(n),y(n),z(n);
  REP(i,n)cin >> x[i] >> y[i] >> z[i];

  vvi d(n,vi(n));
  REP(i,n)REP(j,n){
    d[i][j] = abs(x[j]-x[i]) + abs(y[j]-y[i]) + max(0, z[j]-z[i]);
  }

  int n2 = 1<<n;
  // dp[i][j]: これまで訪れた町の集合i（ビット表現）、今いる町j の最小コスト
  // 答えはdp[1<<n-1][0]
  vvi dp(n2, vi(n, INF));
  dp[0][0]=0;

  REP(i,n2)REP(j,n){
    // 集合i に今いる町jが含まれてなければスキップ
    if(!(i>>j & 1) && (i+j!=0))continue;

    // 町j→k
    REP(k,n){
      chmin(dp[i| 1<<k][k], dp[i][j]+d[j][k]);
    }
  }

  // REP(i,n2)REP(j,2){
  //   cout << i << " " << j << " " << dp[i][j] << endl;
  // }

  cout << dp[n2-1][0] << endl;
}

