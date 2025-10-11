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
//const ll LINF = 1001001001001001001ll;
const ll LINF = (1LL << 60) - 6846976;

using mint = modint1000000007;
// using mint = modint998244353;

int main(){
  int n;
  ll k;
  ll m;
  cin >> n >> m >> k;

  vector<ll> a(n);
  REP(i,n)cin >> a[i];

  auto f = [&](ll v) -> bool {
    ll cnt = 0;
    for(auto x: a){
      if(x >= v)continue;

      cnt += (v - x + k - 1) / k;
      if(cnt > m)return false;
    }
    return cnt <= m;
  };

  ll ok=0, ng=LINF;

  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }

  vector<ll> b(n);
  REP(i,n){
    if(a[i] >= ok){
      b[i] = a[i];
    }else{
      b[i] = (ok - a[i] + k - 1) / k * k + a[i];
      m -= (ok - a[i] + k - 1) / k;
    }
  }

  priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
  REP(i,n)q.push({b[i],i});
  while(m>0){
    auto [v, i] = q.top();
    q.pop();
    b[i] += k;
    q.push({b[i],i});
    m--;
  }
  for(auto x: b)cout << x << endl;

}


