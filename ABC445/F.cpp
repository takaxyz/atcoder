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

vector<vector<ll>> calc(const vector<vector<ll>>& a, const vector<vector<ll>>& b){
  int n = a.size();
  vector<vector<ll>> res(n,vector<ll>(n,LINF));

  REP(i,n)REP(j,n)REP(k,n){
    chmin(res[i][k], a[i][j] + b[j][k]);
  }
  return res;
}


int main(){
  int n,k;
  cin >> n >> k;
  vector c(n,vector<ll>(n));

  REP(i,n)REP(j,n)cin >> c[i][j];

  vector d(31,vector(n,vector<ll>(n)));
  d[0] = c;

  FOR(i,1,31){
    d[i] = calc(d[i-1],d[i-1]);
  }

  vector ans(vector(n,vector<ll>(n,LINF)));
  REP(i,n)ans[i][i]=0;

  REP(i,31){
    if((k >> i) & 1){
      ans = calc(ans, d[i]);
    }
  }

  REP(i,n)cout << ans[i][i] << endl;

}

