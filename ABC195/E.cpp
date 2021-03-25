#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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
  string s,x;
  cin >> n >> s >> x;

  vvi dp(n+1,vi(7,0));
  dp[n][0] = 1;

  int ten=1;
  for(int i = n; i > 0; i-- ){
    for(int j = 0; j < 7; j++){
      int nj = (j + ten * (s[i-1]-'0')) % 7;
      if(x[i-1]=='T'){
        dp[i-1][j] = dp[i][nj] | dp[i][j];  
      }else{
        dp[i-1][j] = dp[i][nj] & dp[i][j];  
      }

    }
    ten = (ten*10 % 7);
  }

  // REP(i,n+1)REP(j,7){
  //   printf("dp[%d][%d] = %d\n", i,j,dp[i][j]);
  // }

  cout << (dp[0][0] ? "Takahashi" : "Aoki") << endl;

}

