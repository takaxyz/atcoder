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
  unordered_map<int,int> bef, aft;

  int prev=0;
  REP(i,n){
    int a;
    cin >> a;

    bef[a]=prev;
    aft[prev]=a;

    if(i==n-1){
      aft[a]=INF;
    }
    prev = a;
  }

  int q;
  cin >> q;
  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int x,y;
      cin >> x >> y;

      int z = aft[x];
      // x z -> x y z 
      bef[z] = y;
      aft[x] = y;
      bef[y] = x;
      aft[y] = z;
    }else{
      int x;
      cin >> x;

      // z x y -> z y
      int z = bef[x];
      int y = aft[x];
      bef[y]=z;
      aft[z]=y;
      //bef.erase(x);
      //aft.erase(x);
    }

  }
  // for(auto [k,v]: bef){
  //   cout << k << " " << v << endl;
  // }
  // cout << endl;
  // for(auto [k,v]: aft){
  //   cout << k << " " << v << endl;
  // }

  prev=0;
  while(true){
    int nxt = aft[prev];
    if(nxt == INF)break;
    cout << nxt << endl;
    prev = nxt;
  }
}

