class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;

        // Add every character
        for (string word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string a = words[i];
            string b = words[i + 1];

            int len = min(a.size(), b.size());

            bool found = false;

            for (int j = 0; j < len; j++) {

                if (a[j] != b[j]) {

                    graph[a[j]].push_back(b[j]);
                    indegree[b[j]]++;

                    found = true;
                    break;
                }
            }

            // Invalid case:
            // ["abc", "ab"]
            if (!found && a.size() > b.size()) {
                return "";
            }
        }

        // Topological sort
        queue<char> q;

        for (auto it : indegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }

        string ans;

        while (!q.empty()) {

            char c = q.front();
            q.pop();

            ans += c;

            for (char next : graph[c]) {

                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Cycle exists
        if (ans.size() != indegree.size()) {
            return "";
        }

        return ans;
    }
};