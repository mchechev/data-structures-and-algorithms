#include <iostream>
using namespace std;

long long a, b, ans = 0;
bool used[10];

void gen(long long x)
{
    if(x > b)
        return;
    if(x >= a)
        ans ++;
    for(int i=0;i<10;++i)
    {
        if(!used[i])
        {
            used[i] = 1;
            gen(x*10+i);
            used[i] = 0;
        }
    }
}

int main()
{
    cin>>a>>b;
    for(int i=1;i<10;++i)
    {
        used[i] = 1;
        gen(i);
        used[i] = 0;
    }
    cout<<ans<<endl;
}
