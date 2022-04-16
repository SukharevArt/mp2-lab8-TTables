#pragma once
#include "ArrayTable.h"

class TScanTable : public ArrayTable {
public:
	TScanTable(int _sz = 100) : ArrayTable(_sz) {}
	bool Find(TKey _key) {
		for (int i = 0; i < DataCount; i++) {
			Eff++;
			if (_key == Arr[i].key) {
				Curr = i;
				return true;
			}
		}
		Curr = DataCount;
		return false;
	}

	bool Insert(TRecord rec) {
		if (IsFull() || Find(rec.key)) {
			return false;
		}
		Arr[DataCount] = rec;
		DataCount++;
		Eff++;
		return true;
	}

	bool Delete(TKey _key) {
		if (IsEmpty() || !Find(_key)) {
			return false;
		}
		Eff++;
		DataCount++;
		Arr[Curr] = Arr[DataCount];
		return true;
	}

};
