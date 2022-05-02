#pragma once
#include "TTable.h"
struct TTreeNode {
	TRecord rec;
	TTreeNode* pLeft,* pRight;
	TTreeNode() {
		pLeft = pRight = nullptr;
	}
};

class TTreeTable : public TTable {
	TTreeNode* pRoot;

};