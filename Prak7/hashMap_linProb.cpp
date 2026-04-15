#include <iostream>
using namespace std;
#define TABLE_SIZE 7
#define EMPTY -1
int hashTable[TABLE_SIZE];
int hashFunction(int key){
 return key % TABLE_SIZE;
}
void insert(int key){
 int index = hashFunction(key);
 while(hashTable[index] != EMPTY){
 index = (index + 1) % TABLE_SIZE;
 }
 hashTable[index] = key;
}
void display(){
 for(int i = 0; i < TABLE_SIZE; i++){
 if(hashTable[i] == EMPTY)
 cout << i << " -> kosong" << endl;
 else
 cout << i << " -> " << hashTable[i] << endl;
 }
}
int main(){
 for(int i = 0; i < TABLE_SIZE; i++)
 hashTable[i] = EMPTY;
 int n, x;
 cout << "Masukkan jumlah data: ";
 cin >> n;
 cout << "Masukkan data:" << endl;
 for(int i = 0; i < n; i++){
 cin >> x;
 insert(x);
 }
 cout << "\nHash Table:" << endl;
 display();
 return 0;
}