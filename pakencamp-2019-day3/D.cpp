#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

// dp_ij: i列目がj色（R:0, B:1, W:2）になる最小の塗り替えるマス

int dp[1000][3];


int main(){
  int n;
  cin >> n;

  vector<vector<char>> s(5, vector<char>(n+1));

  REP(i,5)REP(j,n)cin >> s[i][j+1];

  FOR(i,1,n+1){
    int cnt_r=0;
    int cnt_b=0;
    int cnt_w=0;
    REP(j,5){
      if(s[j][i]=='R')cnt_r++;
      else if(s[j][i]=='B')cnt_b++;
      else if(s[j][i]=='W')cnt_w++;
    }

    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + 5-cnt_r;
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + 5-cnt_b;
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + 5-cnt_w;
  }

  cout << min(dp[n][0], min(dp[n][1],dp[n][2])) << endl;

  // REP(i,n+1)REP(j,3){
  //   cout << dp[i][j] << (j==2 ? "\n" : " ");
  // }
}

