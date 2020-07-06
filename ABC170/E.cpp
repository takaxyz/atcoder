#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define RALL(v) rbegin(v), rend(v)

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


void pp(set<P> &x){
  PRINT("pp start");
  for(auto v: x){
    cout << v.Fi << " " << v.Se << endl;
  }
  PRINT("pp end");
}

int main(){
  int n,q;
  cin >> n >> q;

  vi a(n), b(n);
  vector<set<P>> t(200000, set<P>());
  REP(i,n){
    cin >> a[i] >> b[i];
    b[i]--;
    t[b[i]].insert(P{a[i],i});
  }

  set<P> ma;
  REP(i,200000){
    if(t[i].size()>0){
      auto iter = t[i].end();
      iter--;
//      printf("%d: %d %d\n",i, (*iter).Fi, (*iter).Se);
//      ma[i] = t[i][t[i].size()-1];


      ma.insert(make_pair(iter->Fi,iter->Se));
    }
  }
//  pp(ma);

  REP(i,q){
    int c,d;
    cin >> c >> d;
    c--; d--;

    // 現在の幼稚園
    int f = b[c];
    b[c] = d;

    t[f].erase(P{a[c], c});

    if(t[d].size()>0){
      auto iter = t[d].end();
      iter--;
      P dst_old = (*iter);
      ma.erase(dst_old);
    }

    if(ma.find(P{a[c], c}) != ma.end()){
      ma.erase(P{a[c], c});
      if(t[f].size()>0){
        auto iter = t[f].end();
        iter--;
        ma.insert(make_pair(iter->Fi, iter->Se));
      }
    }

    t[d].insert(P{a[c],c});
    auto iter = t[d].end();
    iter--;
    P dst_new = (*iter);
    ma.insert(dst_new);

//    pp(ma);
    auto iter2 = ma.begin();
    cout << iter2->Fi << endl;

  }
}

