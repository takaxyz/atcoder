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

//using mint = modint1000000007;
using mint = modint998244353;

struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

int main(){
  int n;
  cin >> n;

  combination comb(n+1);

  vvi cand(n+1);
  vi l(n),r(n);

  REP(i,n){
    cin >> l[i] >> r[i];

    cand[l[i]].pb(i);
    cand[r[i]+1].pb(i);
    cand[n-r[i]].pb(i);
    cand[n-l[i]+1].pb(i);
  }

  vi cnt(n);
  cnt[0]=n;

  auto f = [&](int x, int i){
    int ret = 0;

    if(l[i] <= x && x <= r[i])ret |= 1;
    if(n - r[i] <= x && x <= n - l[i])ret |= 2;
    return ret;
  };

  mint ans = 0;

  vi s(n);

  FOR(i,1,n){

    for(auto j: cand[i]){
      cnt[s[j]]--;
      s[j] = f(i, j);
      cnt[s[j]]++;
    }


    if(cnt[0] > 0)continue;
    if(cnt[1] > i)continue;
    if(cnt[2] > n - i)continue;

    ans += comb(cnt[3], i - cnt[1]);
  }

  cout << ans.val() << endl;

}

