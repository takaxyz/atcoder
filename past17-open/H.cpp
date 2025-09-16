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
  int n,m;
  cin >> n >> m;

  int MX=5000;
  vector ac(MX, vector<P>());

  REP(_,n){
    int a,b,c;
    cin >> a >> b >> c;
    b--;
    ac[b].pb({a,c});
  }

  vvi dp(MX+1, vi(m+1, INF));
  dp[0][0] = 0; 
  REP(b,MX){
    REP(i,m+1){
      if(dp[b][i]==INF)continue;
      chmin(dp[b+1][i],dp[b][i]);
      for(auto [a,c] : ac[b]){
        chmin(dp[b+1][min(m, i+c)], dp[b][i]+a);
      }
    }
  }

  //REP(i,MX+1)REP(j,m+1)printf("%d %d: %d\n",i,j,dp[i][j]);

  cout << (dp[MX][m] == INF ? -1 : dp[MX][m]) << endl;
}

