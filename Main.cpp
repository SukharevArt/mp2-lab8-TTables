#include "TSortTable.h"
#include "TArrayHash.h"
#include "TListHash.h"


using namespace std;

int main() {
	TTable * tbl = new TListHash(100);
	tbl->Insert(TRecord(12, "ertt"));
	tbl->Insert(TRecord(4, "e22rtt"));
	tbl->Insert(TRecord(230, "wwww")); 
	tbl->Insert(TRecord(930, "wwwwwww"));
	tbl->Insert(TRecord(130, "ererww"));
	tbl->Insert(TRecord(30, "11111"));
	tbl->Insert(TRecord(1, "11123"));
	tbl->Delete(930);
	cout << *tbl << "\n";
	return 0;
}