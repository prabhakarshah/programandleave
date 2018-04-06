#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int  counter,N,M,c;

int invalid(int i,int j){
    return (i<0 || j<0 || i>=N || j>=M); 
}

vector< vector<int> > grid(10,vector<int>(10));

void get_region_count(int i,int j) {
    if(invalid(i,j) || !grid[i][j])
        return;
    grid[i][j]=0;
    
    c++;
    for(int p=-1;p<2;p++)
        for(int q=-1;q<2;q++){
            if(p || q)
                get_region_count(i+p,j+q);
        }
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    N=n;M=m;
    
    counter ;
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
           if(grid[grid_i][grid_j]){
               c=0;
            get_region_count(grid_i,grid_j);
            if(c>counter)
                counter = c;
        }
    }
    }
    cout << counter << endl;
    return 0;
}
