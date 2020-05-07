#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


map<ll, int > prime_factor(ll n) {
  map<ll, int > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main(){
  ll n;
  cin >> n;

  int ans=0;
  for(ll i = 1; i <= n; i+=2){
    map<ll,int> mp = prime_factor(i);
    int x=1;
    for(auto &v: mp){
      x *= (v.second+1);
    }
    if(x==8){
      ans++;
    }
  }
  cout << ans << endl;

}

