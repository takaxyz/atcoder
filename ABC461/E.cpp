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

  vector fw(2, fenwick_tree<int>(q));
  ll ans=0;
  vvi last(2, vi(n,-1));
  REP(i,q){
    int t,x;
    cin >> t >> x;
    t--;
    x--;

    if(t==0){
      if(last[t][x] == -1){
        ans += n;
      }else{
        ans += fw[1-t].sum(last[t][x], i);
        fw[t].add(last[t][x], -1);
      }
      fw[t].add(i, 1);
      last[t][x] = i;
    }else{
      if(last[t][x] == -1){
        ans -= fw[1-t].sum(0, i); 
      }else{
        ans -= fw[1-t].sum(last[t][x], i);
        fw[t].add(last[t][x], -1);
      }
      fw[t].add(i, 1);
      last[t][x] = i;
    }
    cout << ans << endl;
  }


}

