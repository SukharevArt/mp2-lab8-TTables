#pragma once
#include<iostream>
#include<string>

typedef int TKey;
typedef std::string TValue;

struct TRecord {
	TKey key;
	TValue val;
	bool operator==(const TRecord& a) {
		return key==a.key;
	}
	bool operator!=(const TRecord& a) {
		return key!=a.key;
	}
	bool operator<(const TRecord& a) {
		return key<a.key;
	}
	bool operator>(const TRecord& a) {
		return key>a.key;
	}
	bool operator>=(const TRecord& a) {
		return key>=a.key;
	}
	bool operator<=(const TRecord& a) {
		return key<=a.key;
	}
};

class TTable {
protected:
	int DataCount;
	int Eff;
public:
	TTable() {
		DataCount = 0;
		Eff = 0;
	}
	virtual ~TTable() {}
	int GetDataCount() {
		return DataCount;
	}
	int GetEff() {
		return Eff;
	}
	void ClearEff() {
		Eff = 0;
	}
	bool IsEmpty() {
		return DataCount == 0;
	}
	virtual bool IsFull() const = 0;
	virtual bool Find() = 0;
	virtual bool Insert() = 0;
	virtual bool Delete() = 0;
	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() const = 0;
	virtual TKey GetKey() const = 0;
	virtual TValue GetValue() const = 0;
	friend std::ostream& operator<<(std::ostream& os, TTable& a) {
		for (a.Reset(); !a.IsEnd(); a.GoNext()) {
			os << a.GetKey() << " : " << a.GetValue() << "\n";
		}
	}

};
