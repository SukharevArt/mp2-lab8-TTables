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
	int CurrNum;
	TListNode* CurrPtr;
	int Size;

public:
	TListHash(int _size=100):Size(_size) {
		Arr = new TListNode*[Size];
		for (int i = 0; i < Size; i++)
			Arr[i] = nullptr;
		CurrNum = 0;
		CurrPtr = nullptr;
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
	bool IsFull() const {
		return false;
	}

	TKey GetKey() const {
		if (CurrPtr == nullptr) {
			throw "WP";
		}
		return CurrPtr->val.key;
	}
	TValue GetValue() const {
		if (CurrPtr == nullptr) {
			throw "WP";
		}
		return CurrPtr->val.val;
	}

	bool IsEnd() const{
		return CurrNum == Size;
	}
	void Reset() {
		for (CurrNum = 0; Arr[CurrNum] == nullptr && CurrNum < Size; CurrNum++) {
		}
		CurrPtr = Arr[CurrNum];
	}
	void GoNext() {
		if (CurrPtr->pNext != nullptr) {
			CurrPtr = CurrPtr->pNext;
		}
		else {
			CurrPtr = nullptr;
			for (CurrNum ++; Arr[CurrNum] == nullptr && CurrNum < Size; CurrNum++) {
			}
			CurrPtr = Arr[CurrNum];
		}
	}

	bool Find(TKey _key) {
		int pos = HashFunc(_key)%Size;
		TListNode* tmp = Arr[pos];
		while (tmp != nullptr) {
			Eff++;
			if (tmp->val.key == _key) {
				return true;
			}
			tmp = tmp->pNext;
		}
		return false;
	}
		
	bool Insert(TRecord rec) {
		if (IsFull() && !Find(rec.key))
			return false;
		DataCount++;
		Eff++;
		int pos = HashFunc(rec.key)%Size;
		if (Arr[pos] == nullptr) {
			Arr[pos] = new TListNode;
			Arr[pos] ->val = rec;
			Arr[pos]->pNext = nullptr;
			return true;
		}
		TListNode* tmp = Arr[pos];
		while (tmp->pNext != nullptr)
			tmp = tmp->pNext,Eff++;
		tmp->pNext = new TListNode;
		tmp = tmp->pNext;
		tmp->val = rec;
		tmp->pNext = nullptr;
		return true;
	}
		
	bool Delete(TKey _key) {
		if (IsEmpty() && Find(_key))
			return false;
		int pos = HashFunc(_key)%Size;
		if (Arr[pos]->val.key == _key) {
			TListNode* tmp = Arr[pos]->pNext;
			delete Arr[pos];
			Arr[pos] = tmp;
			return true;
		}
		TListNode* tmp = Arr[pos];
		while (tmp->pNext->val.key != _key)
			tmp = tmp->pNext;
		TListNode* del = tmp->pNext;
		tmp->pNext = del->pNext;
		delete del;
		return true;
	}

};
