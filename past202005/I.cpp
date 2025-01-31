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
  vector t(n,deque<int>());

  map<int,int> mp;
  REP(i,n){
    int k;
    cin >> k;
    REP(_,k){
      int tt;
      cin >> tt;
      t[i].pb(tt);
      mp[tt] = i;
    }
  }

  set<int> st1,st2;
  vi p(n);

  REP(i,n){
    st1.insert(t[i][0]);
    st2.insert(t[i][0]);
    if(t[i].size()>1){
      st2.insert(t[i][1]);
    }
  }

  int m;
  cin >> m;
  REP(_,m){
    int a;
    cin >> a;
    if(a==1){
      auto it = st1.end();
      it--;
      int ma = *it;
      cout << ma << endl;
      int i = mp[ma];

      st1.erase(ma);
      st2.erase(ma);
      t[i].pop_front();
      if(t[i].size()>0){
        st1.insert(t[i][0]);
      }
      if(t[i].size()>1){
        st2.insert(t[i][1]);
      }
    }else{
      auto it = st2.end();
      it--;
      int ma = *it;
      cout << ma << endl;
      int i = mp[ma];

      if(t[i].front() == ma){
        st1.erase(ma);
        st2.erase(ma);
        t[i].pop_front();
        if(t[i].size()>0){
          st1.insert(t[i][0]);
        }
        if(t[i].size()>1){
          st2.insert(t[i][1]);
        }
      }else{
        st2.erase(ma);
        int v = t[i].front();
        t[i].pop_front();
        t[i].pop_front();
        t[i].push_front(v);
        if(t[i].size()>1){
          st2.insert(t[i][1]);
        }
      }
    }
  }
}

