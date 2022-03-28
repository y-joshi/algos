#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (k--)
    {
        int x;
        cin >> x;
        //put left limit - 1 in l and right limit + 1 in r and while(r > l + 1)
        int l = -1;     // a[l] < x
        int r = n; // a[r] >= x

        while (r > l + 1)
        {
            int m = (l + r) / 2;
            if (arr[m] >= x)
                r = m;
            else
                l = m;
        }
        if(r < n && arr[r] == x)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
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
