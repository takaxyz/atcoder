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
  int n,q;
  cin >> n >> q;
  vi a(n,-1), b(n,-1);
  REP(_,q){
    int t,x,y;
    cin >> t;
    if(t==1){
      cin >> x >> y;
      x--; y--;
      b[x] = y;
      a[y] = x;
    }else if(t==2){
      cin >> x >> y;
      x--; y--;
      b[x]=-1;
      a[y]=-1;
    }else{
      cin >> x;
      x--;
      deque<int> q;
      q.push_back(x+1);
      int v = a[x];
      while(v != -1){
        q.push_front(v+1);
        v = a[v];
      }
      v = b[x];
      while(v != -1){
        q.push_back(v+1);
        v = b[v];
      }

      cout << q.size() << " ";
      REP(i, q.size()){
        cout << q[i] << (i == q.size()-1 ? "\n" : " ");
      }
    }
  }
}

