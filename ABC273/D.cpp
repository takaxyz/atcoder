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
const ll LINF = 1001001001001001001LL;
const int MOD = 1e9 + 7;
int main(){
  ll h,w,rs,cs;
  cin >> h >> w >> rs >> cs;

  int n;
  cin >> n;
  map<ll,vector<ll>> rw,cw;
  REP(i,n){
    ll r,c;
    cin >> r >> c;
    rw[r].emplace_back(c);
    cw[c].emplace_back(r);
  }

  for(auto &[k,v]: rw){
    sort(ALL(v));
  }
  for(auto &[k,v]: cw){
    sort(ALL(v));
  }
  for(auto &p : rw) sort(p.second.begin(), p.second.end());
  for(auto &p : cw) sort(p.second.begin(), p.second.end());

  int q;
  cin >> q;
  REP(i,q){
    char d;
    ll l;
    cin >> d >> l;

    if(d=='U'){
      if(cw.count(cs)){
        auto it = lower_bound(ALL(cw[cs]), rs);
        if(it == cw[cs].begin()){
          rs = max(1LL, rs-l);
        }else{
          it--;
          rs = max(*it + 1, rs-l);
        }
      }else{
        rs = max(1LL, rs-l);
      }
    }else if(d=='D'){
      if(cw.count(cs)){
        auto it = upper_bound(ALL(cw[cs]), rs);
        if(it == cw[cs].end()){
          rs = min(h, rs+l);
        }else{
          rs = min(*it - 1,rs+l);
        }
      }else{
        rs = min(h, rs+l);
      }
    }else if(d=='R'){
      if(rw.count(rs)){
        auto it = upper_bound(ALL(rw[rs]),cs);
        if(it == rw[rs].end()){
          cs = min(w, cs+l);
        }else{
          cs = min(*it - 1, cs+l);
        }
      }else{
        cs = min(w, cs+l);
      }
    }else{
      if(rw.count(rs)){
        auto it = lower_bound(ALL(rw[rs]),cs);
        if(it == rw[rs].begin()){
          cs = max(1LL, cs-l);
        }else{
          it--;
          cs = max(*it + 1, cs-l);
        }
      }else{
        cs = max(1LL, cs-l);
      }
    }

    cout << rs << " " << cs << endl;

  }


  // for(auto [k,v]: cw){
  //   cout << k << endl;
  //   for(auto x: v){
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // }


}

