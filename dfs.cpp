#include  <iostream>
#include  <string>

class Graph
{

	public:
		Graph(int size):m_size(size)
		{
		
		}
		void dfs(int startnode)
		{
			std::cout<<startnode << std::endl;
			m_visited[startnode] = 1;
			for(int j=0;j<m_size;++j)
			{
				if(!m_visited[j] &&
						m_arr[startnode][j]==1)
				{
					dfs(j);
				}

			}
			
		}
		void dfs_impl()
		{

		}

		void addEdge(int u,int v)
		{
			m_arr[u][v] = 1;
		}
	private:
	int m_arr[12][12] = {{0}};
	int m_size = 1;
	bool m_visited[12]={false};
	
};

int main()
{
    Graph g(4);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.dfs(2);
    
    return 0;
}
