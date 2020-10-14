#include <bits/stdc++.h> 
using namespace std; 
  

class Disjoint_sets 
{ 
      
    vector<int> weight, parent; 
    int n; 
      
    public: 
    Disjoint_sets(int n) 
    { 
        weight.resize(n); 
        parent.resize(n); 
        this->n = n; 
        form_sets(); 
    } 
  
    void form_sets() 
    { 

        for (int i = 0; i < n; i++) 
            parent[i] = i; 
    } 
  

    int find(int x) 
    { 
        if (parent[x] != x) 
        { 

            return find(parent[x]); 
        } 
  
        return x; 
    } 
  

    void Union(int x, int y) 
    { 

        int x_root = find(x); 
        int y_root = find(y); 

      
        if (x_root == y_root) 
            return; 

        if (weight[x_root] < weight[y_root]) 
        {
            parent[x_root] = y_root; 
           
        }
        else if (weight[y_root] < weight[x_root]) 
        {
            parent[y_root] = x_root;
            
        }
        else 
        { 
            parent[y_root] = x_root; 
            weight[x_root] = weight[x_root] + 1; 
        } 
    } 
}; 

int count_island(vector<vector<int>>a) 
{ 
    int row = a.size(); 
    int col = a[0].size(); 
    
    Disjoint_sets *set = new Disjoint_sets(row * col); 
  
 
    for (int j = 0; j < row; j++) 
    { 
        for (int k = 0; k < col; k++) 
        { 

            if (a[j][k] == 0) 
                continue; 
  
            if (j + 1 < row && a[j + 1][k] == 1) 
                set->Union(j * (col) + k, (j + 1) * (col) + k); 
                
            if (j - 1 >= 0 && a[j - 1][k] == 1) 
                set->Union(j * (col) + k, (j - 1) * (col) + k); 
                
            if (k + 1 < col && a[j][k + 1] == 1) 
                set->Union(j * (col) + k, (j) * (col) + k + 1); 
                
            if (k - 1 >= 0 && a[j][k - 1] == 1) 
                set->Union(j * (col) + k,(j) * (col) + k - 1); 
                
            if (j + 1 < row && k + 1 < col &&   a[j + 1][k + 1] == 1) 
                set->Union(j * (col) + k, (j + 1) * (col) + k + 1); 
                
            if (j + 1 < row && k - 1 >= 0 &&  a[j + 1][k - 1] == 1) 
                set->Union(j * col + k, (j + 1) * (col) + k - 1); 
                
            if (j - 1 >= 0 && k + 1 < col &&  a[j - 1][k + 1] == 1) 
                set->Union(j * col + k, (j - 1) * col + k + 1); 
                
            if (j - 1 >= 0 && k - 1 >= 0 && a[j - 1][k - 1] == 1) 
                set->Union(j * col + k, (j - 1) * col + k - 1); 
        } 
    } 

    int *frequency = new int[row * col]; 
    int no_of_islands = 0; 
    for (int j = 0; j < row; j++) 
    { 
        for (int k = 0; k < col; k++) 
        { 
            if (a[j][k] == 1) 
            { 
                int x = set->find(j * col + k); 
  
                if (frequency[x] == 0) 
                { 
                    no_of_islands++; 
                    frequency[x]++; 
                } 
  
                else
                    frequency[x]++; 
            } 
        } 
    } 
    return no_of_islands; 
} 
  

int main(void) 
{ 
    vector<vector<int>>c = {{1, 1, 0, 0, 0}, 
                            {0, 1, 0, 0, 1}, 
                            {1, 0, 0, 1, 1}, 
                            {0, 0, 0, 0, 0}, 
                            {1, 0, 1, 0, 1}}; 
	 for (int i = 0; i < c.size(); i++)
	{
	    for (int j = 0; j < c[i].size(); j++)
	    {
		cout << c[i][j]<<" ";
	    }
	    cout<< endl;
	}
                            
    cout << "Number of Islands are: " << count_island(c)<< endl; 
} 
