#include <bits/stdc++.h>
#define ll long long
#define OO 1e9
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.ren()
#define TC int t; cin >> t; while(t--)
using namespace std;
void Fero(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
    #endif
}

string tobin(ll n){
    string s = "";
    while(n){
        s += (n % 2) + '0';
        n /= 2;
    }
    reverse(all(s));
    return s;
}

int main(){
    Fero();

    ll n;
    cin >> n;
    vector < vector < ll > > v(n, vector < ll > (5));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            cin >> v[i][j];
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < n; j++){
            string s = tobin(v[j][i]);
            while(sz(s) < 5){   
                s = '0' + s;
            }
            for(int k = 0; k < 5; k++){
                if(s[k] == '1'){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
