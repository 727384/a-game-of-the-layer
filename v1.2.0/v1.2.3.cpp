#include <conio.h>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "loong\lbi.h" //
#define Tick 100
#define loadTick 1000
#define Version "v1.2.3"
#define splace "save1.loong"
using namespace loong;
using namespace std;
int a = 1;
int unlock = 1;
vector<string> tips = {
		"《原神》是由米哈游自主研发的一款全新开放世界冒险游戏。游戏发生在一个被称作“提瓦特”的幻想世界，在这里，被神选中的人将被授予“神之眼”，导引元素之力。你将扮演一位名为“旅行者”的神秘角色，在自由的旅行中邂逅性格各异、能力独特的同伴们，和他们一起击败强敌，找回失散的亲人--同时，逐步发掘“原神”的真相。",
		"本游戏使用了loong-big-integer。",
		"1,000,000,006+1=0",
		"998,244,352+1=0",
        "北冥有鱼，其名为鲲。鲲之大，long long存不下。",
        "e9e15年增量一场空，不小心丢档见祖宗",
        "超光速粒子会产生T    i    m    e",
        "import turtle;",
        "井include《iosteam》",
        "126,127,-128",
        "254,255,0",
        "32766,32767,-32768",
        "65534,65535,0",
        "2147183646,2147483647,-2147483648",
        "4294967294,4294967295,0",
        "'BREAKING' NEWS : 这是第2^1024+1条新闻。新闻终于不用再强制大坍缩了!",
        "import bits/stdpython.h",
        "新闻被重复播放不叫新闻，叫旧闻（",
        "新款同伴符文：+1.7976e308%幸福。耶！",
        string("此版本（") + Version + "）中，本游戏共有35条不同的新闻（尽管大（quan）多（dou）数（shi）来自zlyxj的游戏）。",
        "进入Teresa的时候不要忘记写：freopen(AD1,\"w\",\"teresa.out\")",
        "/*看不见我*/",
        "break_quantum.js支持{10,10,10,10}的数字。break_ghost.js支持{10,10[10]10}的数字。",
        "科技这么发达了吗，都有K65路公交车了，比葛立恒数还大",
        "您知道吗？新闻里可能会有随地大小刀",
    	"老婆饼里没有老婆，佛跳墙里没有佛，所以巴尔泽布没有__ (2分)",
    	"快排已死，STL当立，岁在11，OI大吉",
    	"ST表是啥，我只知道线段树大法好",
    	"十年OI一场空，不开longlong见祖宗",
    	"提瓦特初代神：温迪，钟离，雷电真，后面是谁来着",
    	"是的，182376只是一个普通的自然数。",
    	"我曾遭到pi/60背叛",
    	"如何区分温迪和巴巴托斯？",
    	"你们好啊，我是Farmer John，我要开始放牛了，害怕的OIer已经划走了",
    	"nowt = tips[rand() % tips.size()];"
};
string nowt = "点击输入新闻";
int prett = time(NULL);
struct T
{
	lBI point = 0, ptplus = 1, multi = 1, ipmul = 1, maxpoint = 10000;
	lBI s1plus = 0, s2plus = 0;
	lBI ipoint = 0;
	int itimes = 0, etimes = 0, l4time = 0;
	lBI ptpcnt = 0, s1pcnt = 0, s2pcnt = 0;
	lBI rl0mul = 1, l0supd;
	lBI imucnt, su0cnt;
	lBI epmul, epoint;
	lBI eu01ct = 0, eu02ct = 0, eu03ct = 2, timetime = 1;
	lBI l4point, l4mul, l4u01c, l4u02c = 1, l4u03c = 2;
	lBI total1, total2, total3, total4;
	int rtime;
	int stime;
	lBI gtime;
} game;
void buy(int layer, int update)
{
	if (layer == 0)
	{
		if (update == 1 && game.point >= pow(lBI(1.05), game.ptpcnt))
		{
			game.ptplus += game.multi;
			game.point -= ceil(pow(lBI(1.05), game.ptpcnt));
			game.ptpcnt ++;
		}
		if (update == 2 && game.point >= pow(lBI(1.1), game.s1pcnt) * 10)
		{
			game.s1plus += game.multi;
			game.point -= pow(lBI(1.1), game.s1pcnt) * 10;
			game.s1pcnt ++;
		}
		if (update == 3 && game.point >= pow(lBI(1.2), game.s2pcnt) * 100)
		{
			game.s2plus += game.multi;
			game.point -= pow(lBI(1.2), game.s2pcnt) * 100;
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
		if (update == 3 && game.ipoint >= pow(lBI(1.5), game.su0cnt) * 10)
		{
			game.l0supd += 10;
			game.ipoint -= pow(lBI(1.5), game.su0cnt) * 10;
			game.su0cnt ++;
		}
	}
	if (layer == 2)
	{
		if (update == 1 && game.epoint >= pow(lBI(2.5), game.eu01ct))
		{
			game.epmul *= 3;
			game.epoint -= pow(lBI(2), pow(lBI(2.5), game.eu01ct));
			game.eu01ct ++;
		}
		if (update == 2 && game.epoint >= pow(lBI(3), game.eu02ct) * 10)
		{
			game.timetime *= 2;
			game.epoint -= pow(lBI(3), game.eu02ct) * 10;
			game.eu02ct ++;
		}
		if (update == 3 && game.epoint >= pow(game.eu03ct, lBI(1.5)) * 100)
		{
			game.epoint -= pow(game.eu03ct, lBI(1.5)) * 100;
			game.eu03ct ++;
		}	
	}	
	if (layer == 3)
	{
		if (update == 1 && game.l4point >= pow(game.l4u01c, lBI(3.5)))
		{
			game.l4mul = pow(lBI(3.5), game.l4u01c);
			game.l4point -= pow(game.l4u01c, lBI(3.5));
			game.l4u01c ++;
		}
		if (update == 2 && game.l4point >= pow(game.l4u02c, lBI(4)) * 5)
		{
			game.l4point -= pow(game.l4u02c, lBI(4)) * 5;
			game.l4u02c ++;
		}
		if (update == 3 && game.l4point >= pow(lBI(10), game.l4u03c + 2))
		{
			game.l4point -= pow(lBI(10), game.l4u03c + 2);
			game.l4u03c ++;
		}	
	}
}
void layerreset(int layer)
{
	if (layer == -1)
	{
		game.multi *= pow(max(lBI({1, 0}), game.point / game.maxpoint), game.rl0mul);
		game.ptplus = game.multi + game.l0supd * game.multi;
		game.ptpcnt = lBI_to_int(game.l0supd);
		game.s1pcnt = lBI_to_int(game.l0supd);
		game.s2pcnt = lBI_to_int(game.l0supd);
		game.maxpoint = max(game.maxpoint, game.point);
		game.point = pow(lBI(4), game.l4u02c - 1) - 1;
		game.s1plus = game.multi * game.l0supd;
		game.s2plus = game.multi * game.l0supd;
	}
	if (layer == 0)
	{
		game.point = pow(lBI(4), game.l4u02c - 1) - 1;
		game.multi = pow(game.eu03ct - 1, lBI(3));
		game.ptplus = lBI({1, 0}) + game.l0supd;
		game.ptpcnt = game.l0supd;
		game.s1pcnt = game.l0supd;
		game.s2pcnt = game.l0supd;
		game.maxpoint = 10000;
		game.s1plus = game.l0supd;
		game.s2plus = game.l0supd;
		unlock = max(unlock, 2);
		game.itimes ++;
		game.ipoint += game.ipmul;
		game.total1 = 0;
		game.total2 += game.ipmul;
	}
	if (layer == 1)
	{
		game.point = pow(lBI(4), game.l4u02c - 1) - 1;
		game.multi = pow(game.eu03ct - 1, lBI(3));
		game.ptplus = 1;
		game.ptpcnt = 0;
		game.s1pcnt = 0;
		game.s2pcnt = 0;
		game.maxpoint = 10000;
		game.s1plus = 0;
		game.s2plus = 0;
		unlock = max(unlock, 3);
		game.itimes = 0;
		game.ipoint = pow(lBI(4), game.l4u02c - 1) - 1;
		game.ipmul = pow(game.l4u03c - 1, game.l4u03c - 1);
		game.rl0mul = 1;
		game.l0supd = 0;
		game.imucnt = 0;
		game.su0cnt = 0;
		game.itimes = 0;
		game.etimes ++;
		game.epoint += game.epmul;
		game.total1 = 0;
		game.total2 = 0;
		game.total3 += game.epmul;
	}
	if (layer == 2)
	{
		game.point = pow(lBI(4), game.l4u02c - 1) - 1;
		game.multi = pow(game.eu03ct - 1, lBI(3));
		game.ptplus = 1;
		game.ptpcnt = 0;
		game.s1pcnt = 0;
		game.s2pcnt = 0;
		game.maxpoint = 10000;
		game.s1plus = 0;
		game.s2plus = 0;
		unlock = max(unlock, 4);
		game.itimes = 0;
		game.ipoint = pow(lBI(4), game.l4u02c - 1) - 1;
		game.ipmul = pow(game.l4u03c - 1, game.l4u03c - 1);
		game.rl0mul = 1;
		game.l0supd = 0;
		game.imucnt = 0;
		game.su0cnt = 0;
		game.itimes = 0;
		game.etimes = 0;
		game.epoint = pow(lBI(4), game.l4u02c - 1) - 1;
		game.epmul = pow(game.l4u03c - 1, game.l4u03c - 1);
		game.eu01ct = 0;
		game.eu02ct = 0;
		game.eu03ct = 2;
		game.timetime = 1;
		game.l4time ++;
		game.l4point += game.l4mul;
		game.total1 = 0;
		game.total2 = 0;
		game.total3 = 0;
		game.total4 += game.l4mul;
	}	
	if (layer == 3)
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
		unlock = max(unlock, 5);
		game.itimes = 0;
		game.ipoint = 0;
		game.ipmul = 1;
		game.rl0mul = 1;
		game.l0supd = 0;
		game.imucnt = 0;
		game.su0cnt = 0;
		game.itimes = 0;
		game.etimes = 0;
		game.epoint = 0;
		game.epmul = 1;
		game.eu01ct = 0;
		game.eu02ct = 0;
		game.eu03ct = 2;
		game.timetime = 1;
		game.l4time = 0;
		game.l4point = 0;
		game.l4mul = 1;
		game.l4u01c = 0;
		game.l4u02c = 1;
		game.l4u03c = 2;
		game.total1 = 0;
		game.total2 = 0;
		game.total3 = 0;
		game.total4 = 0;
	}
}
void savegame()
{
	ofstream fout(splace);
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
	fout << game.ptpcnt.x << " " << game.ptpcnt.e << endl;
	fout << game.s1pcnt.x << " " << game.s1pcnt.e << endl;
	fout << game.s2pcnt.x << " " << game.s2pcnt.e << endl;
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
	fout << game.eu01ct.x << " " << game.eu01ct.e << endl;
	fout << game.eu02ct.x << " " << game.eu02ct.e << endl;
	fout << game.eu03ct.x << " " << game.eu03ct.e << endl;
	fout << game.timetime.x << " " << game.timetime.e << endl;
	fout << game.l4time << endl;
	fout << game.l4point.x << " " << game.l4point.e << endl;
	fout << game.l4mul.x << " " << game.l4mul.e << endl;
	fout << game.l4u01c.x << " " << game.l4u01c.e << endl;
	fout << game.l4u02c.x << " " << game.l4u02c.e << endl;
	fout << game.l4u03c.x << " " << game.l4u03c.e << endl;
	fout << game.total1.x << " " << game.total1.e << endl;
	fout << game.total2.x << " " << game.total2.e << endl;
	fout << game.total3.x << " " << game.total3.e << endl;
	fout << game.total4.x << " " << game.total4.e << endl;
	fout << unlock << endl;
	fout << a << endl;
	fout.close();
}
void loadgame()
{
	ifstream fin(splace);
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
		int xx1, xx2, xx3;
		fin >> xx1;
		fin >> xx2;
		fin >> xx3;
		game.ptpcnt = xx1;
		game.s1pcnt = xx2;
		game.s2pcnt = xx3;
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
		int xx1, xx2, xx3;
		fin >> xx1;
		fin >> xx2;
		fin >> xx3;
		game.ptpcnt = xx1;
		game.s1pcnt = xx2;
		game.s2pcnt = xx3;
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
		int xx1, xx2, xx3;
		fin >> xx1;
		fin >> xx2;
		fin >> xx3;
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
	if (x == "v1.1.1" || x == "v1.1.2" || x == "v1.1.3")
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
	if (x == "v1.2.0")
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
		fin >> game.eu01ct;
		fin >> game.eu02ct;
		fin >> game.eu03ct;
		fin >> game.timetime;
		fin >> game.l4time;
		fin >> game.l4point;
		fin >> game.l4mul;
		fin >> game.l4u01c;
		fin >> game.l4u02c;
		fin >> game.l4u03c;
		fin >> unlock;
		fin >> a;
	}
	if (x == "v1.2.1" || x == "v1.2.2" || x == "v1.2.3")
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
		fin >> game.eu01ct;
		fin >> game.eu02ct;
		fin >> game.eu03ct;
		fin >> game.timetime;
		fin >> game.l4time;
		fin >> game.l4point;
		fin >> game.l4mul;
		fin >> game.l4u01c;
		fin >> game.l4u02c;
		fin >> game.l4u03c;
		fin >> game.total1;
		fin >> game.total2;
		fin >> game.total3;
		fin >> game.total4;		
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
		return '\0';
	}
}
void printscr(int x)
{
	system("cls");
	cout << "============================" << endl;
	if (time(NULL) > prett + 4)
	{
		nowt = tips[rand() % tips.size()];
		prett = time(NULL);
	}
	cout << nowt << endl;
	cout << "============================" << endl;
	if (x == 1)
	{
		if (game.point < lBI_Infinity)
		{
			cout << "你有 " << game.point << " * Layer 0。" << endl;
			cout << ")` Layer 0 + " << game.ptplus << endl;
			cout << ")1 每次按键增加 Layer 0 + " << game.multi << " 价格：" << pow(lBI(1.05), game.ptpcnt) << " 当前： " << game.ptplus << endl;
			cout << ")2 每秒增加 Layer 0 + " << game.multi << " 价格：" << pow(lBI(1.1), game.s1pcnt) * 10 << " 当前： " << game.s1plus << endl;
			cout << ")3 每秒增加每秒增加 Layer 0 + " << game.multi << " 价格：" << pow(lBI(1.2), game.s2pcnt) * 100 << " 当前： " << game.s2plus << endl;
			cout << ")4 重置升级和 Layer 0，但将 Layer 0 乘数 * " << pow(max(lBI({1, 0}), game.point / game.maxpoint), game.rl0mul) << " 当前： " << game.multi << endl;
		}                                                                  
		else                                                             
		{                                                                    
			cout << "你拥有的 Layer 0 太多了。" << endl;
			cout << ")1 将 Layer 0 转换为 " << game.ipmul << " * Layer 1" << endl;
		}
	}
	if (x == 2)
	{
		if (game.ipoint < lBI_Infinity)
		{
			cout << "你有 " << game.ipoint << " * Layer 1。" << endl;
			cout << ")1 Layer 1 乘数 * 2 价格： " << pow(lBI(2), game.imucnt + 1) << " 当前： " << game.ipmul << endl;
			cout << ")2 改进 Layer 0 乘数公式为 " << "(当前乘数 * 当前 Layer 0 / 上次重置最大获取 Layer 0) ^ " << game.rl0mul + 1 << " 价格：" << pow(game.rl0mul, lBI(2)) << " 当前： (当前乘数 * 当前 Layer 0 / 上次重置最大获取 Layer 0) ^ " << game.rl0mul << endl;
			cout << ")3 初始时每个 Layer 0 升级都升级了 " << game.l0supd + 10 << " 次 价格：" << pow(lBI(1.5), game.su0cnt) * 10 << " 当前： " << game.l0supd << endl;
		}
		else
		{
			cout << "你拥有的 Layer 1 太多了。" << endl;                                                            
			cout << ")1 将 Layer 1 转换为 " << game.epmul << " * Layer 2" << endl;
		}
	}
	if (x == 3)
	{
		if (game.epoint < lBI_Infinity)
		{
			cout << "你有 " << game.epoint << " * Layer 2。" << endl;
			cout << ")1 Layer 2 乘数 * 3 价格： " << pow(lBI(2.5), game.eu01ct) << " 当前： " << game.epmul << endl;
			cout << ")2 时间流速 * 2 价格： " << pow(lBI(3), game.eu02ct) * 10 << " 当前： " << game.timetime << endl;
			cout << ")3 Layer 0 乘数初始为 " << pow(game.eu03ct, lBI(3)) << " 价格： " << pow(game.eu03ct, lBI(1.5)) * 100 << " 当前： " << pow(game.eu03ct - 1, lBI(3)) << endl;
		}
		else
		{
			cout << "你拥有的 Layer 2 太多了。" << endl;                                                            
			cout << ")1 将 Layer 2 转换为 " << game.l4mul << " * Layer 3" << endl;
		}
	}
	if (x == 4)
	{
		if (game.l4point < lBI_Infinity)
		{
			cout << "你有 " << game.epoint << " * Layer 3。" << endl;
			cout << ")1 Layer 3 乘数变为 " << pow(lBI(3.5), game.l4u01c) << " 价格： " << pow(game.l4u01c, lBI(3.5)) << " 当前： " << game.l4mul << endl;
			cout << ")2 Layer 0-3 初始有 " << pow(lBI(4), game.l4u02c) - 1 << " 个 价格： " << pow(game.l4u02c, lBI(4)) * 5 << " 当前： " << pow(lBI(4), game.l4u02c - 1) - 1 << endl;
			cout << ")3 Layer 1-3 乘数初始为 " << pow(game.l4u03c, game.l4u03c) << " 价格： " << pow(lBI(10), game.l4u03c + 2) << " 当前： " << pow(game.l4u03c - 1, game.l4u03c - 1) << endl;
		}
		else
		{
			cout << "你拥有的 Layer 3 太多了。" << endl;                                                            
			cout << ")1 将 Layer 3 转换为 " << 1 << " * Layer 4" << endl;
		}
	}
	if (x == 5)
	{
		cout << "你已通关游戏！" << endl;
		cout << ")1 等待作者更新...... " << endl;
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
	cout << "你在本次 Layer 0 中获得了 " << game.total1 << " * Layer 0。" << endl;
	if (unlock >= 2)
	{
		cout << "你在本次 Layer 1 中重置了 " << game.itimes << " 次 Layer 0。" << endl;
		cout << "你在本次 Layer 1 中获得了 " << game.total2 << " * Layer 1。" << endl;
	}
	if (unlock >= 3)
	{
		cout << "你在本次 Layer 2 中重置了 " << game.etimes << " 次 Layer 1。" << endl;
		cout << "你在本次 Layer 2 中获得了 " << game.total3 << " * Layer 2。" << endl;
	}
	if (unlock >= 4)
	{
		cout << "你在本次 Layer 3 中重置了 " << game.l4time << " 次 Layer 2。" << endl;
		cout << "你在本次 Layer 3 中获得了 " << game.total4 << " * Layer 3。" << endl;
	}
}
void update(char t, lBI gtick)
{
	game.gtime += 1.0 / gtick * game.timetime;
	game.rtime = time(NULL) - game.stime;
	game.s1plus += game.s2plus / gtick * game.timetime;
	game.point += game.s1plus / gtick * game.timetime;
	game.total1 += game.s1plus / gtick * game.timetime;
	if (t == '`' && game.point < lBI_Infinity)
	{
		game.point += game.ptplus;
		game.total1 += game.ptplus;
	}
	if (a == 1)
	{
		if (t == '1' && game.point >= lBI_Infinity)
		{
			layerreset(0);
		}
		else if (t == '4' && game.point < lBI_Infinity)
		{
			layerreset(-1);
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
		if (t == '1' && game.ipoint >= lBI_Infinity)
		{
			layerreset(1);
		}
		else
		{
			if ('1' <= t && t <= '3')
			{
				buy(1, t - '0');
			}
		}
	}	
	if (a == 3)
	{
		if (t == '1' && game.epoint >= lBI_Infinity)
		{
			layerreset(2);
		}
		else
		{
			if ('1' <= t && t <= '3')
			{
				buy(2, t - '0');
			}
		}
	}	
	if (a == 4)
	{
		if (t == '1' && game.l4point >= lBI_Infinity)
		{
			layerreset(3);
		}
		else
		{
			if ('1' <= t && t <= '3')
			{
				buy(3, t - '0');
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
		if (loadTick >= lxsj)
		{
			for (int i = 1; i <= lxsj; i ++)
			{
				update('\0', 1);
				cout << "============================" << endl;
				cout << "计算离线时间中...... " << double(i) / lxsj * 100 << "%" << endl;
			}
		}
		else
		{
			for (int i = 1; i <= loadTick; i ++)
			{
				update('\0', loadTick / lxsj);
				cout << "============================" << endl;
				cout << "计算离线时间中...... " << double(i) / loadTick * 100 << "%" << endl;
			}
		}
	}
	while (1)
	{
		Sleep(1000 / Tick);
		update(_lgetch(), Tick);
		savegame();
	}
}