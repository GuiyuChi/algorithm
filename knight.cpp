#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
 * 骑士巡游问题
 * @author guiyu
 * 
 */
class Knight 
{
private:
	vector<vector<int>> map;
	int count;
	vector<vector<int>> res;
	int d[8][2] = { {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2} };

	bool isInBound(int x,int y,int n) {
		if (x >= 0 && x < n && y >= 0 && y < n) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isNotGone(int x,int y) {
		if (map[x][y] == 0)
			return true;
		else
			return false;
	}
	bool knightGo(int x,int y,int n) {
		if (!isInBound(x,y,n) || !isNotGone(x,y)) {
			return false;
		}
		else {
			count++;
			map[x][y] = 1;
			if (count == n * n) {
				vector<int> temp;
				temp.push_back(x);
				temp.push_back(y);
				res.push_back(temp);
				return true;
			}
			else {
				for (int i = 0; i < 8; i++) {
					if (knightGo(x + d[i][0], y + d[i][1], n)) {
						vector<int> temp;
						temp.push_back(x);
						temp.push_back(y);
						res.push_back(temp);
						return true;
					}
				}
				map[x][y] = 0;//回退
				count--;
				return false;
			}
		}
	}
public:
	bool knight(int x,int y,int n) {
		map = vector<vector<int>>(n,vector<int>(n,0));
		if (knightGo(x, y, n)) {

			for (int i = res.size()-1; i >= 0;i--) {
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
	cout << knight.knight(x, y,n);
	return 0;
}