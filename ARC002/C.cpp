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
//const int INF=(1<<29);
int N;

int solve(string l, string r, string s){
  VI dp(N+1, (1<<29));

  dp[0]=0;
  dp[1]=1;
  FOR(i,2,N+1){
    chmin(dp[i], dp[i-1]+1);
    if(s.substr(i-2,2) == l || s.substr(i-2,2) == r){
      chmin(dp[i], dp[i-2]+1);
    }
  }
  return dp[N];
}

int main(){
  cin >> N;
  string c;
  cin >> c;

  string s = "ABXY";

  int ans=(1<<30);
  REP(i,4)REP(j,4)REP(k,4)REP(l,4){
    string L = string(1,s[i]) + string(1,s[j]);
    string R = string(1,s[k]) + string(1,s[l]);
    chmin(ans, solve(L,R,c));
  }
  cout << ans << endl;
}

