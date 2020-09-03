#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
ll INF = 1e15;
ll MOD = 1e9 + 7;
vector <ll> a;

void mergeSort(ll start, ll mid1, ll mid2, ll end)
{
    vector <ll> one;
    vector <ll> two;
    vector <ll> three;
    for(int i=start;i<=mid1;i++)
        one.push_back(a[i]);
    for(int i=mid1+1;i<=mid2;i++)
        two.push_back(a[i]);
    for(int i=mid2+1;i<=end;i++)
        three.push_back(a[i]);
    ll p1 = 0;
    ll p2 = 0;
    ll p3 = 0;
    ll c = start;
    while(p1 < one.size() && p2 < two.size() && p3 < three.size())
    {
        if(one[p1] < two[p2])
        {
            if(one[p1] < three[p3])
            {
                a[c] = one[p1];
                p1++;
            }
            else
            {
                a[c] = three[p3];
                p3++;
            }
        }
        else
        {
            if(two[p2] < three[p3])
            {
                a[c] = two[p2];
                p2++;
            }
            else
            {
                a[c] = three[p3];
                p3++;
            }
        }
        c++;
    }

    while(p1 < one.size() && p2 < two.size())
    {
        if(one[p1] < two[p2])
        {
            a[c] = one[p1];
            p1++;
        }
        else
        {
            a[c] = two[p2];
            p2++;
        }
        c++;
    }
    while(p1 < one.size() && p3 < three.size())
    {
        if(one[p1] < three[p3])
        {
            a[c] = one[p1];
            p1++;
        }
        else
        {
            a[c] = three[p3];
            p3++;
        }
        c++;
    }
    while(p2 < two.size() && p3 < three.size())
    {
        if(two[p2] < three[p3])
        {
            a[c] = two[p2];
            p2++;
        }
        else
        {
            a[c] = three[p3];
            p3++;
        }
        c++;
    }

    while(p1 < one.size())
    {
        a[c] = one[p1];
        p1++;
        c++;
    }
    while(p2 < two.size())
    {
        a[c] = two[p2];
        p2++;
        c++;
    }
    while(p3 < three.size())
    {
        a[c] = three[p3];
        p3++;
        c++;
    }
}

void merge(ll start, ll end)
{
    if(end - start > 1)
    {
        // cout<<start<<" "<<end<<"\n";
        ll mid1 = start + (end-start)/3;
        ll mid2 = start + 2*(end-start)/3; 
        // cout<<mid1<<" "<<mid2<<"\n";
        merge(start, mid1);
        merge(mid1 + 1, mid2);
        merge(mid2 + 1, end);
        mergeSort(start, mid1, mid2, end);
    }
}

int main(void)
{
    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll input;
        cin>>input;
        a.push_back(input);
    }
    merge(0, n-1);
    return 0;
}