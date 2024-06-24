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
  int sz=1;
  REP(_,n)sz*=3;

  vector<string> ans(sz, string(sz, '#'));

  auto f = [&](int k, int x, int y, auto f) -> void{
    if(k == 1){
      ans[x+1][y+1]='.';
      return;
    }

    int m = 1;
    REP(_, k-1)m *= 3;

    REP(i,3){
      f(k-1,x, y + m * i, f);
    }
    f(k-1,x + m, y, f);
    REP(i,m)REP(j,m)ans[x+m+i][y+m+j]='.';
    f(k-1,x + m, y + m * 2, f);

    REP(i,3){
      f(k-1,x + m * 2, y + m * i, f);
    }


  };

  if(n==0){
    cout << '#' << endl;
    return 0;
  }

  f(n, 0, 0, f);

  for(auto s: ans)cout << s << endl;


}

