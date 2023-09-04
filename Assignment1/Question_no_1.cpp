#include <bits/stdc++.h>
using namespace std;

void marge(vector<int>& arr, int l, int mid, int r)
{
    vector<int> left_vector;
    for (int i = l; i <= mid; i++)
    {
        left_vector.push_back(arr[i]);
    }
    left_vector.push_back(INT_MIN);

    vector<int> right_vector;
    for (int i = mid + 1; i <= r ; i++)
    {
        right_vector.push_back(arr[i]);
    }
    right_vector.push_back(INT_MIN);

    int lp = 0, rp = 0;
    
    for (int i = l; i <= r; i++)
    {
        if(left_vector[lp]<= right_vector[rp])
        {
            arr[i] = right_vector[rp];
            rp ++;
        }
        else
        {
            arr[i] = left_vector[lp];
            lp++;
        }
    }
    
    
}

void margeSort(vector<int>& arr, int l, int r)
{
    if(l == r) return;
    int mid = (l + r)/2;
    margeSort(arr,l,mid);
    margeSort(arr, mid + 1, r);
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
    margeSort(arr,l,r);
    for(int val: arr) cout<<val<<" ";
    return 0;
}