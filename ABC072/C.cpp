#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
 
using namespace std;
 
typedef long long int ll;
 
const ll INF=(ll)1e18;
 
#define MAX 99999
 
int s[MAX+3];
 
int main(){
    int N;
    cin >> N;
 
    REP(i,MAX+3)s[i]=0;
 
    REP(i,N){
        int a;
        cin >> a;
 
        s[a]++;
        s[a+1]++;
        s[a+2]++;
    }
 
    int ans = 0;
 
    REP(i,MAX+3)ans = max(ans, s[i]);
 
    cout << ans << endl;
}