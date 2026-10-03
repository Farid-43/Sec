#include <iostream>
using namespace std;
typedef long long ll;

ll modinverse(ll x, ll p)
{
    x = x % p;

    if (x < 0)
    {
        x += p;
    }

    for (int i = 1; i < p; i++)
    {
        if ((x * i) % p == 1)
        {
            return i;
        }
    }

    return -1;
}

ll p = 17;
ll a = 2;

ll x3, y3;

void add(ll x1, ll y1, ll x2, ll y2, ll p)
{
    if (x1 == x2 && y1 == y2)
    {
        ll s = ((3 * x1 * x1 + a) *
                modinverse(2 * y1, p)) %
               p;

        if (s < 0)
        {
            s += p;
        }

        x3 = (s * s - x1 - x2) % p;

        if (x3 < 0)
        {
            x3 += p;
        }

        y3 = (s * (x1 - x3) - y1) % p;

        if (y3 < 0)
        {
            y3 += p;
        }
    }
    else
    {
        ll s = ((y2 - y1) *
                modinverse(x2 - x1, p)) %
               p;

        if (s < 0)
        {
            s += p;
        }

        x3 = (s * s - x1 - x2) % p;

        if (x3 < 0)
        {
            x3 += p;
        }

        y3 = (s * (x1 - x3) - y1) % p;

        if (y3 < 0)
        {
            y3 += p;
        }
    }
}

void multiply(ll x1, ll y1, ll k, ll p)
{
    ll x2 = x1;
    ll y2 = y1;

    for (int i = 1; i < k; i++)
    {
        add(x1, y1, x2, y2, p);

        x2 = x3;
        y2 = y3;
    }

    x3 = x2;
    y3 = y2;
}

int main()
{
    ll gx = 5;
    ll gy = 1;
    ll d = 7;

    // Q = dG
    multiply(gx, gy, d, p);

    ll qx = x3;
    ll qy = y3;

    cout << "Public Key Q = (" << qx << "," << qy << ")" << endl;
    /*
        ll k1 = 3;

        ll M1x = 6;
        ll M1y = 3;

        // C11 = k1 * G
        multiply(gx, gy, k1, p);

        ll C11x = x3;
        ll C11y = y3;

        // C12 = M1 + k1 * Q
        multiply(qx, qy, k1, p);

        ll k1Qx = x3;
        ll k1Qy = y3;

        add(M1x, M1y, k1Qx, k1Qy, p);

        ll C12x = x3;
        ll C12y = y3;

        ll k2 = 4;

        ll M2x = 3;
        ll M2y = 1;

        // C21 = k2 * G
        multiply(gx, gy, k2, p);

        ll C21x = x3;
        ll C21y = y3;

        // C22 = M2 + k2 * Q
        multiply(qx, qy, k2, p);

        ll k2Qx = x3;
        ll k2Qy = y3;

        add(M2x, M2y, k2Qx, k2Qy, p);

        ll C22x = x3;
        ll C22y = y3;

        cout << "\nCiphertext of M1:" << endl;
        cout << "C11 = (" << C11x << "," << C11y << ")" << endl;
        cout << "C12 = (" << C12x << "," << C12y << ")" << endl;
        cout << "\nCiphertext of M2:" << endl;
        cout << "C21 = (" << C21x << "," << C21y << ")" << endl;
        cout << "C22 = (" << C22x << "," << C22y << ")" << endl;
        // C1' = C11 + C21
        add(C11x, C11y, C21x, C21y, p);

        ll C1x = x3;
        ll C1y = y3;

        // C2' = C12 + C22
        add(C12x, C12y, C22x, C22y, p);

        ll C2x = x3;
        ll C2y = y3;

        cout << "\nHomomorphic Ciphertext:" << endl;

        cout << "C1' = C11 + C21 = (" << C1x << "," << C1y << ")" << endl;
        cout << "C2' = C12 + C22 = (" << C2x << "," << C2y << ")" << endl;
        // d * C1'
        multiply(C1x, C1y, d, p);

        ll dC1x = x3;
        ll dC1y = y3;

        // -dC1'
        ll negdC1x = dC1x;
        ll negdC1y = (p - dC1y) % p;

        // M1 + M2 = C2' - dC1'
        add(C2x, C2y, negdC1x, negdC1y, p);

        ll decryptedX = x3;
        ll decryptedY = y3;

        cout << "\nDecrypted M1 + M2:" << endl;
        cout << "(" << decryptedX << "," << decryptedY << ")" << endl;
        add(M1x, M1y, M2x, M2y, p);

        ll directX = x3;
        ll directY = y3;

        cout << "\nDirect M1 + M2:" << endl;
        cout << "(" << directX << "," << directY << ")" << endl;

        if (decryptedX == directX && decryptedY == directY)
            cout << "\nHomomorphic property verified!" << endl;
        else
            cout << "\nHomomorphic property failed!" << endl;
    */

    // Basic EC-ElGamal encryption and decryption.
    ll encK = 3;
    ll encMx = 6;
    ll encMy = 3;

    // C1 = kG
    multiply(gx, gy, encK, p);
    ll encC1x = x3;
    ll encC1y = y3;

    // C2 = M + kQ
    multiply(qx, qy, encK, p);
    ll encKQx = x3;
    ll encKQy = y3;

    add(encMx, encMy, encKQx, encKQy, p);
    ll encC2x = x3;
    ll encC2y = y3;

    cout << "\nBasic Ciphertext:" << endl;
    cout << "C1 = (" << encC1x << "," << encC1y << ")" << endl;
    cout << "C2 = (" << encC2x << "," << encC2y << ")" << endl;

    // M = C2 - dC1
    multiply(encC1x, encC1y, d, p);
    ll encDC1x = x3;
    ll encDC1y = y3;

    add(encC2x, encC2y, encDC1x, (p - encDC1y) % p, p);

    cout << "Decrypted message: (" << x3 << "," << y3 << ")" << endl;

    return 0;
}