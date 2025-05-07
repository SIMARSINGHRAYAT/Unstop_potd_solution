
# 🔄 The Shifting Mirrors Labyrinth

This project simulates an underground research facility formed as a **mirror labyrinth**, where each mirror reflects light in a fixed direction. Your mission is to determine whether a laser beam will **ESCAPE** the grid or get **TRAPPED** in a loop.

## 🧩 Problem Statement

You are given:
- An **N x M** grid representing the labyrinth.
- Each cell contains a mirror pointing in one of four directions:
  - `U`: Up
  - `D`: Down
  - `L`: Left
  - `R`: Right
- Mirrors **do not rotate** after the initial snapshot (hour 0).
- A list of `Q` laser queries indicating the starting cell of each laser.

Each laser moves according to the mirror's current direction. The laser continues until it either exits the grid (**ESCAPED**) or re-enters a previously visited cell (**TRAPPED**).

## 📥 Input Format

```
N M
<grid of N rows and M columns, characters U/D/L/R>
Q
x1 y1
x2 y2
...
xQ yQ
```

- `1 ≤ N, M ≤ 1000`
- `1 ≤ Q ≤ 10^5`

## ✅ Sample Input

```
4 4
R R D L
U L D D
R U L R
U D U U
3
0 0
1 1
3 3
```

## 🧾 Sample Output

```
TRAPPED
TRAPPED
ESCAPED
```

## 💡 Approach

### Direction Mapping

```cpp
// Mapping mirror direction to movement (dx, dy)
const int dx[] = {-1, 1, 0, 0}; // U, D, L, R
const int dy[] = {0, 0, -1, 1}; 
const char dir[] = {'U', 'D', 'L', 'R'}; // Corresponding directions

// Function to check if laser escapes or is trapped
void user_logic(int N, int M, vector<vector<char>> &grid, int Q, vector<pair<int, int>> &queries, vector<string> &results) {
    for (int i = 0; i < Q; i++) {
        int x = queries[i].first, y = queries[i].second;
        set<pair<int, int>> visited;

        while (true) {
            // If out of bounds, laser escapes
            if (x < 0 || x >= N || y < 0 || y >= M) {
                results[i] = "ESCAPED";
                break;
            }

            // If revisiting a cell, laser is trapped
            if (visited.count({x, y})) {
                results[i] = "TRAPPED";
                break;
            }

            visited.insert({x, y});

            // Determine movement direction
            char d = grid[x][y];
            int moveIdx = (d == 'U' ? 0 : d == 'D' ? 1 : d == 'L' ? 2 : 3);
            x += dx[moveIdx];
            y += dy[moveIdx];
        }
    }
}
```

## 🧠 Complexity

- Time per query: **O(K)** where K is path length until escape or cycle.
- Memory: **O(N × M)** if visited tracking is reused.

## 🗂️ Folder Structure

```
shifting_mirrors_labyrinth/
├── main.cpp
├── README.md
└── sample_input.txt
```

## 📜 License

MIT License

## 👨‍🔬 Author

Created by **Simar Singh Rayat**. Contributions are welcome!
