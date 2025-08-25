#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;

using mint = modint1000000007;
// using mint = modint998244353;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll count(vector<pair<ll,ll>>& vs){
  ll ret = 0;

  int l = 0,r=0;
  while(l < vs.size()){
    while(r < vs.size() && vs[l] == vs[r])r++;
    ll len = r - l;
    ret += len * (len-1) / 2;
    l = r;
  }
  return ret;
}


int main(){
  int n;
  cin >> n;
  vector<ll> x(n), y(n);
  REP(i,n)cin >> x[i] >> y[i];

  vector<pair<ll,ll>> vs1;
  REP(i,n)FOR(j,i+1,n){
    ll dx = x[j]-x[i];
    ll dy = y[j]-y[i];

    if(dx == 0){
      dx = 0;
      dy = 1;
    }else if(dy == 0){
      dx = 1;
      dy = 0;
    }else{
      if(dx < 0){
        dx = -dx;
        dy = -dy;
      }

      ll g = gcd(abs(dx),abs(dy));

      dx /= g;
      dy /= g;
    }
    vs1.emplace_back(dx,dy);
  }
  sort(ALL(vs1));

  ll ans = count(vs1);

  vector<pair<ll,ll>> vs2;
  REP(i,n)FOR(j,i+1,n){
    vs2.pb({x[i]+x[j], y[i]+y[j]});
  }
  sort(ALL(vs2));

  ans -= count(vs2);

  cout << ans << endl;

}

