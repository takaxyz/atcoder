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

int main(){
  int n;
  cin >> n;

  int n3 = n * 3;
  vi a(n3);
  REP(i,n3)cin >> a[i];

  int ans = INF;

  auto dfs = [&](int s, int mx, int mn, auto dfs) -> void{
    if(s == (1<<n3)-1){
      chmin(ans, mx - mn);
      return;
    }

    int i = 0;
    while((s>>i) & 1)i++;

    REP(j,n3){
      if(j==i)continue;
      if((s>>j) & 1)continue;
      FOR(k,j+1,n3){
        if(j==i)continue;
        if((s>>k) & 1)continue;

        //fprintf(stderr, "%d: %d %d %d\n",s,i,j,k);
        int sum = a[i] + a[j] + a[k];

        dfs(s | 1<<i | 1<<j | 1<<k, max(sum,mx), min(sum, mn), dfs);
      }
    }
  };

  dfs(0, 0, INF, dfs);

  cout << ans << endl;
}

