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

int main(){
  multiset<ll> st;
  int a,q;
  cin >> q;
  REP(i,q){
    int t, k;
    ll x;
    cin >> t;
    if(t==1){
      cin >> x;
      st.insert(x);
    }else if(t==2){
      cin >> x >> k;
      auto it = st.upper_bound(x);
      bool ok=true;
      REP(i,k){
        if(it == st.begin()){
          ok = false;
          break;
        }
        it--;
      }
      if(ok){
        cout << *it << endl;
      }else{
        cout << -1 << endl;
      }
    }else{
      cin >> x >> k;
      auto it = st.lower_bound(x);
      bool ok=true;
      REP(i,k-1){
        if(it == st.end()){
          ok = false;
          break;
        }
        it++;
      }
      if(it != st.end() && ok){
        cout << *it << endl;
      }else{
        cout << -1 << endl;
      }
    }
  }
}

