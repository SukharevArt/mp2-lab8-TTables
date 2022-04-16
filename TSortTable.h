#pragma once
#include "TScanTable.h"

class TSortTable : public TScanTable {
public:
	TSortTable(int _sz = 100) :TScanTable(_sz) {}

	bool Find(TKey _key) {
		int l, r, mid;
		l = 0; r = DataCount - 1;
		while (l <= r) {
			mid = (l + r) >> 1;
			Eff++;
			if (Arr[mid].key < _key)
				l = mid + 1;
			if (Arr[mid].key > _key)
				r = mid - 1;
			if (Arr[mid].key == _key) {
				Curr = mid;
				return true;
			}
		}
		Curr = l;
		return false;
	}
	
	bool Insert(TRecord rec) {
		if (IsFull() || Find(rec.key)) {
			return false;
		}
		for (int i = DataCount - 1; i >= Curr; i--) {
			Arr[i + 1] = Arr[i];
			Eff++;
		}
		Eff++;
		Arr[Curr] = rec;
		DataCount++;
		return true;
	}

	bool Delete(TKey _key) {
		if (IsEmpty() || !Find(_key)) {
			return false;
		}
		for (int i = Curr; i < DataCount - 1; i++) {
			Arr[i] = Arr[i + 1];
			Eff++;
		}
		DataCount--;
		return true;
	}
};