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

int main(){
  string s;
  cin >> s;

  int n = s.size();
  vvi dp(n, vi(n+1,-1));

  auto f = [&](int l, int r, auto f) -> int {
    if(dp[l][r]!=-1)return dp[l][r];

    if(r-l < 3)return dp[l][r]=0;

    if(r-l ==3)return dp[l][r] = (s.substr(l,3) == "iwi");

    int ret=-1;
    FOR(i,l+1,r){
      chmax(ret, f(l,i,f)+f(i,r,f));
    }

    if(s[l]=='i' && s[r-1]=='i'){
      FOR(i,l+1,r-1){
        if(s[i]=='w'){
          int a = f(l+1,i,f);
          int b = f(i+1,r-1,f);
          if(a*3 == i - l - 1 && b*3 == r-2-i)chmax(ret, a+b+1);
        }
      }
    }
    return dp[l][r]=ret;
  };

  f(0, s.size(), f);

  // REP(i,n)REP(j,n+1){
  //   cout << i << " " << j << " " << dp[i][j] << endl;
  // }

  cout << (dp[0][n] == -1 ? 0 : dp[0][n]) << endl;
}

