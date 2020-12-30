#include<bits/stdc++.h> 
using namespace std; 

void unique(int l, int r) 
{ 
    cout << "Unique nos between "<<l<<" and "<<r<< " are=\n";
    
    for (int i=l ; i<=r ; i++) 
    { 
        int n = i; 
        bool visited[10] = {false}; 
        while (n) 
        { 
            if (visited[n % 10]) 
                break; 
  
            visited[n%10] = true; 
  
            n = n/10; 
        } 
        if (n == 0) 
            cout <<i << " "; 
    } 
} 

int main() 
{ 
    int l , r; 
    cout<<"Enter the range of numbers (from to)\n";
    cin>>l;
    cin>>r;
    unique(l, r); 
    return 0; 
} 