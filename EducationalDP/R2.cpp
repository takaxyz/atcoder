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

using mint = modint1000000007;
using mtx = vector<vector<mint>>;

int main(){
  int n;
  ll k;
  cin >> n >> k;

  vvi a(n,vi(n));
  REP(i,n)REP(j,n)cin >> a[i][j];

  auto mul = [&](mtx& s, mtx& t) -> mtx {
    vector<vector<mint>> ret(n,vector<mint>(n,0));
    int sz = s.size();
    REP(i,sz)REP(j,sz)REP(k,sz){
      ret[i][j] += s[i][k] * t[k][j]; 
    }
  return ret;
  };

  vector<vector<mint>> y(n,vector<mint>(n,0));
  REP(i,n)y[i][i]=1;

  vector<vector<mint>> x(n,vector<mint>(n,0));
  REP(i,n)REP(j,n)x[i][j]=a[i][j];
  while(k>0){
    if(k & 1)y = mul(y,x);
    x = mul(x,x);
    k /= 2;
  }

  mint ans=0;
  REP(i,n)REP(j,n){
    ans += y[i][j];
  }
  cout << ans.val() << endl;
}

