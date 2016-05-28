#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAXNUM 4

string name[10] = {"a", "b", "c", "d" };

typedef struct list {
  string name;
  struct list *next;
} LIST;

void visit(LIST **head) {
  if (!head || !(*head)) {
    cout << "Invalid list" << endl;
    return;
  }

  LIST *ptr = *head;
  
  do {
    cout << "Soldier:" << ptr->name << endl; 
    ptr = ptr->next;
  } while (ptr && ptr != *head);
}

LIST* insert(LIST **head, string name) {
  if (*head == NULL) {
    LIST *ptr = new LIST;
    ptr->name = name;
    *head = ptr; 
    ptr->next = *head;
    return *head;
  }

  LIST *pCurrent = *head;
  while (pCurrent && pCurrent->next != *head) {
    pCurrent = pCurrent->next;
  }
  
  LIST *pSoldier = new LIST;
  pSoldier->name = name;
  pSoldier->next = *head;
  
  pCurrent->next = pSoldier;
  return pSoldier;
}

static LIST *Head = NULL;
int main(int argc, char *argv[]) {
  
  LIST **h = static_cast<LIST **> (&Head);
  vector<LIST *> ins;
  LIST *pIns;

  for (int i = 0; i < MAXNUM; i++) {
    pIns = insert(h, name[i]);
    ins.push_back(pIns);
    cout << "dump: " << name[i] << "address: " << pIns << endl;
    visit(static_cast<LIST **>(&pIns));
  }

  srand(time(NULL));
  int total = MAXNUM;
 
  LIST *ptr = Head;
  visit(h);
  while (total > 1) {
    int ran = rand()%total + 1;
    cout << "random number: " << ran << endl;

    LIST *previous = NULL;
  
    do {
      previous = ptr;
      ran--;
      ptr = ptr->next;    
    } while (ran > 0);
    cout << "Should remove " << ptr->name << endl;
    //remove ptr
    previous->next = ptr->next;
    delete ptr;
    ptr = previous->next;
    Head = ptr;
    visit(static_cast<LIST **>(&Head));
    total--;
  }

  cout << "Last soldier: " << ptr->name << endl;
  visit(static_cast<LIST **>(&Head));
  return 0;
}
