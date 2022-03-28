#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nline "\n"
class SegmentTree
{

    ll size = 0;
    vector<ll> values;

public:
    SegmentTree(ll n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        values.assign(2 * size, 0ll);
    }
    void build(vector<ll> &arr, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (ll)arr.size())
                values[x] = arr[lx];
            return;
        }
        ll m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    ll calc(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
            return 0;
        if (l <= lx && rx <= r)
            return values[x];
        ll m = (lx + rx) / 2;
        ll s1 = calc(l, r, 2 * x + 1, lx, m);
        ll s2 = calc(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    void set(ll i, ll val, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            values[x] = val;
            return;
        }
        ll m = (lx + rx) / 2;
        if (i < m)
            set(i, val, 2 * x + 1, lx, m);
        else
            set(i, val, 2 * x + 2, m, rx);
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }
    void prll(void)
    {
        cout << values.size() << " : ";
        for (ll i : values)
            cout << i << "  ";
        cout << nline;
    }

    void build(vector<ll> arr) { return build(arr, 0, 0, size); }
    void set(ll i, ll val) { return set(i, val, 0, 0, size); }
    ll calc(ll l, ll r) { return calc(l, r, 0, 0, size); }
};
int main()
{
    ll n, op;
    cin >> n >> op;
    vector<ll> arr(n);
    SegmentTree st(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    st.build(arr);
    // st.prll();

    while (op--)
    {
        ll type, a, b;
        cin >> type >> a >> b;
        if (type == 1)
        {
            st.set(a, b);
        }
        else
        {
            cout << st.calc(a, b) << nline;
        }
        // st.prll();
    }
    return 0;
}
