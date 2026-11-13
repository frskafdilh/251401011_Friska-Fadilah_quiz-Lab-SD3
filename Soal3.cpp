#include <iostream>
#include <queue>
using namespace std;

const int N = 6;
const int INF = 999999;

char vertex[N] = {'A', 'B', 'C', 'D', 'E', 'F'};

int graph[N][N] = {
    {0, 4, 2, 0, 0, 0},
    {4, 0, 1, 5, 3, 0},
    {2, 1, 0, 8, 6, 0},
    {0, 5, 8, 0, 2, 4},
    {0, 3, 6, 2, 0, 3},
    {0, 0, 0, 4, 3, 0}
};

int cariVertex(char tujuan) {
    for (int i = 0; i < N; i++) {
        if (vertex[i] == tujuan) {
            return i;
        }
    }

    return -1;
}

void BFS(int awal) {
    bool dikunjungi[N] = {false};
    queue<int> q;

    dikunjungi[awal] = true;
    q.push(awal);

    cout << "Hasil BFS: ";

    while (!q.empty()) {
        int sekarang = q.front();
        q.pop();

        cout << vertex[sekarang] << " ";

        for (int i = 0; i < N; i++) {
            if (graph[sekarang][i] != 0 && !dikunjungi[i]) {
                dikunjungi[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
}

void DFS(int sekarang, bool dikunjungi[]) {
    dikunjungi[sekarang] = true;
    cout << vertex[sekarang] << " ";

    for (int i = 0; i < N; i++) {
        if (graph[sekarang][i] != 0 && !dikunjungi[i]) {
            DFS(i, dikunjungi);
        }
    }
}

void tampilDFS(int awal) {
    bool dikunjungi[N] = {false};

    cout << "Hasil DFS: ";
    DFS(awal, dikunjungi);
    cout << endl;
}

void dijkstra(int awal, int tujuan) {
    int jarak[N];
    int sebelumnya[N];
    bool dikunjungi[N] = {false};

    for (int i = 0; i < N; i++) {
        jarak[i] = INF;
        sebelumnya[i] = -1;
    }

    jarak[awal] = 0;

    for (int i = 0; i < N; i++) {
        int terkecil = INF;
        int sekarang = -1;

        for (int j = 0; j < N; j++) {
            if (!dikunjungi[j] && jarak[j] < terkecil) {
                terkecil = jarak[j];
                sekarang = j;
            }
        }

        if (sekarang == -1) {
            break;
        }

        dikunjungi[sekarang] = true;

        for (int j = 0; j < N; j++) {
            if (graph[sekarang][j] != 0 &&
                !dikunjungi[j] &&
                jarak[sekarang] + graph[sekarang][j] < jarak[j]) {

                jarak[j] = jarak[sekarang] + graph[sekarang][j];
                sebelumnya[j] = sekarang;
            }
        }
    }

    if (jarak[tujuan] == INF) {
        cout << "Rute tidak ditemukan.\n";
        return;
    }

    int rute[N];
    int jumlah = 0;
    int sekarang = tujuan;

    while (sekarang != -1) {
        rute[jumlah] = sekarang;
        jumlah++;
        sekarang = sebelumnya[sekarang];
    }

    cout << "Rute terpendek: ";

    for (int i = jumlah - 1; i >= 0; i--) {
        cout << vertex[rute[i]];

        if (i > 0) {
            cout << " -> ";
        }
    }

    cout << "\nTotal jarak: " << jarak[tujuan] << endl;
}

int main() {
    int pilih;
    char awal, tujuan;

    do {
        cout << "\n=== SISTEM PENCARIAN RUTE KAMPUS ===\n";
        cout << "1. Tampilkan Adjacency Matrix\n";
        cout << "2. BFS\n";
        cout << "3. DFS\n";
        cout << "4. Dijkstra\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "\n   A B C D E F\n";

            for (int i = 0; i < N; i++) {
                cout << vertex[i] << "  ";

                for (int j = 0; j < N; j++) {
                    cout << graph[i][j] << " ";
                }

                cout << endl;
            }
        } else if (pilih == 2) {
            cout << "Masukkan vertex awal (A-F): ";
            cin >> awal;

            int indeks = cariVertex(awal);

            if (indeks == -1) {
                cout << "Vertex tidak valid.\n";
            } else {
                BFS(indeks);
            }
        } else if (pilih == 3) {
            cout << "Masukkan vertex awal (A-F): ";
            cin >> awal;

            int indeks = cariVertex(awal);

            if (indeks == -1) {
                cout << "Vertex tidak valid.\n";
            } else {
                tampilDFS(indeks);
            }
        } else if (pilih == 4) {
            cout << "Masukkan vertex awal (A-F): ";
            cin >> awal;

            cout << "Masukkan vertex tujuan (A-F): ";
            cin >> tujuan;

            int indeksAwal = cariVertex(awal);
            int indeksTujuan = cariVertex(tujuan);

            if (indeksAwal == -1 || indeksTujuan == -1) {
                cout << "Vertex tidak valid.\n";
            } else {
                dijkstra(indeksAwal, indeksTujuan);
            }
        }

    } while (pilih != 5);

    return 0;
}
