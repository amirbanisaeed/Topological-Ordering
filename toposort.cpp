#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;
using namespace std;

void postorderFunc(vector<int>& order, int node)
{
    order.push_back(node);
}

void explore(vector<vector<int>>& w, vector<bool>& visited, int node, vector<int>& order)
{
    //cout << "In explore" << endl;
    visited[node] = true;

    for (size_t i = 0; i < w[node].size(); i++)
    {
        //cout << "In Loop " << i << endl;
        if (!visited[w[node][i]])
        {
            //cout << "Next Node: " << w[node][i]<< endl;
            explore(w, visited, w[node][i], order);
            //cout << "Node " << node << "  Desti: " << endl;
           // postorderFunc(order, node);
        }

    }
    postorderFunc(order, node);
}

void dfs(vector<vector<int> >& adj, vector<bool>& visited, vector<int>& order) {

    for (size_t i = 0; i < visited.size(); i++)
    {
        visited[i] = false;
    }

    //cout << "In SFS" << endl;

    bool succeeded = false;

    for (size_t i = 0; i < adj.size(); i++)
    {
        if (visited[i] == false)
        {
            //cout << "Hey " << i << endl;
            explore(adj, visited, i, order);
        }

    }
}

vector<int> toposort(vector<vector<int> > adj) {
    //vector<int> used(adj.size(), 0);
    vector<bool> visited(adj.size(), 0);

    vector<int> order;
    //order.resize(adj.size());

    //cout << "In topo" << endl;

    dfs(adj, visited, order);

    //write your code here
    return order;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    vector<int> order = toposort(adj);
    //for (size_t i = 0; i < order.size(); i++) {
     // std::cout << order[i] + 1 << " ";
   // }

    for (int i = order.size() - 1; i >= 0; i--)
    {
        std::cout << order[i] + 1 << " ";
    }
}
