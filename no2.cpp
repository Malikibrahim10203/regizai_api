#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definisi fungsi yang akan dimaksimalkan atau diminimalkan
double fungsi(double x) {
    return sin(x) * exp(2 * x + sin(x)) + pow(x, 3) + pow(x, 2);
}

// Fungsi untuk menginisialisasi populasi secara acak
vector<double> inisialisasiPopulasi(int ukuranPopulasi, double batasBawah, double batasAtas) {
    vector<double> populasi(ukuranPopulasi);
    for (int i = 0; i < ukuranPopulasi; ++i) {
        populasi[i] = batasBawah + static_cast<double>(rand()) / RAND_MAX * (batasAtas - batasBawah);
    }
    return populasi;
}

// Fungsi untuk seleksi orang tua menggunakan metode turnamen
double seleksiTurnamen(const vector<double>& populasi) {
    int ukuranTurnamen = 3;
    double terbaik = populasi[rand() % populasi.size()];
    for (int i = 1; i < ukuranTurnamen; ++i) {
        double kandidat = populasi[rand() % populasi.size()];
        if (fungsi(kandidat) > fungsi(terbaik)) {
            terbaik = kandidat;
        }
    }
    return terbaik;
}

// Fungsi crossover untuk menghasilkan keturunan baru
double crossover(double parent1, double parent2) {
    double alpha = static_cast<double>(rand()) / RAND_MAX;
    return alpha * parent1 + (1 - alpha) * parent2;
}

// Fungsi mutasi untuk memperkenalkan variasi baru dalam populasi
double mutasi(double individu, double batasBawah, double batasAtas) {
    double mutasiRate = 0.1;
    if (static_cast<double>(rand()) / RAND_MAX < mutasiRate) {
        individu += (static_cast<double>(rand()) / RAND_MAX - 0.5) * (batasAtas - batasBawah) * 0.1;
        if (individu < batasBawah) individu = batasBawah;
        if (individu > batasAtas) individu = batasAtas;
    }
    return individu;
}

// Fungsi utama algoritma genetika untuk mencari nilai maksimum dan minimum
void algoritmaGenetika(int ukuranPopulasi, int generasi, double batasBawah, double batasAtas) {
    srand(time(0));

    vector<double> populasi = inisialisasiPopulasi(ukuranPopulasi, batasBawah, batasAtas);

    for (int g = 0; g < generasi; ++g) {
        vector<double> populasiBaru;

        for (int i = 0; i < ukuranPopulasi; ++i) {
            double parent1 = seleksiTurnamen(populasi);
            double parent2 = seleksiTurnamen(populasi);
            double anak = crossover(parent1, parent2);
            anak = mutasi(anak, batasBawah, batasAtas);
            populasiBaru.push_back(anak);
        }

        populasi = populasiBaru;
    }

    // Mencari nilai maksimum dan minimum dalam populasi akhir
    double maksimum = *max_element(populasi.begin(), populasi.end(), [](double a, double b) { return fungsi(a) < fungsi(b); });
    double minimum = *min_element(populasi.begin(), populasi.end(), [](double a, double b) { return fungsi(a) < fungsi(b); });

    cout << "Hasil nilai maksimum fungsi: " << fungsi(maksimum) << ", di x = " << maksimum << endl;
    cout << "Hasil nilai minimum fungsi: " << fungsi(minimum) << ", di x = " << minimum << endl;
}

int main() {
    int ukuranPopulasi = 100;
    int generasi = 1000;
    double batasBawah = -10;
    double batasAtas = 10;

    algoritmaGenetika(ukuranPopulasi, generasi, batasBawah, batasAtas);

    return 0;
}
