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
  int n, d;
  cin >> n >> d;

  vi x(n), y(n);
  REP(i,n)cin >> x[i] >> y[i];
  sort(ALL(x));
  sort(ALL(y));

  const int MAX = 1000000;

  auto f = [&](vi& v){
    vector<ll> ret;

    ll dist = 0;
    REP(i,n)dist += abs(v[i]+MAX*2);
    ret.pb(dist);
    //printf("%d: %lld %d\n", -MAX*2, dist, 0);

    int k = 0;
    for(int i = -MAX*2+1; i <= MAX*2; i++){
      dist += (2*k-n);
      //printf("%d: %lld %d\n", i, dist, k);
      ret.pb(dist);
      while(k < n && v[k] <= i)k++;
    }
    return ret;
  };

  vector<ll> a = f(x);
  vector<ll> b = f(y);
  sort(ALL(a));
  sort(ALL(b));

  int j = b.size()-1;
  ll ans = 0;
  REP(i,a.size()){
    while(j >= 0 && a[i]+b[j] > d)j--;
    ans += j + 1;
    //printf("%d : %lld\n", i, ans);
  }

  cout << ans << endl;


}

