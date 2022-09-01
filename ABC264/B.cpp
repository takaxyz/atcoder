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
  int r,c;
  cin >> r >> c;
  r--;c--;
  int b;
  switch (r)
  {
  case 0:
  case 14:
    b = 1;
    /* code */
    break;
  case 1:
  case 13:
    if(c==0 || c == 14)b=1;
    else b = 0;
    /* code */
    break;
  case 2:
  case 12:
    if(c==1 || c == 13)b=0;
    else b = 1;
    /* code */
    break;
  case 3:
  case 11:
    if(c==0 || c == 2 || c == 14 || c == 12)b=1;
    else b = 0;
    /* code */
    break;
  case 4:
  case 10:
    if(c==1 || c == 13 || c == 3 || c == 11)b=0;
    else b = 1;
    /* code */
    break;
  case 5:
  case 9:
    if(c==0 || c == 2 || c == 4 || c == 14 || c == 12 || c == 10)b=1;
    else b = 0;
  case 6:
  case 8:
    if(c==1 || c == 13 || c == 3 || c == 11 || c == 5 || c == 9)b=0;
    else b = 1;
  case 7:
    if(c%2)b = 0;
    else b = 1;
  
  default:
    break;
  }
  cout << (b ? "black" : "white") << endl;
}

