#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Struktur untuk merepresentasikan setiap node
struct Node {
    int value;
    vector<int> neighbors; // menyimpan indeks node tetangga dalam grafik
    bool visited; // menandai apakah node telah dikunjungi

    // Konstruktor default
    Node() : value(0), visited(false) {}

    // Konstruktor dengan parameter nilai node
    Node(int v) : value(v), visited(false) {}
};

// Kelas untuk merepresentasikan grafik
class Graph {
private:
    vector<Node> nodes; // menyimpan semua node dalam grafik

public:
    Graph(int n) {
        nodes.reserve(n); // Mengalokasikan memori untuk n node
        for (int i = 0; i < n; ++i) {
            nodes.emplace_back(i); // Menggunakan konstruktor Node(int v)
        }
    }

    // Menambahkan edge antara dua node
    void addEdge(int from, int to) {
        nodes[from].neighbors.push_back(to);
        nodes[to].neighbors.push_back(from); // Jika grafik tak-arah, baris ini bisa dihapus
    }

    // BFS traversal dari node awal
    void bfs(int startNode) {
        queue<int> q;
        q.push(startNode);
        nodes[startNode].visited = true;

        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            cout << nodes[currNode].value << " ";

            // Traverse semua tetangga dari node saat ini
            for (int neighbor : nodes[currNode].neighbors) {
                if (!nodes[neighbor].visited) {
                    q.push(neighbor);
                    nodes[neighbor].visited = true;
                }
            }
        }
    }
};

int main() {
    // Contoh penggunaan BFS
    Graph graph(6); // Membuat grafik dengan 6 node

    // Menambahkan edge antara node
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);

    cout << "BFS traversal dari node 0: ";
    graph.bfs(0);
    cout << endl;

    return 0;
}
