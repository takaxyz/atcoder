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
  map<int,int> mp1,mp2;
  int n;
  cin >> n;
  vi a(n),b(n);
  REP(i,n){
    cin >> a[i];
    mp1[a[i]]++;
  }
  REP(i,n){
    cin >> b[i];
    mp2[b[i]]++;
  }

  for(auto v: mp2){
    if(n - mp1[v.first] < v.second){
      cout << "No" << endl;
      return 0;
    }
  }
  sort(RALL(b));

  auto ia=a.begin();
  auto ib=b.begin();

  while(ia!=a.end()){
    if(ia!=a.begin())cout << " ";
    if(*ia != *ib){
      cout << *ib;
      ia++;
      b.erase(ib);
      ib=b.begin();
    }else{
      while()

    }
  }
  cout << endl;
}

