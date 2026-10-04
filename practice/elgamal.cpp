// elgamal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    ll t;
    while (b)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll modp(ll b, ll p, ll m)
{
    ll r = 1;
    while (p)
    {
        r = (r * b) % m;
        p--;
    }
    return r;
}

ll modin(ll x, ll m)
{
    ll i;
    for (i = 1; i < m; i++)
    {
        if ((x * i) % m == 1)
            return i;
    }
    return -1;
}

int main()
{
    ll p = 79, alp = 3, a = 10, r = 7, m = 5;
    ll b = modp(alp, a, p);

    /*
    //enc dec
    ll c1 = modp(alp,r,p);
    ll c2 = modp(b, r, p);
    c2 = (c2*m)%p;

    ll c1a = modp(c1,a,p);
    ll in = modin(c1a,p);
    ll dec = (c2*in)%p;

    cout<<dec<<endl;
    */

    /*
    // Homo
    ll r1=7, r2=11 , m1=5, m2=4;

    ll c11 =modp(alp,r1,p);
    ll c12 =(modp(b,r1,p) * m1) %p;
    ll c21 = modp(alp,r2,p);
    ll c22 = (modp(b,r2,p)*m2)%p;

    ll c1 = (c11*c21)%p;
    ll c2 = (c12*c22)%p;

    ll c1a = modp(c1,a,p);
    ll in = modin(c1a,p);
    ll dec = (c2*in)%p;
    cout<<dec<<endl;
    */

    /*
    // Redandomize
    ll r1=7, r2=11;

    ll c1 = modp(alp,r1,p);
    ll c2 = (modp(b,r1,p)*m)%p;

    c1 =(c1* modp(alp,r2,p))%p;
    c2 = (c2* modp(b,r2,p))%p;

    ll c1a = modp(c1,a,p);
    ll in = modin(c1a,p);
    ll dec = (c2*in)%p;
    cout<<dec<<endl;
    */

    // signature
    ll y1 = modp(alp, r, p);
    ll rin = modin(r, p - 1);
    ll y2 = (rin * (m - a * y1) % (p - 1)) % (p - 1);
    if (y2 < 0)
        y2 += p - 1;
    cout << y1 << endl;
    cout << y2 << endl;

    ll l = modp(alp, m, p);
    cout << l << endl;

    ll ri = (modp(b, y1, p) * modp(y1, y2, p)) % p;
    cout << ri << endl;

    if (l == ri)
        cout << "Valid" << endl;

    return 0;
}
