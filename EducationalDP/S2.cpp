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
  string s;
  int d;
  cin >> s >> d;

  vector<vector<vector<mint>>> dp(s.size()+1, vector<vector<mint>>(2, vector<mint>(d)));  
  
  dp[0][0][0]=1;
  REP(i, s.size()){
    REP(j, 10){
      REP(k,d){
        dp[i+1][1][(k+j) % d] += dp[i][1][k];
        int x = s[i] - '0';
        if(j < x){
          dp[i+1][1][(k+j) % d] += dp[i][0][k];
        }else if(j==x){
          dp[i+1][0][(k+j) % d] += dp[i][0][k];
        }
      }
    }
  }
  // REP(i,s.size()+1)REP(j,2)REP(k,d){
  //   printf("%d %d %d : %d\n", i,j,k,dp[i][j][k].val());
  // }
  cout << (dp[s.size()][1][0] + dp[s.size()][0][0] - 1).val() << endl;
}

