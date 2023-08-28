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
const int MOD = 1e9 + 7;

int main(){
  ll k,n,m;
  cin >> k >> n >> m;
  vector<ll> a(k);
  REP(i,k)cin >> a[i];


  auto f = [&](ll x) -> bool {
    ll l=0, r=0;
    REP(i,k){
      l += (m*a[i]-x+n-1)/n;
      r += (m*a[i]+x)/n;
    }
    return l <= m && m <= r;
  };

  ll ok=LINF, ng=-1;

  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }

  vector<ll> l(k),r(k);
  ll res=m;
  REP(i,k){
    l[i] = (m*a[i]-ok+n-1)/n;
    r[i] = (m*a[i]+ok)/n;
    res -= l[i];
//    cout << l[i] << " " << r[i] << endl;
  }

  REP(i,k){
    if(res == 0)break;
    if(r[i] - l[i] <= res){
      res -= (r[i]-l[i]);
      l[i]=r[i];
    }else{
      l[i]+=res;
      res=0;
    }
  }
  REP(i,k)cout << l[i] << endl;

}

