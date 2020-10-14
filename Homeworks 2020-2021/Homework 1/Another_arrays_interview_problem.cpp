#include <iostream>
using namespace std;
const long long MOD = 1000000007;

long long a[1000000], pref[1000000], suffProduct = 1, ans[1000000];

int main()
{
    for(int j=0;j<10;++j)
    {

        char fileName[20] = "input0X.txt";
        fileName[6] = '0' + j;
        freopen(fileName, "r", stdin);
        char fileName2[20] = "output0X.txt";
        fileName2[7] = '0' + j;
        freopen(fileName2, "w", stdout);
        int n;
        cin>>n;
        cin>>a[0];
        pref[0] = 1;
        for(int i=1;i<n;++i)
        {
            cin>>a[i];
            pref[i] = (pref[i-1] * a[i-1])%MOD;
        }
        suffProduct = 1;
        for(int i=n-1;i>=0;--i)
        {
            ans[i] = (suffProduct * pref[i])%MOD;
            suffProduct = (suffProduct * a[i])%MOD;
        }
        for(int i=0;i<n;++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

}
