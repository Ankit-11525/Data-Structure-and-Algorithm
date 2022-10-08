#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define PI 3.1415926535897932384626
#define push_back pb
#define pop_back pob
#define all(v) v.begin(), v.end()
#define sortall(v) sort(all(v))
#define deb(x) cout << #x << x << endl
#define deb2(x, y) cout << #x << x << #y < < < < y << endl
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
//
//
//
// all typedef vectors,vectorofvectors
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
//============================
//
//
//
// function intialize
int mpow(int base, int exp);
const int mod = 1000000007;
//
//
//
// ---------------------Solve function
void solve()
{
}
//=============================
//
//
//
// main function
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    deb(t);
    while (t--)
    {

        solve();
    }
    return 0;
}
//=================================
//
//
//
int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}
