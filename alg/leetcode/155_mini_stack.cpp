
typedef struct _node
{
    int value;
    struct _node *next;
} node;

class MinStack {
public:
    void push(int x) {
        node *nd = new node();
        nd->next = head->next;
        head->next = nd;
    }

    void pop() {
        node* nd = head->next;
        head->next = nd->next;
        delete nd;
    }

    int top() {
        return head->value;
    }

    int getMin() {
    }
private:
    int min;
    node *head;
};