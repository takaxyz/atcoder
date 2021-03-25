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

vvi used;

int h,w,a,b;

ll dfs(int i, int j, int a, int b){
  ll res=0;

//  fprintf(stderr, "%d %d %d %d\n",i,j,a,b);

  if(a < 0 || b < 0)return 0;
  if(j==w)j=0, i++;
  if(i==h)return 1;

  if(used[i][j])return dfs(i,j+1,a,b);


  // choose b
  used[i][j]=1;
  res += dfs(i, j+1, a, b-1);

  // choose a : yoko
  if(j+1 < w && used[i][j+1] != 1){
    used[i][j+1] = 1;
    res += dfs(i,j+1,a-1,b);
    used[i][j+1] = 0;
  }

  // choose a : tate
  if(i+1 < h && used[i+1][j] != 1){
    used[i+1][j] = 1;
    res += dfs(i,j+1,a-1,b);
    used[i+1][j] = 0;
  }
  used[i][j]=0;
  return res;
}

int main(){
  cin >> h >> w >> a >> b;

  used.resize(h, vi(w));

  int ans = dfs(0,0,a,b);
  cout << ans << endl;
}

