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

  string s;
  cin >> s;
  int ans=0;
  vi c(n);
  REP(i,n-2){
    if(s.substr(i,3) == "ABC"){
      ans++;
      c[i]=1; c[i+1]=2; c[i+2]=3;
    }
  }

  REP(_,q){
    int x;
    char C;
    cin >> x >> C;
    x--;
    if(s[x]==C){
      cout << ans << endl;
    }else{
      s[x]=C;
      int cc = c[x];
      if(cc==1){
        c[x]=0; c[x+1]=0; c[x+2]=0;
        ans--;
      }else if(cc==2){
        c[x-1]=0; c[x]=0; c[x+1]=0;
        ans--;
      }else if(cc==3){
        c[x-2]=0; c[x-1]=0; c[x]=0;
        ans--;
      }
      if(x>=2 && s.substr(x-2,3) == "ABC"){
          c[x-2]=1; c[x-1]=2; c[x]=3;
          ans++;
      }
      if(x>=1 && x < n-1 && s.substr(x-1,3) == "ABC"){
        c[x-1]=1; c[x]=2; c[x+1]=3;          
        ans++;
      }
      if(x < n-2 && s.substr(x,3) == "ABC"){
        c[x]=1; c[x+1]=2; c[x+2]=3;                    
        ans++;
      }
      // REP(i,n){
      //   cout << c[i] << (i==n-1 ? "\n" : " ");
      // }
      cout << ans << endl;
    }

  } 
}

