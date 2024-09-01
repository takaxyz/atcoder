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

int dx[] = {1,0};
int dy[] = {0,1};
 
int main(){
  int h,w;
  cin >> h >> w;

  vector<string> a(h);
  REP(i,h)cin >> a[i];

  vvi dp(h,vi(w, -INF));
  dp[h-1][w-1]=0;

  auto f = [&](int x, int y, auto f) -> int{
    if(dp[x][y]!=-INF)return dp[x][y];

    // Takahashi
    if((x+y)%2==0){
      int ret = -INF;
      REP(i,2){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < h && ny < w){
          chmax(ret, f(nx,ny,f) + (a[nx][ny] == '-' ? -1 : 1));
        }
      }
      return dp[x][y] = ret;
    // Aoki
    }else{
      int ret = INF;
      REP(i,2){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < h && ny < w){
          chmin(ret, f(nx,ny,f) - (a[nx][ny] == '-' ? -1 : 1));
        }
      }       
      return dp[x][y] = ret;
    }

  };

  int score = f(0,0,f);

  if(score > 0){
    cout << "Takahashi" << endl;
  }else if(score == 0){
    cout << "Draw" << endl;

  }else{
    cout << "Aoki" << endl;
  }
}

