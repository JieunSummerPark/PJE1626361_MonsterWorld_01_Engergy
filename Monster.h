#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
	string name, icon;		// 몬스터 이름과 화면 출력용 아이콘
	int x, y, nItem;		// 현재 위치와 먹은 아이템 수
	int nEnergy;			// 에너지를 저장하는 속성

	void clip(int maxx, int maxy) {
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}
	void eat(int map[DIM][DIM]) {
		if (map[y][x] == 1) {
			map[y][x] = 0;
			nItem++;
			nEnergy += 8;		// 아이템을 먹으면 에너지가 8 증가됨
		}
		else if (nEnergy > 0) {	// 에너지의 최솟값은 0 (에너지가 0초과(=1이상)일때 1빼면 0이다. 그러므로 최소값이 0이다.)
			nEnergy -= 1;		// 아이템을 먹지 못하면 에너지가 1 감소
		}
	}
public:
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {} // 맨 처음에는 모든 몬스터 객체의 에너지가 100
	~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~\n"; }

	void draw(Canvas & canvas) { canvas.draw(x, y, icon); }
	void move(int map[DIM][DIM], int maxx, int maxy) {
		switch (rand() % 8) {
		case 0: y--; break;
		case 1: x++; y--; break;
		case 2: x++; break;
		case 3: x++; y++; break;
		case 4: y++; break;
		case 5: x--; y++; break;
		case 6: x--; break;
		case 7: x--; y--; break;
		}
		clip(maxx, maxy);
		eat(map);
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << "\tE:" << nEnergy << endl; }
};