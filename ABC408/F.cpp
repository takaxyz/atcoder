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

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return (int)(-1);
}


int main(){
  int n,d,r;
  cin >> n >> d >> r;
  vi h(n),pos(n);
  REP(i,n){
    cin >> h[i];
    h[i]--;
    pos[h[i]]=i;
  }

  segtree<int, op, e> seg(n);

  vi dp(n);
  
  REP(i,n){
    if(i >= d){
      seg.set(pos[i-d], dp[pos[i-d]]);
    }

    int li = max(0,pos[i]-r);
    int ri = min(n,pos[i]+r+1);
    dp[pos[i]] = seg.prod(li,ri) + 1;
  }

  cout << *max_element(ALL(dp)) << endl;
}

