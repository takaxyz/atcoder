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

struct S{
  S(char lc, int lcnt, char rc, int rcnt, int ans, bool allsame) : lc(lc), lcnt(lcnt), rc(rc), rcnt(rcnt), ans(ans), allsame(allsame){};
  char lc;
  int lcnt;
  char rc;
  int rcnt;
  int ans;
  bool allsame;
};

S op(const S& a, const S& b) {
  if(a.lc == '*')return b;
  if(b.rc == '*')return a;


  if(a.allsame && b.allsame){
    if(a.lc == b.lc){
      return S(a.lc, a.lcnt+b.rcnt, b.rc, a.lcnt+b.rcnt, a.ans + b.ans, a.allsame);
    }else{
      return S(a.lc, a.lcnt, b.rc, b.rcnt, max(a.ans,b.ans), false);
    }
  }else if(a.allsame){
    if(a.lc == b.lc){
      return S(a.lc, a.lcnt+b.lcnt, b.rc, b.rcnt, max(a.lcnt+b.lcnt,b.ans), false);
    }else{
      return S(a.lc, a.lcnt, b.rc, b.rcnt, max(a.ans, b.ans), false);
    }
  }else if(b.allsame){
    if(a.rc == b.lc){
      return S(a.lc, a.lcnt, b.rc, a.rcnt + b.rcnt, max(a.ans, a.rcnt+b.lcnt), false);
    }else{
      return S(a.lc, a.lcnt, b.rc, b.rcnt, max(a.ans,b.ans), false);
    }
  }else{
    if(a.rc != b.lc){
      return S(a.lc, a.lcnt, b.rc, b.rcnt, max(a.ans,b.ans), false);
    }else{
      return S(a.lc, a.lcnt, b.rc, b.rcnt, max(max(a.ans,b.ans), a.rcnt + b.lcnt), false);
    }
  }

}

S e() {
  return S('*',0,'*',0,0,false);
}

int main(){
  int n,q;
  cin >> n >> q;

  string s;
  cin >> s;

  segtree<S,op,e> tree(n);
  REP(i,n){
    tree.set(i, S(s[i],1,s[i],1,1,true));
  }

  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int i;
      char x;
      cin >> i >> x;
      i--;
      tree.set(i,S(x,1,x,1,1,true));
    }else{
      int l,r;
      cin >> l >> r;
      l--;
      cout << tree.prod(l,r).ans << endl;
    }
  }
}

