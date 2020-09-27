#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
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

ll dp[3001][3001][4];

int main(){
  int r,c,k;
  cin >> r >> c >> k;
  
  map<P, int> mp;

  REP(i,k){
    int rr,cc,v;
    cin >> rr >> cc >> v;
    mp[make_pair(rr,cc)]=v;
  }

  FOR(i,1,r+1)FOR(j,1,c+1){
    if(mp.end() != mp.find(make_pair(i,j))){
      ll v = mp[make_pair(i,j)];
      FOR(k,1,4){
        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]+v);        
      }
      REP(l,4){
        dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][l]+v);        
      }
      REP(k,4){
        dp[i][j][k] = max(dp[i][j][k], max(dp[i-1][j][k], dp[i][j-1][k]));        
      }
    }else{
      REP(k,4){
        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);        
        dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][k]);        
      }
    }
  }

  ll ans = 0;
  REP(i,4)chmax(ans, dp[r][c][i]);

  // REP(i,r+1)REP(j,c+1)REP(k,4){
  //   cout << dp[i][j][k] << endl;
  // }

  cout << ans << endl;

}

