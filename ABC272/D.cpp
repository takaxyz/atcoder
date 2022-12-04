#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
  int n,m;
  cin >> n >> m;

  vi a;
  REP(i,n){
    a.emplace_back(i*i);
  }
  set<P> st;
  for(auto x: a)for(auto y: a){
    if(x+y == m){
      st.insert({(int)sqrt(x),(int)sqrt(y)});
    }
  }



  queue<P> q;
  vvi d(n, vi(n,-1));
  d[0][0]=0;
  q.push({0,0});
  while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();

    //if(d[x][y] > dist)continue;

    for(auto [xx, yy] : st){
      REP(i,4){
        int nx = x + xx * dx[i];
        int ny = y + yy * dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
        if(d[nx][ny] != -1)continue;

        d[nx][ny] = d[x][y] + 1;
        q.push({nx,ny});
      }
    }

  }

  REP(i,n)REP(j,n){
    cout << d[i][j] << (j==n-1 ? "\n" : " ");
  }
}

