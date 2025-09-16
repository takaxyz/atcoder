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
  int b1, r1 , b2 , r2, t;
  cin >> b1 >> r1 >> b2 >> r2 >> t;

  int c1 = 0, c2 = 0;
  int t1 = 0, t2 =0;
  int ans=0;
  REP(_,t){
    //printf("%d %d\n",c1,c2);
    if(c1 + c2 == 0)ans++;
    t1++; t2++;
    if(c1 == 0 && t1==b1){
      c1 = 1;
      t1 = 0;
    }else if(c1 == 1 && t1 == r1){
      c1 = 0;
      t1 = 0;
    }
    if(c2 == 0 && t2==b2){
      c2 = 1;
      t2 = 0;
    }else if(c2 == 1 && t2 == r2){
      c2 = 0;
      t2 = 0;
    }
  }
  cout << ans << endl;
}

