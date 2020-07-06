#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define RALL(v) rbegin(v), rend(v)

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
  int W;
  cin >> W;
  int N,K;
  cin >> N >> K;

  // dp[i][j][k]: i枚目まででj枚選んでいる幅kの重要度
  vvvi dp(N+1,vvi(K+1, vi(W+1, -1)));
  vi a(N+1),b(N+1);
  REP(i,N)cin >> a[i+1] >> b[i+1];

  dp[0][0][0]=0;
  FOR(i,1,N+1)REP(j,K+1)REP(k,W+1){
    if(dp[i-1][j][k]==-1)continue;
    // 選ばない
    chmax(dp[i][j][k], dp[i-1][j][k]);

    if(a[i]+k> W|| j+1 > K)continue;
    // 選ぶ
    chmax(dp[i][j+1][k+a[i]], dp[i-1][j][k]+b[i]);
  }

  int ans=0;
  REP(i,N+1)REP(j,K+1)REP(k,W+1){
    //printf("%d %d %d: %d\n", i,j,k,dp[i][j][k]);
  }
  REP(i,K+1)REP(j,W+1){
    chmax(ans, dp[N][i][j]);
  }
  PRINT(ans);

}

