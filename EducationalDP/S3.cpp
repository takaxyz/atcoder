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

int main(){
  string k;
  cin >> k;
  int d;
  cin >> d;

  int sz = k.size();
  vector<vector<vector<mint>>> dp(sz+1, vector<vector<mint>>(2, vector<mint>(d, 0)));

  dp[0][0][0]=1;
  REP(i,sz)REP(j,2)REP(l,d){
    int x = k[i] - '0';

    REP(m,10){

      int ni = i+1;
      int nj = j;
      int nl = (l + m) % d;

      if(j == 0){
        if(x < m)continue;
        if(x > m)nj=1;
      }

      dp[ni][nj][nl] += dp[i][j][l];
    }
  }

  cout << (dp[sz][0][0] + dp[sz][1][0] - 1).val() << endl;
}

