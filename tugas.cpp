#include <iostream>
#include <string>
using namespace std;

// Function Return Type Berparameter: Menhitung total harga (penerapan rumus)
int hitungTotal(int hargaPerJam, int durasiJam) {
    return hargaPerJam * durasiJam;
}

// Function Return Type Tanpa Parameter: Mengembalikan Watermark Kelompok
string getWatermark() {
    return "=== KELOMPOK 5 - PROGDAS 2026 ===";
}

// Function Non-Return Type (Void) Tanpa Parameter: Menampilkan Header
void tampilkanHeader() {
    cout << "========================================\n";
    cout << "      RENTAL GAME ARENA 'GAMING HUB'    \n";
    cout << "========================================\n";
}

// ==========================================
// CLASS DAN METHOD (Object-Oriented)
// ==========================================

class RentalManager {
public:
    // Method Non-Return Type (Void) Berparameter: Menampilkan Struk
    void cetakStruk(string namaPenyewa, string namaPaket, int harga, int durasi, bool isMember) {
        int totalAwal = hitungTotal(harga, durasi); // Memanggil Function
        double diskon = 0;

        // Pengkondisian (If-Else)
        if (isMember) {
            diskon = totalAwal * 0.15; // Diskon 15% untuk member
        }

        double totalBayar = totalAwal - diskon;

        // Output Struk
        cout << "\n========================================\n";
        cout << "            STRUK SEWA RENTAL           \n";
        cout << "========================================\n";
        cout << "Nama Penyewa : " << namaPenyewa << "\n";
        cout << "Paket Rental : " << namaPaket << "\n";
        cout << "Durasi Sewa  : " << durasi << " Jam\n";
        cout << "Total Awal   : Rp " << totalAwal << "\n";

        if (isMember) {
            cout << "Diskon (15%): Rp " << diskon << "\n";
        } else {
            cout << "Diskon      : Rp 0 (Non-Member)\n";
        }

        cout << "----------------------------------------\n";
        cout << "TOTAL BAYAR  : Rp " << totalBayar << "\n";
        cout << "========================================\n";
    }
};

int main() {

    cout << "-KELOMPOK 5 SHIFT 1-\n";
    cout << "TAUFIQUR RAHMAN (NIM: 21120126130057)\n";
    cout << "VINCENTIUS GUIDO BIMO WICAKSONO (NIM: 21120126130073)\n";
    cout << "DAFFA ALTAMIS PARSA (NIM: 21120126140181)\n";
    cout << "MUYASSAR AMIRULLAH (NIM: 21120126140186)\n\n";

    // MODUL 1: VARIABEL, TIPE DATA, & ARRAY
    string daftarPaket[3] = {"PlayStation 4", "PlayStation 5", "PC Gaming RTX"};
    int hargaPaket[3] = {10000, 20000, 25000};

    RentalManager rental; // Instansiasi Objek
    char ulang;

    tampilkanHeader();
    cout << getWatermark() << "\n\n";

    // MODUL 2: PERULANGAN (Do-While)
    do {
        string namaPenyewa;
        int pilihanPaket, durasi;
        char statusMember;
        bool isMember = false;

        // Input data penyewa
        cout << "Masukkan Nama Penyewa: ";
        cin.ignore(); // Membersihkan sisa input buffer
        getline(cin, namaPenyewa);

        // Menampilkan daftar paket menggunakan ARRAY & PERULANGAN FOR
        cout << "\nDaftar Paket Rental:\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << daftarPaket[i] << " (Rp " << hargaPaket[i] << "/jam)\n";
        }

        // Input Pilihan
        cout << "Pilih Paket (1-3): ";
        cin >> pilihanPaket;

        // MODUL 3: PENGKONDISIAN (Validasi Input)
        if (pilihanPaket < 1 || pilihanPaket > 3) {
            cout << "[ERROR] Pilihan paket tidak valid!\n\n";
            continue;
        }

        cout << "Masukkan Durasi (Jam): ";
        cin >> durasi;

        cout << "Apakah Memiliki Kartu Member? (y/n): ";
        cin >> statusMember;

        if (statusMember == 'y' || statusMember == 'Y') {
            isMember = true;
        }

        // Memanggil METHOD untuk memproses data dari ARRAY
        int idx = pilihanPaket - 1; // Konversi ke indeks array (0-2)
        rental.cetakStruk(namaPenyewa, daftarPaket[idx], hargaPaket[idx], durasi, isMember);

        // Pertanyaan untuk perulangan
        cout << "\nIngin memproses transaksi lagi? (y/n): ";
        cin >> ulang;
        cout << "\n";

    } while (ulang == 'y' || ulang == 'Y');

    cout << "Terima kasih telah menggunakan layanan kami!\n";
    cout << getWatermark() << "\n";

    return 0;
}
