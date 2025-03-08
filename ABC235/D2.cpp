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
  ll a,n;
  cin >> a >> n;
  const int MAX=1000001;

  vi d(MAX,INF);

  queue<int> q;
  q.push(1);
  d[1]=0;

  while(!q.empty()){
    int v = q.front();
    q.pop();

    if(v * a < MAX){
      if(d[v * a] == INF){
        d[v * a] = d[v]+1;
        q.push(v * a);
      }
    }

    if(v >= 10 && v % 10 != 0){
      string s = to_string(v);
      string ss = s.back() + s.substr(0, s.size()-1);
      //cout << ss << endl;
      int nv = stoi(ss);
      if(d[nv] == INF){
        d[nv] = d[v]+1;
        q.push(nv);
      }

    }
  }

  cout << (d[n] == INF ? -1 : d[n]) << endl;

}


