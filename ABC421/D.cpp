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

struct Point{
  ll r;
  ll c;

  bool operator==(const Point& x){
    return x.r == r && x.c == c;
  }
};

map<char,int> dr = {{'U',-1}, {'D',1}, {'R',0}, {'L',0}};
map<char,int> dc = {{'U',0}, {'D',0}, {'R',1}, {'L',-1}};


int main(){
  Point T, A;
  cin >> T.r >> T.c >> A.r >> A.c;
  ll n;
  int m,l;
  cin >> n >> m >> l;
  deque<pair<char,int>> sa(m),tb(l);
  REP(i,m)cin >> sa[i].first >> sa[i].second;
  REP(i,l)cin >> tb[i].first >> tb[i].second;

  vector<tuple<char,char,int>> vs;

  while(!sa.empty() || !tb.empty()){
    auto [s,a] = sa.front();
    sa.pop_front();
    auto [t,b] = tb.front();
    tb.pop_front();

    if(a == b){
      vs.emplace_back(s,t,a);
    }else if(a < b){
      vs.emplace_back(s,t,a);
      tb.push_front({t,b-a});
    }else{
      vs.emplace_back(s,t,b);
      sa.push_front({s,a-b});
    }
  }

  Point nT,nA;

  auto f = [&](char s, char t, ll v) -> int{
    if(dr[s] == 0 && dr[t] == 0){
      if(T.r != A.r)return 0;
      if((T.c - A.c) % (dc[t] - dc[s]) != 0)return 0; 
      if(0 < (T.c - A.c) / (dc[t] - dc[s]) && (T.c - A.c) / (dc[t] - dc[s]) <= v)return 1;
      else return 0;
    }else if(dc[s] == 0 && dc[t] == 0){
      if(T.c != A.c)return 0;
      if((T.r - A.r) % (dr[t] - dr[s]) != 0)return 0; 
      if(0 < (T.r - A.r) / (dr[t] - dr[s]) && (T.r - A.r) / (dr[t] - dr[s]) <= v)return 1;
      else return 0;
    }
    if((T.r - A.r) % (dr[t] - dr[s]) != 0)return 0; 
    if((T.c - A.c) % (dc[t] - dc[s]) != 0)return 0; 
    if((T.r - A.r) / (dr[t] - dr[s]) != (T.c - A.c) / (dc[t] - dc[s]))return 0; 

    if(0 < (T.r - A.r) / (dr[t] - dr[s]) && (T.r - A.r) / (dr[t] - dr[s]) <= v)return 1;
    else return 0;
  };


  ll ans = 0;
  for(auto [s,t,v]: vs){
    nT.r = T.r + dr[s] * v;
    nT.c = T.c + dc[s] * v;
    nA.r = A.r + dr[t] * v;
    nA.c = A.c + dc[t] * v;
    if(s == t){
      if(T == A)ans += v;
    }else{
      ans += f(s,t,v);
    }
    T = nT;
    A = nA;
  }
  cout << ans << endl;

}

