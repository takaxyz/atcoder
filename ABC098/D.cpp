#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  REP(i,n)cin >> a[i];

  ll ans=0;
  int r=0;
  int l=0;
  ll t=0;
  while(r < n){
    if( (t + a[r]) == (t ^ a[r])){
      t += a[r];
      ans += r-l+1;
      r++;
    }else{
      t -= a[l];
      l++;
    }
  }
  cout << ans << endl;
}

