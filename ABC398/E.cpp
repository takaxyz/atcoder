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
  vvi d(n,vi(n,INF));
  REP(i,n)d[i][i]=0;
  REP(_,n-1){
    int u,v;
    cin >> u >> v;
    u--; v--;
    d[u][v]=1;
    d[v][u]=1;
  }
  REP(k,n)REP(i,n)REP(j,n){
    chmin(d[i][j], d[i][k]+d[k][j]);
  }
  set<P> st;
  REP(i,n)FOR(j,i,n){
    if(d[i][j]>=3 && d[i][j]%2==1){
      st.insert({i,j});
    }
  }

  int f;
  if(st.size()%2==0){
    cout << "Second" << endl;
    fflush(stdout);
    f = 0;
  }else{
    cout << "First" << endl;
    fflush(stdout);
    f = 1;
  }

  while(true){
    if(f){
      auto it = st.begin();
      cout << it->first + 1  << " " <<  it->second + 1 << endl;
      fflush(stdout);
      st.erase(it);
    }else{
      int x,y;
      cin >> x >> y;
      if(x==-1)return 0;
      x--; y--;
      if(x > y)swap(x,y);
      st.erase({x,y});
    }
    f ^= 1;
  }


}

