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
  vector<ll> a(n), b(n);
  
  REP(i,n)cin >> a[i] >> b[i];

  ll ans=0;
  REP(i,n)ans+=abs(b[i]-a[i]);

  sort(ALL(a));
  sort(ALL(b));

  ll ma,mb;
  if(n%2==0){
    ma = (a[n/2] + a[n/2-1])/2;
    mb = (b[n/2] + b[n/2-1])/2;
  }else{
    ma = a[n/2];
    mb = b[n/2];
  }
  REP(i,n){
    ans+=abs(ma-a[i]);
    ans+=abs(mb-b[i]);
  }
  cout << ans << endl;

}

