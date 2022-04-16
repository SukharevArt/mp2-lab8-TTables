#pragma once
#include"TTable.h"

class ArrayTable : public TTable {
protected:
	TRecord* Arr;
	int Size;
	int Curr;
public:
	ArrayTable(int _size = 100) : Size(_size), Curr(-1) {
		Arr = new TRecord[_size];
	}
	bool IsFull() const {
		return Size == DataCount;
	}
	TKey GetKey() const {
		if (Curr >= DataCount)
			throw "WI";
		return Arr[Curr].key;
	}
	TValue GetValue() const {
		if (Curr >= DataCount)
			throw "WI";
		return Arr[Curr].val;
	}

	void Reset() {
		Curr = 0;
	}
	void GoNext() {
		Curr++;
	}
	bool IsEnd() const {
		return DataCount == Curr ;
	}

};