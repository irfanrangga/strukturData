#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
using namespace std;

struct jadwalPenerbangan{
    string Kode;
    string Jenis;
    string Tanggal;
    string Waktu;
    string Asal;
    string Tujuan;
    int Kapasitas;
};

typedef struct elemJadwal *adr_jadwalP;
typedef struct jadwalPenerbangan infotype;

struct elemJadwal{
    infotype info;
    adr_jadwalP next;
};

struct ListJadwal{ adr_jadwalP first; };

void createListJadwal_103022300100(ListJadwal &L);
adr_jadwalP createElemenJadwal_103022300100(infotype x);
void insertLastJ_103022300100(ListJadwal &L, adr_jadwalP P);
void showJadwal_103022300100(ListJadwal L);
void deleteFirstJ_103022300100(ListJadwal &L, adr_jadwalP P);
adr_jadwalP searchJ_103022300100(ListJadwal L, string dari, string ke, string tanggal);

#endif // FLIGHT_H_INCLUDED
