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

int sx, sy, gx, gy;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
map<char, vector<P>> m;



int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  vector<vector<int>> d(h, vector<int>(w, INF));

  map<char,int> used;

  queue<pair<P, int>> q;

  REP(i,h)REP(j,w){
    cin >> s[i][j];
    if(s[i][j]=='S'){
      sx=i; sy=j;
    }else if(s[i][j]=='G'){
      gx=i; gy=j;
    }else if('a' <= s[i][j] && s[i][j] <= 'z'){
      m[s[i][j]].push_back({i,j});
    }
  }

  q.push({{sx,sy}, 0});
  while(!q.empty()){
    pair<P, int> v = q.front();
    q.pop();
    int x = v.first.first;
    int y = v.first.second;
    int dist = v.second;

    //fprintf(stderr, "%d %d %d\n",x,y,dist);

    if(d[x][y]<= dist)continue;

    d[x][y] = dist;

    REP(i,4){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx<0 || nx >=s.size() || ny <0 || ny >= s[0].size())continue;
      if(s[nx][ny]=='#')continue;
      q.push({{nx,ny}, dist+1});
    }

    if('a' <= s[x][y] && s[x][y] <= 'z'){
      if(used[s[x][y]] > 0)continue;
      used[s[x][y]] = 1;
      for(auto p: m[s[x][y]]){
        if(p.first == x && p.second == y)continue;
        q.push({{p.first, p.second}, dist+1});
     }
    }
  }
  cout <<   (d[gx][gy] == INF ? -1 : d[gx][gy]) << endl;

}

