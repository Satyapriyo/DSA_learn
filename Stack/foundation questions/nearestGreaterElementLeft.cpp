#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    stack<int> s;
    vector<int> v;
    cout<<"enter the number of elements:\n";
    cin>>n;// input size of array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];// entering the elements of input
    }
     for (int i =0; i<n; i++)
     {
        if(s.size()==0)
            v.push_back(-1);
        else if(s.size()>0 && s.top()>arr[i])
            v.push_back(s.top());
        else if(s.size()>0 && s.top()<arr[i]){
            while (s.size()>0 && s.top()<=arr[i])
            {
                s.pop();
            }
            if(s.size()>0)
                v.push_back(s.top());
            else    
                v.push_back(-1);
        }
        s.push(arr[i]);
     }
     
     for (int i = 0; i < n; i++)
     {
        cout<<v[i]<<" ";
     }
}