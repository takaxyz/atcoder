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

const ll INF=(ll)1e18;
//const int INF=(1<<30);

vector<ll> s;
vector<ll> t;

ll solve(ll x){
  auto sr = upper_bound(ALL(s),x);
  auto tr = upper_bound(ALL(t),x);

  ll ret = INF;

  chmin(ret, max(*sr - x,*tr - x));
  chmin(ret, max(x - *(sr-1),x - *(tr-1)));

  chmin(ret, 2*(*sr - x) + x - *(tr - 1));
  chmin(ret, 2*(x - *(sr-1)) + *tr - x);
  chmin(ret, 2*(*tr - x) + x - *(sr - 1));
  chmin(ret, 2*(x - *(tr-1)) + *sr - x);

  return ret;
}


int main(){
  int a,b,q;
  cin >> a >> b >> q;

  s.resize(a+2);
  t.resize(b+2);
  s[0] = t[0] = -INF;
  s[a+1] = t[b+1] = INF;

  REP(i,a)cin >> s[i+1];
  REP(i,b)cin >> t[i+1];

  REP(i,q){
    ll x;
    cin >> x;
    cout << solve(x) << endl;
  }

}

