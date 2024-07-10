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

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

int main(){
  int h,w;
  ll k;
  cin >> h >> w >> k;

  int si,sj;
  cin >> si >> sj;
  si--; sj--;
  vvi a(h, vi(w));
  REP(i,h)REP(j,w)cin >> a[i][j];

  int hw = h*w;

  vector<vector<vector<ll>>> dp(hw+1, vector<vector<ll>>(h, vector<ll>(w,-LINF)));
  dp[0][si][sj]=0;

  ll ans=0;
  REP(l,hw)REP(i,h)REP(j,w){
    if(dp[l][i][j]==-LINF)continue;

    REP(d, 4){
      int ni = i + di[d];
      int nj = j + dj[d];
      if(ni < 0 || ni >= h || nj < 0 || nj >= w)continue;
      chmax(dp[l+1][ni][nj], dp[l][i][j]+a[ni][nj]);
    }
  }

  REP(l,hw)REP(i,h)REP(j,w){
    if(l > k)continue;
    if(dp[l][i][j]==-LINF)continue;
    chmax(ans, (k-l)*a[i][j] + dp[l][i][j]);
  }


  // REP(l,hw+1)REP(i,h)REP(j,w){
  //   printf("%d %d %d: %lld\n", l,i,j,dp[l][i][j]);
  // }

  cout << ans << endl;

}

