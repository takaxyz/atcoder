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

int main(){
  int a,b;
  cin >> a >> b;
  vector<string> s(3);
  REP(i,3)cin >> s[i];

  vector<vector<bool>> visited(9,vector<bool>(9,false));

  queue<P> q;
  q.push({a-1,b-1});
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if(visited[x][y])continue;
    visited[x][y]=true;

    REP(i,3)REP(j,3){
      if(s[i][j]=='.')continue;;

      int nx = x + i + 1 - 2;
      int ny = y + j + 1 - 2;
      if(nx < 0 || nx >= 9 || ny < 0 || ny >= 9)continue;
      if(visited[nx][ny])continue;
      q.push({nx,ny});
    }

  }
  int ans=0;
  REP(i,9)REP(j,9)if(visited[i][j])ans++;
  cout << ans << endl;
}

