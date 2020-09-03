#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
ll INF = 1e15;
ll MOD = 1e9 + 7;
vector <ll> a;

void mergeSort(ll start, ll mid, ll end)
{
    vector <ll> left;
    vector <ll> right;
    for(int i=start;i<=mid;i++)
        left.push_back(a[i]);
    for(int i=mid+1;i<=end;i++)
        right.push_back(a[i]);
    ll p1 = 0;
    ll p2 = 0;
    ll c = start;   
    while(p1 < left.size() && p2 < right.size())
    {
        if(left[p1] < right[p2])
        {
            a[c] = left[p1];
            p1++;
        }
        else 
        {
            a[c] = right[p2];
            p2++;
        }
        c++;
    }
    while(p1 < left.size())
    {
        a[c] = left[p1];
        p1++;
        c++;
    }
    while(p2 < right.size())
    {
        a[c] = right[p2];
        p2++;
        c++;
    }
}

void merge(ll start, ll end)
{
    if(start < end)
    {
        ll mid = (start+end)/2;
        merge(start, mid);
        merge(mid+1, end);
        mergeSort(start, mid, end);
    }
}

int main()
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
