#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

// ============================
// KALKULATOR MATEMATIKA LANJUTAN
// Fitur: Integral, Turunan, Persamaan Kuadrat
// ============================

// Fungsi untuk menghitung turunan dari fungsi polinomial sederhana ax^n
void hitungTurunan() {
    double a;
    int n;
    cout << "\n=== PERHITUNGAN TURUNAN ===" << endl;
    cout << "Masukkan koefisien a: ";
    cin >> a;
    cout << "Masukkan pangkat n: ";
    cin >> n;

    double hasil = a * n;
    int pangkatBaru = n - 1;

    cout << "Turunan dari " << a << "x^" << n << " adalah ";
    if (pangkatBaru == 0)
        cout << hasil << endl;
    else if (pangkatBaru == 1)
        cout << hasil << "x" << endl;
    else
        cout << hasil << "x^" << pangkatBaru << endl;
}

// Fungsi untuk menghitung integral tak tentu dari ax^n
void hitungIntegral() {
    double a;
    int n;
    cout << "\n=== PERHITUNGAN INTEGRAL ===" << endl;
    cout << "Masukkan koefisien a: ";
    cin >> a;
    cout << "Masukkan pangkat n: ";
    cin >> n;

    int pangkatBaru = n + 1;
    double hasil = a / pangkatBaru;

    cout << "Integral tak tentu dari " << a << "x^" << n << " adalah ";
    if (pangkatBaru == 1)
        cout << hasil << "x + C" << endl;
    else
        cout << hasil << "x^" << pangkatBaru << " + C" << endl;
}

// Fungsi untuk menghitung akar-akar persamaan kuadrat
void hitungPersamaanKuadrat() {
    double a, b, c;
    cout << "\n=== PERSAMAAN KUADRAT ===" << endl;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Masukkan nilai c: ";
    cin >> c;

    if (a == 0) {
        cout << "Nilai a tidak boleh 0 pada persamaan kuadrat!" << endl;
        return;
    }

    double D = (b * b) - (4 * a * c);
    cout << "Diskriminan (D) = " << D << endl;

    if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Persamaan memiliki dua akar real: x1 = " << x1 << ", x2 = " << x2 << endl;
    } else if (D == 0) {
        double x = -b / (2 * a);
        cout << "Persamaan memiliki satu akar kembar: x = " << x << endl;
    } else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-D) / (2 * a);
        cout << "Persamaan memiliki akar kompleks:\n";
        cout << "x1 = " << realPart << " + " << imagPart << "i" << endl;
        cout << "x2 = " << realPart << " - " << imagPart << "i" << endl;
    }
}

// Menu utama program
void menuUtama() {
    int pilihan;

    do {
        cout << "\n==============================\n";
        cout << "   KALKULATOR MATEMATIKA LANJUTAN   \n";
        cout << "==============================\n";
        cout << "1. Hitung Turunan\n";
        cout << "2. Hitung Integral\n";
        cout << "3. Selesaikan Persamaan Kuadrat\n";
        cout << "4. Keluar\n";
        cout << "==============================\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        // Validasi input agar tidak error
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan masukkan angka 1-4.\n";
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
                hitungPersamaanKuadrat();
                break;
            case 4:
                cout << "\nTerima kasih telah menggunakan Kalkulator Matematika Lanjutan!" << endl;
                cout << "Semoga program ini bermanfaat :)\n" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);
}

// Fungsi utama
int main() {
    menuUtama();
    return 0;
}
