#include <iostream>
#include <vector>
using namespace std;

// 方向数组，包括水平、垂直、对角的 8 个方向
int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                  {0,  -1},          {0,  1},
                  {1,  -1},  {1,  0}, {1,  1}};

// 深度优先搜索函数，用于标记与 (x,y) 相连的陆地为已访问
void dfs(vector<vector<int>>& grid, int x, int y) {
    int h = grid.size();
    int w = grid[0].size();
    // 检查是否越界，或者当前位置不是陆地，或者已访问过
    if (x < 0 || x >= h || y < 0 || y >= w || grid[x][y] != 1) {
        return;
    }
    // 标记为已访问（可以将其置为 0，避免重复访问）
    grid[x][y] = 0;
    // 遍历 8 个方向
    for (auto& dir : dirs) {
        dfs(grid, x + dir[0], y + dir[1]);
    }
}

// 计算岛屿数量的函数
int countIslands(vector<vector<int>>& grid) {
    int h = grid.size();
    if (h == 0) return 0;
    int w = grid[0].size();
    int count = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            // 如果是陆地，进行 DFS 并计数
            if (grid[i][j] == 1) {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int w, h;
    while (cin >> w >> h) {
        // 处理结束条件
        if (w == 0 && h == 0) break;
        vector<vector<int>> grid(h, vector<int>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
            }
        }
        // 计算并输出岛屿数量
        cout << countIslands(grid) << endl;
    }
    return 0;
}