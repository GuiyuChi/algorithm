#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include <assert.h> 
#include <cassert>
#include<time.h>
using namespace std;
/*
* 
* @author guiyu
*
*/
class Knight
{
private:
	clock_t start, finish;
	int startx;
	int starty;
	vector<vector<int>> map;
	int count;
	vector<vector<int>> res;
	int d[8][2] = { { 2,1 },{ 2,-1 },{ -2,1 },{ -2,-1 },{ 1,2 },{ 1,-2 },{ -1,2 },{ -1,-2 } };

	bool isInBound(int x, int y, int n) {
		if (x >= 0 && x < n && y >= 0 && y < n) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isNotGone(int x, int y) {
		if (map[x][y] == 0)
			return true;
		else
			return false;
	}
	int findNext(int x, int y,int n) {
		if (!isInBound(x, y, n) || !isNotGone(x, y)) {
			return 0;
		}
		//find number of point can get
		int count = 0;
		for (int i = 0; i < 8; i++) {
			if (isInBound(x+d[i][0], y+d[i][1], n) && isNotGone(x + d[i][0], y + d[i][1])) {
				count++;
			}
		}
		return count;
	}
	bool ishave(int x, int y) {
		for (int i = 0; i < 8; i++) {
			if (x == d[i][0] && y == d[i][1]) {
				return true;
			}
		}
		return false;
	}
	vector<vector<int>> goSort(int x,int y,int n) {
		//choose min road
		vector<vector<int>> a;
		for (int i = 0; i < 8; i++) {
			if (isInBound(x + d[i][0], y + d[i][1], n) && isNotGone(x + d[i][0], y + d[i][1])) {
				vector<int> t;
				t.push_back(findNext(x + d[i][0], y + d[i][1], n));
				t.push_back(d[i][0]);
				t.push_back(d[i][1]);
				a.push_back(t);
			}
		}
		sort(a.begin(), a.end());
		return a;
	}
	bool knightGo(int x, int y, int n) {
		finish = clock();
		int totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		if (!isInBound(x, y, n) || !isNotGone(x, y)) {
			return false;
		}
		else {
			count++;
			map[x][y] = 1;
			if (count == n * n ) {
				vector<int> temp;
				temp.push_back(x);
				temp.push_back(y);
				res.push_back(temp);
				return true;
			}
			else {
				vector<vector<int>> newsort = goSort(x, y, n);
					for (int i = 0; i < newsort.size(); i++) {
						int newx = x + newsort[i][1];
						int newy = y + newsort[i][2];
						if (knightGo(newx, newy, n)) {
							//if(knightGo(x+d[i][0],y+d[i][1],n)){
							vector<int> temp;
							temp.push_back(x);
							temp.push_back(y);
							res.push_back(temp);
							return true;
						}
					}
				map[x][y] = 0;
				count--;
				return false;
			}
		}
	}
public:
	bool knight(int x, int y, int n) {
		
		double totaltime;
		start = clock();

		startx = x;
		starty = y;
		map = vector<vector<int>>(n, vector<int>(n, 0));
		if (knightGo(x, y, n)) {

			for (int i = res.size() - 1; i >= 0; i--) {
				vector<int> a = res[i];
				for (int j = 0; j < a.size(); j++) {
					cout << a[j] << " ";
				}
				cout << endl;
			}
			return true;
		}
		else {
			return false;
		}
	}

};
int main() {
	Knight knight;
	int n, x, y;
	cin >> n;
	cin >> x;
	cin >> y;
	cout << knight.knight(x, y, n);
	return 0;
}