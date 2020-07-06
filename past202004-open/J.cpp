#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define RALL(v) rbegin(v), rend(v)

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

//(ab)c  5
//01234

string rev(string s){
  // xxx(xxx)xxx
  int cnt_l =0;
  int cnt_r =0;

  string ret="";

  string x = "";
  REP(i,s.size()){
    if(s[i] == '('){
      cnt_l++;
      if(cnt_l==1)continue;
    }
    if(s[i] == ')'){
      cnt_r++;
    }

    if(cnt_l==0){
      ret += s[i];
      continue;
    }

    if(cnt_l > cnt_r){
      if(s[i]!='(')x += s[i];
    }else{
      cout << x << endl;
      string tmp = rev(x);
      ret += tmp;
      reverse(ALL(tmp));
      ret += tmp;
      cnt_l = 0;
      cnt_r = 0;
    }
  }
  return ret;
}

int main(){
  string S;
  cin >> S;

  cout << rev(S) << endl;

}

