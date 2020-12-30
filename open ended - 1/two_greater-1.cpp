#include<bits/stdc++.h> 
using namespace std; 
  
void search(int a[], int n) 
{ 
    cout<<"Elements of array which have at-least two greater elements are:\n";
    for (int i = 0; i < n; i++) 
    { 
        int count = 0; 
        for (int j = 0; j < n; j++) 
            if (a[j] > a[i]) 
                count++; 
        
        if (count >= 2) 
            cout << a[i] << " "; 
    } 
} 

int main() 
{ 
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n] ; 
    cout<<"Enter array elements:\n";
    for (int i = 0; i < n; i++) 
    {
        cin>>arr[i];
    }
    search(arr, n); 
    return 0; 
} 