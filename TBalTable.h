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
	int LeftBalanceDel(TTreeNode*& p);

	int RightBalance(TTreeNode*& p);
	int RightBalanceDel(TTreeNode*& p);
	
	int InsBalance(TTreeNode*& p, TRecord rec);
	int DelBalance(TTreeNode*& p, TKey key);
	bool Delete(TKey key) {
		if (!Find(key)) {
			return false;
		}
		DelBalance(pRoot, key);
		return true;

	}
	bool Insert(TRecord rec) {
		if (IsFull()||Find(rec.key))
			return false;
		InsBalance(pRoot, rec);
		return true;
	}
};

int TBalTable::DelBalance(TTreeNode*& p, TKey key) {
	int Result = H_Ok;
	int tmp;
	Eff++;
	if (p == nullptr)
		throw "Something";
	if (p->rec.key > key) {
		tmp = DelBalance(p->pLeft, key);
		if (tmp == H_Dec) {
			Result = RightBalanceDel(p);
		}
	}
	else if (p->rec.key < key) {
		tmp = DelBalance(p->pRight, key);
		if (tmp == H_Dec) {
			Result = LeftBalanceDel(p);
		}
	}
	else {
		if (p->pLeft == nullptr && p->pRight == nullptr) {
			p->pRight = nullptr;
			delete p;
			DataCount--;
			p = nullptr;
			Result = H_Dec;
		}
		else if (p->pRight==nullptr) {
			p->rec = p->pLeft->rec;
			delete p->pLeft;
			DataCount--;
			p->pLeft = nullptr;
			Result = H_Dec;
			p->bal = H_Ok;
		}
		else if (p->pLeft == nullptr) {
			p->rec = p->pRight->rec;
			delete p->pRight;
			DataCount--;
			p->pRight = nullptr;
			Result = H_Dec;
			p->bal = H_Ok;
		}
		else {
			TTreeNode* Maxx=p->pLeft;
			while (Maxx->pRight != nullptr)
				Maxx = Maxx->pRight,Eff++;
			p->rec = Maxx->rec;
			tmp = DelBalance(p->pLeft, Maxx->rec.key);
			if (tmp == H_Dec) {
				Result = RightBalanceDel(p);
			}
		}
	}
	return Result;
}

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

int TBalTable::LeftBalanceDel(TTreeNode *&p) {
	int Result = H_Ok;
	if (p->bal == H_Inc) {
		p->bal = H_Ok;
		Result = H_Dec;
	}
	else if (p->bal == H_Ok) {
		p->bal = H_Dec;
	}
	else {
		TTreeNode* pl, *pr;
		pl = p->pLeft;
		pr = pl->pRight;

		if (pl->bal == H_Ok) {
			//type1
			p->pLeft = pl->pRight;
			pl->pRight = p;
			pl->bal = H_Inc;
			p->bal = H_Dec;
			Result = H_Ok;
			p = pl;
		}
		else if (pl->bal == H_Dec) {
			//type2
			p->pLeft = pl->pRight;
			pl->pRight = p;
			pl->bal = p->bal = 0;
			Result = H_Dec;
			p = pl;
		}
		else {
			//type3
			p->pLeft = pr->pRight;
			pl->pRight = pr->pLeft;
			pr->pLeft = pl;
			pr->pRight = p;
			Result = H_Dec;
			if (pr->bal == H_Inc) {
				pl->bal = H_Dec;
				p->bal = H_Ok;
			}
			else {
				if (pr->bal == H_Ok) {
					pl->bal = p->bal = H_Ok;
				}
				else {
					pl->bal = H_Ok;
					p->bal = H_Inc;
				}
			}
			pr->bal = H_Ok;
			p = pr;
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
			p->pLeft = pr->pRight;
			pl->pRight = pr->pLeft;
			pr->pLeft = pl;
			pr->pRight = p;
			Result = H_Ok;
			if (pr->bal==H_Inc) {
				pl->bal = H_Dec;
				p->bal = H_Ok;
			}
			else {
				if (pr->bal == H_Ok) {
					pl->bal = p->bal = H_Ok;
				}
				else {
					pl->bal = H_Ok;
					p->bal = H_Inc;
				}
			}
			pr->bal = H_Ok;
			p = pr;
		}
	}
	return Result;
}

int TBalTable::RightBalanceDel(TTreeNode *&p) {
	int Result = H_Ok;
	if (p->bal == H_Dec) {
		p->bal = H_Ok;
		Result = H_Dec;
	}
	else if (p->bal == H_Ok) {
		p->bal = H_Inc;
	}
	else {
		TTreeNode* pl, *pr;
		pr = p->pRight;
		pl = pr->pLeft;
		if (pr->bal == H_Ok) {
			//type1
			p->pRight = pr->pLeft;
			pr->pLeft = p;
			pr->bal = H_Dec;
			p->bal = H_Inc;
			Result = H_Ok;
			p = pr;
		}
		else if (pr->bal == H_Inc) {
			//type2
			p->pRight = pr->pLeft;
			pr->pLeft = p;
			pr->bal = p->bal = H_Ok;
			Result = H_Dec;
			p = pr;
		}
		else {
			//type3

			pr->pLeft = pl->pRight;
			p->pRight = pl->pLeft;
			pl->pLeft = p;
			pl->pRight = pr;
			Result = H_Dec;
			if (pl->bal == H_Inc) {
				pr->bal = H_Ok;
				p->bal = H_Dec;
			}
			else {
				if (pl->bal == H_Ok) {
					pr->bal = p->bal = H_Ok;
				}
				else {
					pr->bal = H_Inc;
					p->bal = H_Ok;
				}
			}
			pl->bal = H_Ok;
			p = pl;

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
			pr->bal = p->bal = H_Ok;
			Result = H_Ok;
			p = pr;
		}
		else {
			//type4

			pr->pLeft = pl->pRight;
			p->pRight = pl->pLeft;
			pl->pLeft = p;
			pl->pRight = pr;
			Result = H_Ok;
			if (pl->bal == H_Inc) {
				pr->bal = H_Ok;
				p->bal = H_Dec;
			}
			else {
				if (pl->bal == H_Ok) {
					pr->bal = p->bal = H_Ok;
				}
				else{
					pr->bal = H_Inc;
					p->bal = H_Ok;
				}
			}
			pl->bal = H_Ok;
			p = pl;
			
		}
	}
	return Result;
}
