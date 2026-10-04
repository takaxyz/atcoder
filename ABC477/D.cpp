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

  vi m(n);
  vector<P> querys;
  REP(_,q){
    int t;
    cin >> t;
    if(t==1){
      int x;
      cin >> x;
      x--;
      querys.pb({1,x});
      m[x] ^= 1;
    }else{
      char c;
      cin >> c;
      querys.pb({2,(int)(c-'a')});
    }
  }
  reverse(ALL(querys));

  set<int> st;
  REP(i,n)if(m[i]==0)st.insert(i);

  vector<char> ans(n,' ');
  for(auto [t,x]: querys){
    if(t==1){
      m[x] ^= 1;
      if(m[x]==0 && ans[x]==' ')st.insert(x);
      if(m[x]==1)st.erase(x);
    }else{
      for(auto y: st)ans[y]=x + 'a';
      st.clear();
    }
  }

  REP(i,n)cout << (ans[i]==' ' ? 'a' : ans[i]);
  cout << endl;
}

