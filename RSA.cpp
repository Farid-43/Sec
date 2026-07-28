#include <bits/stdc++.h>
using namespace std;
using ll = __int128_t;

ll gcd(ll a, ll b)
{
    ll c;
    while (b)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

ll ex(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll xx, yy, g = ex(b, a % b, xx, yy);
    x = yy;
    y = xx - (a / b) * yy;
    return g;
}

ll modinv(ll e, ll phi)
{
    ll x, y, g = ex(e, phi, x, y);
    if (g != 1)
    {
        return -1;
    }
    x %= phi;
    if (x < 0)
        x += phi;
    return x;
}

ll modpow(ll b, ll p, ll m)
{
    ll r = 1;
    b %= m;
    while (p)
    {
        /* code */
        if (p & 1)
            r = (r * b) % m;
        b = (b * b) % m;
        p /= 2;
    }
    return r;
}

ll hs(const string &s, ll m)
{
    ll hval = 0;
    ll p = 31;
    for (char c : s)
    {
        hval = (hval * p + c) % m;
    }
    return hval;
}

void prnt(ll n)
{
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (n < 0)
    {
        cout << "-";
        n = -n;
    }
    string r;
    while (n)
    {
        r.push_back(char('0' + n % 10));
        n /= 10;
    }
    reverse(r.begin(), r.end());
    cout << r << endl;
}

int main()
{
    ll p = 1000000007, q = 1000000009;
    ll n = p * q, phi = (p - 1) * (q - 1);
    ll e;
    for (e = 2; e < phi; e++)
    {
        if (gcd(e, phi) == 1)
            break;
    }
    ll d = modinv(e, phi);

    // (Rsa signature with msg and number)
    // // ll msg = 123443533;
    // string msg = "Hello world 1204";
    // ll h = hs(msg, n);
    // cout << "hash: ";
    // // prnt(msg);
    // prnt(h);

    // // ll sig = modpow(msg, d, n);
    // ll sig = modpow(h, d, n);
    // cout << "sig: ";
    // prnt(sig);

    // ll ver = modpow(sig, e, n);
    // cout << "ver:";
    // prnt(ver);
    // if (ver == h)
    //     cout << "Valid" << endl;
    // else
    //     cout << "Invalid" << endl;

    // (Rsa product cipher)
    ll m1 = 65, m2 = 77;
    ll c1 = modpow(m1, e, n), c2 = modpow(m2, e, n);
    cout << "Enc(m1): ";
    prnt(c1);
    cout << "Enc(m2): ";
    prnt(c2);

    ll prod = (c1 * c2) % n;
    cout << "combined cipher: ";
    prnt(prod);

    ll dec = modpow(prod, d, n);
    cout << "Decrypted product:";
    prnt(dec);
    cout << "Expected:";
    ll v = (m1 * m2) % n;
    prnt(v);
}