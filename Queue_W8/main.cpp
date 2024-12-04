#include "queue_vaksinasi.h"
int main(){
    Queue Q;

    createQueue_103022300100(Q);
    address P1 = createElemQueue_103022300100("John Doe", 65, "Lansia", 1);
    address P2 = createElemQueue_103022300100("Alice", 30, "tenaga kesehatan", 2);
    address P3 = createElemQueue_103022300100("Bob", 25, "pekerja", 3);
    address P4 = createElemQueue_103022300100("Charlie", 70, "pensiunan", 4);
    address P5 = createElemQueue_103022300100("David", 28, "pekerja", 5);

    enqueue_103022300100(Q, P1);
    enqueue_103022300100(Q, P2);
    enqueue_103022300100(Q, P3);
    enqueue_103022300100(Q, P4);
    enqueue_103022300100(Q, P5);

    cout << "Isi Antrean Awal: " << endl;
    printInfo_103022300100(Q);
    //Melayani Antrean
    cout << "\nMelakukan pelayanan pada antrean: " << endl;
    serveQueue_103022300100(Q);
    cout << "\nList setelah pelayanan: " << endl;
    printInfo_103022300100(Q);
    address P6 = createElemQueue_103022300100("Edward", 22, "pekerja", 6);
    enqueue_103022300100(Q, P6);
    cout << "\nMengatur ulang antrean berdasarkan prioritas" << endl;
    reassignQueue_103022300100(Q);
    printInfo_103022300100(Q);
    cout << "\nMemeriksa waktu tunggu dan mengubah prioritas jika lebih dari 2 jam:" << endl;
    checkWaitingTime_103022300100(Q, 130);
    printInfo_103022300100(Q);
    cout << "\nMenangani kondisi darurat untuk warga dengan nomor antrean 5: " << endl;
    emergencyHandle_103022300100(Q, 5);
    printInfo_103022300100(Q);
    cout << "\nMengupdate prioritas antrean setiap jam: " << endl;
    updatePriority_103022300100(Q);
    printInfo_103022300100(Q);
    cout << "\nMenghapus warga dengan nomor antrean 3: " << endl;
    address removedElem = findAndRemove_103022300100(Q, 3);
    if(removedElem){
        cout << "Warga yang dhapus: " << info(removedElem).nama << endl;
    }
    printInfo_103022300100(Q);
    cout << "\nUkuran queue saat ini: " << size_103022300100(Q) << endl;
    return 0;
}
