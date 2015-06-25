// Linked list implementation
// Insert - insert element at end
// Print - print all elements from head to end
// Insert_at_head - insert element as new head
// Insert_at_index - insert new element at given index
// Delete_at_index - deletes node at given index
// ReversePrint - print elements data from tail to head
// Takes input nr of nodes to create followed
// by the data each of them should contain
// Tests each function
#include<iostream>
#include <stdio.h>
#include <string.h>

struct Node
{
  int data;
  struct Node *next;
};

Node* Insert(Node *head,int data)
{
  using namespace std;
  Node *nextNode = new Node;
  if (!head->data)
    {
      nextNode->data = data;
      return nextNode;
    }
  nextNode = head;
  while (nextNode->next)
    {
      nextNode = nextNode->next;
    }
  // create new node
  Node *newNode = new Node;
  newNode->data = data;
  nextNode->next = newNode;
  return head;
}

int Print(Node *head)
{
  using namespace std;
  Node* thisNode = new Node;
  thisNode = head;
  while (thisNode && thisNode->data)
    {
      cout << thisNode->data << endl;
      thisNode = thisNode -> next;
    }
  return 0;
}

Node* Insert_at_head(Node *head, int data)
{
  using namespace std;
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = head;
  return newNode;
}

Node* Insert_at_index(Node *head, int data, int position)
{
  int i = 0;
  Node *followerNode = new Node;
  followerNode = head;
  Node *previousNode = new Node;
  while (i != position )
    {
      previousNode = followerNode;
      followerNode = followerNode->next;
      i++;
    }
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = followerNode;
  previousNode->next = newNode;
  if (i == 0)
    {
      return newNode;
    }
  else
    {
      return head;
    }
}


Node* Delete_at_index(Node *head, int position)
{
  using namespace std;
  if ( position == 0 )
    {
      head = head->next;
      return head;
    }
  int i = 1;
  Node *prevNode = new Node;
  Node *nextNode = new Node;
  prevNode = head;
  nextNode = head->next->next;
  while ( i != position )
    {
      prevNode = prevNode->next;
      nextNode = nextNode->next;
      i++;
    }
  prevNode->next=nextNode;
  return head;
}

void ReversePrint(Node* head)
{
  using namespace std;
  char buffer [100] = {};
  char tmp [100] = {};
  Node* thisNode = new Node;
  thisNode = head;
  while (thisNode && thisNode->data)
    {
      sprintf(buffer, "%d\n%s", thisNode->data, tmp);
      strncpy(tmp, buffer, 100);
      thisNode = thisNode->next;
    }	
  cout << buffer;
  return;
}

int main()
{
  using namespace std;
  int nr_of_data;
  int data;
  Node *head = new Node;
  cin >> nr_of_data;
  while (cin >> data)
    {
      head = Insert(head,data);
    }
  cout << "contents after reading from stdin:" << endl;
  Print(head);
  head = Insert_at_head(head, 99);
  cout << "contents after inserting at head: " << endl;
  Print(head);
  head = Insert_at_index(head, 2301, 2);
  cout << "contents after inserting at index 2: " << endl;
  Print(head);
  head = Delete_at_index(head, 2);
  cout << "contents after deleting at index 2: " << endl;
  Print(head);
  cout << "printing in reverse" << endl;
  ReversePrint(head);
  return 0;
}
