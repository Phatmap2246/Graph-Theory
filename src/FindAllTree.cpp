#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, id; // Thêm id để dễ phân biệt các cạnh
};

// Cấu trúc DSU để kiểm tra chu trình
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false; // Đã cùng tập -> tạo chu trình
        parent[b] = a;
        return true;
    }
};

int n, m;
vector<Edge> edges;
vector<Edge> currentTree;
vector<vector<Edge>> allSpanningTrees;

void backtrack(int idx, DSU dsu) {
    // Nếu đã chọn đủ n-1 cạnh -> Đã tạo thành 1 cây khung
    if (currentTree.size() == n - 1) {
        allSpanningTrees.push_back(currentTree);
        return;
    }
    
    // Nếu đã duyệt hết các cạnh mà chưa đủ n-1 cạnh
    if (idx == m) return;
    
    // Cắt tỉa: Nếu số cạnh còn lại không đủ để lấp đầy cây khung thì dừng
    if (currentTree.size() + (m - idx) < n - 1) return;

    // --- LỰA CHỌN 1: CHỌN CẠNH HIỆN TẠI ---
    int u = edges[idx].u;
    int v = edges[idx].v;
    DSU nextDsu = dsu; // Copy trạng thái DSU
    
    if (nextDsu.unite(u, v)) { // Nếu không tạo chu trình
        currentTree.push_back(edges[idx]);
        backtrack(idx + 1, nextDsu);
        currentTree.pop_back(); // Quay lui
    }

    // --- LỰA CHỌN 2: KHÔNG CHỌN CẠNH HIỆN TẠI ---
    backtrack(idx + 1, dsu);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v, i + 1});
    }

    DSU initialDsu(n);
    backtrack(0, initialDsu);

    cout << "Tong so cay khung tim duoc: " << allSpanningTrees.size() << "\n\n";
    
    for (int i = 0; i < allSpanningTrees.size(); i++) {
        cout << "Cay khung " << i + 1 << ": ";
        for (auto e : allSpanningTrees[i]) {
            cout << "(" << e.u << "," << e.v << ") ";
        }
        cout << "\n";
    }

    return 0;
}