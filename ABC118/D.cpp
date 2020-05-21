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

//const ll INF=(ll)1e19;
const int INF=(1<<30);

int M[10] = {0,2,5,5,4,5,6,3,7,6};
 
int main(){
  int n,m;
  cin >> n >> m;

  VI a(m);
  REP(i,m)cin >> a[i];
  sort(a.rbegin(), a.rend());
  // dp[i]: i本で作れる桁数
  vector<int> dp(n+1,-1);
  dp[0]=0;

  REP(i,n){
    REP(j,m){
      if(i+M[a[j]] <= n && dp[i+M[a[j]]] < dp[i]+1){
        dp[i+M[a[j]]] = dp[i]+1;
      }
    }
  }

  // REP(i,n+1){
  //   cout << i << " " << dp[i] << endl;
  // }

  VI ans;
  for(int i=n; i> 0; ){
    REP(j,m){
      if(i-M[a[j]] >= 0 && dp[i] == dp[i-M[a[j]]] + 1){
        ans.emplace_back(a[j]);
        i -= M[a[j]];
        break;
      }
    }
  }
  for(auto v: ans)cout << v;
  cout << endl;
}

