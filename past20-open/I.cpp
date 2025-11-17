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
  vvi a(2,vi(4));
  REP(i,2)REP(j,4)cin >> a[i][j];

  map<vvi, int> d;

  vvi s(2,vi(4));
  REP(i,2)REP(j,4)s[i][j] = i * 4 + j+1;

  queue<vvi> q;
  q.push(s);
  d[s] = 0;
  while(q.size()){
    vvi v = q.front();
    q.pop();

    REP(i,4){
      vvi nv = v;
      swap(nv[0][i],nv[1][i]);
      if(d.count(nv))continue;
      q.push(nv);
      d[nv] = d[v]+1;
    }
    
    REP(i,2)REP(j,3){
      vvi nv = v;
      swap(nv[i][j],nv[i][j+1]);
      if(d.count(nv))continue;
      q.push(nv);
      d[nv] = d[v]+1;
    }
  }

  cout << d[a] << endl;


}

