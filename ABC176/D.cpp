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

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int h,w;
bool visited[1001][1001];

set<pair<int>> st;

int dfs(int x, int y, int c, vector<vector<char>> &s, vector<vector<int>> &cost){
  cost[x][y]=c;
  visited[x][y]=true;

  for(int i = -2; i < 3; i++){
    for(int j = -2; j < 3; j++){
      if(i==0 && j==0)continue;
      int nx=x+i;
      int ny=y+j;
      if(nx<0 || nx >=h || ny <0 || ny>=w)continue;
      if(s[nx][ny]=='#')continue;
      if(visited[nx][ny])continue;

      if(abs(i)+abs(j)==1){
        if(st.count(make_pair(nx,ny))){
          st.erase(make_pair(nx,ny));
        }
        dfs(nx,ny,c,s,cost);
      }else{
        if(cost[nx][ny] > c){
          cost[nx][ny] = c+1;
          st.insert(make_pair(nx,ny));
        }else{

        }
      }

    }
  }

}

int main(){
  cin >> h >> w;
  int ch, cw, dh, dw;
  cin >> ch >> cw >> dh >> dw;
  ch--; cw--; dh--; dw--;

  vector<vector<char>> s(h, vector<char>(w));
  vector<vector<int>> cost(h, vector<int>(w,INF));

  REP(i,w)REP(j,h)cin >> s[i][j];

  int now=0;
  while(!st.empty()){
    st.be
    dfs(ch,cw,now,s,cost);

  }

}

