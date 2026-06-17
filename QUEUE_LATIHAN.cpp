/*
 * ================================================
 *  QUEUE (ANTRIAN) - Implementasi Sederhana C++
 * ================================================
 *
 * Queue = Antrian
 * Prinsip: FIFO (First In, First Out)
 * Seperti antrian di kasir - yang pertama masuk, pertama keluar.
 *
 * Operasi dasar:
 *   - enqueue  : masukkan data ke belakang antrian
 *   - dequeue  : keluarkan data dari depan antrian
 *   - peek     : lihat data paling depan tanpa mengeluarkannya
 *   - isEmpty  : cek apakah antrian kosong
 *   - isFull   : cek apakah antrian penuh
 *   - display  : tampilkan semua isi antrian
 */

#include <iostream>
using namespace std;
const int KAPASITAS_MAX = 3; 

struct Queue {
    int data[KAPASITAS_MAX]; 
    int depan;               
    int belakang;            
    int jumlah;              
};

// Inisialisasi queue
void inisialisasi(Queue &q) {
    q.depan   = 0;
    q.belakang = -1;
    q.jumlah  = 0;
}

// Cek apakah queue kosong
bool isEmpty(Queue &q) {
    return q.jumlah == 0;
}

// Cek apakah queue penuh
bool isFull(Queue &q) {
    return q.jumlah == KAPASITAS_MAX;
}

// Tambah data ke belakang antrian (ENQUEUE)
void enqueue(Queue &q, int nilai) {
    if (isFull(q)) {
        cout << "Antrian PENUH! Tidak bisa menambah data.\n";
        return;
    }

    // Geser belakang ke kanan
    q.belakang = (q.belakang + 1) % KAPASITAS_MAX;
    q.data[q.belakang] = nilai;
    q.jumlah++;

    cout << "Enqueue: " << nilai << " ditambahkan ke antrian.\n";
}

// Keluarkan data dari depan antrian (DEQUEUE)
int dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrian KOSONG! Tidak ada data yang bisa dikeluarkan.\n";
        return -1; 
    }

    int nilaiKeluar = q.data[q.depan];
    q.depan = (q.depan + 1) % KAPASITAS_MAX;
    q.jumlah--;

    cout << "Dequeue: " << nilaiKeluar << " dihapus dari antrian.\n";
    return nilaiKeluar;
}

// Lihat elemen paling depan tanpa mengeluarkannya (PEEK)
int peek(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrian KOSONG! Tidak ada data untuk dilihat.\n";
        return -1;
    }

    cout << "PEEK: antrian paling depan adalah " << q.data[q.depan] << "\n";
    return q.data[q.depan];
}

// Tampilkan semua isi antrian
void display(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "Isi antrian (depan -> belakang): ";
    for (int i = 0; i < q.jumlah; i++) {
        int index = (q.depan + i) % KAPASITAS_MAX;
        cout << q.data[index];
        if (i < q.jumlah - 1) cout << " -> ";
    }
    cout << "\nJumlah antrian: " << q.jumlah << "/" << KAPASITAS_MAX << "\n";
}


int main() {


    Queue antrian;
    inisialisasi(antrian);

    cout << "\n- MEMASUKKAN DATA (ENQUEUE) -\n";
    enqueue(antrian, 10);
    enqueue(antrian, 20);
    enqueue(antrian, 30);
    enqueue(antrian, 40);

    cout << "\n- TAMPILKAN ISI ANTRIAN -\n";
    display(antrian);

    cout << "\n- MELIHAT ELEMEN DEPAN (PEEK) -\n";
    peek(antrian);

    cout << "\n- MENGELUARKAN DATA (DEQUEUE) -\n";
    dequeue(antrian);
    dequeue(antrian);

    cout << "\n- TAMPILKAN ISI ANTRIAN SETELAH DEQUEUE -\n";
    display(antrian);

    cout << "\n- TAMBAH DATA LAGI -\n";
    enqueue(antrian, 40);
    enqueue(antrian, 50);
    enqueue(antrian, 60);
    display(antrian);

    cout << "\n- KOSONGKAN SEMUA ANTRIAN -\n";
    while (!isEmpty(antrian)) {
        dequeue(antrian);
    }

    cout << "\n- COBA DEQUEUE SAAT KOSONG -\n";
    dequeue(antrian); // Ini akan gagal karena kosong

    return 0;
}