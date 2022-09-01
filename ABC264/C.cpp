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

int main(){
  int h1,w1,h2,w2;

  cin >> h1 >> w1;
  vvi a(h1,vi(w1));

  REP(i,h1)REP(j,w1)cin >> a[i][j];

  cin >> h2 >> w2;
  vvi b(h2, vi(w2));
  REP(i,h2)REP(j,w2)cin >> b[i][j];

  REP(i, (1<<h1))REP(j, (1<<w1)){
    if(__builtin_popcount(i) == h1 - h2 && __builtin_popcount(j) == w1 - w2){
      bool ok=true;
      int hh = 0;
      REP(h,h1){
        if(((i>>h) & 1) == 0){
          int ww = 0;
          REP(w,w1){
            if(((j>>w) & 1) == 0){
              //fprintf(stderr, "%d %d : %d %d %d %d\n",i,j,h,w,hh,ww);
              if(a[h][w]!=b[hh][ww])ok=false;
              ww++;
            }
          }
          hh++;
        }
      }
      if(ok){
        cout << "Yes" << endl;
        return 0;
      }
      
    }
  }
  cout << "No" << endl;

}

