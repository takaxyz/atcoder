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
 
int main(){
  int n,k;
  cin >> n >> k;
 
  VI a(n);
  REP(i,n)cin >> a[i];
 
  int mx = a[0];
  int cnt=1;
  FOR(i,1,n){
    if(mx < a[i]){
      mx = a[i];
      cnt++;
    }
  }
 
  if(k<=cnt){
    cout << 0 << endl;
    return(0);
  }
 
  ll ans=INF;
  REP(i,(1<<n)){
    mx = a[0];
    cnt = 1;
    ll cost = 0;
    FOR(j,1,n){
      if(cnt==k)break;
 
      if(mx < a[j]){
        cnt++;
        mx = a[j];
        continue;
      }
      if((i>>j)&1){
        if(mx >= a[j]){
          cost += mx - a[j] + 1;
          mx++;
          cnt++;          
        }
      }
    }
 
    if(cnt>=k)chmin(ans, cost);
  }
 
  cout << ans << endl;
}