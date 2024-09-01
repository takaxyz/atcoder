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
  vector<ll> a(n),b(n);

  fenwick_tree<ll> seg(n);
  REP(i,n){
    cin >> a[i];
    seg.add(i, a[i]);
  }

  set<int> st;
  REP(i,n){
    cin >> b[i];
    if(b[i]>1)st.insert(i);
  }

  int q;
  cin >> q;
  while(q--){
    int t;
    cin >> t;

    int i,l,r;
    ll x;
    if(t==1){
      cin >> i >> x;
      i--;
      seg.add(i, x - a[i]);
      a[i]=x;
    }else if(t==2){
      cin >> i >> x;
      i--;
      if(b[i]>1)st.erase(i);
      if(x>1)st.insert(i);
      b[i]=x;
    }else{
      cin >> l >> r;
      l--;

      ll v = 0;
      while(l < r){
        auto it = st.lower_bound(l);

        if(it != st.end() && *it <= r){
          i = *it;
          v += seg.sum(l,i);
          l = i+1;
          if(i < r)v = max(v + a[i], v * b[i]);
        }else{
          v += seg.sum(l,r);
          l = r;
        }
      }
      cout << v << endl;
    }



  }
}

