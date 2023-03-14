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
  vvi a(n, vi(n));
  REP(i,n)REP(j,n)cin >> a[i][j];

  vi s(n);
  REP(i,n)s[i]=i;;
  
  vvi xy(n,vi(n));
  int m;
  cin >> m;

  REP(_, m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    xy[x][y]=1;
    xy[y][x]=1;
  }

  int ans=INF;
  do {
    bool ok = true;
    int t=0;
    REP(i,n){
      if(i+1 < n && xy[s[i]][s[i+1]]){
        ok=false;
        break;
      }
      t += a[s[i]][i];
    }
    if(ok)chmin(ans,t);
  }while(next_permutation(ALL(s)));


  cout << (ans == INF ? -1 : ans) << endl;
}

