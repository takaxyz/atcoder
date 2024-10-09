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
  int mg;
  cin >> mg;
  vvi eg(n,vi(n));;
  REP(i,mg){
    int a,b;
    cin >> a >> b;
    a--; b--;
    eg[a][b]=1;
    eg[b][a]=1;
  }

  int mh;
  cin >> mh;
  vvi eh(n,vi(n));;
  REP(i,mh){
    int a,b;
    cin >> a >> b;
    a--; b--;
    eh[a][b]=1;
    eh[b][a]=1;
  }

  vvi a(n,vi(n));
  REP(i,n)FOR(j,i+1,n){
    cin >> a[i][j];
    a[j][i] = a[i][j];
  }

  vi p(n);
  REP(i,n)p[i] = i;

  int ans = INF;
  do{
    int cost = 0;
    REP(i,n)FOR(j,i+1,n){
      if(eg[i][j] + eh[p[i]][p[j]] == 1){
        cost += a[p[i]][p[j]];
      }
    }
    chmin(ans,cost);
  }while(next_permutation(ALL(p)));

  cout << ans << endl;
}

