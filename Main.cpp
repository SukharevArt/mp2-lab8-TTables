#include "TSortTable.h"
#include "TArrayHash.h"
#include "TListHash.h"
#include "TTreeTable.h"
#include "TBalTable.h"


using namespace std;

int main() {
	TTable * tbl = new TBalTable;
	tbl->Insert(TRecord(12, "ertt"));
	tbl->Insert(TRecord(4, "e22rtt"));
	tbl->Insert(TRecord(230, "wwww")); 
	tbl->Insert(TRecord(930, "wwwwwww"));
	tbl->Insert(TRecord(130, "ererww"));
	tbl->Insert(TRecord(30, "11111"));
	tbl->Insert(TRecord(1, "11123"));
	tbl->Insert(TRecord(345, "1rrw"));
	tbl->Insert(TRecord(321, "1rww3aw"));

	cout << *tbl << "\n";
	return 0;
}