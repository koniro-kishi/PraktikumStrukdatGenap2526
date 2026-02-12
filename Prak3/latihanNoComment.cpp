#include <iostream>
#include <cstdint>

// Definisi struktur Node
struct Node {
   int data;
   Node* next;
};

// Fungsi untuk menambahkan node di awal linked list
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menambahkan node di akhir linked list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = newNode;
}

// Fungsi untuk menghapus node di awal linked list
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        std::cout << "Linked list is empty. Cannot delete from the beginning." <<
        std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

// Fungsi untuk menghapus node di akhir linked list
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        std::cout << "Linked list is empty. Cannot delete from the end." <<
        std::endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    
    Node* secondLast = head;
    while (secondLast->next->next != nullptr) {
        secondLast = secondLast->next;
    }

    delete secondLast->next;
    secondLast->next = nullptr;
}

// Fungsi untuk mencari data tertentu dan menggantinya dengan nilai baru
void updateData(Node* head, int oldData, int newData) {
    Node* current = head;
    
    while (current != nullptr) {
        if (current->data == oldData) {
            current->data = newData;
            std::cout << "Data updated successfully." << std::endl;
            return;
        }

        current = current->next;
    }

    std::cout << "Data not found in the linked list." << std::endl;
}

// Fungsi untuk mencetak seluruh isi linked list
void printLinkedList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " " <<  reinterpret_cast<uintptr_t>(current) << std::endl;
        // std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

// Fungsi untuk menghapus seluruh linked list
// Node*&: *& itu artinya reference to pointer. kita ngubah alamat yang dipegang variable pointernya itu sendiri
// variable parameter bisa (tanpa simbol atau cuma *) ketika kita ngasih variable sebagai input, dia gak ngubah variable awal
void deleteLinkedList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}



int main() {
    Node* head = nullptr;
    int choice;
    do {
        std::cout << "\nMenu:\n1. Insert di Awal\n2. Insert di Akhir\n3. Hapus di Awal\n4. Hapus di Akhir\n5. Update Data\n6. Cetak Linked List\n0. Keluar\n";
        std::cout << "Pilih operasi (0-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int insertData;
                std::cout << "Masukkan data untuk di-insert di awal: ";
                std::cin >> insertData;
                insertAtBeginning(head, insertData);
                break;

            case 2:
                int insertDataEnd;
                std::cout << "Masukkan data untuk di-insert di akhir: ";
                std::cin >> insertDataEnd;
                insertAtEnd(head, insertDataEnd);
                break;

            case 3:
                deleteAtBeginning(head);
                break;

            case 4:
                deleteAtEnd(head);
                break;

            case 5:
                int oldData, newData;
                std::cout << "Masukkan data yang ingin di-update: ";
                std::cin >> oldData;
                std::cout << "Masukkan nilai baru: ";
                std::cin >> newData;
                updateData(head, oldData, newData);
                break;

            case 6:
                printLinkedList(head);
                break;

            case 0:
                std::cout << "Keluar dari program.\n";
                break;

            default:
                std::cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    } while (choice != 0);
    
    // Hapus seluruh linked list sebelum keluar dari program
    deleteLinkedList(head);
    return 0;
}