#include <iostream>

using namespace std;

// harga tiket
const int VIP = 500000;
const int CAT1 = 200000;
const int REGULER = 150000;

// Stok tiket
int stokvip = 3;
int stokcat1 = 3;
int stokreguler = 3;

// menu dan jenis tiket
int pilihTiket() {
    int pilihan;
    cout << "=================================================" << endl;
    cout << "=            SILAHKAN PILIH JENIS TIKET         =" << endl;
    cout << "=                 KONSER MERIAH PALU            =" << endl;
    cout << "=================================================" << endl;
    cout << "= 1. VIP        = Rp500.000                     =" << endl;
    cout << "= 2. CAT 1      = Rp200.000                     =" << endl;
    cout << "= 3. REGULER    = Rp150.000                     =" << endl;
    cout << "=================================================" << endl;
    cout << "Masukkan pilihan anda    :";
    cin >> pilihan;
    return pilihan;
}

// proses pembelian tiket
void beliTiket(int jenisTiket, int &stok, string namaTiket, int hargaTiket) {
    float banyak;
    cout << "Banyak tiket yang dibeli :";
    cin >> banyak;
    if (banyak <= stok) {
        string tgl;
        cout << "Tanggal pembelian (dd/mm/yy) :";
        cin >> tgl;
        cout << "=================================================" << endl;
        cout << "=           TIKET KONSER MERIAH PALU            =" << endl;
        cout << "=================================================" << endl;
        cout << "= Kode tiket         : " << jenisTiket << endl;
        cout << "= Nama tiket         : " << namaTiket << endl;
        cout << "= Harga tiket        : Rp" << hargaTiket << endl;
        cout << "= Banyak tiket       : " << banyak << endl;
        cout << "= Total harga        : Rp" << banyak * hargaTiket << endl;
        cout << "=================================================" << endl;
        cout << endl;
        
        // menghitung kembalian
        float totalBayar = banyak * hargaTiket;
        float bayar;
        cout << "Masukkan jumlah uang yang dibayarkan: Rp";
        cin >> bayar;
        float kembalian = bayar - totalBayar;
        cout << "Kembalian Anda adalah Rp" << kembalian << endl;

        // Mengurangi stok tiket
        stok =stok- banyak;
    } else {
        cout << "Maaf, stok tiket " << namaTiket << " tidak mencukupi." << endl;
    }
}

int main() {
    string nama;
    int pilihan;
    char ulangi;
    
    do {
        cout << "=================================================" << endl;
        cout << "=            SELAMAT DATANG DILOKER TIKET       =" << endl;
        cout << "=                 KONSER MERIAH PALU            =" << endl;
        cout << "=================================================" << endl;
        cout << "Nama Pemebeli: ";
        cin >> nama;
        cout << endl;

        pilihan = pilihTiket();

        switch (pilihan) {
            case 1:
                beliTiket(pilihan, stokvip, "VIP", VIP);
                break;
            case 2:
                beliTiket(pilihan, stokcat1, "CAT 1", CAT1);
                break;
            case 3:
                beliTiket(pilihan, stokreguler, "REGULER", REGULER);
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << "Terima kasih telah membeli tiket." << endl;

        cout << "Apakah Anda ingin membeli tiket lagi? (y/n): ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');

    return 0;
}