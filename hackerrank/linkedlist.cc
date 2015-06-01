// Linked list implementation
// Insert
// Print
// Takes input nr of nodes to create followed
// by the data each of them should contain
// Prints the data
#include<iostream>

struct Node
{
  int data;
  struct Node *next;
};

Node* Insert(Node *head,int data)
{
  using namespace std;
  Node *nextNode = new Node;
  if (!head)
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
  if (head && head->data)
    {
      Node *thisNode;
      thisNode = new Node;
      thisNode = head;
      cout << thisNode->data << endl;
      while (thisNode->next)
	{
	  thisNode = thisNode->next;
	  cout << thisNode->data << endl;
	}
      return 0;
    }
  return 0;
}

int main()
{
  using namespace std;
  int nr_of_data;
  int data;
  Node *head;
  cin >> nr_of_data;
  while (cin >> data)
    {
      head = Insert(head,data);
    }
  Print(head);
  return 0;
}
