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

int f(int b, ll n){

  ll ok=1, ng=n+1;

  auto ck = [&](ll x) -> bool {
    ll a = x;
    REP(i,b-1){
      if(a > n / x)return false;
      a *= x;
    }
    return a <= n;
  };


  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(ck(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  return ok-1;

}

int main(){
  ll n;
  cin >> n;

  ll ans=1;
  vector<ll> F(60);

  for(int b = 59; b >= 2; b--){
    F[b] = f(b, n);
    for(int i = b*2; i < 60; i+=b)F[b] -= F[i];
    ans += F[b];
  }

  cout << ans << endl;

}

