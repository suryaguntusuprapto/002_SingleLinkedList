#include <iostream>
using namespace std;

struct node {
	int noMhs;
	string name;
	node* next;
};

node* start = NULL;

void addNode() {
	int nim;
	string nama;
	node* nodeBaru = new node();
	cout << "Masukkan NIM: ";
	cin >> nim;
	cout << "Masukkan Nama: ";
	cin >> nama;
	nodeBaru->noMhs = nim;
	nodeBaru->name = nama;

	if (start == NULL || nim <= start->noMhs) {
		if (start != NULL && nim == start->noMhs) {
			cout << "NIM sudah ada" << endl;
			return;
		}
		nodeBaru->next = start;
		start = nodeBaru;
	}
	node* previous = start;
	node* current = start;

	while ((current != NULL) && (nim >= current->noMhs)) {
		if (nim == current->noMhs) {
			cout << "NIM Sudah Ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}
	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool searchNode(int nim, node* current, node* previous) {
	previous = start;
	current = start;
	while (current != NULL && nim > current->noMhs) {
		previous = current;
		current = current->next;
	}
}