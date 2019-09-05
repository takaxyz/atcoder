#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007LL

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

ll dp[100005][13];

int main(){
  string s;
  cin >> s;

  REP(i,100005)REP(j,13)dp[i][j]=0;

  dp[0][0] = 1;

  int l = 1;
  REP(i,s.size()){
    char c = s[s.size()-i-1];

    if(c=='?'){
      REP(k,10){
        int m = k * l % 13;
        REP(j,13){
          int mm = (j + m) % 13;
          dp[i+1][mm] += dp[i][j];
          dp[i+1][mm] %= MOD;
        }
      }

    }else{
      int m = (c - '0') * l % 13;
      REP(j,13){
        int mm = (j + m) % 13;
        dp[i+1][mm] += dp[i][j];
        dp[i+1][mm] %= MOD;
      }
    }


    l = l * 10 % 13;
  }
  
  printf("%lld\n", dp[s.size()][5]);
}