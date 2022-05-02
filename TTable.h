#pragma once
#include<iostream>
#include<string>

typedef int TKey;
typedef std::string TValue;

struct TRecord {
	TKey key;
	TValue val;
	TRecord(TKey _key = 100,TValue _val ="something") {
		key = _key;
		val = _val;
	}
	TRecord(const TRecord& a) {
		key = a.key;
		val = a.val;
	}
	TRecord& operator=(const TRecord& a) {
		key = a.key;
		val = a.val;
		return *this;
	}

	bool operator==(const TRecord& a) const {
		return key==a.key;
	}
	bool operator!=(const TRecord& a) const {
		return key!=a.key;
	}
	bool operator<(const TRecord& a) const {
		return key<a.key;
	}
	bool operator>(const TRecord& a) const {
		return key>a.key;
	}
	bool operator>=(const TRecord& a) const {
		return key>=a.key;
	}
	bool operator<=(const TRecord& a) const {
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
	int GetDataCount() const {
		return DataCount;
	}
	int GetEff() const {
		return Eff;
	}
	void ClearEff() {
		Eff = 0;
	}
	bool IsEmpty() const {
		return DataCount == 0;
	}
	int GetDataCount() {
		return DataCount;
	}
	virtual bool IsFull() const = 0;
	virtual bool Find(TKey _key) = 0;
	virtual bool Insert(TRecord rec) = 0;
	virtual bool Delete(TKey _key) = 0;
	virtual void Reset() = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() const = 0;
	virtual TKey GetKey() const = 0;
	virtual TValue GetValue() const = 0;
	friend std::ostream& operator<<(std::ostream& os, TTable& a) {
		for (a.Reset(); !a.IsEnd(); a.GoNext()) {
			os << a.GetKey() << " : " << a.GetValue() << "\n";
		}
		return os;
	}
};
