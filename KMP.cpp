#include <bits/stdc++.h>
using namespace std;

void createLPS(vector<int> &lps, string &pat)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat.size())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
bool isMatch(string &s, string &pat)
{
    // create LPS
    int N = s.length(), M = pat.length();

    vector<int> lps(pat.size(), 0);
    createLPS(lps, pat);
    int i = 0; // index for s[]
    int j = 0; // index for pat[]
    while (i < N)
    {
        if (pat[j] == s[i])
        {
            j++;
            i++;
        }

        if (j == M)
            return true;
        
        else if (i < N && pat[j] != s[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}
void solve()
{
    string s, pat;
    cin >> s >> pat;
    cout << isMatch(s, pat);
}
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}