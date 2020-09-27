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

int fn(int n){
  int ret=1;
  while(n!=0){
    n %= ;
  }
}

int main(){
  int n;
  cin >> n;
  vector<char> s(n);
  int p = 0;
  REP(i,n){
    cin >> s[n-1-i];
    if(s[n-1-i]=='1')p++;
  }
  int m=1;
  int f1=0;
  p++;
  REP(i,n){
    int l = s[i] - '0';
    f1 += l * m;
    f1 %= p;
    m = m << 1;
    m %= p;
  }
  p-=2;
  m=1;
  int f2=0;
  REP(i,n){
    int l = s[i] - '0';
    f2 += l * m;
    f2 %= p;
    m = m << 1;
    m %= p;
  }

  m=1;
  REP(i,n){
    int l = s[i] - '0';
    if(l==1){
      f2 - m
    }else{
      f1 + m
    }

  }


}

