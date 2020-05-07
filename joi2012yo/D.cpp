#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 10000

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int dp[101][3][3];
int p[101];

int main(){
  int n,k;
  cin >> n >> k;

  REP(i,n+1)p[i]=-1;

  REP(i,k){
    int a,b;
    cin >> a >> b;
    p[a] = --b;
  }

  // day1-2
  REP(i,3){
    if(p[1] == -1 || p[1] == i ){
      REP(j,3){
        if(p[2] == -1 || p[2]==j){
          dp[2][j][i]=1;
        }
      }
    }
  }

  FOR(i,3,n+1){
    REP(j,3){
      if(p[i]==-1 || p[i] == j){
        REP(k,3)REP(l,3){
          if(j==k && k==l)continue;
          dp[i][j][k] += dp[i-1][k][l];
          dp[i][j][k] %= MOD;
        }
      }
    }
  }

  // FOR(l,2,n+1)REP(i,3)REP(j,3){
  //   printf("%d : %d %d: %d\n", l, i,j, dp[l][i][j]);
  // }

  int ans = 0;
  REP(i,3)REP(j,3){
    ans+=dp[n][i][j];
    ans%=MOD;
  }

  cout << ans << endl;

}

