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

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll xx, yy, g = exgcd(b, a % b, xx, yy);

    x = yy;
    y = xx - (a / b) * yy;

    return g;
}

ll modinv(ll e, ll phi)
{
    ll x, y, g = exgcd(e, phi, x, y);

    if (g != 1)
        return -1;

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
        if (p & 1)
            r = (r * b) % m;

        b = (b * b) % m;

        p /= 2;
    }

    return r;
}

ll hs(const string &s, ll m)
{
    ll hv = 0;
    ll p = 31;

    for (char c : s)
    {
        hv = (hv * p + c) % m;
    }

    return hv;
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
    // =========================
    // ALICE KEY GENERATION
    // =========================

    ll p = 1000000007, q = 1000000009;

    ll n = p * q;

    ll phi = (p - 1) * (q - 1);

    ll e, d;

    for (e = 2; e < phi; e++)
    {
        if (gcd(e, phi) == 1)
            break;
    }

    d = modinv(e, phi);

    // =========================
    // BOB KEY GENERATION
    // =========================

    ll p2 = 1000000033, q2 = 1000000087;

    ll n2 = p2 * q2;

    ll phi2 = (p2 - 1) * (q2 - 1);

    ll e2, d2;

    for (e2 = 2; e2 < phi2; e2++)
    {
        if (gcd(e2, phi2) == 1)
            break;
    }

    d2 = modinv(e2, phi2);

    // =========================
    // KEYS
    // =========================

    cout << "Alice Public Key (e,n): e = ";
    prnt(e);

    cout << "Alice Private Key (d,n): d = ";
    prnt(d);

    cout << "Bob Public Key (e,n): e = ";
    prnt(e2);

    cout << "Bob Private Key (d,n): d = ";
    prnt(d2);

    // =========================
    // MESSAGE
    // =========================

    string msg = "Hello world 112";

    ll h = hs(msg, n);

    cout << "msg:\t" << msg << endl;

    cout << "Hash:\t";
    prnt(h);

    // =================================================
    // 1. ALICE CREATES DIGITAL SIGNATURE
    // =================================================

    // S = H^dA mod nA

    ll s = modpow(h, d, n);

    cout << "Sig:\t";
    prnt(s);

    // =================================================
    // 2. ALICE ENCRYPTS THE HASH USING BOB'S PUBLIC KEY
    // =================================================

    // C = H^eB mod nB

    ll cipher = modpow(h, e2, n2);

    cout << "Cipher:\t";
    prnt(cipher);

    // =================================================
    // 3. BOB DECRYPTS USING HIS PRIVATE KEY
    // =================================================

    // H' = C^dB mod nB

    ll decryptedHash = modpow(cipher, d2, n2);

    cout << "Decrypted Hash:\t";
    prnt(decryptedHash);

    // =================================================
    // 4. BOB VERIFIES ALICE'S SIGNATURE
    // =================================================

    // H'' = S^eA mod nA

    ll verifiedHash = modpow(s, e, n);

    cout << "Verified Hash:\t";
    prnt(verifiedHash);

    // =================================================
    // 5. CHECK
    // =================================================

    if (decryptedHash == h && verifiedHash == h)
    {
        cout << "Valid Signature and Encryption" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}