#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

void print_lcs(string &s, string &t, vector<vector<int>> &dp, int i, int j){
  if(i==-1 || j==-1)return;

  if(s[i] == t[j]){
    print_lcs(s,t,dp,i-1,j-1);
    cout << s[i];
  }else if(dp[i+1][j] > dp[i][j+1]){
    print_lcs(s,t,dp,i,j-1);
  }else{
    print_lcs(s,t,dp,i-1,j);
  }
}

int main(){
  string s, t;
  cin >> s;
  cin >> t;

  vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));

  REP(i,s.size())REP(j,t.size()){
    if(s[i]==t[j]){
      dp[i+1][j+1] = dp[i][j]+1;
    }else{
      dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
    }
  }

  print_lcs(s,t,dp,s.size()-1,t.size()-1);
  cout << endl;
}

