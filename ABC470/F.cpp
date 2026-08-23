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
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  dsu uf(n);
  REP(_,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    uf.merge(a,b);
  }

  vector cnt(n, map<char,int>());

  bool flag=false;

  REP(i,n){
    cnt[uf.leader(i)][s[i]]++;
    if(cnt[uf.leader(i)][s[i]] >= 2)flag=true;
  }

  combination comb(n+1);
 
  mint ans=1;
  REP(i,n){
    if(cnt[i].size()==0)continue;

    int sz = uf.size(i);
    for(auto [k,v]: cnt[i]){
      ans *= comb(sz, v);
      sz -= v;
    }
  }

  if(!flag)ans /= 2;
  cout << ans.val() << endl;

}

