#pragma once
#include "TTable.h"
#include<iostream>

struct TTreeNode {
	TRecord rec;
	TTreeNode* pLeft,* pRight;
	int bal;
	TTreeNode() {
		pLeft = pRight = nullptr;
		bal = 0;
	}
	TTreeNode(const TRecord& _rec) {
		pLeft = pRight = nullptr;
		bal = 0;
		rec = _rec;
	}
};

struct TStackNode {
	TTreeNode* val;
	TStackNode* pNext;
	TStackNode() {
		val = nullptr;
		pNext = nullptr;
	}
};

class TTreeStack {
	TStackNode* pFirst;

public:
	TTreeStack() {
		pFirst = nullptr;
	}
	void Clear() {
		TStackNode* del;
		while (pFirst != nullptr) {
			del = pFirst;
			pFirst = pFirst->pNext;
		}
	}
	TTreeNode* Top() {
		if (pFirst == nullptr)
			throw "ES";
		return pFirst->val;
	}
	void Pop() {
		if (pFirst == nullptr)
			throw "ES";
		TStackNode* del;
		del = pFirst;
		pFirst = pFirst->pNext;
		delete del;
	}
	void Push(TTreeNode * a) {
		TStackNode* tmp = new TStackNode;
		tmp->val = a;
		tmp->pNext = pFirst;
		pFirst = tmp;
	}

	bool Empty() const {
		return pFirst == nullptr;
	}
	bool Full() const {
		TStackNode* tmp = new TStackNode;
		if (tmp == nullptr)
			return false;
		delete tmp;
		return true;
	}
};

class TTreeTable : public TTable {
protected:	
	TTreeNode* pRoot;
	TTreeNode* pCurr,* pPrev;
	TTreeStack st;


	void DelRec(TTreeNode* p) {
		if (p == nullptr)
			return;
		DelRec(p->pLeft);
		DelRec(p->pRight);
		delete p;
	}
	void PrintRec(std::ostream& fout, TTreeNode* tmp, int level) {
		if (tmp == nullptr)
			return;
		fout << std::string(level*2,' ') << tmp->rec.key << "\n";
		PrintRec(fout, tmp->pLeft, level + 1);
		PrintRec(fout, tmp->pRight, level + 1);
	}

public:
	TTreeTable():TTable() {
		pRoot = pCurr = pPrev = nullptr;
	}
	bool IsFull() const {
		TTreeNode* tmp = new TTreeNode;
		if (tmp == nullptr)
			return true;
		delete tmp;
		return false;
	}

	bool Find(TKey _key) {
		pPrev = nullptr;
		pCurr = pRoot;
		while (pCurr != nullptr) {
			Eff++;
			if (pCurr->rec.key == _key) {
				return true;
			}
			if (_key < pCurr->rec.key) {
				if (pCurr->pLeft == nullptr)
					break;
				pPrev = pCurr;
				pCurr = pCurr->pLeft;
			}
			else {
				if (pCurr->pRight == nullptr)
					break;
				pPrev = pCurr;
				pCurr = pCurr->pRight;
			}
		}
		return false;
	}
	virtual bool Insert(TRecord rec) {
		if (IsFull() || Find(rec.key)) {
			return false;
		}
		DataCount++;
		Eff++;
		TTreeNode* tmp = new TTreeNode;
		tmp->rec = rec;
		if (DataCount == 1) {
			pRoot = tmp;
			return true;
		}
		if (rec.key < pCurr->rec.key) {
			pCurr->pLeft = tmp;
		}else{
			pCurr->pRight = tmp;
		}
		return true;
	}
	virtual bool Delete(TKey _key) {
		if (IsEmpty() || !Find(_key)) {
			return false;
		}
		int fl = 0;
		if (pRoot == pCurr) {
			fl = 1;
		}
		Eff++;
		TTreeNode* del;
		if (pCurr->pRight == nullptr) {
			del = pCurr;
			pCurr = pCurr->pLeft;
			if (fl) {
				pRoot = pCurr;
			}
			else {
				if (pPrev->pLeft == del) {
					pPrev->pLeft = pCurr;
				}
				else {
					pPrev->pRight = pCurr;
				}
			}
			delete del;
			return true;
		}
		if (pCurr->pLeft == nullptr) {
			del = pCurr;
			pCurr = pCurr->pRight;
			if (fl) {
				pRoot = pCurr;
			}
			else {
				if (pPrev->pLeft == del) {
					pPrev->pLeft = pCurr;
				}
				else {
					pPrev->pRight = pCurr;
				}
			}
			delete del;
			return true;
		}
		TTreeNode* tmp,* tmpPrev;
		tmp = pCurr->pLeft;
		tmpPrev = nullptr;
		while (tmp->pRight != nullptr)
			tmpPrev = tmp,tmp = tmp->pRight,Eff++;
		del = tmp;
		pCurr->rec = tmp->rec;
		if (tmp == pCurr->pLeft) {
			pCurr->pLeft = tmp->pLeft;
		}
		else {
			tmpPrev->pRight = tmp->pLeft;
		}
		delete del;
		DataCount--;
		return true;
	}

	TKey GetKey() const{
		if (pCurr == nullptr)
			throw "Wrong position";
		return pCurr->rec.key;
	}
	TValue GetValue() const {
		if (pCurr == nullptr)
			throw "Wrong position";
		return pCurr->rec.val;
	}

	~TTreeTable() {
		DelRec(pRoot);
	}
	
	void Reset() {
		st.Clear();
		pCurr = pRoot;
		while (pCurr != nullptr) {
			st.Push(pCurr);
			pCurr = pCurr->pLeft;
		}
		if(!st.Empty())
			pCurr = st.Top();
	}
	void GoNext() {
		st.Pop();
		pCurr = pCurr->pRight;
		while (pCurr != nullptr) {
			st.Push(pCurr);
			pCurr = pCurr->pLeft;
		}
		if (st.Empty())
			pCurr = nullptr;
		else
			pCurr = st.Top();
	}

	bool IsEnd() const{
		return pCurr==nullptr;
	}
	void Print(std::ostream& fout) {
		PrintRec(fout, pRoot, 0);
	}

};