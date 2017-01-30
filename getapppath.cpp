#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solve
{
public:
    solve(int N):_N(N-1) { }
    void getallpaths(int x,int y)
    {
        _paths.push_back(make_pair(x,y));
        if( x == _N && y == _N)
        {
            for(auto& i: _paths)
                cout<<"("<<i.first<<","<<
                    i.second<<")";


            cout<<endl;
            _count++;
        }
        else if( x == _N)
        {
            getallpaths(x,y+1);
        }
        else if( y == _N)
        {
            getallpaths(x+1,y);
        }
        else
        {
            getallpaths(x+1,y);
            getallpaths(x,y+1);
        }
    }
    int count()
    {
        return _count;
    }
    void printRobotPaths(string path,int row,int col,int r_idx,int c_idx) {
        if ((r_idx == row-1) && (c_idx == col-1)) {
            cout<<path<<endl;
            return;
        }
	else if (r_idx == row-1) {
            printRobotPaths(path+'D',row,col,r_idx,c_idx+1);
            return;
        }
	else if (c_idx == col-1) {
            printRobotPaths(path+'R',row,col,r_idx+1,c_idx);
            return;
        }
	else{
        printRobotPaths(path+'D',row,col,r_idx,c_idx+1);
        printRobotPaths(path+'R',row,col,r_idx+1,c_idx);
	}
    }
    void getallpaths2(int x,int y)
    {
	    string path;
	    printRobotPaths(path,_N+1,_N+1,0,0);
    }
private:
    static vector<vector<pair<int,int>>> _pathsVec;
    
    int _N;
    int _count = 0;
};

vector<vector<pair<int,int>>> solve::_pathsVec;

int main()
{
    solve sol(3);
    sol.getallpaths(0,0);
    sol.getallpaths2(0,0);
    std::cout<<"No of paths : "<< sol.count();
    return 0;

}
