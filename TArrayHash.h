#pragma once
#include"THashTable.h"

class TArrayHash : public THashTable {
protected:
	TRecord Free, Del;
	TRecord* Arr;
	int Size, Curr, Step;
public:
	TArrayHash(int _size = 100, int _step = 1):THashTable() {
		Size = _size;
		Step = _step;
		Arr = new TRecord[Size];
		Free.key = - 2;
		Del.key = -1 ;
		Curr = -1;
		for(int i=0;i<Size;i++){
			Arr[i] = Free;
		}
	}

	~TArrayHash() {
		delete[] Arr;
	}

	TKey GetKey() const {
		if (Curr < 0 || Curr >= Size)
			throw "Wrong Position";
		return Arr[Curr].key;
	}
	TValue GetValue() const {
		if (Curr < 0 || Curr >= Size)
			throw "Wrong Position";
		return Arr[Curr].val;
	}
	bool IsFull() const {
		return DataCount == Size;
	}

	bool Find(TKey _key) {
		int pos = HashFunc(_key) % Size;
		int fl = 1;
		for (int i = 0; i < Size; i++) {
			Eff++;
			if (Arr[pos].key == _key) {
				Curr = pos;
				return true;
			}
			if (Arr[pos] == Del && fl) {
				Curr = pos;
				fl = 0;
			}
			if (Arr[pos] == Free) {
				if (fl) {
					fl = 0;
					Curr = pos;
				}
				break;
			}
			pos = (pos + Step) % Size;
		}
		return false;
	}

	bool Insert(TRecord rec) {
		if (IsFull()||Find(rec.key))
			return false;
		Arr[Curr] = rec;
		DataCount++;
		return true;
	}

	bool Delete(TKey _key) {
		if (IsEmpty()||!Find(_key))
			return false;
		Arr[Curr] = Del;
		return true;
	}

	void Reset() {
		for (Curr = 0; Curr < Size; Curr++) {
			if (Arr[Curr] != Free && Arr[Curr] != Del)
				return;
		}
	}

	void GoNext() {
		for (Curr++; Curr < Size; Curr++) {
			if (Arr[Curr] != Free && Arr[Curr] != Del)
				return;
		}
	}
	
	bool IsEnd() const  {
		return Curr == Size;
	}

};