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
  int h,w;
  cin >> h >> w;
  vector<string> s(h),t(h);
  REP(i,h)cin >> s[i];
  REP(i,h)cin >> t[i];

  auto rotate = [&](vector<string> &x){
    vector<string> y(x[0].size(), string(x.size(),' '));
    REP(i,x[0].size())REP(j,x.size()){
      y[(y.size()-i-1)][j] = x[j][i];
    }
    return y;
  };

  int h2 = h;
  int w2 = w;
  REP(_,4){
    t = rotate(t);
    swap(h2,w2);
    // REP(i,h2){
    //   cout << t[i] << endl;
    // }
    for(int i = max(h,h2)*(-1); i <= max(h,h2); i++){
      for(int j = max(w,w2)*(-1); j <= max(w,w2); j++){
        //printf("%d %d\n",i,j);
        bool ok = true;
        REP(k,h2)REP(l,w2){
          int ni = k + i;
          int nj = l + j;
          //printf("%d %d : %d %d\n",k,l,ni,nj);
          if(t[k][l]=='#' && (ni < 0 || ni >= h || nj < 0 || nj >= w)){
            ok = false;
            break;
          }
          if(ni < 0 || nj < 0 || ni >= h || nj >= w)continue;
          if(t[k][l] == '#' && s[ni][nj] == '#'){
            ok = false;
            break;
          }
        }

        if(ok){
          cout << "Yes" << endl;
          return 0;
        }

      }
    }


  }
  cout << "No" << endl;
}

