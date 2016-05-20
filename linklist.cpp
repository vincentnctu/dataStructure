#include <iostream>

using namespace std;

typedef struct element {
  int data;
  struct element *next;
} ELEMENT;

static ELEMENT *Head = NULL;

void dataInsertTrail(int data) {
  ELEMENT *pElement;
  pElement = new element;
  pElement->data = data;
  pElement->next = NULL;

  ELEMENT *ptr = Head;
  while (ptr && ptr->next != NULL) {
    ptr = ptr->next; 
  }

  ptr->next = pElement;
}

void dataInsertHead(int data) {
  ELEMENT *pElement;
  pElement = new element;
  pElement->data = data;

  ELEMENT *pHead;
  pHead = Head;
  Head = pElement;
  Head ->next = pHead;
}

void dataList() {
  ELEMENT *ptr; 
  ptr = Head;
  
  while (ptr) {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

void dataDelete(int data) {
  if (!Head) return;
  
  cout << "Delete " << data << " from list" << endl;
  ELEMENT *pCurrent = Head;
  ELEMENT *pPrevious = Head;

  while (pCurrent && pCurrent->next != NULL) {
    if (pCurrent->data == data) {
      break;
    }
    pPrevious = pCurrent;
    pCurrent = pCurrent->next;
  }
  if (pPrevious == pCurrent) {
    Head = pCurrent->next;
    
  } else {
    pPrevious->next = pCurrent->next;
  }
  delete pCurrent;
}

void dataDeleteHead() {
  if (!Head) return;

  cout << "Delete head data from list" << endl;

  ELEMENT *ptr = Head;
  Head = ptr->next;

  delete ptr;
}

void dataDeleteTrail() {
  if (!Head) return;

  cout << "Delete trail data from list" << endl;

  ELEMENT *pCurrent = Head;
  ELEMENT *pPrevious = NULL;

  while (pCurrent && pCurrent->next != NULL) {
    pPrevious = pCurrent;
    pCurrent = pCurrent->next;
  }
  pPrevious->next = NULL;
  delete pCurrent;
}

int main(int argc, char *argv[]) {
  Head = new element;
  Head->data = 1;
  Head->next = NULL;

  dataInsertTrail(2);
  dataInsertTrail(3);
  dataInsertTrail(4);
  dataInsertHead(0);
  dataInsertHead(-1);
  dataList();

  dataDelete(1);
  dataDelete(-1);
  dataDelete(4);
  dataList();
  dataDeleteTrail();
  dataList();
  dataDeleteHead();
  dataList();
}
