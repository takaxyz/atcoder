#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define RALL(v) rbegin(v), rend(v)

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

int dist(P s, P t){
  return abs(s.Fi - t.Fi) + abs(s.Se - t.Se);
}

int main(){
  int N,M;
  cin >> N >> M;
  int sx,sy,gx,gy;
  
  vector<vector<P>> m(11,vector<P>());

  REP(i,N)REP(j,M){
    char c;
    cin >> c;
    if(c=='S'){
      m[0].eb(P{i,j});
    }else if(c=='G'){
      m[10].eb(P{i,j});
    }else{
      int n = c - '0';
      m[n].eb(P{i,j});
    }
  }

  vvi dp(11);

  REP(i,11){
    dp[i] = vi(m[i].size(), INF);
  }
  dp[0][0]=0;

  REP(i,10){
    REP(j,m[i].size()){
      REP(k,m[i+1].size()){
        chmin(dp[i+1][k], dp[i][j] + dist(m[i][j], m[i+1][k]));
      }
    }
  }

  cout << (dp[10][0] == INF ? -1 : dp[10][0])  << endl;
}

