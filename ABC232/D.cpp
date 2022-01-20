#include <bits/stdc++.h>
using namespace std;

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

vector<string> c;
int h,w;
vvi d;

void dfs(int i, int j, int dist=1){
  d[i][j]=dist;
  if(i+1 < h && c[i+1][j]=='.' && d[i+1][j] < d[i][j]){
    dfs(i+1,j,dist+1);
  }
  if(j+1 < w && c[i][j+1]=='.' && d[i][j+1] < d[i][j]){
    dfs(i,j+1,dist+1);
  }
}

int main(){
  cin >> h >> w;
  c.resize(h);
  d = vvi(h, vi(w));

  REP(i,h)cin >> c[i];

  dfs(0,0);

  int ans=-1;
  REP(i,h)REP(j,w)chmax(ans,d[i][j]);
  cout << ans << endl;
  
}

