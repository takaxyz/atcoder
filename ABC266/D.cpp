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

ll dp[100001][5];

int main(){
  int n;
  map<int, pair<int, ll>> mp;
  cin >> n;
  int tmx=0;
  REP(i,n){
    int t,x;
    ll a;
    cin >> t >> x >> a;
    mp[t] = {x, a};
    chmax(tmx,t);
  }

  REP(i,100001)FOR(j,1,5)dp[i][j]=-LINF;
  dp[0][0]=0;

  REP(i,100001){
    if(mp.count(i+1)){
      int x = mp[i+1].first;
      ll a = mp[i+1].second;
      REP(j,5){
        if(dp[i][j]==-LINF)continue;
        chmax(dp[i+1][j], dp[i][j] + (x == j ? a : 0));
        if(j+1<5)chmax(dp[i+1][j+1], dp[i][j] + (x == j+1 ? a : 0));
        if(j-1>=0)chmax(dp[i+1][j-1], dp[i][j] + (x == j-1 ? a : 0));
      }
    }else{
      REP(j,5){
        if(dp[i][j]==-LINF)continue;
        chmax(dp[i+1][j], dp[i][j]);
        if(j+1<5)chmax(dp[i+1][j+1], dp[i][j]);
        if(j-1>=0)chmax(dp[i+1][j-1], dp[i][j]);
      }
    }
  }

  ll ans=0;
  REP(i,5){
    chmax(ans, dp[tmx][i]);
  }
  cout << ans << endl;

}

