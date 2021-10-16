#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val = 0;
	Node* next = nullptr;
	Node (int a) : val(a) {}
};

int main () 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	Node* head = new Node(5);
	Node* cur = head;
	for (int i = 1; i < 5; i++) {
		Node* node = new Node(i);
		cur->next = node;
		cur = cur->next;
	}
	
	cur = head;
	while (cur != nullptr) {
		cout << cur->val << "\t";
		cur = cur->next;
	}
	
	return 0;
}

// Lorenzo Fiorini
