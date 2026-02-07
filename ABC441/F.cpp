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
  int n, m;
  cin >> n >> m;
  vi p(n);
  vector<ll> v(n);
  REP(i,n)cin >> p[i] >> v[i];

  vector dp(n+1,vector<ll>(m+1, -LINF));
  dp[0][0]=0;

  REP(i,n)REP(j,m+1){
    if(dp[i][j]==-LINF)continue;

    chmax(dp[i+1][j],dp[i][j]);
    if(j+p[i] <= m)chmax(dp[i+1][j+p[i]],dp[i][j] + v[i]);
  }

  ll mx=0;
  REP(i,m+1)chmax(mx,dp[n][i]);
  //REP(i,n+1)REP(j,m+1)printf("%d %d: %lld\n",i,j,dp[i][j]);

  vvi route(n+1,vi(m+1));
  REP(i,m+1)if(dp[n][i] == mx)route[n][i]=1;

  vi skip(n);
  vi use(n);

  for(int i = n; i > 0; i--){
    for(int j = 0; j <= m; j++){
      if(route[i][j]==0)continue;

      if(dp[i][j] == dp[i-1][j]){
        route[i-1][j]=1;
        skip[i-1]=1;
      }

      if(j-p[i-1] >=0){
        if(dp[i][j] == dp[i-1][j-p[i-1]] + v[i-1]){
          use[i-1]=1;
          route[i-1][j-p[i-1]]=1;
        }
      }
    }
  }

  //REP(i,n+1)REP(j,m+1)printf("%d %d: %d\n",i,j,route[i][j]);

  REP(i,n){
    if(use[i]){
      if(skip[i])cout << "B";
      else cout << "A";
    }else{
      cout << "C";
    }
  }
  cout << endl;

}

