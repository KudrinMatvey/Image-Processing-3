#pragma once
#include<map>
using namespace std;

struct item {
	int x;
	int y;
	int z;

	bool operator<(const item& o) const {
		return x < o.x || (x == o.x && y < o.y) || (x == o.x && y == o.y && z < o.z);
	}
	bool operator=(const item &o) const {
		return x == o.x && y == o.y && z == o.z;
	}

};

class AwesomeMap {
private: item tmp;
		 int count;
		 map<item, int> map;
public:

	~AwesomeMap() {
		map.clear();
	}

	void add(int x, int y, int z) {
		tmp.x = x;
		tmp.y = y;
		tmp.z = z;
		int i = 0;
		try {
			i = map.at(tmp);
		}	catch (out_of_range e) {
			i = 0;
		}
		map.insert(pair<item, int>(tmp, ++i));
	}

	item* findLocalMaximums() {
		count = 0;
		for (pair<item, int> i : map) {
			if (i.second > 3) count++;
		}
		item* arr = new item[count];
		int k = 0;
		for (pair<item, int> i : map) {
			if (i.second > 10) 
				arr[k] = i.first;
		}
		return arr;
	}
	int getArrSize() {
		return count;
	}
};