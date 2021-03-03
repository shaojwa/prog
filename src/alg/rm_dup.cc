
#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode {
  ListNode(): val(0), next(nullptr) {}
  int val;
  ListNode *next;
};


void construct_list(ListNode **head, int len) {
  if (!len)  {
    *head = nullptr;
    return;
  }
  ListNode *cur = nullptr;
  cur = new ListNode();
  if (!cur) {
    *head = nullptr;
    return;
  }
  *head = cur;
  int i = 0;
  srand((unsigned int)time(nullptr));
  cur->val = rand() % 10;
  while (++i < len ) {
    ListNode *pnode = new ListNode();
    pnode->val = cur->val + rand() % 2;
    cur->next = pnode;
    cur = pnode;
  }
  cur->next = nullptr;
}


void construct_list2(ListNode **head) {
  ListNode *cur = nullptr;
  ListNode *last = nullptr;
  *head = nullptr;
  int val = 0;
  while (cin >> val) {
    if (val == 0) {
      return;
    }
    cur = new ListNode();
    if (!cur) {
      *head = nullptr;
      return;
    }
    cur->val = val;
    if (!*head) {
      *head = cur;
      last = cur;
      continue;
    }
    last->next = cur;
    last = last->next;
  }
  last->next = nullptr;
}

void print_list(ListNode *head) {
  ListNode *cur = head;
  cout << "list: [";
  while(cur) {
    cout << " " << cur->val;
    cur = cur->next;
  }
  cout << " ]" << endl;
}


ListNode *rm_dup(ListNode *head) {
  ListNode *cur = head;
  if (!cur || !cur->next) {
    return cur;
  }
  ListNode *new_head = nullptr;
  ListNode *prev = nullptr;
  ListNode *last_keep = nullptr;
  while (cur) {
    if (!cur->next) {
      if (!prev || prev->val != cur->val) {
        if (!new_head) {
          new_head = cur;
          last_keep = cur;
        } else {
          last_keep->next = cur;
        }
        return new_head;
      }
      if (last_keep) {
        last_keep->next = nullptr;
      }
      return new_head;
    }

    if (cur->val != cur->next->val) {
      if (prev && prev->val == cur->val) {
        prev = cur;
        cur = cur->next;
        continue;
      }
      // !prev || prev != cur
      if (!new_head) {
        new_head = cur;
        last_keep = cur;
      } else {
        last_keep->next = cur;
        last_keep = last_keep->next;
      }
    }
    prev = cur;
    cur = cur->next;
  }
  return new_head;
}


ListNode *rm_dup2(ListNode *head) {
  if (!head) {
    return head;
  }
  ListNode *cur = head;
  ListNode *last = nullptr;
  ListNode *new_head = nullptr;
  int count = 0;
  while (cur) {
    if (!cur->next) {
      if (!count) {
        if (!last) {
          last = cur;
          new_head = cur;
        } else {
          last->next = cur;
        }
      } else {
        if (last) {
          last->next = nullptr;
        }
      }
      return new_head;
    }
    if (cur->val != cur->next->val) {
      if (count) {
        cur = cur->next;
        count = 0;
        continue;
      }
      // count == 0
      if (!last) {
        new_head = cur;
      } else {
        last->next = cur;
      }
      last = cur;
      cur = cur->next;
      count = 0;
      continue;
    }
    // cur == next
    cur = cur->next;
    count++;
  }
  return new_head;
}


int main() {
  ListNode *head;
  // construct_list(&head, 10);
  construct_list2(&head);
  print_list(head);
  head = rm_dup(head);
  print_list(head);
  return 0;
}

