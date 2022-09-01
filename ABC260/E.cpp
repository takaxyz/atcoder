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
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

int main(){
  int n,m;
  cin >> n >> m;
  vi a(n), b(n);
  vvi idx(200001, vi());

  vi ans(m+2);

  REP(i,n){
    cin >> a[i] >> b[i];
    idx[a[i]].emplace_back(i);
    idx[b[i]].emplace_back(i);
  }

  vi c(n);
  int cnt=0;
  for(int l = 1, r = 1; l <= m; l++){
    for(; r <= m && cnt < n; r++){
      for(auto id: idx[r]){
        if(c[id]==0)cnt++;
        c[id]++;
      }      
    }
    if(cnt < n)break;
    
    //printf("%d %d\n",l,r);
    ans[r-l]++;
    ans[m-l+2]--;

    for(auto id: idx[l]){
      if(c[id]==1)cnt--;
      c[id]--;
    }
  }

  int s = 0;
  FOR(i,1,m+1){
    s += ans[i];
    cout << s << endl;
  }
}

