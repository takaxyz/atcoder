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

int dx[] = {1,0};
int dy[] = {0,1};

int main(){
  int h,w;
  cin >> h >> w;
  int k = h + w - 1;
  vector a(h, vector<ll>(w));

  REP(i,h)REP(j,w)cin >> a[i][j];

  vector dp(h, vector(w, vector<ll>(k+1, -1)));
  dp[0][0][0]=0;
  dp[0][0][1]=a[0][0];

  REP(i,h)REP(j,w){
    REP(l,2){
      int ni = i + dx[l];
      int nj = j + dy[l];
      if(ni >= h || nj >= w)continue;

      REP(m,k){
        if(dp[i][j][m]==-1)continue;
        chmax(dp[ni][nj][m], dp[i][j][m]);
        chmax(dp[ni][nj][m+1], dp[i][j][m] + a[ni][nj]);
      }
    }
  }

  FOR(i,1,k+1)cout << dp[h-1][w-1][i] << endl;


}

