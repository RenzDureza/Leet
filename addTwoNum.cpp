#include <iostream>
using namespace std;

struct ListNode {
  int data;
  ListNode *next;
};

class Solution {
public:
  ListNode *head;

  Solution() { head = nullptr; }

  void insertNode(int val);
};

void Solution::insertNode(int val) {
  ListNode *newNode = new ListNode();
  newNode->next = nullptr;
  newNode->data = val;

  if (head == nullptr) {
    head = newNode;
  } else {
    ListNode *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

int listToInt(Solution list) {
  int num = 0;
  int multiplier = 1;
  ListNode *temp = list.head;
  while (temp != nullptr) {
    num += temp->data * multiplier;
    multiplier *= 10;
    temp = temp->next;
  }

  return num;
}

Solution intToList(int val) {
  Solution list;

  if (val == 0) {
    list.insertNode(0);
    return list;
  }

  while (val > 0) {
    int digit = val % 10;
    list.insertNode(digit);
    val /= 10;
  }

  return list;
}

int main() {
  Solution list1;
  list1.insertNode(2);
  list1.insertNode(4);
  list1.insertNode(3);

  Solution list2;
  list2.insertNode(5);
  list2.insertNode(6);
  list2.insertNode(4);

  intToList(listToInt(list1) + listToInt(list2));
}
