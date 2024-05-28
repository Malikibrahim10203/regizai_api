#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int N = 3; // Ukuran dari puzzle 8 (3x3)

// Struktur untuk mendefinisikan state dari puzzle
struct State {
    vector<vector<int>> board;
    int x, y; // Posisi dari tile kosong (0)
    int g;    // Biaya dari start ke state saat ini
    int h;    // Heuristik (misplaced tiles)

    State(vector<vector<int>> b, int _x, int _y, int _g) : board(b), x(_x), y(_y), g(_g) {
        h = 0;
        vector<vector<int>> goal = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != 0 && board[i][j] != goal[i][j]) {
                    h++;
                }
            }
        }
    }

    bool isGoal() const {
        vector<vector<int>> goal = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
        return board == goal;
    }

    bool operator>(const State& other) const {
        return (g + h) > (other.g + other.h);
    }
};

// Hash function untuk unordered_set
struct HashFunction {
    size_t operator()(const vector<vector<int>>& board) const {
        size_t hash = 0;
        for (const auto& row : board) {
            for (int num : row) {
                hash = hash * 31 + num;
            }
        }
        return hash;
    }
};

// Fungsi untuk memeriksa apakah posisi berada dalam batas-batas puzzle
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Fungsi untuk mencetak board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Fungsi utama untuk algoritma Best First Search (BFS)
void bestFirstSearch(vector<vector<int>> startBoard, int startX, int startY) {
    priority_queue<State, vector<State>, greater<State>> openList;
    unordered_set<vector<vector<int>>, HashFunction> closedList;

    State startState(startBoard, startX, startY, 0);
    openList.push(startState);

    while (!openList.empty()) {
        State current = openList.top();
        openList.pop();

        if (current.isGoal()) {
            cout << "Puzzle berhasil diselesaikan!" << endl;
            printBoard(current.board);
            return;
        }

        closedList.insert(current.board);

        // Gerakan ke atas, bawah, kiri, kanan
        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& move : moves) {
            int newX = current.x + move.first;
            int newY = current.y + move.second;

            if (isValid(newX, newY)) {
                vector<vector<int>> newBoard = current.board;
                swap(newBoard[current.x][current.y], newBoard[newX][newY]);

                if (closedList.find(newBoard) == closedList.end()) {
                    State newState(newBoard, newX, newY, current.g + 1);
                    openList.push(newState);
                }
            }
        }
    }

    cout << "Tidak ditemukan solusi untuk puzzle ini." << endl;
}

int main() {
    vector<vector<int>> startBoard = {
        {2, 8, 3},
        {1, 6, 4},
        {7, 0, 5}
    };

    int startX = 2, startY = 1; // Posisi dari tile kosong (0)

    bestFirstSearch(startBoard, startX, startY);

    return 0;
}
