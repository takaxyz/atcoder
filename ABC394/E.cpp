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

int main(){
  int n;
  cin >> n;
  vector<string> c(n);
  REP(i,n)cin >> c[i];

  queue<P> q;
  vvi d(n,vi(n,INF));

  REP(i,n){
    d[i][i]=0;
    q.emplace(i,i);
  }

  REP(i,n)REP(j,n){
    if(i!=j && c[i][j] != '-'){
      d[i][j]=1;
      q.emplace(i,j);
    }
  }

  while(!q.empty()){
    auto [i,j] = q.front();
    q.pop();

    REP(k,n)REP(l,n){
      if(d[k][l]!=INF)continue;

      if(c[k][i] != '-' && c[k][i] == c[j][l]){
        d[k][l] = d[i][j]+2;
        q.emplace(k,l);
      }
    }
  }

  REP(i,n)REP(j,n){
    cout << (d[i][j] == INF ? -1 : d[i][j]) << (j==n-1 ? "\n" : " ");
  }
}

