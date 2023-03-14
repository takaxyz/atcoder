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

char conv(char c){
  if(c=='a')return 'b';
  if(c=='b')return 'c';
  if(c=='c')return 'a';
}


char conv2(char c){
  if(c=='b')return 'a';
  if(c=='c')return 'b';
}

void solve(string s, int x){
//  printf(" %s\n",s.c_str());
  int i = 0;
  while(i < s.size() && s[i] == 'a')i++;

  if(s.size() ==i){
    cout << x << endl;
    return;
  }

  s[i]=conv2(s[i]);
  i--;
  while(i >= 0){
    s[i] =  conv(s[i]);
    i--;
  }

  solve(s, x+1);

}

int main(){
  REP(i,3)REP(j,3)REP(k,3){
    string s;
    s += char('a'+k);
    s += char('a'+j);
    s += char('a'+i);
    cout << s << " ";
    solve(s,0);
  }

}

