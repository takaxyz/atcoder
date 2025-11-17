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
  cin >> n >> m;
  vi a(n);
  REP(i,n)cin >> a[i];

  vi a0(n/2),a1((n+1)/2);
  REP(i,n/2)a0[i]=a[i];
  REP(i,(n+1)/2)a1[i]=a[n-1-i];

  auto f = [&](const vi& vs) -> pair<vi,vi> {
    vi used, unused;
    unused.pb(0);

    for(auto x: vs){
      swap(used,unused);
      REP(i,used.size()){
        unused.emplace_back(used[i]);
        used[i] += x;
        used[i] %= m;
      }
    }
    sort(ALL(used));
    sort(ALL(unused));
    return {used, unused};
  };

  auto [used0,unused0] = f(a0);
  auto [used1,unused1] = f(a1);

  ll ans = 0;
  for(auto x: used0){
    int y = (m-x)%m;
    ans += upper_bound(ALL(unused1), y) - lower_bound(ALL(unused1), y);
  }
  for(auto x: unused0){
    int y = (m-x)%m;
    ans += upper_bound(ALL(unused1), y) - lower_bound(ALL(unused1), y);
    ans += upper_bound(ALL(used1), y) - lower_bound(ALL(used1), y);
  }
  cout << ans << endl;

}

