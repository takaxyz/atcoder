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
  int n,k;
  cin >> n >> k;

  vector<ll> l,r;

  REP(i,n){
    ll x;
    cin >> x;
    if(x<0){
      l.emplace_back(-x);
    }else if(x>0){
      r.emplace_back(x);
    }else{
      k--;
    }
  }
  reverse(ALL(l));
  if(k==0){
    cout << 0 << endl;
    return(0);
  }
  
  if(l.size()==0){
    cout << r[k-1] << endl;
    return(0);
  }
  if(r.size()==0){
    cout << l[k-1] << endl;
    return(0);
  }

  ll ans = INF;
  for(int li = 1; li <= k && li <= l.size(); li++){
    int ri = k-li;
    if(ri > r.size())continue;
    ans=min(ans,l[li-1]*2+r[ri-1]);
  }
  for(int ri = 1; ri <= k && ri <= r.size(); ri++){
    int li = k-ri;
    if(li > l.size())continue;
    ans=min(ans,r[ri-1]*2+l[li-1]);
  }
  cout << ans << endl;
}

