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
  int n,m;
  cin >> n >> m;
  vector<ll> s(n+1,0);
  REP(i,n){
    int a;
    cin >> a;
    s[i+1] = s[i] + a;
  }

  map<int, ll> mp;
  REP(i,n+1)mp[s[i]%m]++;

  ll ans=0;
  for(auto &v: mp){
    ans += v.second * (v.second-1) / 2;
  }
  cout << ans << endl;

}

