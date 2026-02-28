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
  int n;
  cin >> n;

  vector dp(n+1,vector<double>(n+1,-1));

  dp[0][0] = 0;

  vi p(n);
  REP(i,n)cin >> p[i];
  //sort(ALL(p));
  REP(i,n)REP(j,n){

    if(dp[i][j]==-1)continue;
    chmax(dp[i+1][j],dp[i][j]);

    chmax(dp[i+1][j+1],dp[i][j]*0.9 + p[i]);
  }

  //REP(i,n+1)REP(j,n+1)printf("%d %d : %.5f\n",i,j,dp[i][j]);

  double m=0.0;
  double ans=-1e18;
  FOR(k,1,n+1){
    m = m * 0.9 + 1;

    REP(i,n+1){
      if(dp[i][k]==-1)continue;
      chmax(ans, dp[i][k]/m - 1200/sqrt(k));
    }
  }

  printf("%.9f\n",ans);

}

