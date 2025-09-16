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
  string s;
  int n;
  cin >> s >> n;
  vi cv(26);
  REP(_,n){
    char c;
    int v;
    cin >> c >> v;
    cv[c-'a'] = v;
  }
  int ans;
  
  if(s[0] >= '0' && s[0] <= '9'){
    ans = s[0] - '0';
  }else{
    ans = cv[s[0] - 'a'];
  }
  
  for(int i = 1; i <= s.size(); i+= 2){
    int x;
    if(s[i+1] >= '0' && s[i+1] <= '9'){
      x = s[i+1] - '0';
    }else{
      x = cv[s[i+1] - 'a'];
    }
    if(s[i]=='+'){
      ans += x;
    }else{
      ans -= x;
    }
  }
  cout << ans << endl;
}

