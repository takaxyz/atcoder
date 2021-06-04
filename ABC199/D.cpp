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

int n,m;
vvi edge;
vi col;

ll dfs(int x, int c){
  col[x]=c;
  st.insert(c);
  int ret=0;
  int cnt=0;
  int nc=c;
  for(auto y : edge[x]){
    if(col[y] == c)return false;
    if(col[y]!=-1)continue;

    nc = (nc + 1)%3;
    if(nc==c)nc = (nc + 1)%3;
    dfs(y, nc, st);
  }
  return true;
}


int main(){
  cin >> n >> m;
  edge.resize(n);
  col.resize(n,-1);
  REP(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  // 3: x6 2: x6 1: x3
  ll ans=1;
  REP(i,n){
    if(col[i]!=-1)continue;
    set<int> st;
    bool ret = dfs(i,0,st);
    if(ret==false){
      cout << 0 << endl;
      return 0;
    }else if(st.size()==1){
      ans*=3;
    }else{
      ans*=6;
    }
  }
  cout << ans << endl;

}

