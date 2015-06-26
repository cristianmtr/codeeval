#include <array>
#include <iostream>
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

Node* Reverse(Node* head)
{
  using namespace std;
  Node* thisNode = new Node;
  thisNode = head;
  Node* prevNode = new Node;
  prevNode = head;
  Node* nextNode = new Node;
  nextNode = head->next;
  head->next=0;
  while (nextNode && nextNode != NULL && nextNode !=0 )
    {
      thisNode = nextNode;
      nextNode = thisNode->next;
      thisNode->next=prevNode;
      prevNode = thisNode;
    }
  return prevNode;
}

int main()
{
  using namespace std;
  
  array <int,5> data = {44, 12, 173, -4, 1600 };
  Node *head = new Node;
  for (uint i = 0; i < data.size(); i++)
    {
      head = Insert(head,data[i]);
    }
  cout << "contents after inserting data from array:" << endl;
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
  cout<< "sanity print" << endl;
  Print(head);
  cout << "reversing list..." << endl;
  head = Reverse(head);
  cout << "contents after reversing" << endl;
  Print(head);
  return 0;
}

