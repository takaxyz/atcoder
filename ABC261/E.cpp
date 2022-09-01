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
const int MOD = 1e9 + 7;

int main(){
  int n;
  ll c;
  cin >> n >> c;
  vi t(n);
  vector<ll> a(n);
  REP(i,n)cin >> t[i] >> a[i];

  vector<ll> ans(n);
  REP(i,30){
    int cur = c>>i & 1;

    array<int, 2> f = {0,1};

    REP(j,n){
      cur = f[cur];

      int p = a[j]>>i & 1;
      if(t[j]==1){
        //and
        cur &= p;
        f[0] &= p;
        f[1] &= p;
      }else if(t[j]==2){
        //or
        cur |= p;
        f[0] |= p;
        f[1] |= p;
      }else{
        //xor
        cur ^= p;
        f[0] ^= p;
        f[1] ^= p;
      }
      ans[j] += cur<<i;
    }
  }

  for(auto v: ans){
    cout << v << endl;
  }
}


