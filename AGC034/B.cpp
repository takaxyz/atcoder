#include <bits/stdc++.h>
using namespace std;

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
  string s;
  cin >> s;
  vector<char> c;

  REP(i,s.size()-1){
    if(s[i]=='B' && s[i+1]=='C'){
      c.emplace_back('D');
      i++;
    }else{
      c.emplace_back(s[i]);
      if(i==s.size()-2){
        c.emplace_back(s[i+1]);
      }
    }
  }

  // REP(i,c.size()){
  //   cout << c[i];
  // }
  // cout << endl;

  ll cnt=0;
  ll ans=0;
  REP(i,c.size()){
    if(c[i]=='B' || c[i]=='C'){
      cnt=0;
    }else if(c[i]=='A'){
      cnt++;
    }else{
      ans += cnt;
    }

  }
  cout << ans << endl;
}

