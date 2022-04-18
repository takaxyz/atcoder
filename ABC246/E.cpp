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

int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};

int main(){
  int n;
  cin >> n;
  int ax,ay,bx,by;
  cin >> ax >> ay >> bx >> by;
  ax--; ay--; bx--; by--;
  vector<string> s(n);
  REP(i,n)cin >> s[i];

  deque<P> q;
  vvi d(n,vi(n,INF));
  q.push_back({ax,ay});
  d[ax][ay]=0;

  while(q.size()){
    auto v = q.front(); q.pop_front();
    int x = v.first;
    int y = v.second;

    REP(i,4){
      int nx = x + dx[i];
      int ny = y + dy[i];
      while(1){
        if(nx >= n || ny >= n || nx < 0 || ny < 0)break;
        if(s[nx][ny]=='#')break;
        nx += dx[i];
        ny += dy[i];
      }
    }

  }
}

