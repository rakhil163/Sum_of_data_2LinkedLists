#include <iostream>
using namespace std;

typedef struct node {
    int data;
    node *next;
} *nodePtr;



void push(nodePtr &head, int data)
{
    nodePtr newnode=new node;

    /* link the old list off the new node */
    newnode->data=data;
    newnode->next = head;

    /* move the head to point to the new node */
   head = newnode;
}

nodePtr Sum(nodePtr n1,nodePtr n2) {
    nodePtr temp=new node;
    nodePtr curr = NULL;
    if (n1 == NULL) {
        return n2;
    }
    if (n2 == NULL) {
        return n1;
    }
    nodePtr final = NULL;
    int carry = 0;
    int sum = 0;
    while (n1 != NULL || n2 != NULL) {

        if (n1 != NULL && n2 != NULL)
            sum = n1->data + n2->data + carry;
        else if (n1 == NULL) {
            sum = n2->data + carry;
        } else if (n2 == NULL) {
            sum = n1->data + carry;
        }
        if (sum >= 10) {
            carry = 1;

        } else {
            carry = 0;
        }
        sum = sum % 10;



       temp->data=sum;
        if (final == NULL) {
            final = temp;
        } else {
            curr->next = temp;
        }
        curr = temp;
        if (n1 != NULL)
            n1 = n1->next;
        if (n2 != NULL)
            n2 = n2->next;

    }
    if (carry > 0) {
        nodePtr extra = new node;
        extra->data=carry;
        curr->next->next=extra;
    }
    return final;
}


    void printList(nodePtr head)
    {
        while(head != NULL)
        {
            cout<<head->data<<"\t";
            head = head->next;
        }
cout<<endl;


    }


int main() {
   nodePtr n1=NULL;
   nodePtr n2=NULL;
   push(n1,9);
    push(n1,9);
    push(n2,9);
    push(n2,9);
  nodePtr x=Sum(n1,n2);
    printList(n1);
    printList(n2);
    printList(x);

}