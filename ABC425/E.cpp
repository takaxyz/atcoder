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

ll comb[5001][5001];

int main(){
  int t,m;
  cin >> t >> m;
  comb[0][0]=1;
  comb[1][0]=1;
  comb[1][1]=1;
  
  for(int i = 2; i <= 5000; i++){
    comb[i][0]=1;
    for(int j = 1; j <= i; j++){
      comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
      comb[i][j] %= m;
    }
  }

//  REP(i,6)FOR(j,0,i+1)printf("%d %d: %d\n",i,j,comb[i][j]);


  REP(_,t){
    int n;
    cin >> n;
    vi c(n);
    REP(i,n)cin >> c[i];
    int sum = 0;
    REP(i,n) sum += c[i];
    ll ans=1;
    REP(i,n){
      ans *= comb[sum][c[i]];
      ans %= m;
      sum -= c[i];
    }
    cout << ans << endl;
  }
}

