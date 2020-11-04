#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n;
pair <int, int> a[10000000];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    cin>>n;
    cerr<<n<<endl;
    for(int i=0;i<n;++i)
    {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a, a+n, cmp);
    int ans = 0;
    int rightMost = a[0].second;
    for(int i=1;i<n;++i)
    {
        if(a[i].second > rightMost)
            rightMost = a[i].second;
        else
            ans++;
    }
    cout<<ans<<endl;


}
