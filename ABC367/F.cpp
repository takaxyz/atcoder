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

const ll MOD =  (1LL << 61) - 1;

int main(){
  int n,q;
  cin >> n >> q;

  vi a(n),b(n);
  REP(i,n)cin >> a[i];
  REP(i,n)cin >> b[i];

  int const MAX = 200005; 
  vector<ll> t(MAX), sa(n+1),sb(n+1);

  random_device seed_gen;
  mt19937_64 rnd(seed_gen());

  uniform_int_distribution<ll> d(1, (1LL<<62));

  REP(i,MAX)t[i] =  d(rnd);

  REP(i,n)sa[i+1] = (sa[i] + t[a[i]]) % MOD;
  REP(i,n)sb[i+1] = (sb[i] + t[b[i]]) % MOD;

  while(q--){
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    l1--; l2--;

    cout << ((sa[r1]-sa[l1] + MOD) % MOD == (sb[r2] - sb[l2] + MOD) % MOD ? "Yes" : "No") << endl;
  }

}

