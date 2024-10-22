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
  int n,q;
  cin >> n >> q;
  int l = 1,r = 2;

  int ans = 0;
  REP(_,q){
    char h;
    int t;
    cin >> h >> t;
    if(h=='L'){
      if(l < r ){
        if(l < t && t < r){
          ans += t-l;
//          cout << "a" << endl;
        }else if(t <= l){
          ans += l-t;
//          cout << "b" << endl;
        }else{
          ans += l+n-t;
//          cout << "c" << endl;
        }
      }else{
        if(r < t && t < l){
          ans += l-t;
//          cout << "d" << endl;
        }else if(t < r){
          ans += t+n-l;
//          cout << "e" << endl;
        }else{
          ans += t-l;
//          cout << "f" << endl;
        }
      }
      l = t;
    }else{
      if(r < l ){
        if(r < t && t < l){
          ans += t-r;
//          cout << "g" << endl;
        }else if(t <= r){
          ans += r-t;
//          cout << "h" << endl;
        }else{
          ans += r+n-t;
//          cout << "i" << endl;
        }
      }else{
        if(l < t && t < r){
          ans += r-t;
//          cout << "j" << endl;
        }else if(t < l){
          ans += t+n-r;
//          cout << "k" << endl;
        }else{
          ans += t-r;
//          cout << "l" << endl;
        }
      }
      r = t;
    }
//    cout << ans << endl;

  }
  cout << ans << endl;
}

