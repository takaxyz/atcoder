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

// using mint = modint1000000007;
using mint = modint998244353;

bool  isPalindrome(string s){
  string s2 = s;
  reverse(ALL(s2));
  return s == s2;
}


int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;

  map<string,mint> dp;

  dp[""] = 1;

  for(auto c: s){
    map<string,mint> dp2;
    swap(dp2,dp);

    for(auto [ss, v] : dp2){
      if(ss.size() < k-1){
        if(c == '?'){
          dp[ss+"A"] += v;
          dp[ss+"B"] += v;
        }else{
          dp[ss+c] += v;
        }
        continue;
      }

      string t = ss.substr(1, ss.size()-1);

      if(c == '?'){
        if(!isPalindrome(ss + "A")){
          dp[t+"A"] += v;
        }

        if(!isPalindrome(ss+ "B")){
          dp[t+"B"] += v;
        }
      }else{
        if(!isPalindrome(ss + c)){
          dp[t+c] += v;
        }
      }
    }



  }
  mint ans;
  for(auto [ss,v]: dp){
//    cout << ss << endl;
    ans += v;
  }
  cout << ans.val() << endl;

}

