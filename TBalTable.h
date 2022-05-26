#pragma once
#include "TTreeTable.h"

constexpr int H_Ok = 0;
constexpr int H_Inc = 1;
constexpr int H_Dec = -1;

class TBalTable : public TTreeTable {
public:
	TBalTable() : TTreeTable() {};
	~TBalTable() {}
	int LeftBalance(TTreeNode*& p);
	int RightBalance(TTreeNode*& p);
	int InsBalance(TTreeNode*& p, TRecord rec);
	bool Insert(TRecord rec) {
		if (IsFull()||Find(rec.key))
			return false;
		InsBalance(pRoot, rec);
		return true;
	}
};

int TBalTable::InsBalance(TTreeNode*& p, TRecord rec) {
	int Result = H_Ok;
	Eff++;
	int tmp;
	if (p == nullptr) {
		p = new TTreeNode(rec);
		DataCount++;
		Result = H_Inc;
	}
	else if (rec < p->rec) {
		tmp = InsBalance(p->pLeft,rec);
		if (tmp == H_Inc) {
			Result = LeftBalance(p);
		}
	}
	else if (rec > p->rec) {
		tmp = InsBalance(p->pRight,rec);
		if (tmp == H_Inc) {
			Result = RightBalance(p);
		}
	}
	return Result;
}

int TBalTable::LeftBalance(TTreeNode *&p) {
	int Result = H_Ok;
	if (p->bal == H_Inc) {
		p->bal = H_Ok;
	}
	else if (p->bal == H_Ok) {
		p->bal = H_Dec;
		Result = H_Inc;
	}
	else {
		TTreeNode* pl, *pr;
		pl = p->pLeft;
		pr = pl->pRight;
		if (pl->bal == H_Dec) {
			//type1
			p->pLeft = pl->pRight;
			pl->pRight = p;
			pl->bal = p->bal = 0;
			Result = H_Ok;
			p = pl;
		}
		else {
			//type3
			pl->pRight = pr->pLeft;
			p->pLeft = pr->pRight;
			pr->pLeft = pl;
			pr->pRight = pr;
			Result = H_Ok;
			if (pr->bal==H_Inc) {
				pl->bal = H_Inc;
				p->bal = H_Ok;
			}
			else {
				pl->bal = H_Ok;
				p->bal = H_Dec;
			}
			pr->bal = 0;
			p = pr;
		}
	}
	return Result;
}

int TBalTable::RightBalance(TTreeNode *&p) {
	int Result = H_Ok;
	if (p->bal == H_Dec) {
		p->bal = H_Ok;
	}
	else if (p->bal == H_Ok) {
		p->bal = H_Inc;
		Result = H_Inc;
	}
	else {
		TTreeNode* pl, *pr;
		pr = p->pRight;
		pl = pr->pLeft;
		if (pr->bal == H_Inc) {
			//type2
			p->pRight = pr->pLeft;
			pr->pLeft = p;
			pl->bal = p->bal = 0;
			Result = H_Ok;
			p = pr;
		}
		else {
			//type4
			p->pRight = pl->pLeft;
			pr->pLeft = pl->pRight;
			pl->pLeft = p;
			pl->pRight = pr;
			Result = H_Ok;
			if (pl->bal==H_Inc) {
				pr->bal = H_Ok;
				p->bal = H_Dec;
			}
			else {
				pr->bal = H_Inc;
				p->bal = H_Ok;
			}
			pl->bal = 0;
			p = pl;
		}
	}
	return Result;
}
