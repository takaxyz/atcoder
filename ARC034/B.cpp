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
//const int INF=(1<<29);

int main(){
  ll n;
  cin >> n;

  vector<ll> ans;

  for(ll i = max(1LL, n - 9*19); i < n; i++){
    ll t=i;
    ll s=0;
    while(t>0){
      s += t%10;
      t /= 10;
    }
    if(i+s == n)ans.emplace_back(i);
  }

  cout << ans.size() << endl;
  REP(i,ans.size()){
    cout << ans[i] << endl;
  }


}

