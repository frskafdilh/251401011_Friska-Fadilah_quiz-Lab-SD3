#include <iostream>
#include <string>
using namespace std;

class DynamicArray {
private:
    int *nilai;
    int jumlah;
    int kapasitas;

public:
    DynamicArray() {
        jumlah = 0;
        kapasitas = 5;
        nilai = new int[kapasitas];
    }

    void tambah(int data) {
        if (jumlah == kapasitas) {
            kapasitas *= 2;
            int *baru = new int[kapasitas];

            for (int i = 0; i < jumlah; i++) {
                baru[i] = nilai[i];
            }

            delete[] nilai;
            nilai = baru;
        }

        nilai[jumlah] = data;
        jumlah++;
    }

    void insertionSort() {
        for (int i = 1; i < jumlah; i++) {
            int key = nilai[i];
            int j = i - 1;

            while (j >= 0 && nilai[j] > key) {
                nilai[j + 1] = nilai[j];
                j--;
            }

            nilai[j + 1] = key;
        }
    }

    int binarySearch(int cari) {
        int kiri = 0;
        int kanan = jumlah - 1;

        while (kiri <= kanan) {
            int tengah = (kiri + kanan) / 2;

            if (nilai[tengah] == cari) {
                return tengah;
            } else if (nilai[tengah] < cari) {
                kiri = tengah + 1;
            } else {
                kanan = tengah - 1;
            }
        }

        return -1;
    }

    void tampilkan() {
        if (jumlah == 0) {
            cout << "Belum ada nilai.\n";
            return;
        }

        for (int i = 0; i < jumlah; i++) {
            cout << nilai[i] << " ";
        }

        cout << endl;
    }

    ~DynamicArray() {
        delete[] nilai;
    }
};

struct Node {
    string nim;
    string nama;
    int nilai;
    Node *next;
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        head = NULL;
    }

    void tambah(string nim, string nama, int nilai) {
        Node *baru = new Node;
        baru->nim = nim;
        baru->nama = nama;
        baru->nilai = nilai;
        baru->next = NULL;

        if (head == NULL) {
            head = baru;
        } else {
            Node *bantu = head;

            while (bantu->next != NULL) {
                bantu = bantu->next;
            }

            bantu->next = baru;
        }
    }

    void cariNIM(string nim) {
        Node *bantu = head;

        while (bantu != NULL) {
            if (bantu->nim == nim) {
                cout << "Data ditemukan\n";
                cout << "NIM   : " << bantu->nim << endl;
                cout << "Nama  : " << bantu->nama << endl;
                cout << "Nilai : " << bantu->nilai << endl;
                return;
            }

            bantu = bantu->next;
        }

        cout << "Mahasiswa tidak ditemukan.\n";
    }

    void tampilkan() {
        if (head == NULL) {
            cout << "Belum ada data mahasiswa.\n";
            return;
        }

        Node *bantu = head;

        while (bantu != NULL) {
            cout << "NIM   : " << bantu->nim << endl;
            cout << "Nama  : " << bantu->nama << endl;
            cout << "Nilai : " << bantu->nilai << endl;
            cout << "-------------------\n";

            bantu = bantu->next;
        }
    }

    ~LinkedList() {
        while (head != NULL) {
            Node *hapus = head;
            head = head->next;
            delete hapus;
        }
    }
};

int main() {
    LinkedList mahasiswa;
    DynamicArray nilai;

    int pilih;

    do {
        cout << "\n=== SISTEM NILAI MAHASISWA ===\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Mahasiswa\n";
        cout << "3. Cari Mahasiswa berdasarkan NIM\n";
        cout << "4. Urutkan Nilai\n";
        cout << "5. Cari Nilai\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            string nim, nama;
            int angka;

            cout << "Masukkan NIM: ";
            cin >> nim;

            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, nama);

            cout << "Masukkan Nilai: ";
            cin >> angka;

            if (angka < 0 || angka > 100) {
                cout << "Nilai harus 0 sampai 100.\n";
            } else {
                mahasiswa.tambah(nim, nama, angka);
                nilai.tambah(angka);
                cout << "Data berhasil ditambahkan.\n";
            }
        } else if (pilih == 2) {
            mahasiswa.tampilkan();
        } else if (pilih == 3) {
            string nim;

            cout << "Masukkan NIM: ";
            cin >> nim;

            mahasiswa.cariNIM(nim);
        } else if (pilih == 4) {
            nilai.insertionSort();
            cout << "Nilai berhasil diurutkan.\n";
            nilai.tampilkan();
        } else if (pilih == 5) {
            int cari;

            cout << "Masukkan nilai yang dicari: ";
            cin >> cari;

            nilai.insertionSort();

            int hasil = nilai.binarySearch(cari);

            if (hasil != -1) {
                cout << "Nilai ditemukan pada indeks " << hasil << endl;
            } else {
                cout << "Nilai tidak ditemukan.\n";
            }
        }

    } while (pilih != 6);

    return 0;
}
