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

string solve(string s){
  int cnt = 0;
  string ret="";
  for(int i = 0; i < s.size(); i++){
    if(s[i] != '('){
      ret += s[i];
    }else{
      string tmp;
      ll cnt=1;
      i++;
      for(; i < s.size(); i++){
        if(s[i]=='(')cnt++;
        else if(s[i]==')')cnt--;
        if(cnt==0)break;
        tmp += s[i];
      }
      tmp = solve(tmp);
      ret += tmp;
      reverse(ALL(tmp));
      ret += tmp;
    }
  }
  return ret;
}

int main(){
  string s;
  cin >> s;
  cout << solve(s) << endl;

}

