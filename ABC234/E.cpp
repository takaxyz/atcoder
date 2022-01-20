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
const ll LINF = 200000000000000000ll;
const int MOD = 1e9 + 7;

int main(){
  set<ll> st;
  REP(i,10){
    FOR(j,1,10){
      ll x = j;
      st.insert(x);
      int y = j;
      while(y + i <= 10){
        x = x * 10 + (y + i)%10;
        if(x > LINF)break;
        st.insert(x);
        y = y + i;
      }
    }
  }
  FOR(i,1,10){
    FOR(j,1,10){
      ll x = j;
      st.insert(x);
      int y = j;
      while(y - i >= 0){
        x = x * 10 + y - i;
        if(x > LINF)break;
        st.insert(x);
        y = y - i;
      }
    }
  }

  ll X;
  cin >> X;
  vector<ll> list;
  for(auto k: st){
    list.emplace_back(k);
  }

  auto iter = lower_bound(ALL(list), X);
  cout << *iter << endl;

}

