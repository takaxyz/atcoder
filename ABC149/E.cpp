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
  int n;
  ll m;
  cin >> n >> m;

  vi a(n);
  REP(i,n)cin >> a[i];
  sort(ALL(a));

  vector<ll> s(n+1);
  REP(i,n)s[i+1] = s[i] + a[i];

  auto check = [&](int x) {
    ll tot=0, num=0;
    REP(i,n){
      int y = x - a[i];
      int j = lower_bound(ALL(a), y) - a.begin();
      num += n-j;
      tot += (ll)a[i] * (n-j);
      tot += s[n]-s[j];
    }
    return make_pair(num, tot);
  };

  int ok=0, ng=INF;
  while(abs(ok-ng)>1){
    int mid = (ok+ng)/2;

    if(check(mid).first>=m){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  ll ans = check(ok).second;
  ans -= (check(ok).first - m)*ok;
  cout << ans << endl;

}

