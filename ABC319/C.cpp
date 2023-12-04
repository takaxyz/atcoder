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
  vi c(9);
  REP(i,9)cin >> c[i];

  vector<tuple<int,int,int>> chk = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};

  vi ord(9);
  REP(i,9)ord[i]=i;

  int cnt=0;
  do{
    for(auto [s,t,u] : chk){
      bool ok=false;
      REP(_,3){
        if(c[s]==c[t] && c[t] != c[u] && ord[s] < ord[u] && ord[t] < ord[u]){
          cnt++;
          ok=true;
          break;
        }
        swap(s,t);
        swap(t,u);
      }
      if(ok)break;
    }
  }while(next_permutation(ALL(ord)));

  double tot = 9*8*7*6*5*4*3*2;
  printf("%.10f\n", (tot-cnt)/tot);
}

