#include <iostream>
using namespace std;
int a[1000000];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin>>a[0];
    cout<<a[0]<<endl;
    for(int i=1;i<n;++i)
    {
        cin>>a[i];
        int x = a[i], j = i;
        while(x < a[j-1] && j != 0)
        {
            a[j] = a[j-1];
            --j;
        }
        a[j] = x;
        for(int j=0;j<=i;++j)
        {
            cout<<a[j]<<" ";
        }
        cout<<endl;
        if(i%2 == 0)
        {
            cout<<a[i/2]<<endl;
        }
        else
            cout<<((double)a[i/2]+(double)a[i/2+1])/2<<" x "<<endl;

    }
}
