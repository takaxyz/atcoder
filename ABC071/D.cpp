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

int main(){
    int N;
    cin >> N;

    string s1, s2;

    cin >> s1 >> s2;

    int i = 0;

    ll ans = 0;
    int flag;
    if(s1[i] == s2[i]){
        ans = 3;
        i += 1;
        flag = 1;
    }else{
        ans = 6;
        i += 2;
        flag = 2;
    }

    while(i < N){
        if(s1[i] == s2[i]){
            if(flag == 1){
                ans *= 2;
                ans %= MOD;
            }
            i += 1;
            flag = 1;
        }else{
            if(flag == 1){
                ans *= 2;
                ans %= MOD;
            }else{
                ans *= 3;
                ans %= MOD;
            }
            i += 2;
            flag = 2;
        }
    }

    cout << ans << endl;
}