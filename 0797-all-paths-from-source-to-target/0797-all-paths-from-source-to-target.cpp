class Solution
{
    public:
        void helper(int vertex, int finalvertex, vector<vector < int>> &finalans, vector< int > &path, vector< vector< int>> &graph)
        {
            if (vertex == finalvertex)
            {
                path.push_back(vertex);
                finalans.push_back(path);
                path.pop_back();
                return;
            }
            path.push_back(vertex);
            for (auto i: graph[vertex])
            {
                helper(i, finalvertex, finalans, path, graph);
            }
            path.pop_back();
            return;
        }
    vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &graph)
    {
        // vector<bool> vis(graph.size(), false);
        vector<vector < int>> finalans;
        vector<int> path;
        helper(0, graph.size() - 1, finalans, path, graph);
        return finalans;
    }
};