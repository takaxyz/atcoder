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


ll mex(int x,int y,int z){
  REP(i,3){
    if(x != i && y != i && z !=i)return i;
  }
  return 3;
}

int main(){
  int n;
  cin >> n;
  vi a(n);
  REP(i,n)cin >> a[i];
  string s;
  cin >> s;
  vi cntx(3);
  vi cntm(3);
  REP(i,n)if(s[i]=='X')cntx[a[i]]++;

  ll ans = 0;
  REP(i,n){
    if(s[i]=='M')cntm[a[i]]++;

    if(s[i]=='E'){
      REP(j,3)REP(k,3){
        ans += mex(a[i],j,k) * cntm[j] * cntx[k];
      }      
    }
    if(s[i]=='X')cntx[a[i]]--;
  }
  cout << ans << endl;


}
