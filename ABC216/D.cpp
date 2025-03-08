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
  vvi a(m);
  vvi p(n);
  queue<P> q;
  REP(i,m){
    int k;
    cin >> k;
    a[i] = vi(k);
    REP(j,k){
      cin >> a[i][k-j-1];
      a[i][k-j-1]--;
    }
    p[a[i].back()].pb(i);
    if(p[a[i].back()].size()==2){
      q.emplace(p[a[i].back()][0], p[a[i].back()][1]);
    }
  }

  int cnt=0;
  while(!q.empty()){
    auto [i,j] = q.front();
    q.pop();
    cnt++;

    //printf("%d %d\n",i,j);
    a[i].pop_back();
    a[j].pop_back();

    if(a[i].size()){
      p[a[i].back()].pb(i);
      if(p[a[i].back()].size()==2){
        q.emplace(p[a[i].back()][0], p[a[i].back()][1]);
      }
    }

    if(a[j].size()){
      p[a[j].back()].pb(j);
      if(p[a[j].back()].size()==2){
        q.emplace(p[a[j].back()][0], p[a[j].back()][1]);
      }  
    }
  }
  cout << (cnt==n ? "Yes" : "No") << endl;
}

