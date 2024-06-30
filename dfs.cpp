#include <iostream>
#include <vector>

using namespace std;

bool isValid(int x, int y, size_t n, size_t m) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}

bool dfs(vector<vector<int> > &grid, pair<int, int> start, pair<int, int> end, vector<vector<bool> > &visited, int &steps) {
  size_t n = grid.size();
  size_t m = grid[0].size();

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  visited[start.first][start.second] = true;

  if (start == end) {
    return true;
  }

  for (int i = 0; i < 4; i++) {
    int nx = start.first + dx[i];
    int ny = start.second + dy[i];

    if (isValid(nx, ny, n, m) && !visited[nx][ny] && grid[nx][ny] == 0) {
      steps++;
      if (dfs(grid, {nx, ny}, end, visited, steps))
        return true;
      steps--;  // backtrack
    }
  }

  return false;
}

int main() {
  size_t n, m;
  cin >> n >> m;

  vector<vector<int> > grid(n, vector<int>(m));

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  pair<int, int> start, end;
  cin >> start.first >> start.second >> end.first >> end.second;

  vector<vector<bool> > visited(n, vector<bool>(m, false));

  int steps = 0;

  if (dfs(grid, start, end, visited, steps)) {
    cout << "Destination reached in " << steps << " steps." << endl;
  } else {
    cout << "Destination not reachable." << endl;
  }

  return 0;
}
