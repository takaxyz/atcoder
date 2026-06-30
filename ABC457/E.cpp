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
  int n,m;
  cin >> n >> m;
  vi min_r(n,INF);
  map<P,int> mp;

  vvi vr(n), vl(n);
  REP(_,m){
    int l,r;
    cin >> l >> r;
    l--; r--;
    mp[{l,r}]++;
    vl[l].pb(r);
    vr[r].pb(l);
    chmin(min_r[l], r);
  }

  REP(i,n){
    sort(ALL(vl[i]));
    sort(ALL(vr[i]));
  }

  vi mi(n+1, INF);
  for(int i = n - 1; i >= 0; i--){
    mi[i] = min(mi[i+1],min_r[i]);
  }

  int q;
  cin >> q;
  REP(_,q){
    int s,t;
    cin >> s >> t;
    s--; t--;

    if(mp.count({s,t}) && mp[{s,t}] >= 2){ 
      cout << "Yes" << endl;
    }else if(mp.count({s,t}) && mp[{s,t}] == 1){

      if(mi[s+1] <= t || mi[s] <= t-1){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }else{
      if(vl[s].size() == 0 || vr[t].size() == 0){
        cout << "No" << endl;
      }else{
        int p1 = upper_bound(ALL(vl[s]), t) - vl[s].begin();
        p1--;

        int p2 = lower_bound(ALL(vr[t]), s) - vr[t].begin();

        bool ok = false;
        if(p1 >= 0 && p2 < vr[t].size()){
          //cout << vr[t][p2] << " " << vl[s][p1] << endl;
          if(vr[t][p2]-vl[s][p1] <= 1){
            ok = true;
          } 
        }

        cout << (ok ? "Yes" : "No") << endl;
      }
    }
  }


}

