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
  int n;
  cin >> n;
  vi a(n);
  REP(i,n)cin >> a[i];
  vector<pair<int,int>> rle;

  int cnt=0;
  REP(i,n){
    if(i > 0 && a[i] != a[i-1]){
      rle.emplace_back(a[i-1], cnt);
      cnt=0;
    }
    cnt++;
    if(i==n-1)rle.emplace_back(a[i],cnt);
  }

  int l=0;
  set<int> st;
  int ans=0;
  REP(i,rle.size()){
    if(rle[i].second == 2){
      if(l==-1)l=i;
      if(st.count(rle[i].first) == 0){
        st.insert(rle[i].first);
      }else{
        chmax(ans,(i - l + 1)*2);
        st = set<int>();
        st.insert(rle[i].first);
        l = i;
      }
    }else if(rle[i].second > 2 ){
      if(l==-1)l=i;
      if(st.count(rle[i].first) == 0){
        cnt+=2;
        chmax(ans,cnt);

        st = set<int>();
        st.insert(rle[i].first);
      }else{
        chmax(ans,cnt);
        st = set<int>();
        st.insert(rle[i].first);
        l = i;
      }
    }else{
      chmax(ans,cnt);
      st = set<int>();
      l = -1;
    }
  }
  chmax(ans,cnt);

  cout << ans << endl;
}

