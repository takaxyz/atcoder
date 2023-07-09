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
  int ha,wa;
  cin >> ha >> wa;
  vector<string> a(ha);
  REP(i,ha)cin >> a[i];

  int hb,wb;
  cin >> hb >> wb;
  vector<string> b(hb);
  REP(i,hb)cin >> b[i];

  int hx,wx;
  cin >> hx >> wx;
  vector<string> x(hx);
  REP(i,hx)cin >> x[i];

  vector<string> c(30, string(30, '.'));

  REP(i,hx)REP(j,wx)c[10+i][10+j] = x[i][j];

  //REP(i,30)cout << i << " " << c[i] << endl;

  auto f = [&](int ai, int aj, int bi, int bj) -> bool {
    vector<string> d(30, string(30, '.'));

    REP(i,ha)REP(j,wa){
      if(a[i][j]=='#')d[ai+i][aj+j]='#';
    }
    REP(i,hb)REP(j,wb){
      if(b[i][j]=='#')d[bi+i][bj+j]='#';
    }

    //REP(i,30)cout << i << " " << d[i] << endl;

    bool ok = true;
    REP(i,30)REP(j,30){
      if(d[i][j]=='#' && (i < 10 || i >= 10+hx || j < 10 || j >= 10+wx))ok=false;
    }
    if(!ok)return ok;

    REP(i,hx)REP(j,wx){
      if(c[10+i][10+j]!=d[10+i][10+j])ok=false;
    }
    return ok;

  };

  

  //printf("%d\n",f(11,10,11,10));
  REP(ai,20)REP(aj,20)REP(bi,20)REP(bj,20){
    if(f(ai,aj,bi,bj)){
       cout << "Yes" << endl;
       return 0;
     }
  }
  cout << "No" << endl;



}

