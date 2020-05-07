#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e18;
const int INF=(1<<30);

int main(){
  int N;
  cin >> N;
  vector<int> a(N),b(N),c(N);
  REP(i,N){
    cin >> a[i] >> b[i] >> c[i];
  }

  vector<int> dp(3,0);

  REP(i,N){
    int s,t,u;
    s = max(dp[1]+a[i], dp[2]+a[i]);
    t = max(dp[0]+b[i], dp[2]+b[i]);
    u = max(dp[0]+c[i], dp[1]+c[i]);
    dp[0]=s;dp[1]=t;dp[2]=u;
  }

  cout << max(dp[0],max(dp[1],dp[2])) << endl;
}

