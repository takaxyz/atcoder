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

int main(){
  int n;
  ll x;
  cin >> n >> x;
  vi a(n),b(n);
  vector<ll> p(n),q(n);
  REP(i,n)cin >> a[i] >> p[i] >> b[i] >> q[i];

  auto f = [&](ll v) {
    ll sum = 0;
    //printf("v = %lld\n",v);
    REP(i,n){
      ll cost = LINF;

      REP(j,b[i]){
        ll k = (max(0LL,v - j * a[i]) + b[i] - 1)/b[i];
        chmin(cost, p[i]*j + q[i]*k);
      }

      REP(j,a[i]){
        ll k = (max(0LL,v - j * b[i]) + a[i] - 1)/a[i];
        chmin(cost, q[i]*j + p[i]*k);
      }

      sum += cost;
    }
    return sum <= x;
  };

  ll ok=0, ng=10000000000ll;


  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }

  cout << ok << endl;

}

