#pragma once
#include "TTable.h"
class THashTable : public TTable {
protected:
	int HashFunc(TKey _key) {
		return _key;
	}
	THashTable() :TTable() {}
};
