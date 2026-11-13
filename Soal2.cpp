#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Peminjam {
    string nama;
    int idBuku;
};

struct Buku {
    int id;
    Buku *kiri;
    Buku *kanan;
};

class Perpustakaan {
private:
    queue<Peminjam> antrean;
    stack<Peminjam> riwayat;
    Buku *root;

    Buku* tambahBST(Buku *node, int id) {
        if (node == NULL) {
            Buku *baru = new Buku;
            baru->id = id;
            baru->kiri = NULL;
            baru->kanan = NULL;
            return baru;
        }

        if (id < node->id) {
            node->kiri = tambahBST(node->kiri, id);
        } else if (id > node->id) {
            node->kanan = tambahBST(node->kanan, id);
        }

        return node;
    }

    bool cariBST(Buku *node, int id) {
        if (node == NULL) {
            return false;
        }

        if (node->id == id) {
            return true;
        }

        if (id < node->id) {
            return cariBST(node->kiri, id);
        }

        return cariBST(node->kanan, id);
    }

    void preOrder(Buku *node) {
        if (node != NULL) {
            cout << node->id << " ";
            preOrder(node->kiri);
            preOrder(node->kanan);
        }
    }

    void inOrder(Buku *node) {
        if (node != NULL) {
            inOrder(node->kiri);
            cout << node->id << " ";
            inOrder(node->kanan);
        }
    }

    void postOrder(Buku *node) {
        if (node != NULL) {
            postOrder(node->kiri);
            postOrder(node->kanan);
            cout << node->id << " ";
        }
    }

    void hapusBST(Buku *node) {
        if (node != NULL) {
            hapusBST(node->kiri);
            hapusBST(node->kanan);
            delete node;
        }
    }

public:
    Perpustakaan() {
        root = NULL;
    }

    void tambahAntrean(string nama, int id) {
        Peminjam data;
        data.nama = nama;
        data.idBuku = id;

        antrean.push(data);
        cout << "Berhasil masuk antrean.\n";
    }

    void prosesPeminjaman() {
        if (antrean.empty()) {
            cout << "Antrean masih kosong.\n";
            return;
        }

        Peminjam data = antrean.front();
        antrean.pop();

        cout << "Peminjaman berhasil diproses.\n";
        cout << "Nama: " << data.nama << endl;
        cout << "ID Buku: " << data.idBuku << endl;
    }

    void kembalikanBuku(string nama, int id) {
        Peminjam data;
        data.nama = nama;
        data.idBuku = id;

        riwayat.push(data);
        cout << "Pengembalian berhasil dicatat.\n";
    }

    void tampilAntrean() {
        if (antrean.empty()) {
            cout << "Antrean kosong.\n";
            return;
        }

        queue<Peminjam> sementara = antrean;

        cout << "\nDaftar Antrean:\n";

        while (!sementara.empty()) {
            cout << "Nama: " << sementara.front().nama;
            cout << " | ID Buku: " << sementara.front().idBuku << endl;
            sementara.pop();
        }
    }

    void tampilRiwayat() {
        if (riwayat.empty()) {
            cout << "Belum ada riwayat pengembalian.\n";
            return;
        }

        stack<Peminjam> sementara = riwayat;

        cout << "\nRiwayat Pengembalian:\n";

        while (!sementara.empty()) {
            cout << "Nama: " << sementara.top().nama;
            cout << " | ID Buku: " << sementara.top().idBuku << endl;
            sementara.pop();
        }
    }

    void tambahBuku(int id) {
        if (cariBST(root, id)) {
            cout << "ID buku sudah tersedia.\n";
            return;
        }

        root = tambahBST(root, id);
        cout << "Buku berhasil ditambahkan.\n";
    }

    void cariBuku(int id) {
        if (cariBST(root, id)) {
            cout << "Buku ditemukan.\n";
        } else {
            cout << "Buku tidak ditemukan.\n";
        }
    }

    void tampilBST() {
        if (root == NULL) {
            cout << "BST masih kosong.\n";
            return;
        }

        cout << "Pre-Order  : ";
        preOrder(root);

        cout << "\nIn-Order   : ";
        inOrder(root);

        cout << "\nPost-Order : ";
        postOrder(root);

        cout << endl;
    }

    ~Perpustakaan() {
        hapusBST(root);
    }
};

int main() {
    Perpustakaan perpus;
    int pilih;

    do {
        cout << "\n=== SISTEM PERPUSTAKAAN ===\n";
        cout << "1. Tambah Antrean Peminjaman\n";
        cout << "2. Proses Peminjaman\n";
        cout << "3. Tampilkan Antrean\n";
        cout << "4. Catat Pengembalian Buku\n";
        cout << "5. Tampilkan Riwayat Pengembalian\n";
        cout << "6. Tambah ID Buku ke BST\n";
        cout << "7. Cari ID Buku\n";
        cout << "8. Tampilkan Traversal BST\n";
        cout << "9. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            string nama;
            int id;

            cout << "Nama mahasiswa: ";
            cin.ignore();
            getline(cin, nama);

            cout << "ID buku: ";
            cin >> id;

            perpus.tambahAntrean(nama, id);
        } else if (pilih == 2) {
            perpus.prosesPeminjaman();
        } else if (pilih == 3) {
            perpus.tampilAntrean();
        } else if (pilih == 4) {
            string nama;
            int id;

            cout << "Nama mahasiswa: ";
            cin.ignore();
            getline(cin, nama);

            cout << "ID buku: ";
            cin >> id;

            perpus.kembalikanBuku(nama, id);
        } else if (pilih == 5) {
            perpus.tampilRiwayat();
        } else if (pilih == 6) {
            int id;

            cout << "Masukkan ID buku: ";
            cin >> id;

            perpus.tambahBuku(id);
        } else if (pilih == 7) {
            int id;

            cout << "Masukkan ID buku yang dicari: ";
            cin >> id;

            perpus.cariBuku(id);
        } else if (pilih == 8) {
            perpus.tampilBST();
        }

    } while (pilih != 9);

    return 0;
}
