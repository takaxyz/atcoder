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

vector<ll> get_divisor(ll n){
  vector<ll> ret;

  for(ll i = 1; i*i <= n; i++){
    if(n%i==0){
      ret.push_back(i);
      if(i*i != n) ret.push_back(n/i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int main(){
  ll n;
  cin >> n;

  int ans = get_divisor(n-1).size() -1;

  vector<ll> l = get_divisor(n);

  for(auto &v: l){
    if(v==1)continue;
    ll m = n;
    while(m > 1 && m >= v){
      if(m%v==0){
        m/=v;
      }else{
        m%=v;
      }
    }
    if(m==1)ans++;
  }

  cout << ans << endl;
}

