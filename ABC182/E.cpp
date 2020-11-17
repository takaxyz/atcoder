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
  int h,w,n,m;
  cin >> h >> w >> n >> m;

  vvi cl(w), cb(w), rl(h), rb(h);
  REP(i,n){
    int a,b;
    cin >> a >> b;
    a--;b--;
    rl[a].push_back(b);
    cl[b].push_back(a);
  }
  REP(i,m){
    int c,d;
    cin >> c >> d;
    c--;d--;    
    rb[c].push_back(d);
    cb[d].push_back(c);
  }
  REP(i,h){
    rl[i].push_back(-1);
    rl[i].push_back(INF);
    sort(ALL(rl[i]));
  }
  REP(i,h){
    rb[i].push_back(-1);
    rb[i].push_back(INF);
    sort(ALL(rb[i]));
  }
  REP(i,w){
    cl[i].push_back(-1);
    cl[i].push_back(INF);
    sort(ALL(cl[i]));
  }
  REP(i,w){
    cb[i].push_back(-1);
    cb[i].push_back(INF);
    sort(ALL(cb[i]));
  }

  int ans=0;
  REP(i,h)REP(j,w){
    // i行j列
    auto l = lower_bound(ALL(rl[i]), j);
    auto b = lower_bound(ALL(rb[i]), j);

    if(*l < *b){
      ans++;
      continue;
    }

    l = upper_bound(ALL(rl[i]), j);
    b = upper_bound(ALL(rb[i]), j);
    l--;b--;
    if(*l > *b){
      ans++;
      continue;
    }

    l = lower_bound(ALL(cl[j]), i);
    b = lower_bound(ALL(cb[j]), i);
    if(*l < *b){
      ans++;
      continue;
    }
    l = upper_bound(ALL(cl[j]), i);
    b = upper_bound(ALL(cb[j]), i);
    l--;b--;
    if(*l > *b){
      ans++;
      continue;
    }



  }

  cout << ans << endl;
}

