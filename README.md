 QUIZ LAB STRUKTUR DATA 3

Identitas Mahasiswa

- **Nama:** Friska Fadilah Simatupang
- **NIM:** 251401011
- **Program Studi:** Ilmu Komputer
- **Mata Kuliah:** Struktur Data
- **Bahasa Pemrograman:** C++

## Deskripsi Program

Repository ini berisi empat program C++ untuk memenuhi tugas Kuis Lab Struktur Data 3&4. Setiap program menggunakan struktur data dan algoritma yang telah dipelajari.

### 1. Sistem Pengelolaan Nilai Mahasiswa

File: `Soal1.cpp`

Program ini digunakan untuk mengelola data mahasiswa yang terdiri dari NIM, nama, dan nilai.

Struktur data dan algoritma yang digunakan:

- Dynamic Array
- Single Linked List
- Insertion Sort
- Linear Search
- Binary Search

Fitur program:

- Menambahkan data mahasiswa
- Menampilkan data mahasiswa
- Mencari mahasiswa berdasarkan NIM
- Mengurutkan nilai dari terkecil hingga terbesar
- Mencari nilai menggunakan Binary Search

### 2. Sistem Antrean dan Pengelolaan Buku Perpustakaan

File: `Soal2.cpp`

Program ini digunakan untuk membantu pengelolaan antrean peminjaman dan riwayat pengembalian buku.

Struktur data yang digunakan:

- Queue dengan prinsip FIFO
- Stack dengan prinsip LIFO
- Binary Search Tree (BST)

Fitur program:

- Menambahkan mahasiswa ke antrean peminjaman
- Memproses antrean peminjaman
- Menampilkan antrean
- Mencatat pengembalian buku
- Menampilkan riwayat pengembalian
- Menambahkan dan mencari ID buku
- Menampilkan traversal Pre-Order, In-Order, dan Post-Order

### 3. Sistem Pencarian Rute di Lingkungan Kampus

File: `Soal3.cpp`

Program ini digunakan untuk mencari rute dan jarak antar lokasi di lingkungan kampus menggunakan Graph.

Struktur data dan algoritma yang digunakan:

- Graph
- Adjacency Matrix
- Breadth First Search (BFS)
- Depth First Search (DFS)
- Dijkstra

Fitur program:

- Menampilkan Adjacency Matrix
- Melakukan penelusuran menggunakan BFS
- Melakukan penelusuran menggunakan DFS
- Mencari jarak terpendek menggunakan Dijkstra
- Menampilkan rute dan total jarak

Vertex yang digunakan adalah A, B, C, D, E, dan F.

### 4. Sistem Pengelolaan Data Mahasiswa Menggunakan Hash Table

File: `Soal4.cpp`

Program ini digunakan untuk menyimpan dan mengelola data mahasiswa menggunakan NIM sebagai key dan nama sebagai value.

Struktur data dan algoritma yang digunakan:

- Hash Table
- Double Hashing

Ukuran Hash Table: 20

Fungsi Hash:

- Hash1(key) = key % 20
- Hash2(key) = 19 - (key % 19)

Fitur program:

- Insert data mahasiswa
- Search data mahasiswa
- Remove data mahasiswa
- Display isi Hash Table
- Menangani collision menggunakan Double Hashing

## Struktur Folder

```text
├── Soal1.cpp
├── Soal2.cpp
├── Soal3.cpp
├── Soal4.cpp
└── README.md
```

## Cara Menjalankan Program

Program dijalankan menggunakan compiler G++.

**Program 1**

```bash
g++ -std=c++11 Soal1.cpp -o Soal1
./Soal1
```

**Program 2**

```bash
g++ -std=c++11 Soal2.cpp -o Soal2
./Soal2
```

**Program 3**

```bash
g++ -std=c++11 Soal3.cpp -o Soal3
./Soal3
```



**Program 4**

```bash
g++ -std=c++11 Soal4.cpp -o Soal4
./Soal4
```

## Video Penjelasan

Video berisi penjelasan mengenai keempat program, struktur data dan algoritma yang digunakan, serta contoh hasil eksekusi program.

**Link YouTube:** (https://youtu.be/V_-eSqVXgaQ?si=zYUxnl-lG--LpECd)
