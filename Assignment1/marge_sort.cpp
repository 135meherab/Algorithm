#include <bits/stdc++.h>
using namespace std;
void marge(vector<int> &arr, int l, int mid, int r)
{
    vector<int> left_arr;
    for(int i = l; i<=mid; i++)
    {
        left_arr.push_back(arr[i]);
    }

    vector<int> right_arr;
    for(int i = mid + 1; i<=r; i++)
    {
        right_arr.push_back(arr[i]);
    }

    left_arr.push_back(1e9+1);
    right_arr.push_back(1e9+1);

    int lp = 0;
    int rp = 0;
    for (int i = l; i<=r; i++)
    {
        if(left_arr[lp] >= right_arr[rp])
        {
            arr[i] = right_arr[rp];
            rp++;
        }
        else
        {
            arr[i] = left_arr[lp];
            lp++;
        }
    }


}

void mrgSrt(vector <int> &arr, int l, int r)
{
    if(l == r) return;
    int mid = (l+r)/2;
    mrgSrt(arr, l, mid);
    mrgSrt(arr, mid + 1, r);
    marge(arr, l, mid, r);
}

int main()
{   
    int n;
    cin>>n;
    vector<int> arr;
    int v;
    for (int i = 0; i < n; i++)
    {
        cin>>v;
        arr.push_back(v);
    }
    int l = 0;
    int r = n-1;
    mrgSrt(arr,l,r);
    return 0;
}