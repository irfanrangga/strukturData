#include "queue_vaksinasi.h"

void createQueue_103022300100(Queue &Q){
    head(Q) = nil;
    tail(Q) = nil;
}

bool isEmpty_103022300100(Queue Q){
    return head(Q) == nil;
}

address createElemQueue_103022300100(string nama, int usia, string pekerjaan, int nomor_antrean){
    address P = new ElemQ;
    info(P).nama = nama;
    info(P).usia = usia;
    info(P).pekerjaan = pekerjaan;
    info(P).prioritas = (usia >= 60 || pekerjaan == "tenaga kesehatan");
    info(P).nomor_antrean = nomor_antrean;
    info(P).kondisi_darurat = false;
    next(P) = nil;

    return P;
}

void enqueue_103022300100(Queue &Q, address P){
    if(isEmpty_103022300100(Q)){
        head(Q) = P;
        tail(Q) = P;
    } else if(info(P).prioritas){
        if(!info(head(Q)).prioritas){
            next(P) = head(Q);
            head(Q) = P;
        } else {
            address temp = head(Q);
            while(next(temp) != nil && info(next(temp)).prioritas){
                temp = next(temp);
            }
            next(P) = next(temp);
            next(temp) = P;
            if(next(P) == nil){
                tail(Q) = P;
            }
        }
    } else {
        next(tail(Q)) = P;
        tail(Q) = P;
    }
}

void dequeue_103022300100(Queue &Q, address P){
    if(isEmpty_103022300100(Q)){
        P = nil;
        cout << "Semua warga telah terlayani" << endl;
    } else {
        P = head(Q);
        head(Q) = next(head(Q));
        if (head(Q) == nil){
            tail(Q) = nil;
        }
        next(P) = nil;
    }
}

address front_103022300100(Queue Q){
    return head(Q);
}

address back_103022300100(Queue Q){
    return tail(Q);
}

int size_103022300100(Queue Q){
    int count = 0;
    address temp = head(Q);
    while(temp != nil){
        count++;
        temp = next(temp);
    }
    return count;
}

void printInfo_103022300100(Queue Q){
    address P = front_103022300100(Q);
    if(isEmpty_103022300100(Q)){
        cout << "Antrian Kosong." << endl;
    }
    while(P != nil){
        cout << "Nama: " << info(P).nama << endl;
        cout << "Usia: " << info(P).usia << endl;
        cout << "Pekerjaan: " << info(P).pekerjaan << endl;
        cout << "Prioritas: ";
        if(info(P).prioritas){
            cout << "Ya" << endl;
        } else {
            cout << "Tidak" << endl;
        }
        cout << "Nomor Antrean: " << info(P).nomor_antrean << endl;
        cout << "--------------------" << endl;
        P = next(P);
    }
}

void serveQueue_103022300100(Queue Q){
    address P = front_103022300100(Q);
    while(!isEmpty_103022300100(Q)){
        cout << "Melayani Warga: " << endl;
        cout << "Nama: " << info(P).nama << endl;
        cout << "Usia: " << info(P).usia << endl;
        cout << "Pekerjaan: " << info(P).pekerjaan << endl;
        cout << "Prioritas: ";
        if(info(P).prioritas){
            cout << "Ya" << endl;
        } else {
            cout << "Tidak" << endl;
        }
        cout << "Nomor Antrean: " << info(P).nomor_antrean << endl;
        cout << "Vaksinasi berhasil." << endl;
        cout << "--------------------" << endl;
        P = next(P);
        dequeue_103022300100(Q, P);
    }
    if(!isEmpty_103022300100(Q)){
        cout << "Silahkan datang kembali besok." << endl;
    }
}

void reassignQueue_103022300100(Queue Q){
    Queue QueuePriority;
    Queue QueueNormal;
    createQueue_103022300100(QueuePriority);
    createQueue_103022300100(QueueNormal);
    address P = nil;
    while(!isEmpty_103022300100(Q)){
        dequeue_103022300100(Q, P);
        if(info(P).prioritas){
            enqueue_103022300100(QueuePriority, P);
        } else {
            enqueue_103022300100(QueueNormal, P);
        }
    }
    while(!isEmpty_103022300100(QueuePriority)){
        dequeue_103022300100(QueuePriority, P);
        enqueue_103022300100(Q, P);
    }
    while(!isEmpty_103022300100(QueueNormal)){
        dequeue_103022300100(QueueNormal, P);
        enqueue_103022300100(Q, P);
    }

}

void checkWaitingTime_103022300100(Queue &Q, int waktu_sekarang){
    Queue QueuePriority;
    Queue QueueNormal;
    createQueue_103022300100(QueuePriority);
    createQueue_103022300100(QueueNormal);

    address P = nil;
    while(!isEmpty_103022300100(Q)){
        dequeue_103022300100(Q, P);
        bool valid = waktu_sekarang - info(P).waktu_daftar > 120 && !info(P).prioritas;
        if(valid){
            info(P).prioritas = true;
            enqueue_103022300100(QueuePriority, P);
        } else {
            enqueue_103022300100(QueueNormal, P);
        }
    }
    while(!isEmpty_103022300100(QueuePriority)){
        dequeue_103022300100(QueuePriority, P);
        enqueue_103022300100(Q, P);
    }
    while(!isEmpty_103022300100(QueueNormal)){
        dequeue_103022300100(QueueNormal, P);
        enqueue_103022300100(Q, P);
    }
}

void emergencyHandle_103022300100(Queue &Q, int nomor_antrean){
    address emergency_elm =  findAndRemove_103022300100(Q, nomor_antrean);
    if(!emergency_elm){
         printf("Warga dengan nomor antrean %d tidak ditemukan\n",
               nomor_antrean);
        return;
    }
    info(emergency_elm).kondisi_darurat = true;
    info(emergency_elm).prioritas = "prioritas tinggi";
    address temp = head(Q);

    if(isEmpty_103022300100(Q) || info(temp).prioritas){
        enqueue_103022300100(Q, emergency_elm);
    } else {
        next(emergency_elm) = head(Q);
        head(Q) = emergency_elm;
    }
     printf("Warga dengan nomor antrean %d di prioritaskan karena kondisi darurat\n",
           nomor_antrean);
}

void updatePriority_103022300100(Queue &Q){
    checkWaitingTime_103022300100(Q, 120);
    Queue QueuePriority;
    Queue QueueNormal;
    createQueue_103022300100(QueuePriority);
    createQueue_103022300100(QueueNormal);
    address P = nil;
    while(!isEmpty_103022300100(Q)){
        dequeue_103022300100(Q, P);
        if(info(P).kondisi_darurat || info(P).prioritas){
            enqueue_103022300100(QueuePriority, P);
        } else {
            enqueue_103022300100(QueueNormal, P);
        }
    }
    while(!isEmpty_103022300100(QueuePriority)){
        dequeue_103022300100(QueuePriority, P);
        enqueue_103022300100(Q, P);
    }
    while(!isEmpty_103022300100(QueueNormal)){
        dequeue_103022300100(QueueNormal, P);
        enqueue_103022300100(Q, P);
    }
}

address findAndRemove_103022300100(Queue &Q, int nomor_antrean){
    if(isEmpty_103022300100(Q)){
        return nil;
    }
    address P = head(Q);
    address prev = nil;

    while(P != nil && info(P).nomor_antrean == nomor_antrean){
        prev = P;
        P = next(P);
    }
    if(!P){
        if(prev && info(prev).nomor_antrean == nomor_antrean){
            return prev;
        }
        return nil;
    }

    if(!prev){
        head(Q) = next(Q);
    } else {
        next(prev) = next(P);
    }
    if(P == tail(Q)){
        tail(Q) = prev;
    }
    next(P) = nil;
    return P;
}
