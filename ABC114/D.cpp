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

  map<ll,int> pf;
  FOR(i,1,n+1){
    map<ll,int> mp = prime_factor(i);
    for(auto v: mp){
      pf[v.first] += v.second;
    }
  }

  int cnt74,cnt24, cnt14, cnt4, cnt2;
  cnt74 = cnt24 = cnt14 = cnt4 = cnt2 = 0;
  for(auto v: pf){
    if(v.second >= 2)cnt2++;
    if(v.second >= 4)cnt4++;
    if(v.second >= 14)cnt14++;
    if(v.second >= 24)cnt24++;
    if(v.second >= 74)cnt74++;
  }

  int ans = 0;
  ans += cnt74;
  ans += cnt24 * (cnt2 - 1);
  ans += cnt14 * (cnt4 - 1);
  ans += cnt4 * (cnt4-1) / 2 * (cnt2 - 2);

  cout << ans << endl;
}

// 75 = 5 * 5 * 3, 25 * 3, 15 * 5