#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
	int nowTurnTime;
	int minTurn;
	int numOfWay;
	int turn[8][2] = { {0,1},{0,-1} ,{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1} };
	int oldTurn[1][2] = { {0,0} };
	int nowTurn[1][2];
	bool isInRooms(int x,int y) {
		if (x >= 0 && x < rooms.size() && y >= 0 && y <= rooms[0].size())
			return true;
		else
			return false;
	}
	bool canIn(int x,int y) {
		if (rooms[x][y] != 0 )
			return false;
		else
			return true;
	}
public:
	vector<vector<int>> rooms;
	void display() {
		for (int i = 0; i < rooms.size(); i++) {
			for (int j = 0; j < rooms[i].size(); j++) {
				cout << rooms[i][j] << " ";
			}
			cout << endl;
		}
	}
	bool findWay(int x,int y) {
		if (rooms[x][y] == 4) return true;
		if (!isInRooms(x, y) || !canIn(x, y)) {
			return false;
		}
		else {
			if (oldTurn[0] == 0 && oldTurn[1] == 0) {
				//just begin

			}
		}

	}
	void text() {
		cout << minTurn;
	}
};

int main() {
	int a, b,c;
	while (cin >> a >> b >> c) {
		Solution solution;
		solution.rooms = vector<vector<int>>(a, vector<int>(b, 0));
		for (int i = 0; i < c; i++) {
			//the room cannot move
			int x, y;
			cin >> x >> y;
			solution.rooms[x - 1][y - 1] = 2;//2 means the room cannot in
		}
		int x, y;
		cin >> x >> y;
		int startX = x;
		int startY = y;
		solution.rooms[x - 1][y - 1] = 0;//the room begin
		cin >> x >> y;
		solution.rooms[x - 1][y - 1] = 4;//the room end
		//solution.display();
		//solution.text();
	}
	
	//solution.display();
	return 0;
}