#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

int dp[101][10001];

int main(){
  int n, s;
  cin >> n >> s;

  vi a(n),b(n);
  REP(i,n)cin >> a[i] >> b[i];

  dp[0][0]=1;

  REP(i,n){
    REP(j,s){
      if(dp[i][j]==0)continue;

      if(j+a[i] <= s)dp[i+1][j+a[i]]=1;
      if(j+b[i] <= s)dp[i+1][j+b[i]]=1;
    }
  }

  // REP(i,n+1)REP(j,s+1){
  //   cout << i << " " << j << " " << dp[i][j] << endl;
  // }


  if(dp[n][s]){
    cout << "Yes" << endl;
    vector<string> ans;

    int x = s;
    for(int i = n-1; i >= 0; i--){
      if(dp[i][x - a[i]] == 1){
         ans.emplace_back("H");
         x -= a[i];
      }else{
        ans.emplace_back("T");
        x -= b[i];
      }
    }

    reverse(ALL(ans));
    REP(i,ans.size()){
      cout << ans[i] << (i==ans.size()-1 ? "\n": "");
    }
  }else{
    cout << "No" << endl;
  }


}

