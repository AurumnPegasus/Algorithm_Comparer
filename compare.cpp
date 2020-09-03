#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
ll INF = 1e15;
ll MOD = 1e9 + 7;
vector <ll> a;

void prepInput(ll n)
{
    /*
        Prepares suitable input according to what 
        is required for algorithm and pushes them into
        input.txt
    */
    a.clear();
    for(int i=n;i>0;i--)   
        a.push_back(i);
    ofstream f;
    f.open("input.txt");
    f<<n;
    for(auto i:a)
    {
        f<<"\n";
        f<<i;
    }
    f.close();
}

void algo(string filename, string output)
{
    clock_t start, end;
    string compile = "g++ -o a.out " + filename;
    const char *command = compile.c_str();
    system(command);
    start = clock();
    system("./a.out < input.txt");
    end = clock();
    ld time_taken = ((ld)(end - start))/CLOCKS_PER_SEC;
    ofstream f (output, ios::app);
    f<<time_taken;
    f<<"\n";
    f.close();
}

int main(void)
{
    ll n;
    cout<<" Enter  limit of x axis \n";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        prepInput(i);
        algo("algorithm1.cpp", "A.txt");
        algo("algorithm2.cpp", "B.txt");
    }
}   