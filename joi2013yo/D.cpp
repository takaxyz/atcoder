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

int d,n;

// dp_ij : i日目に服jを選んだ際の派手さの絶対値の合計
int dp[201][201];
int a[201], b[201], c[201];
int t[201];

int main(){
  cin >> d >> n;

  REP(i,d)cin >> t[i+1];

  REP(i,n){
    cin >> a[i] >> b[i] >> c[i];
  }

  FOR(i,1,d+1)REP(j,n)dp[i][j]=-1;

  FOR(i,1,d+1){
    REP(j,n){
      if(a[j] <= t[i] && t[i] << b[j]){
        REP(k,n){
          if(dp[i-1][k]!=-1)dp[i][j] += dp[i-1][k] + abs(c[k]-c[j]);
        }
      }
    }
  }

  REP(i,n){
    cout << dp[n-1][i] << endl;
  }
}

