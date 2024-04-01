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
//const ll LINF = 1001001001001001001ll;

using mint = modint1000000007;
// using mint = modint998244353;

struct S {
  int val1, num1, val2, num2;
  S(int val1=0, int num1=0, int val2=0, int num2=0) : val1(val1), num1(num1), val2(val2), num2(num2) {}
};

S op(S a, S b){
  //return std::max(a, b);
  map<int ,int> mp;
  mp[a.val1] += a.num1;
  mp[a.val2] += a.num2;
  mp[b.val1] += b.num1;
  mp[b.val2] += b.num2;

  auto it = mp.end();

  it--;  
  int val1 = it->first;
  int num1 = it->second;
  it--;
  int val2 = it->first;
  int num2 = it->second;
  return S(val1,num1,val2,num2);

}

S e(){ return S(-INF,0,-INF-1,0); }

int main(){
  int n,q;
  cin >> n >> q;

  segtree<S,op,e> seg(n);

  REP(i,n){
    int a;
    cin >> a;
    seg.set(i, S(a,1,-INF,0));
  }

  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int p, x;
      cin >> p >> x;
      seg.set(--p, S(x,1,-INF,0));
    }else{
      int l,r;
      cin >> l >> r;
      l--;

      S ret = seg.prod(l,r);

      cout << ret.num2 << endl;
    }
  }


}

