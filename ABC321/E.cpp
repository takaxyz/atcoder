#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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

void solve(){
  ll n,x,k;
  cin >> n >> x >> k;

  auto f = [&](ll v, ll d) -> ll{
    if(v>n)return 0;
    ll l = v, r = v;

    REP(_, d){
      l <<= 1;
      r = r<<1|1;
      //r++;
      if(l > n)return 0;
    }

    chmin(r, n);

    //printf("%lld %lld: %lld\n",v,d,r-l+1);
    return r - l + 1;
  };

  ll ans = f(x,k);
  while(x > 1 && k >= 2){
    ans += f(x^1, k- 2);
    k--;
    x >>= 1;
  }

  if(k == 1 && x != 1)ans++;

  cout << ans << endl;
}





int main(){
  int t;
  cin >> t;
  REP(_,t){
    solve();
  }
}

