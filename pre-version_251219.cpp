#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <lbi.h> // 
#define Tick 500
#define Version "pre-version_251219"
using namespace loong;
using namespace std;
int a = 1;
int unlock = 1;
struct T
{
	lBI point = 0, ptplus = 1, multi = 1, ipmul = 1, maxpoint = 10000;
	lBI s1plus = 0, s2plus = 0;
	lBI ipoint;
	int itimes = 0;
	int ptpcnt = 0, s1pcnt = 0, s2pcnt = 0;
} game;
void savegame()
{
	ofstream fout("111.txt");
	fout << Version << endl;
	fout << game.point.x << " " << game.point.e << endl;
	fout << game.ptplus.x << " " << game.ptplus.e << endl;
	fout << game.multi.x << " " << game.multi.e << endl;
	fout << game.ipmul.x << " " << game.ipmul.e << endl;
	fout << game.maxpoint.x << " " << game.maxpoint.e << endl;
	fout << game.s1plus.x << " " << game.s1plus.e << endl;
	fout << game.s2plus.x << " " << game.s2plus.e << endl;
	fout << game.ipoint.x << " " << game.ipoint.e << endl;
	fout << game.itimes << endl;
	fout << game.ptpcnt << endl;
	fout << game.s1pcnt << endl;
	fout << game.s2pcnt << endl;
	fout << unlock << endl;
	fout << a << endl;
	fout.close();
}
void loadgame()
{
	ifstream fin("111.txt");
	string x;
	fin >> x;
	if (x == "pre-version_251219")
	{
		fin >> game.point;
		fin >> game.ptplus;
		fin >> game.multi;
		fin >> game.ipmul;
		fin >> game.maxpoint;
		fin >> game.s1plus;
		fin >> game.s2plus;
		fin >> game.ipoint;
		fin >> game.itimes;
		fin >> game.ptpcnt;
		fin >> game.s1pcnt;
		fin >> game.s2pcnt;
		fin >> unlock;
		fin >> a;
	}
	fin.close();
}
char _lgetch()
{
	if (_kbhit())
	{
		char x = _getch();
		return x;
	}
	else
	{
		return '\x00';
	}
}
void printscr(int x)
{
	system("cls");
	if (x == 1)
	{
		if (game.point < Infinity)
		{
			cout << "你有 " << game.point << " 点数。" << endl;
			cout << ")1 点数 + " << game.ptplus << endl;
			cout << ")2 每次按键增加点数 + " << game.multi << " 价格：" << ceil(pow(1.05, game.ptpcnt)) << " 当前： " << game.ptplus << endl;
			cout << ")3 每秒增加点数 + " << game.multi << " 价格：" << ceil(pow(1.1, game.s1pcnt)) * 10 << " 当前： " << game.s1plus << endl;
			cout << ")4 每秒增加每秒增加点数 + " << game.multi << " 价格：" << ceil(pow(1.2, game.s2pcnt)) * 100 << " 当前： " << game.s2plus << endl;
			cout << ")5 重置升级和点数，但将乘数 * " << max({1, 0}, game.point / game.maxpoint) << " 当前： " << game.multi << endl;
		}
		else
		{
			cout << "你拥有的点数太多了。" << endl;
			cout << ")1 将点数转换为 " << game.ipmul << " 无限点" << endl;
		}
	}
	if (x == 2)
	{
		cout << "你有 " << game.ipoint << " 无限点。" << endl;
	}
	cout << "第 " << a << " 页，共 " << unlock << " 页" << endl;
	cout << ")A 上一页" << endl;
	cout << ")D 下一页" << endl;
}
void update(char t)
{
	game.s1plus += game.s2plus / Tick;
	game.point += game.s1plus / Tick;
	if (a == 1 && t == '1' && game.point < Infinity)
	{
		game.point += game.ptplus;
	}
	if (a == 1 && t == '1' && game.point >= Infinity)
	{
		game.point = 0;
		game.multi = 1;
		game.ptplus = 1;
		game.ptpcnt = 0;
		game.s1pcnt = 0;
		game.s2pcnt = 0;
		game.maxpoint = 10000;
		game.s1plus = 0;
		game.s2plus = 0;
		unlock = max(unlock, 2);
		game.itimes ++;
		game.ipoint += game.ipmul;
	}
	if (a == 1 && t == '2' && game.point >= int_to_lBI(ceil(pow(1.05, game.ptpcnt))) && game.point < Infinity)
	{
		game.ptplus += game.multi;
		game.point -= int_to_lBI(ceil(pow(1.05, game.ptpcnt)));
		game.ptpcnt ++;
	}
	if (a == 1 && t == '3' && game.point >= int_to_lBI(ceil(pow(1.1, game.s1pcnt)) * 10) && game.point < Infinity)
	{
		game.s1plus += game.multi;
		game.point -= int_to_lBI(ceil(pow(1.1, game.s1pcnt)) * 10);
		game.s1pcnt ++;
	}
	if (a == 1 && t == '4' && game.point >= int_to_lBI(ceil(pow(1.2, game.s2pcnt)) * 100) && game.point < Infinity)
	{
		game.s2plus += game.multi;
		game.point -= int_to_lBI(ceil(pow(1.2, game.s2pcnt)) * 100);
		game.s2pcnt ++;
	}
	if (a == 1 && t == '5' && game.point < Infinity)
	{
		game.multi *= max({1, 0}, game.point / game.maxpoint);
		game.point = 0;
		game.ptplus = game.multi;
		game.ptpcnt = 0;
		game.s1pcnt = 0;
		game.s2pcnt = 0;
		game.maxpoint = max(game.maxpoint, game.point);
		game.s1plus = 0;
		game.s2plus = 0;
	}
	if (t == 'a')
	{
		if (a > 1)
		{
			a --;
		}
	}
	if (t == 'd')
	{
		if (a < unlock && unlock >= (a + 1))
		{
			a ++;
		}
	}
	printscr(a);
}
int main()
{
	loadgame();
	while (1)
	{
		Sleep(1000 / Tick);
		update(_lgetch());
		savegame();
	}
}