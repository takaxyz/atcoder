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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
 
int main(){
  int h,w,d;
  cin >> h >> w >> d;
  vector<string> s(h);
  REP(i,h)cin >> s[i];

  vvi dist(h,vi(w,INF));
  queue<P> q;

  REP(i,h)REP(j,w){
    if(s[i][j]!='H')continue;
    q.emplace(i,j);
    dist[i][j]=0;
  }

  while(!q.empty()){
    auto [i,j] = q.front();
    q.pop();
    //printf("%d %d\n",i,j);
    REP(k,4){
      int ni = i + dx[k];
      int nj = j + dy[k];
      //printf(" %d %d\n",ni,nj);

      if(ni < 0 || ni >= h || nj < 0 || nj >=w)continue;
      if(s[ni][nj]!='.')continue;
      if(dist[ni][nj] <= dist[i][j]+1)continue;
      dist[ni][nj] = dist[i][j]+1;
      q.emplace(ni,nj);
    }
  }


  int ans=0;
  REP(i,h)REP(j,w)if(dist[i][j]<=d)ans++;
  cout << ans << endl;
}

