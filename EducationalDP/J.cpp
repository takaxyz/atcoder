#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<iomanip>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
#define MAXS(x,y) (x = max(x,y))
#define MINS(x,y) (x = min(x,y))

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int N;
double dp[301][301][302];

int main(){
  cin >> N;

  vector<int> a(N);
  REP(i,N) cin >> a[i];

  dp[0][0][0] = 0.0;
  map<int, int> m;
  REP(i,N){
    m[a[i]] += 1;
  }


  REP(i,N+1)REP(j,N+1)REP(k,N+1){
    if(i == 0 && j == 0 && k ==0)continue;
    if(i + j + k > N )continue;

    int res = N;
    double p = 1.0;

    if(i > 0){
      p += dp[i-1][j+1][k] * i / N;
      res -= i;
    }

    if(j > 0){
      p += dp[i][j-1][k+1] * j / N;
      res -= j;
    }

    if(k > 0){
      p += dp[i][j][k-1] * k / N;
      res -= k;
    }

    dp[i][j][k] = p * N / (N-res);
  }


  cout << setprecision(10) << dp[m[3]][m[2]][m[1]] << endl;
}