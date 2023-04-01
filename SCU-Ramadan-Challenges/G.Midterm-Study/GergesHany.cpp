#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;

#define EPS 1e-8
#define sz(s) int(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define TC int t; cin >> t; while(t--)
#define getline(s) getline(cin >> ws, s)
#define all(vec)  vec.begin(),  vec.end()
#define updmin(a, b) a = min((ll)a, (ll)b)
#define updmax(a, b) a = max((ll)a, (ll)b)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endd(s) return void(cout << s << "\n")
#define fixed(n) cout << fixed << setprecision(n)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define cin_2d(vec, n, m) for(int i=0;i<n;i++) for(int j=0;j<m&&cin>>vec[i][j];j++);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define ordered_set tree<ll, null_type, less <ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<ll, null_type, less_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;
typedef long double ld;
const ll N = 2 * 1e5 + 5;
const ll mod = 1000000007;
const ll INF = 1LL << 60;

void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x; return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; return out;
}


void Accepted(){

  int k;
  cin >> k;
  string s;
  getline(s);

  int len = 0;
  vector < int > len_of_words;
  for(int i = 0; i < sz(s); i++){
    // the end of the word
    if(s[i] == ' ' || s[i] == '.')
      len_of_words.push_back(len), len = 0;
    else len++;
  }

  len_of_words.push_back(len); // the last word
  
  // binary search
  // the left is the max length of the word because we can't split the word
  ll l = *max_element(all(len_of_words)), r = sz(s), ans = sz(s);

  // check if the mid is good 
  auto is_good = [&](ll mid){
    // cnt equal the number of words
    // curr equal the length of the current line
    ll cnt = 1, curr = 0;
    for(auto& w : len_of_words){
      // if the current word can be added to the current line add it 
      if(curr + w <= mid) curr += w;
      // else add the word to the next line and increase the number of words
      else cnt++, curr = w;
    }
    // if the number of words is less than or equal k then the mid is good
    return cnt <= k;
  };

  // find the smallest number that is good
  while(l <= r){
    ll mid = l  + (r - l) / 2;
    // if the mid is good then the answer is the mid and search in the left because we want the smallest number
    if (is_good(mid)) ans = mid, r = mid - 1;
    else l = mid + 1; // else search in the right
  }

  cout << ans << "\n";

}

int main()
{

  Gerges_Hany();
  int testcaces = 1, T = 1;
   // cin >> testcaces;
  while (testcaces--){  
    // cout << "Scenario #" << T++ << ": \n";
    Accepted();
  }   
  Time; 
  return 0;
}