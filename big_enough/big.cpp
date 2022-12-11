#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
class BigInt{
    public:
        long long operator [](int i) const { return m[i]; }
        long long &operator [](int i) { return m[i]; }
        BigInt(){ l=1, m[0]=0; sign=1; }
        friend istream& operator>>(istream&, BigInt&);   
        friend ostream& operator<<(ostream&, BigInt);   
        BigInt operator +( const BigInt &y );  
        BigInt operator -( const BigInt &y );
    private:
        long long m[1000];
        int l;
        int sign;
};
istream& operator>>(istream & in,  BigInt & b) 
{
    string Num_str;
    in >> Num_str;
    if(Num_str[0] == '-')
    {
        b.sign = -1;
        Num_str = Num_str.substr(1);
        reverse(Num_str.begin(),Num_str.end());
        
    }
    else
    {
        b.sign = 1;
        reverse(Num_str.begin(),Num_str.end());
    }
    
    int idx = 0;
    for(int i=0;i<Num_str.length();i+=5)
    {
        string num_str = Num_str.substr(i,5);
        reverse(num_str.begin(),num_str.end());
        int num = stoi(num_str);
        b.m[idx++] = num;
    }
    b.l = idx;
    return in;
}
ostream& operator<<(ostream& out,  BigInt b) 
{
    if(b.sign == -1)out<<'-';
    out<<b.m[b.l-1];
    for(int i=b.l-2;i>=0;i--)
    {
        out.width(5);
        out.fill('0');
        out<<b.m[i];
    }
    return out;
}
BigInt BigInt::operator +(const BigInt &y) 
{
    BigInt x = (*this);
    long long carry = 0;
    long long max = 100000;
    int i=0;
    for(i=0;i<x.l || i<y.l ||carry;i++)
    {
        carry += ((i<x.l)*x.sign*x.m[i] + (i<y.l)*y.sign*y.m[i] );
        x.m[i] = carry%max;
        carry /= max;
    }
    x.l=i;
    for(;x.l>1 && x[x.l-1]==0;x.l--);
    x.sign = (x.m[x.l-1] < 0 ? -1 : 1);
    if(x.m[x.l-1]>=0)
    {
        for(int i=0;i<x.l;i++)
        {
            if(x.m[i] < 0)
            {
                x.m[i+1]--;
                x.m[i] += max;
            }
        }
    }
    else
    {
        for(int i=0;i<x.l;i++)
        {
            if(x.m[i] > 0)
            {
                x.m[i+1]++;
                x.m[i] -= max;
            }
        }
    }
    for(int i=0;i<x.l;i++)
    {
        x.m[i] *= x.sign;
    }
    for(;x.l>1 && x[x.l-1]==0;x.l--);
    if(x.m[0] == 0 && x.l == 1)x.sign = 1;
    return x;

}
BigInt BigInt::operator -( const BigInt &y )
{
    BigInt x = (*this);
    long long carry = 0;
    long long max = 100000;
    int i=0;
    for(i=0;i<x.l || i<y.l ||carry;i++)
    {
        carry += ((i<x.l)*x.sign*x.m[i] - (i<y.l)*y.sign*y.m[i] );
        x.m[i] = carry%max;
        carry /= max;
    }
    x.l=i;
    for(;x.l>1 && x[x.l-1]==0;x.l--);
    x.sign = (x.m[x.l-1] < 0 ? -1 : 1);
    if(x.m[x.l-1]>=0)
    {
        for(int i=0;i<x.l;i++)
        {
            if(x.m[i] < 0)
            {
                x.m[i+1]--;
                x.m[i] += max;
            }
        }
    }
    else
    {
        for(int i=0;i<x.l;i++)
        {
            if(x.m[i] > 0)
            {
                x.m[i+1]++;
                x.m[i] -= max;
            }
        }
    }
    for(int i=0;i<x.l;i++)
    {
        x.m[i] *= x.sign;
    }
    for(;x.l>1 && x[x.l-1]==0;x.l--);
    if(x.m[0] == 0 && x.l == 1)x.sign = 1;
    return x;

}
