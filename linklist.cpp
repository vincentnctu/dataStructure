#include <iostream>

using namespace std;

typedef struct element {
  int data;
  struct element *next;
} ELEMENT;

static ELEMENT *Head1 = NULL;
static ELEMENT *Head2 = NULL;

void dataInsertTail(ELEMENT **head, int data) {
  ELEMENT *pElement;
  pElement = new element;
  pElement->data = data;
  pElement->next = *head;
  
  if (!*head) {
    *head = pElement;
    pElement->next = *head;
    return;
  }

  ELEMENT *ptr = *head;
  while (ptr && ptr->next != *head) {
    ptr = ptr->next;
  }
  ptr->next = pElement;
}

void dataInsertHead(ELEMENT **head, int data) {
  ELEMENT *pElement;
  pElement = new element;
  pElement->data = data;
  pElement->next = *head;
  
  if (!*head) {
    *head = pElement;
    pElement->next = *head;
    return;
  }

  ELEMENT *ptr = *head;
  while (ptr && ptr->next != *head) {
    ptr = ptr->next;
  }   
  *head = pElement;
  ptr->next = *head;
}

void dataList(ELEMENT *head) {
  ELEMENT *ptr; 
  
  if (!head) {
    cout << "Invalid data list" << endl;
    return;
  }  

  ptr = head;
  do {
    cout << "\'" << ptr->data << "\'" << " ";
    ptr = ptr->next;
  } while (ptr != head);
  cout << endl;
}

void dataReverseList(ELEMENT **head) {
  ELEMENT *current;
  ELEMENT *previous;
  ELEMENT *ptr;

  current = previous = *head;
  current = current->next;
  previous->next = NULL;
  while (current) {
    ptr = current;
    current = current->next;
    ptr->next = previous;
    previous = ptr;
  }
  *head = previous;
}

void dataClear(ELEMENT **head) {
  ELEMENT *ptr; 
  ptr = *head;
  
  ELEMENT *cur;
  while (ptr && ptr->next != *head) {
    cur = ptr;
    ptr = ptr->next;
    delete cur;
  }
  *head = NULL;
}

void dataDelete(ELEMENT **head, int data) {
  if (!head || !*head) return;
  
  cout << "Delete " << data << " from list" << endl;
  ELEMENT *pCurrent = *head;
  ELEMENT *pPrevious = *head;

  while (pCurrent && pCurrent->next != *head) {
    if (pCurrent->data == data) {
      break;
    }
    pPrevious = pCurrent;
    pCurrent = pCurrent->next;
  }
  if (pPrevious == pCurrent) {
    *head = pCurrent->next;
    
  } else {
    pPrevious->next = pCurrent->next;
  }
  delete pCurrent;
}

void dataDeleteHead(ELEMENT **head) {
  if (!head) return;

  cout << "Delete head data from list" << endl;

  ELEMENT *ptr = *head;
  *head = ptr->next;

  delete ptr;
}

void dataDeleteTail(ELEMENT *head) {
  if (!head) return;

  cout << "Delete trail data from list" << endl;

  ELEMENT *pCurrent = head;
  ELEMENT *pPrevious = NULL;

  while (pCurrent && pCurrent->next != head) {
    pPrevious = pCurrent;
    pCurrent = pCurrent->next;
  }
  pPrevious->next = NULL;
  delete pCurrent;
}

void dataListConcatenate(ELEMENT *head1, ELEMENT *head2) {
  ELEMENT *ptr1 = head1;

  while (ptr1 && ptr1->next != head1) {
    ptr1 = ptr1->next;
  }

  ptr1->next = head2;


  ELEMENT *ptr2 = head2;
  while (ptr2 && ptr2->next != head2) {
    ptr2 = ptr2->next;
  }

  ptr2->next = head1;
}

int main(int argc, char *argv[]) {
  ELEMENT **head1 = static_cast<ELEMENT **>(&Head1);
  ELEMENT **head2 = static_cast<ELEMENT **>(&Head2);

  dataInsertTail(head1, 99);
  dataInsertTail(head1, 100);
  dataInsertTail(head1, 4);
  dataList(*head1);
  dataInsertHead(head1, 0);
  dataList(*head1);
  dataInsertHead(head1, -1);
  dataList(*head1);

  dataInsertTail(head2, 9);
  dataInsertTail(head2, 8);
  dataInsertTail(head2, 7);
  dataInsertHead(head2, 6);
  dataInsertHead(head2, 5);

  dataList(*head1);
  dataList(*head2);
  dataListConcatenate(*head1, *head2); 
  dataList(*head1);

  //dataReverseList(head1);
  //dataList(*head1);
  //dataDelete(head1, -1);
  //dataDelete(head1, 4);
  //dataList(*head1);

  //dataDeleteTail(*head1);
  //dataList(*head1);

  //dataDeleteHead(head1);
  //dataList(*head1);

  //dataClear(head1);
  //dataList(*head1);
}
