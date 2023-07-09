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
  int n,m;
  ll d;
  cin >> n >> m >> d;
  vector<ll> a(n), b(m);
  REP(i,n)cin >> a[i];
  REP(i,m)cin >> b[i];
  sort(ALL(b));

  ll ans = -1;
  REP(i,n){
    auto it = lower_bound(ALL(b), a[i]-d);
    if(it != a.end() && abs(a[i]- *it) <= d){
      chmax(ans, a[i] + *it);
    }

    it = upper_bound(ALL(b), a[i]+d);
    it--;
    if(abs(a[i]- *it) <= d){
      chmax(ans, a[i] + *it);
    }

  }
  cout << ans << endl;
}

