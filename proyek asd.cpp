#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// =========================================================
//  KALKULATOR MATEMATIKA LANJUTAN
//  Fitur: Integral, Turunan, Persamaan Kuadrat
//  Bahasa: C++
//  Kelompok 2 - Proyek Algoritma & Struktur Data
// =========================================================

// Fungsi menghitung turunan polinomial sederhana ax^n
void hitungTurunan() {
    double a;
    int n;
    cout << "\n=== PERHITUNGAN TURUNAN ===" << endl;
    cout << "Masukkan koefisien (a): ";
    cin >> a;
    cout << "Masukkan pangkat (n): ";
    cin >> n;

    double hasil = a * n;
    int pangkatBaru = n - 1;

    cout << "\nTurunan dari " << a << "x^" << n << " adalah: ";
    if (pangkatBaru == 0)
        cout << hasil;
    else if (pangkatBaru == 1)
        cout << hasil << "x";
    else
        cout << hasil << "x^" << pangkatBaru;
    cout << endl;
}

// Fungsi menghitung integral tak tentu polinomial ax^n
void hitungIntegral() {
    double a;
    int n;
    cout << "\n=== PERHITUNGAN INTEGRAL ===" << endl;
    cout << "Masukkan koefisien (a): ";
    cin >> a;
    cout << "Masukkan pangkat (n): ";
    cin >> n;

    int pangkatBaru = n + 1;
    double hasil = a / pangkatBaru;

    cout << "\nIntegral tak tentu dari " << a << "x^" << n << " adalah: ";
    if (pangkatBaru == 1)
        cout << hasil << "x + C";
    else
        cout << hasil << "x^" << pangkatBaru << " + C";
    cout << endl;
}

// Fungsi menghitung integral tentu polinomial ax^n dari batas bawah ke atas
void hitungIntegralTentu() {
    double a, bawah, atas;
    int n;
    cout << "\n=== PERHITUNGAN INTEGRAL TENTU ===" << endl;
    cout << "Masukkan koefisien (a): ";
    cin >> a;
    cout << "Masukkan pangkat (n): ";
    cin >> n;
    cout << "Masukkan batas bawah: ";
    cin >> bawah;
    cout << "Masukkan batas atas: ";
    cin >> atas;

    int pangkatBaru = n + 1;
    double hasil = (a / pangkatBaru) * (pow(atas, pangkatBaru) - pow(bawah, pangkatBaru));

    cout << "\nHasil integral tentu dari " << a << "x^" << n
         << " dengan batas [" << bawah << ", " << atas << "] adalah: " << hasil << endl;
}

// Fungsi menghitung akar-akar persamaan kuadrat
void hitungPersamaanKuadrat() {
    double a, b, c;
    cout << "\n=== PENYELESAIAN PERSAMAAN KUADRAT ===" << endl;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Masukkan nilai c: ";
    cin >> c;

    if (a == 0) {
        cout << "Nilai a tidak boleh 0 karena bukan persamaan kuadrat!" << endl;
        return;
    }

    double D = (b * b) - (4 * a * c);
    cout << "\nDiskriminan (D) = " << D << endl;

    if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Persamaan memiliki dua akar real berbeda:\n";
        cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
    } else if (D == 0) {
        double x = -b / (2 * a);
        cout << "Persamaan memiliki satu akar kembar:\n";
        cout << "x = " << x << endl;
    } else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-D) / (2 * a);
        cout << "Persamaan memiliki akar kompleks:\n";
        cout << "x1 = " << realPart << " + " << imagPart << "i" << endl;
        cout << "x2 = " << realPart << " - " << imagPart << "i" << endl;
    }
}

// Fungsi menampilkan menu utama
void menuUtama() {
    int pilihan;

    do {
        cout << "\n=========================================\n";
        cout << "     KALKULATOR MATEMATIKA LANJUTAN     \n";
        cout << "=========================================\n";
        cout << "1. Hitung Turunan\n";
        cout << "2. Hitung Integral Tak Tentu\n";
        cout << "3. Hitung Integral Tentu\n";
        cout << "4. Selesaikan Persamaan Kuadrat\n";
        cout << "5. Keluar\n";
        cout << "=========================================\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        // Validasi input agar tidak error
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan masukkan angka 1-5.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                hitungTurunan();
                break;
            case 2:
                hitungIntegral();
                break;
            case 3:
                hitungIntegralTentu();
                break;
            case 4:
                hitungPersamaanKuadrat();
                break;
            case 5:
                cout << "\n=========================================\n";
                cout << "Terima kasih telah menggunakan program ini!\n";
                cout << "KALKULATOR MATEMATIKA LANJUTAN\n";
                cout << "Kelompok 2 - Universitas Lampung 2025\n";
                cout << "Semoga program ini bermanfaat :)";
                cout << "\n=========================================\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 5);
}

// Program utama
int main() {
    menuUtama();
    return 0;
}
