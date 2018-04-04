//https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void count(int &c, int h){
    if(h==0){
        c++;
        return;
    }
    if(h<0)
        return;
    for(auto i=1;i<=3;++i)
    count(c,h-i);
    
}

int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        int c{0};
        count(c,n);
        cout<<c<<endl;
    }
    
    return 0;
}
