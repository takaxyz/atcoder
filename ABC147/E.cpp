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
  int h,w;
  cin >> h >> w;
  vvi a(h, vi(w));
  vvi b(h, vi(w));
  REP(i,h)REP(j,w)cin >> a[i][j];
  REP(i,h)REP(j,w)cin >> b[i][j];

  const int D = (h+w)*80+1;
  vector<vector<vector<bool>>> dp(h, vector<vector<bool>>(w, vector<bool>(D+1)));
  dp[0][0][abs(a[0][0]-b[0][0])] = true;

  REP(i,h)REP(j,w){
    if(i+j==0)continue;
    if(i > 0){
      REP(k,D+1){
        if(dp[i-1][j][k]){
          dp[i][j][k + abs(a[i][j]-b[i][j])] = true;
          dp[i][j][abs(k - abs(a[i][j]-b[i][j]))] = true;
        }
      }
    }

    if(j > 0){
      REP(k,D+1){
        if(dp[i][j-1][k]){
          dp[i][j][k + abs(a[i][j]-b[i][j])] = true;
          dp[i][j][abs(k - abs(a[i][j]-b[i][j]))] = true;
        }
      }
    }
  }

  REP(i,D+1){
    if(dp[h-1][w-1][i]){
      cout << i << endl;
      return 0;
    }
  }
}

