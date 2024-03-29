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

using mint = modint998244353;

int main(){
  int n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;

  vector dp(n+1, vector(n+1, vector<mint>(2, -1)));

  auto dfs = [&](int x, int y, int t, auto dfs) -> mint{
    //cout << x << " " << y << " " << t << endl;
    if(dp[x][y][t]!=-1)return dp[x][y][t];

    if(x==n && y != n)return dp[x][y][t]=1;
    if(x!=n && y == n)return dp[x][y][t]=0;

    mint ret=0;
    if(t==0){
      FOR(i,1,p+1){
        ret += dfs(min(x + i,n), y, 1, dfs);
      }
      ret /= p;
    }else{
      FOR(i,1,q+1){
        ret += dfs(x, min(y+i,n), 0, dfs);
      }
      ret /= q;
    }
    return dp[x][y][t] = ret;
  };

  cout << dfs(a,b,0,dfs).val() << endl;
}

