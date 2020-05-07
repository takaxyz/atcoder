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
  ll c;
  cin >> n >> c;
  vector<ll> x(n);
  vector<ll> v(n);
  REP(i,n) cin>>x[i]>>v[i];

  vector<ll> r(n),l(n);

  ll t = 0;
  REP(i,n){
    if(i==0){ 
      t += v[i] - x[i];
      r[i] = t;
    }else{
      t += v[i] - (x[i]-x[i-1]);
      r[i] = max(t,r[i-1]);
    }
  } 
  t = 0;
  for(int i=n-1;i>=0; i--){
    if(i==n-1){ 
      t += v[i] - (c-x[i]);
      l[i] = t;
    }else{
      t += v[i] - (x[i+1]-x[i]);
      l[i] = max(t,l[i+1]);
    }
  }


  ll ans=0;

  ans = max(r[n-1],ans);
  ans = max(l[0],ans);

  REP(i,n-1){
    ans = max(ans, r[i]+l[i+1]-x[i]);
  }
  FOR(i,1,n){
    ans = max(ans, l[i]+r[i-1]-(c-x[i]));
  }

  cout << ans << endl;
}

