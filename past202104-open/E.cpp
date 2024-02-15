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

using mint = modint1000000007;
// using mint = modint998244353;

int main(){
  int n;
  cin >> n;
  deque<int> q;
  REP(i,n){
    char c;
    cin >> c;
    if(c=='L')q.push_front(i+1);
    else if(c=='R')q.push_back(i+1);
    else if(c=='A'){
      if(q.size()<1)cout << "ERROR" << endl;
      else{
        cout << q[0] << endl;
        q.pop_front();
      }
    }
    else if(c=='B'){
      if(q.size()<2)cout << "ERROR" << endl;
      else{
        cout << q[1] << endl;
        q.erase(q.begin()+1);
      }
    }
    else if(c=='C'){
      if(q.size()<3)cout << "ERROR" << endl;
      else{
        cout << q[2] << endl;
        q.erase(q.begin()+2);
      }
    }
    else if(c=='D'){
      if(q.size()<1)cout << "ERROR" << endl;
      else{
        cout << q[q.size()-1] << endl;
        q.erase(q.end()-1);
      }
    }
    else if(c=='E'){
      if(q.size()<2)cout << "ERROR" << endl;
      else{
        cout << q[q.size()-2] << endl;
        q.erase(q.end()-2);
      }
    }
    else if(c=='F'){
      if(q.size()<3)cout << "ERROR" << endl;
      else{
        cout << q[q.size()-3] << endl;
        q.erase(q.end()-3);
      }
    }
  }
}

