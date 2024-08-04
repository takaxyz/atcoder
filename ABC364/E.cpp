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
  int n,x,y;
  cin >> n >> x >> y;

  vector dp(n+1, vector(x+1, vector<int>(n+1, INF)));

  dp[0][0][0] = 0;

  REP(i,n){
    int a,b;
    cin >> a >> b;
    
    REP(j,x+1)REP(k,n+1){
      if(dp[i][j][k] == INF)continue;

      // 選ばない
      chmin(dp[i+1][j][k], dp[i][j][k]);

      // 選ぶ
      if(j+a <= x) chmin(dp[i+1][j+a][k+1], dp[i][j][k] + b);
    }
  }

  int ans = 0;
  REP(j,x+1)REP(k,n+1){
    if(dp[n][j][k] <= y)chmax(ans, k);
  }
  cout << min(n,ans+1) << endl;
}

