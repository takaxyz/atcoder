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
  int x;
  vi v2, v3;
  REP(i,n){
    int a;
    cin >> a;

    int c2 = 0; 
    while(a%2==0){
      a /= 2;
      c2++;
    }
    v2.emplace_back(c2);
    int c3 = 0; 
    while(a%3==0){
      a /= 3;
      c3++;
    }
    v3.emplace_back(c3);
    if(i==0){
      x = a;
    }else{
      if(a!=x){
        cout << -1 << endl;
        return 0;
      }
    }
  }

  sort(ALL(v2));
  sort(ALL(v3));

  int ans=0;
  for(auto v: v2){
    ans += v - v2[0];
  }
  for(auto v: v3){
    ans += v - v3[0];
  }
  cout << ans << endl;
}

