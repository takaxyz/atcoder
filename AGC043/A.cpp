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
  int h,w;
  cin >> h >> w;

  vector<vector<char>> s(h,vector<char>(w));
  REP(i,h)REP(j,w)cin >> s[i][j];

  vvi dp(h,vi(w,INF));
  if(s[0][0]=='#')dp[0][0]=1;
  else dp[0][0]=0;

  REP(i,h)REP(j,w){
    int di,dj;
    if(i+j==0)continue;

    if(i==0){
      dj = (s[i][j]!=s[i][j-1] ? 1 : 0);
      dp[i][j] = dp[i][j-1]+dj;
    }else if(j==0){
      di = (s[i][j]!=s[i-1][j] ? 1 : 0);
      dp[i][j] = dp[i-1][j]+di;
    }else{
      dj = (s[i][j]!=s[i][j-1] ? 1 : 0);
      di = (s[i][j]!=s[i-1][j] ? 1 : 0);
      dp[i][j] = min(dp[i-1][j]+di, dp[i][j-1]+dj);
    }
  }

  if(s[h-1][w-1]=='#')dp[h-1][w-1]++;

  // REP(i,h)REP(j,w){
  //   cout << dp[i][j] << (j==w-1 ? "\n" : " ");
  // }
  cout << dp[h-1][w-1]/2 << endl;

}

