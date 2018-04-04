/// TIME OUT ISSUES
//https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem
/// Syntax: C++14
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int counter[500]{0};
//optimize version
int count2(int h){
    
    if(h==0)
        return 1;
    
    if(h<0)
        return 0;
    
    if( counter [h] !=0)
        return counter[h];
    
    for(auto i=1;i<=3;++i)
        counter[h] += count2(h-i);
    
    return counter[h];
}

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
