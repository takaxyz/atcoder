#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int n;
  ll T;
  cin >> n >> T;

  vector<ll> t(n);
  REP(i,n)cin>>t[i];

  ll ans=0;
  FOR(i,1,n){
    if(t[i]-t[i-1] >= T){
      ans += T;
    }else{
      ans += t[i]-t[i-1];
    }
  }
  ans += T;

  cout << ans << endl;

}

