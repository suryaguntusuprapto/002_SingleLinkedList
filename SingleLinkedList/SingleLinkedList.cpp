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

	if (current == NULL) {
		return false;
	}
	else if (current->noMhs == nim) {
		return true;
	}
	else {
		return false;
	}
}

bool deletenode(int nim) {
	node* current = start;
	node* previous = start;
	if (searchNode(nim, previous, current) == false)
		return false;
	previous->next = current->next;
	if (current == start)
		start = current->next;
	return true;
}

bool listempty() {
	if (start == NULL)
		return true;
	else
		return false;
}

void traverse() {
	if (listempty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		node* currentNode = start;
		while (currentNode != NULL) {
			cout << " NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void searchdata() {
	if (listempty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		cout << "Masukkan NIM: ";
		cin >> nim;
		node* currentNode = start;
		while (currentNode->noMhs == nim) {
			if (currentNode->noMhs == nim) {
				cout << "NIM: " << currentNode->noMhs << ", NAMA: " << currentNode->name << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "Data Tidak Ditemukan" << endl;
	}
}