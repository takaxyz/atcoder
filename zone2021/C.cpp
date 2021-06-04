#include <bits/stdc++.h>
using namespace std;

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

bool f(int x, vvi& a){
  set<int> st;
  REP(i, a.size()){
    int mask=0;
    REP(j, 5){
      if(a[i][j]>=x){
        mask |= (1 << j);
      }
    }
    st.insert(mask);
  }
  for(auto& s: st)for(auto& t: st)for(auto& u: st){
    if((s | t | u) == ((1<<5)-1)){
      return true;
    }
  }
  return false;
}

int main(){
  int n;
  cin >> n;

  vvi a(n, vi(5));
  REP(i,n)REP(j,5)cin >> a[i][j];

  int ok=1, ng=INF;

  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    //cout << l << " " << r << " " << mid << endl;
    if(f(mid,a)){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  cout << ok << endl;
}

