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

int main(){
  int H,W,n,h,w;
  cin >> H >> W >> n >> h >> w;

  vector<vector<vector<int>>> sum(H+1, vvi(W+1, vi(n,0)));

  REP(i,H)REP(j,W){
    int a;
    cin >> a;
    a--;
    REP(k,n){
      sum[i+1][j+1][k] = sum[i][j+1][k] + sum[i+1][j][k] - sum[i][j][k];
      if(k==a) sum[i+1][j+1][k]++;
    }
  }

  // REP(i,n){
  //   cout << i+1 << endl;

  //   REP(j,H+1)REP(k,W+1){
  //     cout << sum[j][k][i] << (k == W ? "\n" : " ");
  //   }
  // }

  FOR(i,h,H+1)FOR(j,w,W+1){
    int ans=0;
    REP(k,n){
      int c = sum[H][W][k] - sum[i][j][k] + sum[i-h][j][k] + sum[i][j-w][k] - sum[i-h][j-w][k];
      if(c>0)ans++;
    }
    cout << ans << (j==W ? "\n" : " ");
  }
}

