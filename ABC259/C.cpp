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
  string s,t;
  cin >> s >> t;

  vector<pair<char, int>> ss, tt;

  char c = s[0];
  int cnt = 0;
  REP(i,s.size()){
    if(c==s[i]){
      cnt++;
    }else{
      ss.emplace_back(c,cnt);
      c = s[i];
      cnt=1;
    }
  }
  ss.emplace_back(c,cnt);

  c = t[0];
  cnt = 0;
  REP(i,t.size()){
    if(c==t[i]){
      cnt++;
    }else{
      tt.emplace_back(c,cnt);
      c = t[i];
      cnt=1;
    }
  }
  tt.emplace_back(c,cnt);

  // for(auto [c, cnt]: ss){
  //   cout << c << " " << cnt << endl;
  // }

  if(tt.size()!=ss.size()){
    cout << "No" << endl;
    return 0;
  }

  REP(i, ss.size()){
    if(ss[i].first != tt[i].first){
      cout << "No" << endl;
      return 0;
    }

    if(ss[i].second < tt[i].second && ss[i].second==1){
      cout << "No" << endl;
      return 0;
    }    
    if(ss[i].second > tt[i].second){
      cout << "No" << endl;
      return 0;
    }    

  }
  cout << "Yes" << endl;

}

