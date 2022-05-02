#pragma once
#include "TScanTable.h"

class TSortTable : public TScanTable { 
private:
	void QSort() {
		RecQSort(0,DataCount-1);
	}
	void RecQSort(int first,int last) {
		if (first >= last)
			return;
		TKey mid = Arr[(first+last)>>1].key;
		int l, r;
		l = first; r = last;
		while (l <= r) {
			while (Arr[l] < mid) l++,Eff++;
			while (Arr[r] > mid) r--,Eff++;
			if (l <= r) {
				std::swap(Arr[l], Arr[r]);
				Eff++;
				l++;
				r--;
			}
		}
		RecQSort(first,r);
		RecQSort(l,last);
	}
	void SelectionSort() {
		for (int i = 0; i < Size; i++) {
			int e = i;
			for (int j = i + 1; j < Size; j++) {
				Eff++;
				if (Arr[e] > Arr[j])
					e = j;
			}
			std::swap(Arr[i], Arr[e]);
			Eff++;
		}
	}


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

	TSortTable(TScanTable& st): TScanTable(st.GetSize()) {
		int i;
		DataCount = st.GetDataCount();
		for (i = 0,st.Reset(); i < DataCount && !st.IsEnd(); i++, st.GoNext()) {
			Arr[i].key = st.GetKey();
			Arr[i].val = st.GetValue();
		}
		QSort();
	}

};