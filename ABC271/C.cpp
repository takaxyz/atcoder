#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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

int sold=0;

bool f(vi& b, int x){
  //cout << x << endl;
  // x以下の足りない冊数
  int s = x - (upper_bound(ALL(b), x) - b.begin());

  // xより大きい巻の冊数
  int t = b.end() - upper_bound(ALL(b),x);

  //cout << s << " " << t << " " << sold << endl;

  return s <= (t + sold)/2;
}


int main(){
  int n;
  cin >> n;
  vi a(n);

  REP(i, n)cin >> a[i];
  sort(ALL(a));

  set<int> st;
  vi b;
  REP(i,n){
    if(st.count(a[i]))continue;
    b.emplace_back(a[i]);
    st.insert(a[i]);
  }
  sold = a.size() - b.size();

  ll ok=0, ng=n+1;

  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(b, mid)){
      ok=mid;
    }else{
      ng=mid;
    }
  }

  cout << ok << endl;

}

