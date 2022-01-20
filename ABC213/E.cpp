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

int h,w;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

P conv(int x){
  return make_pair(x/w, x%w);
}

int main(){
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h)cin >> s[i];

  vector<bool> visited(h*w);
  vi dist(h*w,INF);
  deque<P> q;
  q.push_back({0,0});
  while(!q.empty()){
    int v = q.front().first;
    int d = q.front().second;
    q.pop_front();
    if(visited[v])continue;
    visited[v]=true;
    dist[v]=d;
    int x = v%w;
    int y = v/w;

    REP(i,4){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx<0 || nx>=w || ny<0 || ny>=h)continue;
      if(s[ny][nx]=='#')continue;
      q.push_front({ny*w+nx,d});
    }

    for(int i=-2; i<3; i++){
      for(int j=-2; j<3; j++){
        if(abs(i)+abs(j)==4 || (i==0 && j==0))continue;
        int nx = x+i;
        int ny = y+j;
        if(nx<0 || nx>=w || ny<0 || ny>=h)continue;
        q.push_back({ny*w+nx,d+1});
      }
    }
  }

  cout << dist[h*w-1] << endl;
}

