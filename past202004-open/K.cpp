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
  string s;
  cin >> n >> s;
  vi c(n),d(n);
  REP(i,n)cin >> c[i];
  REP(i,n)cin >> d[i];

  vector<vector<ll>> dp(n+1, vector<ll>(n+1, LINF));

  dp[0][0]=0;

  REP(i,s.size()){
    if(s[i]=='('){
      REP(j,i+1){
        if(dp[i][j]==LINF)continue;
        // そのまま
        chmin(dp[i+1][j+1],dp[i][j]);
        // 取り除く
        chmin(dp[i+1][j],dp[i][j]+d[i]);
        // 反転
        if(j > 0)chmin(dp[i+1][j-1],dp[i][j]+c[i]);
      }
    }else{
      REP(j,i+1){
        if(dp[i][j]==LINF)continue;
        // そのまま
        if(j>0)chmin(dp[i+1][j-1],dp[i][j]);
        // 取り除く
        chmin(dp[i+1][j],dp[i][j]+d[i]);
        // 反転
        chmin(dp[i+1][j+1],dp[i][j]+c[i]);
      }
    }
  }

  // REP(i,n+1)REP(j,n+1){
  //   printf("%d %d: %ld\n",i,j,dp[i][j]);
  // }
  PRINT(dp[n][0]);
}

