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
  vector<ll> a(n);
  REP(i,n)cin >> a[i];

  vector<ll> len(n+1), sum1(n+1), sum2(n+1);

  REP(i,n)sum1[i+1] = sum1[i] + a[i];
  REP(i,n)sum2[i+1] = sum2[i] + sum1[i+1];

  REP(i,n){
    len[i+1] = len[i] + (i+1);
  }

  auto f = [&](ll x) -> ll{
    int i = upper_bound(ALL(len), x) - len.begin();
    i--;
    return sum2[i] + sum1[x -len[i]];
  };

  REP(_,q){
    ll l,r;
    cin >> l >> r;
    cout << f(r) - f(l-1) << endl;
  }
}

