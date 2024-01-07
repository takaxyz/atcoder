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
  int n;
  cin >> n;

  vector<ll> ans;

  auto dfs = [&](auto dfs, int n, int res, ll x) -> void{
    if(res == 0){
      ans.pb(x);
      return;
    }

    if(n == 0)return ;

    ll y = 0;
    REP(_,n)y = y * 10 + 1;

    dfs(dfs, n - 1, res, x);
    if(res >= 1)dfs(dfs, n - 1, res - 1, x + y*1);
    if(res >= 2)dfs(dfs, n - 1, res - 2, x + y*2);
    if(res >= 3)dfs(dfs, n - 1, res - 3, x + y*3);
  };

  dfs(dfs,12,3,0);

  sort(ALL(ans));
  cout << ans[n-1] << endl; 
}

