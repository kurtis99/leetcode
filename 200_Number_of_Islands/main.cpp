#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <string>

using namespace std;


void discover_land(vector<vector<char>>& grid, int x, int y, int land_discovered, vector<vector<int>>& visited) {

    if (visited[x][y] != -1)
        return;
    if (grid[x][y] == '1') {
        // we found land
        visited[x][y] = land_discovered;
    } else {
        // We found see
        visited[x][y] = 0;
        return;
    }

    int size_x = grid.size();
    int size_y = grid[0].size();

    if (x > 0) discover_land(grid, x - 1, y, land_discovered, visited);
    if (y > 0) discover_land(grid, x, y - 1, land_discovered, visited);

    if (x < (size_x - 1)) discover_land(grid, x + 1, y, land_discovered, visited);
    if (y < (size_y - 1)) discover_land(grid, x, y + 1, land_discovered, visited);

    return;
}

int numIslands(vector<vector<char>>& grid) {
    int size_x = grid.size();
    int size_y = grid[0].size();
    vector<vector<int>> visited (size_x, vector<int>(size_y, -1));

    int lands_discovered = 0;
    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            if (grid[x][y] == '0') {
                visited[x][y] = 0;
                continue;
            }
            if (visited[x][y] >= 0 && visited[x][y] <= lands_discovered) {
                continue;
            }
            if (grid[x][y] == '1' && visited[x][y] == -1) {
                lands_discovered += 1;
                discover_land(grid, x, y, lands_discovered, visited);
            }
        }
    }

    return lands_discovered;
}

#include "big_island.h"

int main() {


    vector <vector <char> > grid_1 {
          {'1','1','0','0','0'},
          {'1','1','0','0','0'},
          {'0','0','1','0','0'},
          {'0','0','0','1','1'},  
    };
    vector <vector <char> > grid_2 {
          {'1','1','1','1','0'},
          {'1','1','0','1','0'},
          {'1','1','0','0','0'},
          {'0','0','0','0','0'},
    };

    int ret = numIslands(big_grid);
    cout << ret << endl;

//    ret = numIslands(grid_2);
//    cout << ret << endl;

    return 0;
}
