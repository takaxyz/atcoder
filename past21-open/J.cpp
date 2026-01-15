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

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};
int di2[] = {0,1,0,-1};
int dj2[] = {-1,0,1,0};

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i,n)cin >> s[i];


  queue<tuple<int,int,int>> q;
  vector visited(n, vvi(n, vi(4, 0)));
  q.push({1,1,0});
  q.push({1,1,1});
  q.push({1,1,2});
  q.push({1,1,3});
  visited[1][1][0]=1;
  visited[1][1][1]=1;
  visited[1][1][2]=1;
  visited[1][1][3]=1;

  while(q.size()){
    auto [i,j,d] = q.front();
    q.pop();

    int ni = i + di[d];
    int nj = j + dj[d];
    if(s[ni][nj]!='#' && visited[ni][nj][d] == 0){
      visited[ni][nj][d] = 1;
      q.push({ni,nj,d});
    }

    int ni2 = i + di2[d];
    int nj2 = j + dj2[d];
    if(s[ni2][nj2] == '#'){
      int d3 = (d + 1) % 4;

      if(visited[i][j][d3])continue;
      visited[i][j][d3] = 1;
      q.push({i,j,d3});
    }
  }
  int ans=0;
  REP(i,n)REP(j,n){
    if(s[i][j]=='#')continue;
    bool ok = false;
    REP(k,4)if(visited[i][j][k]==1)ok=true;

    if(ok)ans++;
  } 
  cout << ans << endl;


  // REP(i,n){
  //   REP(j,n){
  //     int cnt=0;
  //     REP(k,4)cnt += visited[i][j][k];
  //     if(s[i][j]=='#')printf("# ");
  //     else printf("%d ",cnt > 0 ? 1 : 0);
  //   }
  //   printf("\n");
  // }
}

