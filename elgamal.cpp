#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exg(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll xx, yy, g = exg(b, a % b, xx, yy);
    x = yy;
    y = xx - (a / b) * yy;
    return g;
}

ll modin(ll e, ll phi)
{
    ll x, y, g = exg(e, phi, x, y);
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

int main()
{
    /*product cipher*/
    {
        ll p = 23, alpha = 10, a = 4;
        ll b = modpow(alpha, a, p);
        cout << "public:\t" << p << "\t" << alpha << "\t" << b << endl;
        cout << "private:" << a << endl;

        ll m1 = 5, m2 = 9, r1 = 7, r2 = 11;
        ll c11 = modpow(alpha, r1, p);
        ll c12 = (m1 * modpow(b, r1, p)) % p;

        ll c21 = modpow(alpha, r2, p);
        ll c22 = (m2 * modpow(b, r2, p)) % p;

        ll c1p = (c11 * c21) % p;
        ll c2p = (c12 * c22) % p;

        cout << "Combined :\t" << c1p << "\t" << c2p << endl;

        ll s = modpow(c1p, a, p);
        ll sinv = modin(s, p);
        ll dec = (c2p * sinv) % p;

        cout << "Mdec:\t" << dec << "\t Expected:\t" << (m1 * m2) % p << endl;
    }

    /*rerandomization*/
    /*
    {
        ll p = 23, alpha = 10, a = 4;
        ll b = modpow(alpha, a, p);
        cout << "public:\t" << p << "\t" << alpha << "\t" << b << endl;
        cout << "private:\t" << a << endl;

        ll m = 20, r = 7;
        ll c1 = modpow(alpha, r, p);
        ll c2 = (m * modpow(b, r, p)) % p;
        cout << "Original Cipher:\t" << c1 << "\t" << c2 << endl;

        ll r2 = 9;
        ll c1n = (c1 * modpow(alpha, r2, p)) % p;
        ll c2n = (c2 * modpow(b, r2, p)) % p;
        cout << "Re-randomized Cipher:\t" << c1n << "\t" << c2n << endl;

        ll s = modpow(c1n, a, p);
        ll sinv = modin(s, p);
        ll dec = (c2n * sinv) % p;

        cout << "Mdec:\t" << dec << "\t Expected:\t" << m << endl;
    }
    */

    /*signature*/
    /*
    {
        ll p = 23, alpha = 10, a = 4;
        ll b = modpow(alpha, a, p);
        cout << "Public key (p, alpha, beta):\t" << p << "\t" << alpha << "\t" << b << endl;
        cout << "Private key a:\t" << a << endl;

        ll msg;
        cout << "Enter message (integer): ";
        cin >> msg;

        ll r = 5;
        if (__gcd(r, p - 1) != 1)
        {
            cout << "r not coprime to p-1" << endl;
            return 0;
        }

        ll y1 = modpow(alpha, r, p);
        ll rinv = modin(r, p - 1);
        ll y2 = (rinv * (msg - a * y1)) % (p - 1);
        if (y2 < 0)
            y2 += (p - 1);

        cout << "Signature (y1, y2):\t" << y1 << "\t" << y2 << endl;

        ll left = modpow(alpha, msg, p);
        ll right = (__int128)modpow(b, y1, p) * modpow(y1, y2, p) % p;

        cout << (left == right ? "Signature VALID" : "Signature INVALID") << endl;
    }
    */

    /*elgamal encryption/decryption*/
    /*
    {
        ll p = 23, alpha = 10, a = 4;
        ll b = modpow(alpha, a, p);
        cout << "Public key (p, alpha, beta):\t" << p << "\t" << alpha << "\t" << b << endl;
        cout << "Private key a:\t" << a << endl << endl;

        ll m = 42;
        ll r = 13;
        ll c1 = modpow(alpha, r, p);
        ll c2 = (m * modpow(b, r, p)) % p;
        cout << "Message m:\t" << m << endl;
        cout << "Random r:\t" << r << endl;
        cout << "Encrypted (c1, c2):\t" << c1 << "\t" << c2 << endl << endl;

        ll s = modpow(c1, a, p);
        ll sinv = modin(s, p);
        ll dec = (c2 * sinv) % p;
        cout << "Decrypted m:\t" << dec << endl;
        cout << (dec == m ? "Decryption CORRECT" : "Decryption FAILED") << endl;
    }
    */

    return 0;
}