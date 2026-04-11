#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vst vector<string>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvst vector<vector<string>>
#define vpii vector<pair<int,int>>
#define vpllll vector<pair<ll,ll>>
#define mpii map<int,int>
#define umpii unordered_map<int,int>
#define mpllll map<ll,ll>
#define umpllll unordered_map<ll,ll>
#define mpsi map<string,int>
#define mpis map<int,string>
#define mpsll map<string,ll>
#define mplls map<ll,string>
#define umpsi unordered_map<string,int>
#define umpis unordered_map<int,string>
#define umpsll unordered_map<string,ll>
#define umplls unordered_map<ll,string>
#define pii pair<int,int>
#define pllll pair<ll,ll>
#define psi pair<string,int>
#define pis pair<int,string>
#define psll pair<string,ll>
#define plls pair<ll,string>
#define si set<int>
#define sll set<ll>
#define sst set<string>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using ordered_multiset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve()
{
    cout<<"Hello, world! I am branching out.";
}

int main()
{
    fast_io;
    ll t = 1;
    // cin>>t;
    while(t--){solve();}
    return 0;
}