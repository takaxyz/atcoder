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
const int MOD = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  vi m(n+1);
  vi p;
  vi t(n),x(n);
  REP(i,n)cin >> t[i] >> x[i];

  for(int i = n-1; i>=0; i--){
    if(t[i]==1){
      if(m[x[i]] > 0){
        p.pb(i);
        m[x[i]]--;
      }
    }else{
      m[x[i]]++;
    }
  }

  REP(i,n+1){
    if(m[i]>0){
      cout << -1 << endl;
      return 0;
   }
  }

  int cnt=0;
  int mx=0;
  vi ans;
  REP(i,n){
    if(t[i]==1){
      if(p.size() > 0 && p.back() == i){
        cnt++;
        chmax(mx,cnt);
        p.pop_back();
        ans.push_back(1);
      }else{
        ans.push_back(0);
      }
    }else{
      cnt--;
    }
  }
  cout << mx << endl;
  REP(i,ans.size()){
    cout << ans[i] << (i == ans.size()-1 ? "\n" : " ");
  }

}