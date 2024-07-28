#include"AdjList.h"
#include<iostream>
template<typename T>
AdjList<T>::AdjList(bool dir) :directed(dir)
{
}
template<typename T>
void AdjList<T>::addVertex(T key, T val)
{
    adj[key].push_back(val);
    if (!directed)
    {
        adj[val].push_back(key);
    }
}
template<typename T>
void AdjList<T>::printGraph()
{
    for (auto i : adj)
    {
        cout << i.first << "->";
        for (auto j : i.second)
        {
            cout << j << ",";
        }
        cout << endl;
    }
}
template<typename T>
vector<T> AdjList<T>::BFS(T start)
{
    vector<T> result;
    unordered_map<T, bool> visited;  /// To check if a node is visited
    queue<T> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        T vertex = q.front();
        q.pop();
        result.push_back(vertex);
        for (auto i : adj[vertex])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return result;
}
template<typename T>
vector<T> AdjList<T>::DFS(T start)
{
    vector<T> result;
    unordered_map<T, bool> visited;  /// To check if a node is visited
    dfs(start, result, visited);
    return result;
}
template<typename T>
void AdjList<T>::dfs(T node, vector<T>& res, unordered_map<T, bool>& visited)  /// DFS helping function
{
    visited[node] = true;
    res.push_back(node);
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, res, visited);
        }
    }
}