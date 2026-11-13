#include <iostream>
#include <string>
using namespace std;

const int UKURAN = 20;

struct Mahasiswa {
    long long nim;
    string nama;
    int status;
};

class HashTable {
private:
    Mahasiswa data[UKURAN];

    int hash1(long long key) {
        return key % 20;
    }

    int hash2(long long key) {
        return 19 - (key % 19);
    }

public:
    HashTable() {
        for (int i = 0; i < UKURAN; i++) {
            data[i].status = 0;
        }
    }

    void insert(long long nim, string nama) {
        int awal = hash1(nim);
        int langkah = hash2(nim);
        int hapus = -1;

        for (int i = 0; i < UKURAN; i++) {
            int indeks = (awal + i * langkah) % UKURAN;

            if (data[indeks].status == 1 && data[indeks].nim == nim) {
                cout << "NIM sudah terdaftar.\n";
                return;
            }

            if (data[indeks].status == 2 && hapus == -1) {
                hapus = indeks;
            }

            if (data[indeks].status == 0) {
                if (hapus != -1) {
                    indeks = hapus;
                }

                data[indeks].nim = nim;
                data[indeks].nama = nama;
                data[indeks].status = 1;

                cout << "Data berhasil ditambahkan.\n";
                return;
            }
        }

        if (hapus != -1) {
            data[hapus].nim = nim;
            data[hapus].nama = nama;
            data[hapus].status = 1;

            cout << "Data berhasil ditambahkan.\n";
        } else {
            cout << "Hash Table penuh atau posisi tidak dapat dijangkau.\n";
        }
    }

    void search(long long nim) {
        int awal = hash1(nim);
        int langkah = hash2(nim);

        for (int i = 0; i < UKURAN; i++) {
            int indeks = (awal + i * langkah) % UKURAN;

            if (data[indeks].status == 0) {
                break;
            }

            if (data[indeks].status == 1 && data[indeks].nim == nim) {
                cout << "Data ditemukan.\n";
                cout << "NIM  : " << data[indeks].nim << endl;
                cout << "Nama : " << data[indeks].nama << endl;
                return;
            }
        }

        cout << "Data tidak ditemukan.\n";
    }

    void remove(long long nim) {
        int awal = hash1(nim);
        int langkah = hash2(nim);

        for (int i = 0; i < UKURAN; i++) {
            int indeks = (awal + i * langkah) % UKURAN;

            if (data[indeks].status == 0) {
                break;
            }

            if (data[indeks].status == 1 && data[indeks].nim == nim) {
                data[indeks].status = 2;
                cout << "Data berhasil dihapus.\n";
                return;
            }
        }

        cout << "Data tidak ditemukan.\n";
    }

    void display() {
        cout << "\n=== ISI HASH TABLE ===\n";

        for (int i = 0; i < UKURAN; i++) {
            cout << "Indeks " << i << " : ";

            if (data[i].status == 1) {
                cout << data[i].nim << " - " << data[i].nama;
            } else if (data[i].status == 2) {
                cout << "Dihapus";
            } else {
                cout << "Kosong";
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable tabel;
    int pilih;

    do {
        cout << "\n=== HASH TABLE MAHASISWA ===\n";
        cout << "1. Insert Data Mahasiswa\n";
        cout << "2. Search Data Mahasiswa\n";
        cout << "3. Remove Data Mahasiswa\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            long long nim;
            string nama;

            cout << "Masukkan NIM: ";
            cin >> nim;

            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);

            tabel.insert(nim, nama);
        } else if (pilih == 2) {
            long long nim;

            cout << "Masukkan NIM yang dicari: ";
            cin >> nim;

            tabel.search(nim);
        } else if (pilih == 3) {
            long long nim;

            cout << "Masukkan NIM yang dihapus: ";
            cin >> nim;

            tabel.remove(nim);
        } else if (pilih == 4) {
            tabel.display();
        }

    } while (pilih != 5);

    return 0;
}
