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
  int n;
  cin >> n;

  int l=1;
  int r=n;
  int m=(l+r)/2;
  while(l<r){
    printf("? %d %d %d %d\n",l,m,1,n);
    fflush(stdout);
    int x;
    cin >> x;
    if(m-l+1 == x){
      l = m+1;
      m = (l+r)/2;
    }else{
      r=m;
      m=(l+r)/2;
    }
  }

  int ans1=l;

  l=1;
  r=n;
  m=(l+r)/2;
  while(l<r){
    printf("? %d %d %d %d\n",1,n,l,m);
    fflush(stdout);
    int x;
    cin >> x;
    if(m-l+1 == x){
      l = m+1;
      m = (l+r)/2;
    }else{
      r=m;
      m=(l+r)/2;
    }
  }

  int ans2=l;
  printf("! %d %d\n",ans1, ans2);


}

