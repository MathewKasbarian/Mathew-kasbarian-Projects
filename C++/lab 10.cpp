#include<string>
#include<iostream>

using namespace std;
struct Node
{
   string data;
   Node *next;
};
class Queue
{
public:
   Queue();
   ~Queue();
   bool isEmpty();
   void Enqueue(string);
   void PriorityEnqueue(string);
   string Dequeue();
   string toString();
private:
   Node * front;
   Node *back;
};
Queue::Queue()
{
   front = back = nullptr;
}
Queue::~Queue()
{
   Node * temp = front;
   while (front != nullptr)
   {
       front = front->next;
       delete temp;
       temp = front;
   }
   back = nullptr;
}
bool Queue::isEmpty()
{
   return front == nullptr;
}
void Queue::Enqueue(string element)
{
   Node *newNode = new Node();
   newNode->data = element;
   newNode->next = nullptr;
   if (front == nullptr)
   {
       front = back = newNode;
   }
   else
   {
       back->next = newNode;
       back = newNode;
   }
}
void Queue::PriorityEnqueue(string element)
{
   Node *newNode = new Node();
   newNode->data = element;
   newNode->next = nullptr;
   if (isEmpty())
   {
       front = back = newNode;
   }
   else
   {
       newNode->next = front;
       front = newNode;
   }
}
string Queue::Dequeue()
{
   if (isEmpty())
       return "";
   string element = front->data;
   if (front == back)
       front = back = nullptr;
   else
       front = front->next;
   return element;
}
string Queue::toString()
{
   if (isEmpty())
       return "Queue is empty";
  
   string str = "["+front->data+"]";
   Node *cur = front->next;
   while (cur != nullptr)
   {
       str += "-> [" + cur->data + "]";
       cur = cur->next;
   }
   return str;
}
int main()
{
   Queue *q = new Queue();
   q->Enqueue("Solo");
   q->Enqueue("R2D2");
   q->Enqueue("Yoda");
   q->PriorityEnqueue("BB8");
   cout << q->toString() << endl;

   q->Dequeue();

   cout << q->toString() << endl;

   delete q;

   system("pause");

   return 1;
}
