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
const int MOD = 1e9 + 7;


int main(){
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  REP(i,n)cin >> s[i];


  auto ck = [&](int x, int y) -> bool {
    bool ok = true;
    REP(i,3)REP(j,3){
      if(s[x+i][y+j]!='#')ok=false;
    }
    FOR(i,6,9)FOR(j,6,9){
      if(s[x+i][y+j]!='#')ok=false;
    }

    REP(i,4)if(s[x+3][y+i]!='.')ok=false;
    REP(i,4)if(s[x+5][y+5+i]!='.')ok=false;
    REP(i,4)if(s[x+i][y+3]!='.')ok=false;
    REP(i,4)if(s[x+5+i][y+5]!='.')ok=false;

    return ok;
  };


  vector<P> ans;
  REP(i, n-8)REP(j,m-8){
    if(ck(i,j))ans.emplace_back(i+1,j+1);
  }
  for(auto [x,y]: ans){
    cout << x << " " << y << endl;
  }

}

