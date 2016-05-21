#include <iostream>

using namespace std;

typedef struct polyNode {
  int coefficient;
  int exponent;
  polyNode *next;
} PolyNode;

static PolyNode *pPoly1 = NULL;
static PolyNode *pPoly2 = NULL;
static PolyNode *pPoly3 = NULL;

void addNodeTrail(PolyNode **head, int coefficient, int exponent) {
  if (*head == NULL) {
    PolyNode *node = new PolyNode;
    node->coefficient = coefficient;
    node->exponent = exponent;
    node->next = NULL;
    *head = node;
    cout << "poly = " << pPoly1 << endl;
    return;
  }
 
  PolyNode *node = *head;
  cout << "node = " << node << endl;
  while (node && node->next != NULL) {
    node = node->next;
  }

  PolyNode *ptrNode = new PolyNode;
  ptrNode->coefficient = coefficient;
  ptrNode->exponent = exponent;
  ptrNode->next = NULL;
  node->next = ptrNode;

  return;
}

void listNode(PolyNode **head) {
  PolyNode *node = *head;
  cout << "list node " << node << endl;
  while(node) {
    cout << node->coefficient << "x^" << node->exponent << " "; 
    node = node->next;
  }
  cout << endl;
}

PolyNode* polyAddition(PolyNode *f1, PolyNode *f2) {
  if (!f1 || !f2) {
    cout << __FUNCTION__ << ":" << "Invalid function" << endl;
    return NULL;
  }

  PolyNode *node1 = f1;
  PolyNode *node2 = f2;
  PolyNode **f3 = static_cast<PolyNode **> (&pPoly3);
  
  while (node1 && node2) {
    if (node1->exponent > node2->exponent) {
      addNodeTrail(f3, node1->coefficient, node1->exponent);
      node1 = node1->next;
    } else if (node1->exponent < node2->exponent) {
      addNodeTrail(f3, node2->coefficient, node2->exponent);
      node2 = node2->next;
    } else {
      addNodeTrail(f3, node1->coefficient + node2->coefficient, node1->exponent);
      node1 = node1->next;
      node2 = node2->next;
    }
  }

  if (node1 == NULL) {
    node1 = node2;
  }

  while (node1) {
    addNodeTrail(f3, node1->coefficient, node1->exponent);
    node1 = node1->next;
  }

  listNode(f3);

  return NULL;
} 

PolyNode* polySubtract(PolyNode *f1, PolyNode *f2) {

  return NULL;
} 

int main(int argc, char *argv[]) {
  //3x^2 + 2x - 1;
  PolyNode **f1 = static_cast<PolyNode **> (&pPoly1);
  addNodeTrail(f1, 3, 2);
  addNodeTrail(f1, 2, 1); 
  addNodeTrail(f1, -1, 0); 
  listNode(f1);

  PolyNode **f2 = static_cast<PolyNode **> (&pPoly2);
  //2x^2 + 3x - 1;
  addNodeTrail(f2, 2, 2);
  addNodeTrail(f2, 3, 1); 
  addNodeTrail(f2, -1, 0); 
  listNode(f2);

  PolyNode *polyResult = NULL;
  polyResult = polyAddition(pPoly1, pPoly2);

  return 0;
}
