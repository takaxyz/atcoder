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
  int n,m;
  ll k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  REP(i,n)cin >> a[i];

  if(n==m){
    REP(i,n)cout << 0 << (i==n-1 ? "\n" : " ");
    return 0;
  }


  vector<ll> b = a;
  sort(ALL(b));

  vector<ll> s(n+1);
  REP(i,n)s[i+1] = s[i] + b[i];

  ll rem = k - s[n];

  map<int,ll> ans;

  auto f = [&](int i, ll x){
    int l = n - m;
    int r = upper_bound(ALL(b), b[i]+x+1) - b.begin();

    if(r<l)return false;
    ll need = (b[i]+x+1)*(r-l) - (s[r] - s[l]);

    if(l <= i && i < r){
      need += b[i];
      need -= b[l-1];
    }

    //printf("%lld %lld %lld %lld\n", b[i], x, need, rem);

    return need > rem - x;
  };


  REP(i,n){
    ll ok=rem+1, ng=-1;

    while(abs(ok-ng)>1){
      ll mid = (ok+ng)/2;
      if(f(i,mid)){
        ok=mid;
      }else{
        ng=mid;
      }
    }

    if(ok == rem+1)ans[b[i]]=-1;
    else ans[b[i]]=ok;
  }

  REP(i,n)cout << ans[a[i]] << (i==n-1 ? "\n" : " ");
}

