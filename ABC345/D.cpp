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
  int n,h,w;
  cin >> n >> h >> w;

  vi a(n),b(n);
//  REP(i,n)cin >> a[i] >> b[i];

  vi v(n);
  REP(i,n)v[i] = i;

  set<vi> st;
  int cnt=0;
  do {
    FOR(i, 1, (1<<n)){
      vi v2;
      REP(j,n){
        if((i >> j ) & 1){
          v2.pb(v[j]);
        }
      }
      cnt++;
      st.insert(v2);
    }
  }while(next_permutation(ALL(v)));

  for(auto v2 : st){
    vector<string> tile(h, string('.',w));

    int si=-1;
    int sj=-1;
    for(auto p: v2){
      int ai = a[p];
      int bi = b[p];

      REP(_,2){
        swap(ai,bi);



      }

    }
  }

}

