class Solution {
  public:
  
    bool hasCycleDFS(int course,vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& inCurrentPath) {

        if (inCurrentPath[course])  return true;
        if (visited[course]) return false;
        visited[course] = true;
        inCurrentPath[course] = true;

        for (int nextCourse : graph[course]) {
            if (hasCycleDFS(nextCourse, graph, visited, inCurrentPath)) return true;
        }

        inCurrentPath[course] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            graph[course].push_back(prereq);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inCurrentPath(numCourses, false);

        for (int course = 0; course < numCourses; course++) {
            if (!visited[course] && hasCycleDFS(course, graph, visited, inCurrentPath)) {
                return false; 
            }
        }
        return true; 
        
    }
};