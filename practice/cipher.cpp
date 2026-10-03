#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string matrix[2][2] = {
        {"KUET", "CSE"},
        {"BATCH", "2K21"}};

    string transposed[2][2];
    for (ll i = 0; i < 2; i++)
    {
        for (ll j = 0; j < 2; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "Original matrix:" << endl;
    for (ll i = 0; i < 2; i++)
    {
        cout << matrix[i][0] << " " << matrix[i][1] << endl;
    }

    cout << "\nTransposed matrix:" << endl;
    for (ll i = 0; i < 2; i++)
    {
        cout << transposed[i][0] << " " << transposed[i][1] << endl;
    }
    string recovered[2][2];
    for (ll row = 0; row < 2; row++)
    {
        for (ll col = 0; col < 2; col++)
        {
            string s = transposed[row][col];
            char c;
            ll j, i;
            string bin = "";
            for (i = 0; i < s.length(); i++)
            {
                c = s[i];
                for (j = 128; j > 0; j /= 2)
                {
                    if (c & j)
                        bin += '1';
                    else
                        bin += '0';
                }
            }
            cout << "\nString\t" << s << endl;
            cout << "Binary\t" << bin << endl;

            string k = "";
            for (i = 0; i < bin.length(); i++)
            {
                if (rand() % 2)
                    k += '1';
                else
                    k += '0';
            }

            string en = "";
            for (i = 0; i < bin.length(); i++)
            {
                if (bin[i] == k[i])
                    en += '0';
                else
                    en += '1';
            }
            cout << "Enc:\t" << en << endl;

            string dec = "";
            for (i = 0; i < en.length(); i++)
            {
                if (en[i] == k[i])
                    dec += '0';
                else
                    dec += '1';
            }
            cout << "DEC\t" << dec << endl;

            string org = "";
            for (i = 0; i < dec.length(); i += 8)
            {
                c = 0;
                for (j = 0; j < 8; j++)
                {
                    c *= 2;
                    if (dec[i + j] == '1')
                        c += 1;
                }
                org += c;
            }
            cout << "Original msg:\t" << org << endl;

            recovered[col][row] = org;
        }
    }

    for (ll i = 0; i < 2; i++)
    {
        cout << recovered[i][0] << " " << recovered[i][1] << endl;
    }

    return 0;
}
