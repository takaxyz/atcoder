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

int main(){
  int n;
  cin >> n;
  vi x(n),y(n),z(n);
  ll zsum=0;
  REP(i,n){
    cin >> x[i] >> y[i] >> z[i];
    zsum += z[i];
  }

  vector<vector<ll>>  dp(n+1,vector<ll>(zsum+1, LINF));

  dp[0][0] = 0;
  REP(i,n)REP(j,zsum+1){
    if(dp[i][j]==LINF)continue;


    if(x[i]>y[i]){
      chmin(dp[i+1][j + z[i]],dp[i][j]);
    }else{
      int xx = (y[i]-x[i]+1)/2;
      chmin(dp[i+1][j + z[i]],dp[i][j] + xx);
      chmin(dp[i+1][j],dp[i][j]);
    }
  }
  ll ans=LINF;
  REP(i,n+1)FOR(j,zsum/2+1, zsum+1){
    chmin(ans,dp[i][j]);
  }
  cout << ans << endl;
}

