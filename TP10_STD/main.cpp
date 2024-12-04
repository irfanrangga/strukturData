#include "flight.h"
int main(){
    ListJadwal L;
    infotype x;
    adr_jadwalP P;
    int n;
    int i = 1;
    createListJadwal_103022300100(L);
    cout << "Masukkan jumlah jadwal penerbangan yang ingin diinput: ";
    cin >> n;
    while(i <= n){
        cout << "\nMasukkan Data ke - " << i << endl;
        cout << "Masukkan Kode penerbangan: ";
        cin >> x.Kode;
        cout << "Masukkan Jenis pesawat: ";
        cin >> x.Jenis;
        cout << "Masukkan Tanggal penerbangan: ";
        cin >> x.Tanggal;
        cout << "Masukkan Waktu penerbangan: ";
        cin >> x.Waktu;
        cout << "Masukkan Asal penerbangan: ";
        cin >> x.Asal;
        cout << "Masukkan Tujuan penerbangan: ";
        cin >> x.Tujuan;
        cout << "Masukkan Kapasitas pesawat: ";
        cin >> x.Kapasitas;
        P = createElemenJadwal_103022300100(x);
        insertLastJ_103022300100(L, P);
        i++;
    }
    cout << "\nList Awal" << endl;
    showJadwal_103022300100(L);
    cout << "Menghapus data pertama" << endl;
    deleteFirstJ_103022300100(L, P);
    showJadwal_103022300100(L);
    cout << "Mencari Alamat data pesawat" << endl;
    cout << searchJ_103022300100(L, "Surabaya_(SUB)", "Malang_(MLG)", "9_Desember_2022") << endl;
    return 0;
}
