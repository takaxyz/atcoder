#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 10007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int n;
  cin >> n;

  vector<vector<int>> dp(n, vector<int>(8,0));
  vector<int> s;

  REP(i,n){
    char c;
    cin >> c;
    if(c=='J')s.emplace_back(0);
    else if(c=='O')s.emplace_back(1);
    else s.emplace_back(2);
  }

  REP(i,8){
    if(((1<<s[0]) & i) && (i & 1)){
      dp[0][i]=1;
    }
  }

  FOR(i,1,n){
    REP(j,8){
      if(((1<<s[i]) & j) == 0){
        dp[i][j] = 0;
      }else{
        REP(k,8){
          if((j&k) != 0){
            dp[i][j] += dp[i-1][k];
            dp[i][j] %= MOD;
          }
        }
      }
    }

  }


  int ans = 0;
  REP(i,8){
    ans += dp[n-1][i];
    ans %= MOD;
  }

  cout << ans << endl;

}


