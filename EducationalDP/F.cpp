#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int dp[3001][3001];

void print_lcs(string &s, string &t, int i, int j){
  if(i == 0 || j == 0){
    return;
  }

  if(s[i-1] == t[j-1]){
    print_lcs(s,t,i-1,j-1);
    cout << s[i-1];
  }else{
    if(dp[i-1][j] >= dp[i][j-1]){
      print_lcs(s,t,i-1,j);
    }else{
      print_lcs(s,t,i,j-1);
    }
  }
}

int main(){
  string s, t;
  cin >> s;
  cin >> t;

  REP(i,3001)REP(j,3001)dp[i][j] = 0;

  FOR(i,1,s.size()+1)FOR(j,1,t.size()+1){
    if(s[i-1] == t[j-1]){
      MAXS(dp[i][j], dp[i-1][j-1]+1);
    }else{
      MAXS(dp[i][j], dp[i-1][j]);
      MAXS(dp[i][j], dp[i][j-1]);
    }
  }

  print_lcs(s,t,s.size(),t.size());
  cout << endl;
}