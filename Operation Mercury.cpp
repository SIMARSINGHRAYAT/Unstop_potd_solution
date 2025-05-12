#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

void user_logic(int H, int W, vector<vector<int>>& grid, vector<tuple<int, int, int>>& queries, vector<int>& result) {
    // Directions: up, right, down, left
    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, 1, 0, -1};
    
    for (int query_idx = 0; query_idx < queries.size(); query_idx++) {
        int r = get<0>(queries[query_idx]) - 1; // Convert to 0-indexed
        int c = get<1>(queries[query_idx]) - 1; // Convert to 0-indexed
        int p = get<2>(queries[query_idx]); // Potency
        
        // If origin cell height >= potency, mercury doesn't spread at all
        if (grid[r][c] >= p) {
            result[query_idx] = 0;
            continue;
        }
        
        // BFS to find all cells affected by mercury
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        
        visited.insert({r, c});
        q.push({r, c});
        
        while (!q.empty()) {
            auto [curr_r, curr_c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int new_r = curr_r + dr[i];
                int new_c = curr_c + dc[i];
                
                // Check if the new position is valid and not visited
                if (new_r >= 0 && new_r < H && new_c >= 0 && new_c < W && 
                    visited.find({new_r, new_c}) == visited.end() && 
                    grid[new_r][new_c] < p) {
                    
                    visited.insert({new_r, new_c});
                    q.push({new_r, new_c});
                }
            }
        }
        
        result[query_idx] = visited.size();
    }
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<tuple<int, int, int>> queries(Q);
    for (int i = 0; i < Q; i++) {
        int r, c, p;
        cin >> r >> c >> p;
        queries[i] = make_tuple(r, c, p);
    }
    
    vector<int> result(Q);
    user_logic(H, W, grid, queries, result);
    
    for (int i = 0; i < Q; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}