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

int dx[] = {0,1,0,-1,0};
int dy[] = {0,0,1,0,-1};

int main(){
  int n;
  string s,t;
  cin >> n >> s >> t;
  
  queue<string> q;
  vvi dp(n,vi(n,-1));

  
  auto dfs = [&](int l, int r, auto dfs) -> int {
    if(dp[l][r]!=-1)return dp[l][r];
    if(r - l < 2)return dp[l][r] = 0;

    int res=0;
    for(int i = l; i < r; i++){
      chmax(res, dfs(l,i,dfs)+dfs(i+1,r,dfs));
    }

    for(int i = l+1; i < r; i++){
      if(s[l]==t[0] && s[i] == t[1] && s[r] == t[2]
        && dfs(l+1,i-1,dfs) == (i - l - 1)/3 && (i - l - 1) % 3 == 0 && dfs(i+1,r-1,dfs) == (r - i - 1)/3 && (r - i - 1)%3==0){
        
        chmax(res, dp[l+1][i-1]+dp[i+1][r-1]+1);    
      }
    }

    return dp[l][r] = res;
  };


  dfs(0,n-1,dfs);
  //REP(i,n)REP(j,n)printf("%d %d: %d\n",i,j,dp[i][j]);
  cout << dp[0][n-1] << endl;

}

