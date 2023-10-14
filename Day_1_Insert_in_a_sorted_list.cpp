//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{

    //Just handle the insertion at starting node separately
public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node *head, int data)
    {
        Node *start = head, *back;
        bool flag = false;
        while (head != NULL)
        {
            if (head->data >= data)
            {
                if (head == start)
                    flag = true;
                break;
            }
            back = head;
            head = head->next;
        }

        Node *temp = new Node(data);
        // temp->data=data;
        // temp->next=NULL;
        if (flag)//this will handle the inserion at head separately
        {
            temp->next = head;
            start = temp;
        }
        else//this is the generalized case 
        {
            back->next = temp;
            temp->next = head;
        }

        return start;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;

        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        int k;
        cin >> k;
        Solution obj;
        head = obj.sortedInsert(head, k);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends