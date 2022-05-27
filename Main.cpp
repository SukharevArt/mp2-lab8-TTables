#include "TSortTable.h"
#include "TArrayHash.h"
#include "TListHash.h"
#include "TTreeTable.h"
#include "TBalTable.h"
#include <vector>

using namespace std;

int main() {
	TTable * tbl1 = new TBalTable;
	TTable * tbl2 = new TTreeTable;
	vector<int> v;

	srand(time(0));
	int n = 40;
	tbl1->ClearEff();
	tbl2->ClearEff();
	int e = n / 2;
	
	for (int i = 0; i < n; i++) {
		int a;
		a= rand() % (n * 10);
		while(a==e)
			a= rand() % (n * 10);
		a = i;
		v.push_back(a);
		tbl1->Insert(TRecord(a, "val" + to_string(a)));
		tbl2->Insert(TRecord(a, "val" + to_string(a)));
		
	}
	if (n < 500) {
		cout << "TBalTable:\n";
		tbl1->PrintTbl(cout);
		cout << "TTreeTable:\n";
		tbl2->PrintTbl(cout);

	}
	cout <<"Eff Create TBalTable :" << tbl1->GetEff() << "\n";
	cout <<"Eff Create TTreeTable :"<< tbl2->GetEff() << "\n" << "\n";
	
	tbl1->ClearEff();
	tbl2->ClearEff();
	tbl1->Insert(e);
	tbl2->Insert(e);
	cout << "Eff Insert TBalTable :" << tbl1->GetEff() << "\n";
	cout << "Eff Insert TTreeTable :" << tbl2->GetEff() << "\n" << "\n";

	tbl1->ClearEff();
	tbl2->ClearEff();
	for(int i=0;i<n;i++)
		tbl1->Find(v[i]);
	for(int i=0;i<n;i++)
		tbl2->Find(v[i]);
	cout << "Eff avgFind TBalTable :" << tbl1->GetEff()/n << "\n";
	cout << "Eff avgFind TTreeTable :" << tbl2->GetEff()/n << "\n" << "\n";
	
	tbl1->ClearEff();
	tbl2->ClearEff();
	tbl1->Delete(e);
	tbl2->Delete(e);
	cout << "Eff Delete TBalTable :" << tbl1->GetEff() << "\n";
	cout << "Eff Delete TTreeTable :" << tbl2->GetEff() << "\n" << "\n";

	return 0;
}