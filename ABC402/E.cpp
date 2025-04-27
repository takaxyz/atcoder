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
  int n,x;
  cin >> n >> x;

  vi s(n),c(n),p(n);
  REP(i,n)cin >> s[i] >> c[i] >> p[i];

  vector dp((1<<n), vector<double>(x+1,0));

  dp[0][0]=0;

  for(int i = 0; i < (1<<n); i++){
    REP(j,x){
      REP(k,n){
        if((i>>k)&1)continue;

        if(j + c[k] > x)continue;

        int ni = i | (1<<k);
        // ok
        chmax(dp[ni][j + c[k]], (dp[i][j] + s[k]) * p[k] / 100);
        // ng
        chmax(dp[i][j + c[k]], dp[i][j] * (100-p[k]) / 100);
      }
    }    
  }


  REP(i,(1<<n))REP(j,x+1){
    printf("%d %d %f\n",i,j,dp[i][j]);
  }
}

