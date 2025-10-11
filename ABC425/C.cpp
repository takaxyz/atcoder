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
  int n,q;
  cin >> n >> q;
  vector<ll> a(n),s(n+1);
  REP(i,n)cin >> a[i];
  REP(i,n)s[i+1] = s[i]+a[i];

  ll v=0;
  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int c;
      cin >> c;
      v+=c;
    }else{
      ll l,r;
      cin >> l >> r;
      l--; r--;
      l += v; l %= n;
      r += v; r %= n;
      if(r>=l){
        cout << s[r+1] - s[l] << endl;
      }else{
        cout << s[n] - s[l] + s[r+1] << endl;
      }
    }
  }
}

