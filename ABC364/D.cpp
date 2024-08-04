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
  vi a(n);
  REP(i,n)cin >> a[i];
  sort(ALL(a));

  REP(_,q){
    int b, k;
    cin >> b >> k;

    auto f = [&](int x) -> bool {
      int c1 = a.end() - upper_bound(ALL(a), b + x);      
      int c2 = a.end() - lower_bound(ALL(a), b - x);      

      return (c2 - c1) >= k;
    };


    int ok=INF, ng = -1;

    while(abs(ok-ng)>1){
      int mid = (ok+ng)/2;
      if(f(mid)){
        ok=mid;
      }else{
        ng=mid;
      }
    }
    cout << ok << endl;

  }
}

