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
  int n;
  string s;
  cin >> n >> s;

  vector dp(n+1,vector<pair<int,int>>(10, {-1,-1}));

  dp[0][0] = {0,0};

  REP(i,n){
    if(s[i]=='?'){
      REP(j,10){
        if(dp[i][j].first ==-1)continue;
        REP(k,10){
          int nj = (j + k*(i+1)) % 10;
          dp[i+1][nj] = {j, k};
        }
      }
    }else{
      int k = s[i] - '0';
      REP(j,10){
        if(dp[i][j].first ==-1)continue;
        int nj = (j + k*(i+1)) % 10;
        dp[i+1][nj] = {j, k};
      }
    }
  }

  if(dp[n][0].first==-1){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
    int m = 0;
    string s;
    for(int p = n; p > 0; p--){
      s += (char)('0' + dp[p][m].second);
      m = dp[p][m].first;
    }
    reverse(ALL(s));
    cout << s << endl;
  }


}

