#pragma once
#include "THashTable.h"

struct TListNode {
	TListNode* pNext;
	TRecord val;

	TListNode() {
		pNext = nullptr;
	}
};

class TListHash : public THashTable {
protected:
	TListNode** Arr;
	int Curr;
	int Size;

public:
	TListHash(int _size=100):Size(_size) {
		Arr = new TListNode*[Size];
		Curr = 0;
	};

	~TListHash() {
		TListNode* tmp;
		for (int i = 0; i < Size; i++) {
			while (Arr[i] != nullptr) {
				tmp = Arr[i]->pNext;
				delete Arr[i];
				Arr[i] = tmp;
			}
		}
	}



};
