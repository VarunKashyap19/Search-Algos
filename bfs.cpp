/*
       Implemented BFS algorithm to find the shortest path 
       Code by Varun Kashyap
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int> > &grid, int n, int m, pair<int, int> start, pair<int, int> end) {
  int sx = start.first, sy = start.second;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  int dx_size = sizeof(dx) / sizeof(dx[0]);
  int dy_size = sizeof(dy) / sizeof(dy[0]);

  vector<vector<bool> > visited(n, vector<bool>(m, false));
  vector<vector<int> > distance(n, vector<int>(m, 0));

  queue<pair<int, int> > q;
  q.push(start);
  visited[sx][sy] = true;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();

    int x = p.first;
    int y = p.second;

    for (int i = 0; i < dx_size; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == 0) {
       q.push(make_pair(nx, ny));
        visited[nx][ny] = true;
        distance[nx][ny] = distance[x][y] + 1;

        if (nx == end.first && ny == end.second) {
          cout << "Destination reached in " << distance[nx][ny] << " steps." << endl;
          return;
        }
      }
    }
  }

  cout << "Destination not reachable." << endl;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > grid(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  pair<int, int> start, end;
  cin >> start.first >> start.second >> end.first >> end.second;

  bfs(grid, n, m, start, end);

  return 0;
}

/* Code ends */
