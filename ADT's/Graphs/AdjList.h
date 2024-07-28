#ifndef ADJ_LIST_H
#define ADJ_LIST_H
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class AdjList
{
    const bool directed;
    unordered_map<T, list<T>> adj;
    void dfs(T node, vector<T>& res, unordered_map<T, bool>& visited);  /// DFS helping function
public:
    AdjList(bool dir);
    void addVertex(T key, T val);
    void printGraph();
    vector<T> BFS(T start);
    vector<T> DFS(T start);
};
template class AdjList<int>;
#endif