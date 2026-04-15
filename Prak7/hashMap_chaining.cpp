#include <iostream>
using namespace std;
#define TABLE_SIZE 7
struct Node{
 int key;
 Node* next;
};
Node* hashTable[TABLE_SIZE];
int hashFunction(int key){
 return key % TABLE_SIZE;
}
Node* createNode(int key){
 Node* newNode = new Node();
 newNode->key = key;
 newNode->next = NULL;
 return newNode;
}
void insert(int key){
 int index = hashFunction(key);
 Node* newNode = createNode(key);
 if(hashTable[index] == NULL){
 hashTable[index] = newNode;
 }
 else{
 newNode->next = hashTable[index];
 hashTable[index] = newNode;
 }
}
void display(){
 for(int i=0;i<TABLE_SIZE;i++){
 cout << i << " -> ";
 Node* temp = hashTable[i];
 while(temp != NULL){
 cout << temp->key << " -> ";
 temp = temp->next;
 }
 cout << "NULL" << endl;
 }
}
int main(){
 for(int i=0;i<TABLE_SIZE;i++)
 hashTable[i] = NULL;
 int n,x;
 cout << "Masukkan jumlah data: ";
 cin >> n;
 cout << "Masukkan data:" << endl;
 for(int i=0;i<n;i++){
 cin >> x;
 insert(x);
 }
 cout << "\nHash Table:" << endl;
 display();
 return 0;
}