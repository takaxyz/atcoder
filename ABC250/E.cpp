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
  int n;
  cin >> n;
  vi a(n),b(n);
  REP(i,n)cin >> a[i];
  REP(i,n)cin >> b[i];
  int q;
  cin >> q;
  
  set<int> sta, stb, stc;
  vi ca(n), cb(n);
  vi aa, bb,cc;

  REP(i,n){
    if(sta.count(a[i])==0){
      aa.emplace_back(a[i]);
    }
    if(stb.count(b[i])==0){
      bb.emplace_back(b[i]);
    }
    sta.insert(a[i]);
    ca[i]=sta.size();
    stb.insert(b[i]);
    cb[i]=stb.size();
  }

  // REP(i,ca.size()){
  //   cout << ca[i] << endl;
  // }
  // REP(i,cb.size()){
  //   cout << cb[i] << endl;
  // }

  REP(i, min(aa.size(), bb.size())){
    if(stc.count(aa[i])){
      stc.erase(aa[i]);
    }else{
      stc.insert(aa[i]);
    }
    if(stc.count(bb[i])){
      stc.erase(bb[i]);
    }else{
      stc.insert(bb[i]);
    }
    cc.emplace_back(stc.size());
  }
  // cout << endl;
  // REP(i,cc.size()){
  //   cout << cc[i] << endl;
  // }

  REP(i,q){
    int x,y;
    cin >> x >> y;
    x--;y--;
    if(ca[x]!=cb[y]){
      cout << "No" << endl;
    }else{
      int sz = ca[x];
      if(sz <= cc.size() && cc[sz-1]==0){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
}

