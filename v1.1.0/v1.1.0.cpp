#include <conio.h>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <lbi.h> // 
#define Tick 100
#define Version "v1.1.0"
using namespace loong;
using namespace std;
double inf = 1.8e308;
int a = 1;
int unlock = 1;
string tips[] = {
		"1,000,000,006+1=0",
        "北冥有鱼，其名为鲲。鲲之大，long long存不下。",
        "e9e15年增量一场空，不小心丢档见祖宗",
        "超光速粒子会产生T    i    m    e",
        "import turtle;",
        "井include《iosteam》",
        "2147183646,2147483647,-2147483648",
        "4294967294,4294967295,0",
        "cout<<news_arr[n++];",
        "'BREAKING' NEWS : 这是第2^1024+1条新闻。新闻终于不用再强制大坍缩了!",
        "import bits/stdpython.h",
        "新闻被重复播放还叫新闻吗？",
        "新款同伴符文：+1.7976e308%幸福。耶！",
        "此版本中，本游戏共有29条不同的新闻（尽管大（quan）多（dou）数（shi）来自zlyxj）。",
        "进入Teresa的时候不要忘记写：freopen(AD1,\"w\",\"teresa.out\")",
        "/*看不见我*/",
        "break_quantum.js支持{10,10,10,10}的数字。break_ghost.js支持{10,10[10]10}的数字。",
        "科技这么发达了吗，都有K65路公交车了，比葛立恒数还大",
        "您知道吗？新闻里可能会有随地大小刀",
    	"老婆饼里没有老婆，佛跳墙里没有佛，所以巴尔泽布没有__ (2分)",
    	"快排已死，STL当立",
    	"ST表是啥，我只知道线段树大法好",
    	"十年OI一场空，不开longlong见祖宗",
    	"提瓦特初代神：温迪，钟离，雷电真，后面是谁来着",
    	"182376只是一个普通的自然数...吗？",
    	"我曾遭到π/60背叛",
    	"如何区分温迪和巴巴托斯？",
    	"你们好啊，我是Farmer John，我要开始放牛了，害怕的OIer已经划走了",
    	"nowt = tips[rand() % 29];"
};
string nowt = "点击输入新闻";
int prett = time(NULL);
struct T
{
	lBI point = 0, ptplus = 1, multi = 1, ipmul = 1, maxpoint = 10000;
	lBI s1plus = 0, s2plus = 0;
	lBI ipoint = 0;
	int itimes = 0, etimes = 0;
	int ptpcnt = 0, s1pcnt = 0, s2pcnt = 0;
	lBI rl0mul = 1, l0supd;
	lBI imucnt, su0cnt;
	lBI epmul, epoint;
	int rtime;
	int stime;
	lBI gtime;
} game;
void buy(int layer, int update)
{
	if (layer == 0)
	{
		if (update == 1 && game.point >= ceil(pow(1.05, game.ptpcnt)))
		{
			game.ptplus += game.multi;
			game.point -= ceil(pow(1.05, game.ptpcnt));
			game.ptpcnt ++;
		}
		if (update == 2 && game.point >= ceil(pow(1.1, game.s1pcnt)) * 10)
		{
			game.s1plus += game.multi;
			game.point -= ceil(pow(1.1, game.s1pcnt)) * 10;
			game.s1pcnt ++;
		}
		if (update == 3 && ceil(pow(1.2, game.s2pcnt)) * 100 != inf && game.point >= int_to_lBI(ceil(pow(1.2, game.s2pcnt)) * 100))
		{
			game.s2plus += game.multi;
			game.point -= ceil(pow(1.2, game.s2pcnt)) * 100;
			game.s2pcnt ++;
		}
	}
	if (layer == 1)
	{
		if (update == 1 && game.ipoint >= pow(lBI(2), game.imucnt))
		{
			game.ipmul *= 2;
			game.ipoint -= pow(lBI(2), game.imucnt);
			game.imucnt ++;
		}
		if (update == 2 && game.ipoint >= pow(game.rl0mul, lBI(2)))
		{
			game.ipoint -= pow(game.rl0mul, lBI(2));
			game.rl0mul ++;
		}
		if (update == 3 && game.ipoint >= lBI(ceil(lBI_to_int(pow(lBI(1.5), game.su0cnt)) * 10)))
		{
			game.l0supd += 10;
			game.ipoint -= ceil(lBI_to_int(pow(lBI(1.5), game.su0cnt))) * 10;
			game.su0cnt ++;
		}
	}
}
void softreset(int layer)
{
	if (layer == 0)
	{
		game.multi *= pow(max({1, 0}, game.point / game.maxpoint), game.rl0mul);
		game.ptplus = (game.multi + game.l0supd) * game.multi;
		game.ptpcnt = lBI_to_int(game.l0supd);
		game.s1pcnt = lBI_to_int(game.l0supd);
		game.s2pcnt = lBI_to_int(game.l0supd);
		game.maxpoint = max(game.maxpoint, game.point);
		game.point = 0;
		game.s1plus = game.multi * game.l0supd;
		game.s2plus = game.multi * game.l0supd;
	}
}
void infreset(int layer)
{
	if (layer == 0)
	{
		game.point = 0;
		game.multi = 1;
		game.ptplus = lBI({1, 0}) + game.l0supd;
		game.ptpcnt = lBI_to_int(game.l0supd);
		game.s1pcnt = lBI_to_int(game.l0supd);
		game.s2pcnt = lBI_to_int(game.l0supd);
		game.maxpoint = 10000;
		game.s1plus = game.l0supd;
		game.s2plus = game.l0supd;
		unlock = max(unlock, 2);
		game.itimes ++;
		game.ipoint += game.ipmul;
	}
	if (layer == 1)
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
		unlock = max(unlock, 3);
		game.itimes = 0;
		game.ipoint = 0;
		game.ipmul = 1;
		game.rl0mul = 1;
		game.l0supd = 0;
		game.imucnt = 0;
		game.su0cnt = 0;
		game.itimes = 0;
		game.etimes ++;
		game.epoint += game.epmul;
	}
}
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
	fout << game.rl0mul.x << " " << game.rl0mul.e << endl;
	fout << game.l0supd.x << " " << game.l0supd.e << endl;
	fout << game.imucnt.x << " " << game.imucnt.e << endl;
	fout << game.su0cnt.x << " " << game.su0cnt.e << endl;
	fout << game.etimes << endl;
	fout << game.epmul.x << " " << game.epmul.e << endl;
	fout << game.epoint.x << " " << game.epoint.e << endl;
	fout << game.stime << endl;
	fout << game.rtime << endl;
	fout << game.gtime.x << " " << game.gtime.e << endl;
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
	if (x == "v1.0.0" || x == "v1.0.1")
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
		fin >> game.rl0mul;
		fin >> game.l0supd;
		fin >> game.imucnt;
		fin >> game.su0cnt;
		fin >> game.etimes;
		fin >> game.epmul;
		fin >> game.epoint;
		fin >> unlock;
		fin >> a;
	}
	if (x == "v1.0.2" || x == "v1.1.0")
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
		fin >> game.rl0mul;
		fin >> game.l0supd;
		fin >> game.imucnt;
		fin >> game.su0cnt;
		fin >> game.etimes;
		fin >> game.epmul;
		fin >> game.epoint;
		fin >> game.stime;
		fin >> game.rtime;
		fin >> game.gtime;
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
	cout << "============================" << endl;
	if (time(NULL) > prett + 4)
	{
		nowt = tips[rand() % 29];
		prett = time(NULL);
	}
	cout << nowt << endl;
	cout << "============================" << endl;
	if (x == 1)
	{
		if (game.point < Infinity)
		{
			cout << "你有 " << game.point << " * Layer 0。" << endl;
			cout << ")L Layer 0 + " << game.ptplus << endl;
			cout << ")1 每次按键增加 Layer 0 + " << game.multi << " 价格：" << ceil(pow(1.05, game.ptpcnt)) << " 当前： " << game.ptplus << endl;
			cout << ")2 每秒增加 Layer 0 + " << game.multi << " 价格：" << ceil(pow(1.1, game.s1pcnt)) * 10 << " 当前： " << game.s1plus << endl;
			if (ceil(pow(1.2, game.s2pcnt)) * 100 == inf)
			{
				cout << ")3 每秒增加每秒增加 Layer 0 + " << game.multi << " （不可购买） 当前： " << game.s2plus << endl;
			}
			else
			{
				cout << ")3 每秒增加每秒增加 Layer 0 + " << game.multi << " 价格：" << ceil(pow(1.2, game.s2pcnt)) * 100 << " 当前： " << game.s2plus << endl;
			}
			cout << ")4 重置升级和点数，但将 Layer 0 乘数 * " << pow(max({1, 0}, game.point / game.maxpoint), game.rl0mul) << " 当前： " << game.multi << endl;
		}
		else
		{
			cout << "你拥有的 Layer 0 太多了。" << endl;
			cout << ")1 将 Layer 0 转换为 " << game.ipmul << " * Layer 1" << endl;
		}
	}
	if (x == 2)
	{
		if (game.ipoint < Infinity)
		{
			cout << "你有 " << game.ipoint << " * Layer 1。" << endl;
			cout << ")1 Layer 1 乘数 * 2 价格： " << pow(lBI(2), game.imucnt + 1) << " 当前： " << game.ipmul << endl;
			cout << ")2 改进 Layer 0 乘数公式为 " << "(当前乘数 * 当前 Layer 0 / 上次重置最大获取 Layer 0) ^ " << game.rl0mul + 1 << " 价格：" << pow(game.rl0mul, lBI(2)) << " 当前： " << game.rl0mul << endl;
			cout << ")3 初始时每个 Layer 0 升级都升级了 " << game.l0supd + 10 << " 次 价格：" << ceil(lBI_to_int(pow(lBI(1.5), game.su0cnt))) * 10 << " 当前： " << game.l0supd << endl;
		}
		else
		{
			cout << "你拥有的 Layer 0 太多了。" << endl;
			cout << ")1 将 Layer 1 转换为 " << game.epmul << " * Layer 2" << endl;
		}
	}
	if (x == 3)
	{
		cout << "你有 " << game.epoint << " * Layer 2。" << endl;
		cout << "你已完成游戏！" << endl;
		cout << ")1 等待更新..." << endl;
	}
	cout << "第 " << a << " 页，共 " << unlock << " 页" << endl;
	if (a >= 2)
	{
		cout << ")A 上一页" << endl;
	}
	if (a < unlock)
	{
		cout << ")D 下一页" << endl;
	}
	cout << "==========统计信息==========" << endl;
	cout << "你玩了" << game.gtime << "秒。" << endl;
	cout << "你实际玩了" << game.rtime << "秒。" << endl;
}
void update(char t, double gtick)
{
	game.gtime += 1.0 / gtick;
	game.rtime = time(NULL) - game.stime;
	game.s1plus += game.s2plus / gtick;
	game.point += game.s1plus / gtick;
	if (a == 1)
	{
		if (t == 'l' && game.point < Infinity)
		{
			game.point += game.ptplus;
		}
		else if (t == '1' && game.point >= Infinity)
		{
			infreset(0);
		}
		else if (t == '4' && game.point < Infinity)
		{
			softreset(0);
		}
		else
		{
			if ('1' <= t && t <= '3')
			{
				buy(0, t - '0');
			}
		}
	}
	if (a == 2)
	{
		if (t == '1' && game.ipoint >= Infinity)
		{
			infreset(1);
		}
		else
		{
			if ('1' <= t && t <= '3')
			{
				buy(1, t - '0');
			}
		}
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
	srand(time(NULL));
	loadgame();
	if (game.stime == 0)
	{
		game.stime = time(NULL);
	}
	else
	{
		int lxsj = time(NULL) - (game.stime + game.rtime);
		for (int i = 1; i <= lxsj; i ++)
		{
			update('\0', 1);
		}
	}
	while (1)
	{
		Sleep(1000 / Tick);
		update(_lgetch(), Tick);
		savegame();
	}
}