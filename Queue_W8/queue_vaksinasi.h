#ifndef QUEUE_VAKSINASI_H_INCLUDED
#define QUEUE_VAKSINASI_H_INCLUDED
#include <iostream>
#define head(Q) Q.head
#define tail(Q) Q.tail
#define info(P) P->info
#define next(P) P->next
#define nil NULL
using namespace std;

typedef struct ElemQ *address;

struct Queue{
    address head;
    address tail;
};

struct infotype{
    string nama;
    int usia;
    string pekerjaan;
    bool prioritas;
    int nomor_antrean;
    int waktu_daftar;
    bool kondisi_darurat;
};

struct ElemQ{
    infotype info;
    address next;
};

void createQueue_103022300100(Queue &Q);
bool isEmpty_103022300100(Queue Q);
address createElemQueue_103022300100(string nama, int usia, string pekerjaan, int nomor_antrean);
void enqueue_103022300100(Queue &Q, address P);
void dequeue_103022300100(Queue &Q, address P);
address front_103022300100(Queue Q);
address back_103022300100(Queue Q);
int size_103022300100(Queue Q);
void printInfo_103022300100(Queue Q);
void serveQueue_103022300100(Queue Q);
void reassignQueue_103022300100(Queue Q);
void checkWaitingTime_103022300100(Queue &Q, int waktu_sekarang);
void emergencyHandle_103022300100(Queue &Q, int nomor_antrean);
void updatePriority_103022300100(Queue &Q);
address findAndRemove_103022300100(Queue &Q, int nomor_antrean);

#endif // QUEUE_VAKSINASI_H_INCLUDED
