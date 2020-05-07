#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

ll dp[100][21];
int a[105];

int main(){
  int n;
  cin >> n;


  REP(i,n)cin >> a[i];

  dp[0][a[0]]=1;

  FOR(i,1,n-1){
    REP(j,21){
      if(j+a[i]<=20)dp[i][j+a[i]] += dp[i-1][j];
      if(j-a[i]>=0)dp[i][j-a[i]] += dp[i-1][j];
    }
  }

  cout << dp[n-2][a[n-1]] << endl;
}

