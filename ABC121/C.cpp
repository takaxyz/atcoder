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

int main(){
  ll n,m;
  cin >> n >> m;

  vector<pair<ll,ll>> ab(n);
  REP(i,n){
    ll a,b;
    cin >> a >> b;
    ab.emplace_back(make_pair(a,b));
  }
  sort(ALL(ab));

  ll ans=0;
  for(auto v: ab){
    if(m <= v.second){
      ans += v.first * m;
      break;
    }else{
      ans += v.first * v.second;
      m -= v.second;
    }
  }
  cout << ans << endl;
}

