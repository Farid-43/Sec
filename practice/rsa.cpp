#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    ll t;
    while(b!=0){
        t = b;
        b= a%b;
        a = t;
    }
    return a;
}

ll modp(ll b, ll p, ll m){
    ll r=1;
    while(p){
        r = (r*b)%m;
        p--;
    }
    return r;
}

ll modin(ll x, ll m){
    ll i;
    for(i=1;i<m;i++){
        if((x*i)%m ==1) return i;
    }
    return -1;
}

ll hs(const string &s, ll m){
    ll hv = 0;
    ll p=31;

    for(char c:s){
        hv = (hv*p +c)%m;
    }
    return hv;

}

int main(){
    ll p=11,q=13;
    ll n=p*q, phi = (p-1)*(q-1);

    ll m=11;
    ll e,d;
    for(e=2;e<phi;e++){
        if(gcd(e,phi)==1) break;
    }
    // d = modin(e,phi)
    for(d=1;d<phi;d++){
        if((e*d)%phi ==1 ) break;
    }

    /*
    //enc, dec
    ll c= modp(m,e,n);
    cout<<c<<endl;
    ll dec = modp(c,d,n);

    cout<<dec<<endl;
    */

    /*
    //signature
    //receiver
    ll pr = 17, qr = 19;
    ll nr = pr*qr, phir = (pr-1)*(qr-1);
    ll er,dr;
    for(er=2;er<phir;er++) {
        if(gcd(er,phir)==1) break;
    }
    for(dr=1;dr<phir;dr++){
        if((er*dr)%phir == 1) break;
    }

    ll s = modp(m,d,n);
    cout<<"Signature: "<<s<<endl;
    ll c = modp(s,er,nr);
    cout<<"Enc: "<<c<<endl;

    ll dec = modp(c,dr,nr);
    cout<<"Dec: "<<dec<<endl;
    ll mm = modp(dec,e,n);
    cout<<"MSG ";
    cout<<mm<<endl;
    */


    // Homomorphic enc
    ll m1 = 20, m2 =3;
    ll c1= modp(m1,e,n);
    cout<<"C1 "<<c1<<endl;
    ll c2= modp(m2,e,n);
    cout<<"C2 "<<c2<<endl;

    ll c = (c1%n * c2%n)%n;
    cout<<"C "<<c<<endl;

    ll d1 = modp(c1,d,n);
    cout<<"D1 "<<d1<<endl;
    ll d2 = modp(c2,d,n);
    cout<<"D2 "<<d2<<endl;
    ll dec = modp(c,d,n);
    cout<<dec<<endl;




}

