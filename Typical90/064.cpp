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
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), s(n-1);
  REP(i,n)cin >> a[i];
  REP(i,n-1)s[i] = a[i+1]-a[i];

  ll ans=0;
  REP(i,n-1)ans+=abs(s[i]);

  REP(_,q){
    int l, r;
    ll v;
    cin >> l >> r >> v;
    l--; r--;
    if(l > 0){
      ans -= abs(s[l-1]);
      s[l-1] += v;
      ans += abs(s[l-1]);
    }
    if(r < n-1){
      ans -= abs(s[r]);
      s[r] -= v;
      ans += abs(s[r]);
    }
    cout << ans << endl;
  }
}

