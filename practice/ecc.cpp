// ecc
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modin(ll x, ll p)
{
    x %= p;
    if (x < 0)
        x += p;
    for (ll i = 1; i < p; i++)
    {
        if ((i * x) % p == 1)
            return i;
    }
    return -1;
}
ll p = 71, a = 2, x3, y3;
void add(ll x1, ll y1, ll x2, ll y2, ll p)
{
    ll s;
    if (x1 == x2 && y1 == y2)
    {
        s = ((3 * x1 * x1 + a) * modin(2 * y1, p)) % p;
        if (s < 0)
            s += p;
        x3 = ((s * s) - x1 - x2) % p;
        y3 = (s * (x1 - x3) - y1) % p;

        if (x3 < 0)
            x3 += p;
        if (y3 < 0)
            y3 += p;
    }
    else
    {
        s = ((y2 - y1) * modin(x2 - x1, p)) % p;
        if (s < 0)
            s += p;
        x3 = ((s * s) - x1 - x2) % p;
        y3 = (s * (x1 - x3) - y1) % p;

        if (x3 < 0)
            x3 += p;
        if (y3 < 0)
            y3 += p;
    }
}
void mul(ll x1, ll y1, ll k, ll p)
{
    ll x2 = x1, y2 = y1;
    for (ll i = 1; i < k; i++)
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
    ll gx = 5, gy = 1;
    ll k1 = 4, k2 = 5, d = 18;
    ll m1x = 32, m1y = 31, m2x = 11, m2y = 15;

    mul(gx, gy, d, p); // q = dg
    ll qx = x3, qy = y3;

    mul(gx, gy, k1, p); // c11
    ll c11x = x3, c11y = y3;

    mul(qx, qy, k1, p); // k1q
    ll kqx1 = x3, kqy1 = y3;

    add(m1x, m1y, kqx1, kqy1, p); // c2 = m +kq
    ll c12x = x3, c12y = y3;

    mul(gx, gy, k2, p); // c21
    ll c21x = x3, c21y = y3;

    mul(qx, qy, k2, p); // k2q
    ll kqx2 = x3, kqy2 = y3;

    add(m2x, m2y, kqx2, kqy2, p); // c22 = m +kq
    ll c22x = x3, c22y = y3;

    add(c11x, c11y, c21x, c21y, p); // c1 = c11+c21
    ll c1x = x3, c1y = y3;

    add(c12x, c12y, c22x, c22y, p); // c2 = c12+c22
    ll c2x = x3, c2y = y3;

    mul(c1x, c1y, d, p);
    ll dc1x = x3, dc1y = y3;

    ll negx = dc1x;
    ll negy = (p - dc1y) % p;

    add(c2x, c2y, negx, negy, p);
    ll msgx = x3, msgy = y3;

    cout << msgx << " " << msgy << endl;

    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modin(ll x, ll p){
    x = x%p;
    if(x<0) x+=p;

    for(ll i=1;i<p;i++){
        if((x*i)%p==1) return i;
    }
    return -1;

}

ll p=29,a=2;
ll x3,y3;

void add(ll x1,ll y1, ll x2, ll y2, ll p){
    ll s;
    if(x1==x2 && y1==y2){
        s = ((3*x1*x1 +a)* modin(2*y1,p))%p;
        if(s<0) s+=p;

        x3 = (s*s-x1-x2)%p;
        if(x3<0) x3+=p;

        y3 = (s*(x1-x3) - y1)%p;
        if(y3<0) y3+=p;


    }else{
        s = ((y2-y1)* modin(x2-x1,p))%p;

        if(s<0) s+=p;

        x3 = (s*s-x1-x2)%p;
        if(x3<0) x3+=p;

        y3 = (s*(x1-x3) - y1)%p;
        if(y3<0) y3+=p;

    }
}

void mul(ll x1, ll y1, ll k, ll p){
    ll x2=x1, y2=y1;
    ll i;
    for(i=1;i<k;i++){
        add(x1,y1,x2,y2,p);
        x2= x3;
        y2= y3;
    }
    x3= x2;
    y3= y2;
}


int main(){
    ll gx=5, gy=1;
    ll d=7;
    mul(gx,gy,d,p);     //q = dg
    ll qx=x3, qy=y3;
ll k=3;
    mul(gx,gy,k,p); // c1= kg
    ll c1x= x3, c1y = y3;
    cout<<"C1 :"<<c1x<<" "<<c1y<<endl;

    ll mx =6, my=3;

    mul(qx,qy,k,p);     // kq
    ll kqx = x3, kqy = y3;

    add(mx,my,kqx,kqy,p);
    ll c2x=x3, c2y=y3;
    cout<<"C2:"<<c2x<<" "<<c2y<<endl;

    mul(c1x,c1y,d,p)  ;  //dc1
    ll d1x= x3, d1y = y3;

    add(c2x,c2y,d1x,(p-d1y)%p,p) ;  // m = c2- dc1 ...
    cout<<"Dec msg: "<<x3<<" " <<y3<<endl;

    return 0;
}
*/
