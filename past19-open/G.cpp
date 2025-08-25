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
  vvi a(n,vi(n));
  int x,y;
  REP(i,n)REP(j,n){
    cin >> a[i][j];
    a[i][j]--;
    if(a[i][j]==-1){
      x = i; y = j;
    }
  }

  vector<tuple<int,int,int>> vs;
  REP(i,n)REP(j,n)REP(k,n){
    if(a[i][j]==-1 || a[j][k]==-1){
      vs.emplace_back(i,j,k);
      continue;
    }
    
    if(a[a[i][j]][k]==-1 || a[i][a[j][k]]==-1){
      vs.emplace_back(i,j,k);      
      continue;
    }

    if(a[a[i][j]][k] == a[i][a[j][k]]){
      //printf("%d %d %d: ok\n", i,j,k);
    }else{
      //printf("%d %d %d: ng\n", i,j,k);
      cout << 0 << endl;
      return 0;
    }
  }
  int cnt=0;
  REP(v,n){
    a[x][y] = v;
    bool ok=true;
    for(auto [i,j,k] : vs){
      if(a[a[i][j]][k] != a[i][a[j][k]])ok=false;
    }
    if(ok)cnt++;
  }
  cout << cnt << endl;
}

