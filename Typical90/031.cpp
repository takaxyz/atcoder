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

const int VMAX = 700;

vvi memo(51, vi(1326,-1));


int g(int w, int b){
  if(w == 0 && b <= 1)return memo[w][b] = 0;
  if(memo[w][b] != -1)return memo[w][b];

  int key[VMAX];
  REP(i,VMAX)key[i]=0;

  if(w > 0){
    key[g(w-1, b+w)] = 1;
  }
  if(b > 1){
    FOR(i,1,b/2+1){
      key[g(w, b-i)] = 1;
    }
  }

  REP(i,VMAX)if(key[i]==0)return memo[w][b] = i;
}

int main(){
  int n;
  cin >> n;
  vi w(n),b(n);
  REP(i,n)cin >> w[i];
  REP(i,n)cin >> b[i];


  int sum_xor = 0;
  REP(i,n){
    int gd = g(w[i],b[i]);
    sum_xor ^= gd;
  }

  // REP(i,5)REP(j,5){
  //   printf("%d %d: %d\n",i,j,memo[i][j]);
  // }

  cout << (sum_xor == 0 ? "Second" : "First") << endl;


}

