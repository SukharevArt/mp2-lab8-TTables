#include "TSortTable.h"

using namespace std;

int main() {
	TTable * tbl = new TSortTable(100);
	tbl->Insert(TRecord(12, "ertt"));
	tbl->Insert(TRecord(10, "wwww"));
	tbl->Insert(TRecord(30, "11111"));
	tbl->Insert(TRecord(1, "11123"));
	cout << *tbl << "\n";
	tbl->Delete(10);
	cout << "----\n" << *tbl << "\n";

	return 0;
}