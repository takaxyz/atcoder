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
  int h,r;
  cin >> h >> r;
  vvi g(r,vi(r));
  REP(i,r)REP(j,r)cin >> g[i][j];

  vector<vector<mint>> m(r, vector<mint>(r));

  REP(s,r){
    vector<vector<mint>> dp((1<<r),vector<mint>(r));
    dp[(1<<s)][s]=1;

    REP(ss, (1<<r)){
      REP(i, r){
        if(((ss>>i) & 1) == 0)continue;

        REP(j,r){
          if(g[i][j]==0)continue;
          if(((ss>>j) & 1) == 1)continue;
          dp[ss | (1<<j)][j] += dp[ss][i];
        }
      }
    }

    REP(t,r)REP(ss, (1<<r)){
      //cout << s << " " << t << " " << ss <<" " << dp[ss][t].val() << endl;
      m[s][t] += dp[ss][t];
    }
  }

  auto mul = [&](mtx& s, mtx& t) -> mtx {
    vector<vector<mint>> ret(r,vector<mint>(r,0));
    int sz = s.size();
    REP(i,sz)REP(j,sz)REP(k,sz){
      ret[i][j] += s[i][k] * t[k][j]; 
    }
  return ret;
  };

  vector<vector<mint>> y(r,vector<mint>(r,0));
  REP(i,r)y[i][i]=1;

  vector<vector<mint>> x(r,vector<mint>(r,0));
  REP(i,r)REP(j,r)x[i][j]=m[i][j];

  //REP(i,r)REP(j,r)cout << i << " " << j << " " << x[i][j].val() << endl;

  while(h>0){
    if(h & 1)y = mul(y,x);
    x = mul(x,x);
    h /= 2;
  }

  cout << y[0][0].val() << endl;


}

