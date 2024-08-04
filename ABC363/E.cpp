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

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(){
  int h,w,y;
  cin >> h >> w >> y;

  vvi a(h,vi(w));
  REP(i,h)REP(j,w)cin >> a[i][j];
  vvi q(h,vi(w));
  vvi wt(h,vi(w));


  priority_queue<pair<int, P>, vector<pair<int,P>>, greater<pair<int,P>>>  que;

  REP(i,w)que.emplace(a[0][i], make_pair(0,i));
  REP(i,w)que.emplace(a[h-1][i], make_pair(h-1,i));
  FOR(i,1,h-1)que.emplace(a[i][0], make_pair(i,0));
  FOR(i,1,h-1)que.emplace(a[i][w-1], make_pair(i,w-1));

  REP(i,w)q[0][i]=1;
  REP(i,w)q[h-1][i]=1;
  FOR(i,1,h-1)q[i][0]=1;
  FOR(i,1,h-1)q[i][w-1]=1;


  int ans = h*w;
  FOR(t, 1, y+1){
    while(!que.empty() && que.top().first <= t){
      auto [s, p] = que.top();
      que.pop();

      auto [x,y] = p;
      //cout << x << " " << y << endl;

      if(!wt[x][y]){
        wt[x][y]=1;
        ans--;
      }

      REP(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
        if(q[nx][ny])continue;

        que.emplace(a[nx][ny], make_pair(nx,ny));
        q[nx][ny]=1;
      }

    }

    cout << ans << endl;

  }


}

