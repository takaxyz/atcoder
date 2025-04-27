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
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  REP(i,n){
    if(s[i]=='?'){
      if(i > 0 && s[i-1]=='o')s[i]='.';
      if(i < n-1 && s[i+1]=='o')s[i]='.';
    }
  }

  int cnt=0;

  REP(i,n)if(s[i]=='o')cnt++;
  if(cnt == k){
    REP(i,n)if(s[i]=='?')s[i]='.';
    cout << s << endl;
    return 0;
  }
  
  string t = s;

  REP(i,n){
    if(t[i] == '?'){
      bool ok = true;
      if(i > 0 && t[i-1] == 'o')ok=false;
      if(i > 0 && t[i+1] == 'o')ok=false;
      if(ok)t[i]='o';
    }
  }
  cnt=0;
  REP(i,n)if(t[i]=='o')cnt++;

  
  if(cnt > k){
    cout << s << endl;
    return 0;
  }
  //cout << t << endl;
  t = s;
  int l = 0, r = 0;
  while(true){
    while(l < n && t[l]!='?')l++;
    if(l==n)break;
    r = l;
    while(r < n && t[r]=='?')r++;
    //printf("%d %d\n",l,r);
    int len = r - l;
    if(len % 2 == 1){
      for(int i = 0; i < len; i++){
        if(i%2==0){
          t[l+i]='o';
        }else{
          t[l+i]='.';
        }
      } 
    }
    l = r;
  }

  cout  << t << endl;


}

