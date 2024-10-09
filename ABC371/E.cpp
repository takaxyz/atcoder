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
  ll n;
  cin >> n;
  vi a(n);
  vvi p(n+1);

  REP(i,n){
    cin >> a[i];
    p[a[i]].pb(i);
  }

  ll ans = 0;
  for(auto v: p){
    if(v.size()==0)continue;

    ans += n * (n+1) / 2;
    REP(i,v.size()){
      if(i==0){
        ll x = v[i];
        ans -= x * (x+1)/2;
      }
      if(i != v.size()-1){
        ll x = v[i+1] - v[i] - 1;
        ans -= x * (x+1)/2;
      }else{
        ll x = n - v[i] - 1;
        ans -= x * (x+1)/2;
      }
    }
  }
  cout << ans << endl;

}

