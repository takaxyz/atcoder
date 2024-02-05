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

using mint = modint1000000007;

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h)cin >> s[i];

  vector<vector<mint>> dp(h,vector<mint>(w));
  vector<vector<mint>> dps1(h,vector<mint>(w)); // 縦
  vector<vector<mint>> dps2(h,vector<mint>(w)); // 横
  vector<vector<mint>> dps3(h,vector<mint>(w)); // 斜め

  dp[0][0]=1;
  dps1[0][0]=1;
  dps2[0][0]=1;
  dps3[0][0]=1;

  REP(i,h)REP(j,w){
    if(i+j==0)continue;

    if(s[i][j]=='.'){
      if(i>0)dp[i][j] += dps1[i-1][j];
      if(j>0)dp[i][j] += dps2[i][j-1];
      if(i>0 && j > 0)dp[i][j] += dps3[i-1][j-1];

      if(i==0){
        dps1[i][j] = dp[i][j];
      }else{
        dps1[i][j] = dps1[i-1][j] + dp[i][j];
      }
      if(j==0){
        dps2[i][j] = dp[i][j];
      }else{
        dps2[i][j] = dps2[i][j-1] + dp[i][j];
      }
      if(i>0 && j > 0){
        dps3[i][j] = dps3[i-1][j-1] + dp[i][j];
      }else{
        dps3[i][j] = dp[i][j];
      }
    }else{
      dp[i][j]=0;
      dps1[i][j]=0;
      dps2[i][j]=0;
      dps3[i][j]=0;
    }
  }
  cout << dp[h-1][w-1].val() << endl;
}

