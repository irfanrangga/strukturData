#include "flight.h"

void createListJadwal_103022300100(ListJadwal &L){
    first(L) = NULL;
}

adr_jadwalP createElemenJadwal_103022300100(infotype x){
    adr_jadwalP P = new elemJadwal;

    info(P).Kode = x.Kode;
    info(P).Jenis = x.Jenis;
    info(P).Tanggal = x.Tanggal;
    info(P).Waktu = x.Waktu;
    info(P).Asal = x.Asal;
    info(P).Tujuan = x.Tujuan;
    info(P).Kapasitas = x.Kapasitas;
    next(P) = NULL;

    return P;
}

void insertLastJ_103022300100(ListJadwal &L, adr_jadwalP P){
    if(first(L) == NULL){
        first(L) = P;
    } else {
        adr_jadwalP Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void showJadwal_103022300100(ListJadwal L){
    adr_jadwalP P = first(L);
    if(first(L) == NULL){
        cout << "List kosong." << endl;
    } else {
        cout << "Kode\tJenis\t\tTanggal\t\tWaktu\t\tAsal\t\tTujuan\t\tKapasitas\n" << endl;
        while(P != NULL){
            cout << info(P).Kode << " || " << info(P).Jenis << " || " << info(P).Tanggal << " || " << info(P).Waktu
            << " || " << info(P).Asal << " || " << info(P).Tujuan << " || " << info(P).Kapasitas << endl;
            cout << endl;
            P = next(P);
        }
    }
}

void deleteFirstJ_103022300100(ListJadwal &L, adr_jadwalP P){
    if(first(L) == NULL){
        cout << "Tidak ada data dalam list." << endl;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

adr_jadwalP searchJ_103022300100(ListJadwal L, string dari, string ke, string tanggal){
    adr_jadwalP P = first(L);
    while(P != NULL){
        if(info(P).Asal == dari && info(P).Tujuan == ke && info(P).Tanggal == tanggal){
            return P;
        } else {
            return NULL;
        }
        P = next(P);
    }

}
