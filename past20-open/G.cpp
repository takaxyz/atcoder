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
  int n,m,k;
  cin >> n >> m >> k;
  vi r(n),p(m);
  REP(i,n)cin >> r[i];
  REP(i,m)cin >> p[i];
  sort(ALL(r));
  reverse(ALL(r));
  sort(ALL(p));
  reverse(ALL(p));

  int ans = -1;

  int sum=0;
  // r -> p
  if((k+1)/2 <= n && k/2 <= m){
    REP(i,(k+1)/2){
      sum += r[i];
    }
    REP(i,k/2){
      sum += p[i];
    }

    chmax(ans,sum);

  }
  sum = 0;
  // r -> p

  if((k+1)/2 <= m && k/2 <= n){
    REP(i,(k+1)/2){
      sum += p[i];
    }
    REP(i,k/2){
      sum += r[i];
    }
    chmax(ans,sum);
  }

  cout << ans << endl;
}

