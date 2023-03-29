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

int main(){
    Fero();

    map <string, string> mp;
    for(int i = 0; i < 7; i++){
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
    }
    TC{
        string z1, time1;
        cin >> z1 >> time1;
        string time2 = mp[z1];
        int h1 = stoi(time1.substr(0, 2));
        int m1 = stoi(time1.substr(3, 2));
        int s1 = stoi(time1.substr(6, 2));
        int h2 = stoi(time2.substr(0, 2));
        int m2 = stoi(time2.substr(3, 2));
        int s2 = stoi(time2.substr(6, 2));
        int ans = 0;
        if(h1 < h2 || (h1 == h2 && m1 < m2) || (h1 == h2 && m1 == m2 && s1 < s2)){
            ans += (h2 - h1) * 3600;
            ans += (m2 - m1) * 60;
            ans += (s2 - s1);
        }
        else{
            string nextDay = "";
            if(z1 == "Saturday") nextDay = "Sunday";
            else if(z1 == "Sunday") nextDay = "Monday";
            else if(z1 == "Monday") nextDay = "Tuesday";
            else if(z1 == "Tuesday") nextDay = "Wednesday";
            else if(z1 == "Wednesday") nextDay = "Thursday";
            else if(z1 == "Thursday") nextDay = "Friday";
            else if(z1 == "Friday") nextDay = "Saturday";
            string time3 = mp[nextDay];
            int h3 = stoi(time3.substr(0, 2));
            int m3 = stoi(time3.substr(3, 2));
            int s3 = stoi(time3.substr(6, 2));
            ans = 86400;
            if(h3 < h1 || (h3 == h1 && m3 < m1) || (h3 == h1 && m3 == m1 && s3 < s1)){
                ans -= (h1 - h3) * 3600;
                ans -= (m1 - m3) * 60;
                ans -= (s1 - s3);
            }
            else ans += (h3 - h1) * 3600 + (m3 - m1) * 60 + (s3 - s1);

        }
        cout << ans << endl;
    }
    
    


    return 0;
}
