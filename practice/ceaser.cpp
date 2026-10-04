// ceaser
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string enc(string s, int sft)
{
    string res = "";
    for (char c : s)
    {
        if (c >= 'A' && c <= 'Z')
            res += char(int(c - 'A' + sft) % 26) + 'A';
        else if (c >= 'a' && c <= 'z')
            res += char(int(c - 'a' + sft) % 26) + 'a';
        else if (c >= '0' && c <= '9')
            res += char(int(c - '0' + sft) % 10) + '0';
        else
            res += c;
    }
    return res;
}

string dec(string s, int sft)
{
    string res = "";
    for (char c : s)
    {
        if (c >= 'A' && c <= 'Z')
            res += char(int(c - 'A' - sft + 26) % 26) + 'A';
        else if (c >= 'a' && c <= 'z')
            res += char(int(c - 'a' - sft + 26) % 26) + 'a';
        else if (c >= '0' && c <= '9')
            res += char(int(c - '0' - sft + 10) % 10) + '0';
        else
            res += c;
    }
    return res;
}

int main()
{
    cout << "Enter msg: ";
    string s;
    getline(cin, s);
    cout << "Enter Shift value: ";
    int sft;
    cin >> sft;

    string en = enc(s, sft);
    string de = dec(en, sft);

    cout << en << endl;
    cout << de << endl;
}
