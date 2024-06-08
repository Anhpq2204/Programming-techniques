#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
    Node* q = new Node(data);
    q->next=head;
    head=q;
    return head;
}

// print the list content on a line
void print(Node* head) {
    /*****************
    Pham Quang Anh 20224924
    *****************/
    Node *p =head;
    while (p!= NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;

}

// return the new head of the reversed list
Node* reverse(Node* head) {
    /*****************
    Pham Quang Anh  20224924
    *****************/
    Node* q=head->next;
    head->next=NULL;
    Node* temp = new Node(3);
    while(q!=NULL)
    {   temp=q->next;
        q->next=head;
        head=q;
        q=temp;
    }
    return head;
}


int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}
