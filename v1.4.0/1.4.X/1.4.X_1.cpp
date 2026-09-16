#include <ctime>
#include <cstdio>
#include <cmath>
#if defined(_WIN32) // Windows
#include <conio.h>
#include <windows.h>
#else // Linux
#include <thread>
#include <chrono>
inline void Sleep(double ms)
{
	this_thread::sleep_for(chrono::milliseconds(ms));
}
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
int _getch() 
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
bool _kbhit() 
{
    struct termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    struct termios newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF) 
	{
        ungetc(ch, stdin);
        return true;
    }
    return false;
}
#endif
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "lbi.h" //
#define Tick 50
#define loadTick 1000
#define Version "1.4.X_1"
// #define DEV_VERSION
#define splace "save1.loong"
#define endl '\n'
#define LAYER4MUL pow(pow(log(log(pow(game.l5d0, game.l5dr1 + lBI(1)) + lBI(1)) + lBI(1)), log(log(pow(game.l5d0, game.l5dr1 + lBI(1)) + lBI(1)) + lBI(1))), lBI(0.75))
using namespace loong;
using namespace std;
string tonews(string a);
void update(char t, lBI gtick);
void buy(int layer, int update);
void printscr(int k, int x);
char _lgetch();
void loadgame(string places);
void savegame(string filep);
int a = 1;
int page = 1;
int unlock = 1;
bool isexit = 0;
vector<int> achs(13);
vector<int> cha(5);
vector<int> phq(5);
int now_cha = 0;
lBI cha_sta_tim = 0;
vector<string> tips = {
	    "这是第一条新闻",
	    // "So I've pondered this question for a long time. Antimatter Dimensions... what does it mean? I mean it's a game, that's clear. You buy the first dimension, and it gives you antimatter, and the second dimension provides more first dimensions and so on... But what does it mean? It can't just be a game, it seems too plain for that. The developer must have made it as a metaphor. I was doing my weekly ritual of using the fingernail clipper to cut my pubic hair, when finally the realization came to me. The dimensions are just thinly veiled misspellings of the word 'depression'. Regular matter are the cruel and negative thoughts that add to and fuel depression, while antimatter is the positive thoughts and good friends that dispel it. You start off with something simple, and it fights almost imperceptibly against the depression, but as you keep going the fight builds. But it never seems to fix everything. The depression seems like it could go on to infinity. So you keep going. But eventually, you figure out, depression isn't infinite. It's just very very large. But your 'dimensions' eventually, with enough work, make enough 'antimatter' to usurp that seeming infinity of depression. Then the possibilities are endless. You are actually happy for once, and your happiness grows exponentially as you go beyond and seemingly 'break' the 'infinity' of depression. And you go on until that 'infinity' seems tiny in comparison to the happiness you've managed to achieve in your life, where if you reset you get over that infinity in less than the blink of an eye. If you want to know what the multiple layers of prestige are...'Dimensional Shifts' are getting new things and methods to give you happiness. 'Dimension Boosts' are upgrading the things and methods. Examples would be getting a new car being a 'Dimensional Shift' and trading that car in for a new one would be a 'Dimension Boost'. 'Eternities' are major tragedies such as a loved one dying. That lapse brings you straight back to the beginning, with seemingly no hope of return. But with time, you grow back stronger and happier than ever before. 'Dimensional Sacrifice' is moving away. You have to give up a lot of the things you had that made you happy, but there is new opportunity in where you move to. And that new opportunity gives you more happiness than you ever had. 'Tickspeed' is how easy it is to make you happy, and 'Time Dimensions' make it even easier to be happy. Antimatter Dimensions is a metaphor for a depressed man's successful battle against his illness.",
		// "《原神》是由米哈游自主研发的一款全新开放世界冒险游戏。游戏发生在一个被称作“提瓦特”的幻想世界，在这里，被神选中的人将被授予“神之眼”，导引元素之力。你将扮演一位名为“旅行者”的神秘角色，在自由的旅行中邂逅性格各异、能力独特的同伴们，和他们一起击败强敌，找回失散的亲人--同时，逐步发掘“原神”的真相。",
		// "唔嗯……杂鱼暑假又短又没用，这么点长度，根本满足不了人家嘛~你就那么想看到我被长长的学期给凌辱到神志不清，眼睛转圈圈，只会呜呜咽咽的样子，然后自己一个人躲在角落偷偷兴奋？哇 真是下流死了，你居然会对这种画面兴奋，真搞不懂你是有什么特殊癖好，总之下次给我有点改变啊混蛋",
	    // "齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦  哦哦 哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦哦 齁哦哦哦",	
		// 注：已在 1.4.X 中修复
		// 上行新闻有 bug
		// 注：已在 1.4.X 中修复
		// "噢噢床噢好舒服被子舒好服枕头也好舒哦服哦哪里都好舒唔服唔唔唔唔舒好服好舒服好舒去服了去了去齁了齁齁哦哦哦哦哦齁!!;   不行噢噢身噢体最敏的感地方都被被子盖覆到了能楚清的感到受皮肤一每寸都被顺的滑丝绸和花棉内填给侵犯了呜嗯  明明不应这该样的，明明应该离开被去子上学的，但体身已经无法离开被一子寸了哦齁噢噢噢哦  去了，要进梦去境了嗯嗯嗯 ",
		// 没错，这行也有
		// upd 26/7/23：remove “也”.
		// 注：已在 1.4.X 中修复
		// 尽管bug已被修复，但 Loong_727384 还是决定把这行新闻注释掉。
		// "哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦",
		// "哟 齁齁齁齁齁齁齁齁齁齁齁",
		// "-享受唐氏生活，成就垃圾人生-",
		// "请不要把pjsk（世界计划）叫作：屁交爽哭 喷精射哭 喷精爽快 屁精声控 喷精时刻",
		// 作者官方吐槽，到现在还适用
		// "上条新闻咋那么老长",
		// 现在不适用了
		"我编新闻是因为不想让玩家和作者无聊，而不是让这个游戏变成 18+。",
		"本游戏使用了loong-big-integer中的lbi.h。",
		"1,000,000,006+1=0",
		"998,244,352+1=0",
		"9,007,199,254,740,993-9,007,199,254,740,992=0",
        "北冥有鱼，其名为鲲。鲲之大，long long存不下。",
        "e9e15年增量一场空，不小心丢档见祖宗",
        "超光速粒子会产生T    i    m    e",
        "import turtle;",
        "井include《iosteam》",
        "uisng 那么space 实体店；",
        "interesting mian（）{",
        "print 》》 “Hellowordl” 》》 huanhang",
        "return o}",
        "RBN,RBNP,RBNN*,RBNN,RBNZ,RBNQ,RBNR,RBNC",
        "126,127,-128",
        "254,255,0",
        "32766,32767,-32768",
        "65534,65535,0",
        "2147483646,2147483647,-2147483648",
        "4294967294,4294967295,0",
        "'BREAKING' NEWS : 这是第2^1024+1条新闻。新闻终于不用再强制大坍缩了!",
        "import bits/stdpython.h",
        "新闻被重复播放不叫新闻，叫旧闻（",
        "新款同伴符文：+1.7976e308%幸福。耶！",
        // "此版本（$v）中，本游戏共有$s条不同的新闻（尽管大（quan）多（dou）数（shi）来自zlyxj的游戏）。【更新：现在大多数新闻来自$m】",
        "进入Teresa的时候不要忘记写：freopen(AD1,\"w\",\"teresa.out\")",
        "/*看不见我*/",
        "break_quantum.js支持{10,10,10,10}的数字。break_ghost.js支持{10,10[10]10}的数字。",
        "科技这么发达了吗，都有K65路公交车了，比葛立恒数还大",
        "您知道吗？新闻里可能会有随地大小刀",
        "1, 1, 2, 3, 5, 8, 13, 21...",
        "2, 1, 3, 4, 7, 11, 18, 29...",
        "1, 1, 2, 5, 14, 42, 132, 429...",
    	"老婆饼里没有老婆，佛跳墙里没有佛，所以巴尔泽布没有__ (2分)",
    	"6, 28, 496, 8128, ________ (3.3550336分)",
    	"快排已死，STL当立，岁在11，OI大吉",
    	"ST表是啥，我只知道线段树大法好",
    	"十年OI一场空，不开long long见祖宗，开long long也见祖宗",
    	"提瓦特初代神：温迪，钟离，雷电真，后面是谁来着",
    	"是的，182376只是一个普通的自然数。",
    	"是的，33550336只是一个普通的完美数。",    	
    	"我曾遭到 pi/60 rad 背叛",
    	"如何区分温迪和巴巴托斯？",
    	"你们好啊，我是Farmer John，我要开始放牛了，害怕的OIer已经划走了",
    	"你们好啊，我是/XS-X/，我要开始delete终点了，害怕的adofai玩家们已经划走了",
    	"你们好啊，我是\"T5-X\"，我要开始替换魔改了，害怕的curses已经划走了",
    	"两条新闻黏一起了，说明 Loong_727384 粗心大意忘加逗号了",
    	"nowt = tips[rand() % tips.size()];",
    	"你玩了$t秒，该休息一下了",
    	"玩完 agotl 后，感觉 RBNR 的平衡算好的了",
    	"如果你能看到这条新闻，你就能看到这条新闻。",
    	// "Loong_727384 并不玩世界计划。如果你在新闻中看到与pjsk有关的新闻，请联系 $m。",
    	"Loong_727384 并不是不玩 Doki Doki Literature Club。如果你在新闻中看到与 DDLC 有关的新闻，请不用联系 C_A_zhi_L。",
    	"Loong_727384 并不玩蔚蓝档案。如果你在新闻中看到与蔚蓝档案有关的新闻，请联系 Yangsy56302……\n不对，Yangsy56302 好像不玩蔚蓝档案",
    	"727384 = 483727 + reverse!",
    	"2.0.0 即将来临！",
    	"5 年后更新！",
    	"std::string curses",
    	"Just Monika.",
    	"为什么会有 1.4.X ？",
    	// "待办：在 2.0.0 之前把这条新闻注释掉",
    	"我要在这里塞一个 U+FFFD 把游戏搞崩溃",
    	"O(log n) ≈ lOong",
    	"我计划做到 Layer 5，然后打破无限",
    	"f(x) += 1",
    	"恭喜！",
    	"始源-频谱-增幅-增幅-联结",
    	"0mn1516h7",    
		"Loong_727384 想不出更多的新闻了，怎么办",
		"来哦哦那个——727384",
		"找不同 （$b 与  ）：              $b     ",
		"ψ(Ω^Ω^Ω^Ω^Ω^...)",
		"这是最后一条新闻"
};
//vector<string> tips = {"是的，在 1.4.X 中只有这一条新闻。"};
string nowt = "点击输入新闻";
int prett = time(NULL);
struct T
{
	lBI point = 0, ptplus = 1, multi = 1, ipmul = 1, maxpoint = 10000;
	lBI s1plus = 0, s2plus = 0;
	lBI ipoint = 0;
	lBI layer1a = 0, bl1auc = 0;
	int itimes = 0, etimes = 0, l4time = 0, l5time = 0;
	lBI ptpcnt = 0, s1pcnt = 0, s2pcnt = 0;
	lBI rl0mul = 1, l0supd;
	lBI imucnt, su0cnt;
	lBI epmul = 1, epoint;
	lBI eu01ct = 0, eu02ct = 0, eu03ct = 2, timetime = 1;
	lBI l4point, l4mul = 1, l4u01c = 1, l4u02c = 1, l4u03c = 2;
	lBI total1, total2, total3, total4;
	lBI dice1c, dice2c, dice3c, dresult = 1;
	lBI pointcc = 0;
	bool l3zip = 0;
	lBI l3zipm = 0;
	lBI l5point, l5d0, l5d1, l5d2, l5d3, l5d4;
	lBI total5, l5d0c, l5d1c, l5d2c, l5d3c, l5d4c;
	lBI l5dr1, l5dr2;
	bool l5dr3, l5dr4;
	bool autor = 0;
	int rtime;
	int stime;
	lBI gtime;
	bool break_infinity;
} game;
string tonews(string a)
{
	string ans;
	for (int i = 0; i < a.length(); i ++)
	{
		if (a[i] == '$' && i + 1 < a.length())
		{
			if (a[i + 1] == 'v')
			{
				ans += Version;
			}			
			if (a[i + 1] == 's')
			{
				ans += to_string(tips.size());
			}
			if (a[i + 1] == 't')
			{
				ans += to_string(time(NULL) - game.stime);
			}			
			if (a[i + 1] == 'm')
			{
				ans += "<del>猫猫树上长毛毛</del><del>沐木白UwU</del><del>边拉屎边唱歌屎分子跑嗓子眼里去</del><del>加好友免费领裤衩子</del><del>我的世界大仙</del>不好我的投币键呢";
			}
			if (a[i + 1] == 'b')
			{
				//ans += ' '; // Non-Breaking Space
				ans += "\xa1\xa0";
			}
			if (a[i + 1] == '$')
			{
				ans += '$';
			}
			if (a[i + 1] == 'l')
			{
				ans += '\x03';
			}
			i ++;
		}
		else
		{
			ans += a[i];
		}
	}
	return ans;
}
void buy(int layer, int update)
{
	if (layer == 0)
	{
		if (update == 1 && game.point >= pow(lBI(1.05), game.ptpcnt) && now_cha != 2)
		{
			if (now_cha == 3)
			{
				game.ptplus += 1;
			}
			else
			{
				game.ptplus += game.multi;
			}
			if (!cha[2])
			{
				game.point -= pow(lBI(1.05), game.ptpcnt);
			} 
			game.ptpcnt ++;
		}
		if (update == 2 && game.point >= pow(lBI(1.1), game.s1pcnt) * 10)
		{
			if (now_cha == 3)
			{
				game.s1plus += 1;
			}
			else
			{
				game.s1plus += game.multi;
			}			
			if (!cha[2])
			{
				game.point -= pow(lBI(1.1), game.s1pcnt) * 10;
			}
			game.s1pcnt ++;
		}
		if (update == 3 && game.point >= pow(lBI(1.2), game.s2pcnt) * 100)
		{
			if (now_cha == 3)
			{
				game.s2plus += 1;
			}
			else
			{
				game.s2plus += game.multi;
			}
			if (!cha[2])
			{
				game.point -= pow(lBI(1.2), game.s2pcnt) * 100;
			}
			game.s2pcnt ++;
		}
	}
	if (layer == 1)
	{
		if (update == 1 && game.ipoint >= pow(lBI(2), game.imucnt))
		{
			game.ipmul *= 2;
			if (!cha[2])
			{
				game.ipoint -= pow(lBI(2), game.imucnt);
			}
			game.imucnt ++;
		}
		if (update == 2 && game.ipoint >= pow(game.rl0mul, lBI(2)))
		{
			if (!cha[2])
			{
				game.ipoint -= pow(game.rl0mul, lBI(2));
			}
			game.rl0mul ++;
		}
		if (update == 3 && game.ipoint >= pow(lBI(1.5), game.su0cnt) * 10)
		{
			game.l0supd += 10;
			if (!cha[2])
			{
				game.ipoint -= pow(lBI(1.5), game.su0cnt) * 10;
			}
			game.su0cnt ++;
		}
		if (update == 4 && game.ipoint >= lBI(100000) && game.autor == 0)
		{
			if (!cha[2])
			{
				game.ipoint -= lBI(100000);
			}
			game.autor = 1;
		}
	}
	if (layer == 2)
	{
		if (update == 1 && game.epoint >= pow(lBI(2.5), game.eu01ct))
		{
			game.epmul *= 3;
			game.epoint -= pow(lBI(2.5), game.eu01ct);
			game.eu01ct ++;
		}
		if (update == 2 && game.epoint >= pow(lBI(3), game.eu02ct) * 10 && (!(now_cha == 5 || (phq[0] && !phq[4]))))
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
		if (update == 4 && game.epoint >= pow(game.pointcc + 1, lBI(10)) * 1000)
		{
			game.epoint -= pow(game.pointcc + 1, lBI(10)) * 1000;
			game.pointcc ++;
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
	if (layer == 4)
	{	
		if (update == 1 && game.l5point >= game.l5d1c + lBI(1))
		{
			game.l5point -= game.l5d1c + lBI(1);
			game.l5d1c ++;
			game.l5d1 ++;
		}		
		if (update == 2 && game.l5point >= pow(game.l5d2c + lBI(1), lBI(3)))
		{
			game.l5point -= pow(game.l5d2c + lBI(1), lBI(3));
			game.l5d2c ++;
			game.l5d2 ++;
		}		
		if (update == 3 && game.l5point >= pow(lBI(10), game.l5d3c + lBI(1)))
		{
			game.l5point -= pow(lBI(10), game.l5d3c + lBI(1));
			game.l5d3c ++;
			game.l5d3 ++;
		}	
		if (update == 4 && game.l5point >= pow(lBI(3), lBI(5) * (game.l5d4c + lBI(1))))
		{
			game.l5point -= pow(lBI(3), lBI(5) * (game.l5d4c + lBI(1)));
			game.l5d4c ++;
			game.l5d4 ++;
		}
		if (update == 5 && game.l5d0 >= pow(lBI(3), game.l5dr1))
		{
			game.l5dr1 ++;
		}
		if (update == 6 && game.l5d0 >= pow(lBI(5), game.l5dr2 * lBI(2)))
		{
			game.l5dr2 ++;
		}
		if (update == 7 && game.l5d0 >= lBI(1e20))
		{
			game.l5dr3 = 1;
		}
		if (update == 8 && game.l5d0 >= lBI(1e55))
		{
			game.l5dr4 = 1;
		}
	}
}
void layerreset(int layer)
{
	if (layer == -4)
	{
		game.break_infinity = 1;
		game.point = 0;
		game.multi = 1;
		game.ptplus = 1;
		game.ptpcnt = 0;
		game.s1pcnt = 0;
		game.s2pcnt = 0;
		game.maxpoint = 10000;
		game.s1plus = 0;
		game.s2plus = 0;
		unlock = 10;
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
		game.l4u01c = 1;
		game.l4u02c = 1;
		game.l4u03c = 2;
		game.total1 = 0;
		game.total2 = 0;
		game.total3 = 0;
		game.total4 = 0;
		game.pointcc = 0;
		game.layer1a = 0;
		game.bl1auc = 0;
		game.dice1c = 0;
		game.dice2c = 0;
		game.dresult = 1;
		game.autor = 0;
		game.l3zip = 0;
		game.l3zipm = 0;
		game.gtime = 0;
		a = 1;
		page = 1;
		for (int i = 0; i <= 12; i ++)
		{
			achs[i] = 0;
		}
		for (int i = 0; i <= 4; i ++)
		{
			cha[i] = 0;
		}
		for (int i = 0; i <= 4; i ++)
		{
			phq[i] = 0;
		}
		now_cha = 0;
		cha_sta_tim = 0;
		game.total5 = 0;
		game.l5point = 0;
		game.l5d0 = 0;
		game.l5d1 = 0;
		game.l5d2 = 0;
		game.l5d3 = 0;
		game.l5d4 = 0;		
		game.l5d0c = 0;
		game.l5d1c = 0;
		game.l5d2c = 0;
		game.l5d3c = 0;
		game.l5d4c = 0;
		game.l5dr1 = 0;
		game.l5dr2 = 0;
		game.l5dr3 = 0;
		game.l5dr4 = 0;
		game.l5time = 0;
	}
	if (layer == -3)
	{
		game.point = pow(lBI(4), game.l4u02c - 1) - 1;
		game.multi = pow(game.eu03ct - 1, lBI(3));
		game.ptplus = lBI(1) + game.l0supd;
		game.ptpcnt = game.l0supd;
		game.s1pcnt = game.l0supd;
		game.s2pcnt = game.l0supd;
		game.s1plus = game.l0supd;
		game.s2plus = game.l0supd;
		game.maxpoint = 10000;
		game.total1 = 0;
		cha_sta_tim = 0;
	}
	if (layer == -2)
	{
		game.break_infinity = 0;
		game.point = 0;
		game.multi = 1;
		game.ptplus = 1;
		game.ptpcnt = 0;
		game.s1pcnt = 0;
		game.s2pcnt = 0;
		game.maxpoint = 10000;
		game.s1plus = 0;
		game.s2plus = 0;
		unlock = 1;
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
		game.l4u01c = 1;
		game.l4u02c = 1;
		game.l4u03c = 2;
		game.total1 = 0;
		game.total2 = 0;
		game.total3 = 0;
		game.total4 = 0;
		game.pointcc = 0;
		game.layer1a = 0;
		game.bl1auc = 0;
		game.dice1c = 0;
		game.dice2c = 0;
		game.dresult = 1;
		game.autor = 0;
		game.l3zip = 0;
		game.l3zipm = 0;
		game.gtime = 0;
		game.rtime = 0;
		game.stime = time(NULL);
		a = 1;
		page = 1;
		for (int i = 0; i <= 12; i ++)
		{
			achs[i] = 0;
		}
		for (int i = 0; i <= 4; i ++)
		{
			cha[i] = 0;
		}
		for (int i = 0; i <= 4; i ++)
		{
			phq[i] = 0;
		}
		now_cha = 0;
		cha_sta_tim = 0;
		game.total5 = 0;
		game.l5point = 0;
		game.l5d0 = 0;
		game.l5d1 = 0;
		game.l5d2 = 0;
		game.l5d3 = 0;
		game.l5d4 = 0;		
		game.l5d0c = 0;
		game.l5d1c = 0;
		game.l5d2c = 0;
		game.l5d3c = 0;
		game.l5d4c = 0;
		game.l5dr1 = 0;
		game.l5dr2 = 0;
		game.l5dr3 = 0;
		game.l5dr4 = 0;
		game.l5time = 0;
	}
	if (layer == -1)
	{
		if (achs[2])
		{
			game.multi *= pow(max(lBI(1), game.point / game.maxpoint), game.rl0mul) * log10(lBI(10) + game.point * lBI(0.01));
		}
		else
		{
			game.multi *= pow(max(lBI(1), game.point / game.maxpoint), game.rl0mul);
		}
		if (game.l3zipm >= lBI(1))
		{
			if (now_cha == 3)
			{	
				game.s1plus = max(game.s1plus, game.l0supd);
				game.s2plus = max(game.s2plus, game.l0supd);
				game.ptplus = max(game.ptplus, lBI(1) + game.l0supd);
			}
			else
			{
				game.s1plus = max(game.s1plus, game.multi * game.l0supd);
				game.s2plus = max(game.s2plus, game.multi * game.l0supd);
				game.ptplus = max(game.ptplus, game.multi + game.l0supd * game.multi);
			}
			game.ptpcnt = max(game.ptpcnt, game.l0supd);
			game.s1pcnt = max(game.s1pcnt, game.l0supd);
			game.s2pcnt = max(game.s2pcnt, game.l0supd);
		}
		else
		{
			if (now_cha == 3)
			{	
				game.s1plus = game.s1plus, game.l0supd;
				game.s2plus = game.l0supd;
				game.ptplus = 1 + game.l0supd;
			}
			else
			{
				game.s1plus = game.multi * game.l0supd;
				game.s2plus = game.multi * game.l0supd;
				game.ptplus = game.multi + game.l0supd * game.multi;
			}
			game.ptpcnt = game.l0supd;
			game.s1pcnt = game.l0supd;
			game.s2pcnt = game.l0supd;
		}
		game.maxpoint = max(game.maxpoint, game.point);
		if (cha[0])
		{
			game.point = max(pow(game.point, lBI(0.9)), pow(lBI(4), game.l4u02c - 1) - 1);
		}
		else
		{
			game.point = pow(lBI(4), game.l4u02c - 1) - 1;
		}
	}
	if (layer == 0)
	{
		game.point = pow(lBI(4), game.l4u02c - 1) - 1;
		game.multi = pow(game.eu03ct - 1, lBI(3));
		if (game.l3zipm >= 1)
		{
			game.s1plus = max(game.s1plus, game.l0supd);
			game.s2plus = max(game.s2plus, game.l0supd);
			game.ptplus = max(game.ptplus, lBI(1) + game.l0supd);
			game.ptpcnt = game.l0supd;
			game.s1pcnt = game.l0supd;
			game.s2pcnt = game.l0supd;
		}
		else
		{
			game.ptplus = lBI(1) + game.l0supd;
			game.ptpcnt = game.l0supd;
			game.s1pcnt = game.l0supd;
			game.s2pcnt = game.l0supd;
			game.s1plus = game.l0supd;
			game.s2plus = game.l0supd;
		}
		game.maxpoint = 10000;
		unlock = max(unlock, 2);
		game.itimes ++;
		if (phq[1] && !phq[4])
		{
			if (cha[3])
			{
				game.ipoint += pow(game.ipmul, lBI(1.15));
				game.total2 += pow(game.ipmul, lBI(1.15));
			}
			else
			{
				game.ipoint += game.ipmul;
				game.total2 += game.ipmul;
			}
		}
		else if (phq[3] && !phq[4])
		{
			if (cha[3])
			{
				game.ipoint += pow(pow(game.ipmul, lBI(1.15)), min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.0001) * game.layer1a)));
				game.total2 += pow(pow(game.ipmul, lBI(1.15)), min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.0001) * game.layer1a)));
			}
			else
			{
				game.ipoint += pow(game.ipmul, min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.0001) * game.layer1a)));
				game.total2 += pow(game.ipmul, min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.0001) * game.layer1a)));
			}
		}
		else
		{			
			if (cha[3])
			{
				game.ipoint += pow(pow(game.ipmul, lBI(1.15)), min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.001) * game.layer1a)));
				game.total2 += pow(pow(game.ipmul, lBI(1.15)), min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.001) * game.layer1a)));
			}
			else
			{
				game.ipoint += pow(game.ipmul, min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.001) * game.layer1a)));
				game.total2 += pow(game.ipmul, min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.001) * game.layer1a)));
			}
		}
		game.total1 = 0;
		if (now_cha == 1)
		{
			cha[0] = 1;
		}
		if (now_cha == 2)
		{
			cha[1] = 1;
		}
		if (now_cha == 3)
		{
			cha[2] = 1;
		}
		if (now_cha == 4)
		{
			cha[3] = 1;
			cha_sta_tim = 0;
		}
		if (now_cha == 5 && game.gtime - cha_sta_tim <= lBI(10))
		{
			cha[4] = 1;
			cha_sta_tim = 0;
		}
		game.l3zip = 0;
		now_cha = 0;
	}
	if (layer == 1)
	{
		game.point = pow(lBI(4), game.l4u02c - 1) - 1;
		game.multi = max((game.total3 >= 300? game.multi: (game.total3 >= 30? lBI(333): (game.total3 >= 5? lBI(5): lBI(1)))), pow(game.eu03ct - 1, lBI(3)));
		game.ptplus = (game.l3zipm >= lBI(1)? game.ptplus: lBI(1));
		game.ptpcnt = (game.l3zipm >= lBI(1)? game.ptpcnt: lBI(0));
		game.s1pcnt = (game.l3zipm >= lBI(1)? game.s1pcnt: lBI(0));
		game.s2pcnt = (game.l3zipm >= lBI(1)? game.s2pcnt: lBI(0));
		game.s1plus = (game.l3zipm >= lBI(1)? game.s1plus: lBI(0));
		game.s2plus = (game.l3zipm >= lBI(1)? game.s2plus: lBI(0));
		game.maxpoint = 10000;
		unlock = max(unlock, 3);
		game.itimes = 0;
		game.ipoint = pow(lBI(4), game.l4u02c - 1) - 1;
		game.ipmul = max((game.total3 >= 500? game.ipmul: (game.total3 >= 50? lBI(128): (game.total3 >= 3? lBI(8): lBI(1)))), pow(game.l4u03c - 1, game.l4u03c - 1));
		game.rl0mul = ((game.total3 >= 200 || game.l3zipm >= 10)? game.rl0mul: (game.total3 >= 20? lBI(25): (game.total3 >= 1? lBI(3): lBI(1))));
		game.l0supd = ((game.total3 >= 200 || game.l3zipm >= 10)? game.l0supd: (game.total3 >= 2? lBI(10): lBI(1)));
		game.imucnt = (game.l3zipm >= lBI(10)? game.imucnt: lBI(0));
		game.su0cnt = (game.l3zipm >= lBI(10)? game.su0cnt: lBI(0));
		game.itimes = 0;
		game.etimes ++;
		game.total1 = 0;
		game.total2 = 0;
		if (game.l3zipm >= lBI(1e100))
		{
			if (phq[0])
			{
				game.epoint += pow(pow(lBI(1.05), game.epmul), lBI(1.5));
				game.total3 += pow(pow(lBI(1.05), game.epmul), lBI(1.5));
			}
			else
			{
				game.epoint += pow(game.epmul, lBI(1.5));
				game.total3 += pow(game.epmul, lBI(1.5));
			}
		}

		else
		{
			if (phq[0])
			{
				game.epoint += pow(lBI(1.05), game.epmul);
				game.total3 += pow(lBI(1.05), game.epmul);
			}
			else
			{
				game.epoint += game.epmul;
				game.total3 += game.epmul;
			}
		}
		if (!phq[3] && !(game.l3zipm >= lBI(100)))
		{
			game.layer1a = 0;
			game.bl1auc = 0;
		}
		game.autor = (game.total3 >= 100? game.autor: 0);
		if (game.total3 < 10 && game.l3zipm < lBI(10000))
		{
			for (int i = 0; i <= 4; i ++)
			{
				cha[i] = 0;
			}
		}
		now_cha = 0;
		cha_sta_tim = 0;
	}
	if (layer == 2)
	{
		game.point = pow(lBI(4), game.l4u02c - 1) - 1;
		game.multi = pow(game.eu03ct - 1, lBI(3));
		game.ptplus = (game.l3zipm >= lBI(1)? game.ptplus: lBI(1));
		game.ptpcnt = (game.l3zipm >= lBI(1)? game.ptpcnt: lBI(0));
		game.s1pcnt = (game.l3zipm >= lBI(1)? game.s1pcnt: lBI(0));
		game.s2pcnt = (game.l3zipm >= lBI(1)? game.s2pcnt: lBI(0));
		game.s1plus = (game.l3zipm >= lBI(1)? game.s1plus: lBI(0));
		game.s2plus = (game.l3zipm >= lBI(1)? game.s2plus: lBI(0));
		game.maxpoint = 10000;
		unlock = max(unlock, 4);
		game.itimes = 0;
		game.ipoint = pow(lBI(4), game.l4u02c - 1) - 1;
		game.ipmul = pow(game.l4u03c - 1, game.l4u03c - 1);
		game.rl0mul = (game.l3zipm >= lBI(10)? game.rl0mul: lBI(1));
		game.l0supd = (game.l3zipm >= lBI(10)? game.l3zipm: lBI(0));
		game.imucnt = (game.l3zipm >= lBI(10)? game.l3zipm: lBI(0));
		game.su0cnt = (game.l3zipm >= lBI(10)? game.l3zipm: lBI(0));
		game.itimes = (game.l3zipm >= lBI(10)? game.l3zipm: lBI(0));
		game.etimes = (game.l3zipm >= lBI(10)? game.l3zipm: lBI(0));
		game.epoint = pow(lBI(4), game.l4u02c - 1) - 1;
		game.epmul = pow(game.l4u03c - 1, game.l4u03c - 1);
		game.eu01ct = (game.l3zipm >= lBI(10000)? game.eu01ct: lBI(0));
		game.eu02ct = (game.l3zipm >= lBI(10000)? game.eu02ct: lBI(0));
		game.eu03ct = (game.l3zipm >= lBI(10000)? game.eu03ct: lBI(2));
		game.timetime = (game.l3zipm >= lBI(10000)? game.timetime: lBI(1));
		game.l4time ++;
		game.l4point += game.l4mul * game.dresult * pow(game.dice3c, lBI(100));
		game.total1 = 0;
		game.total2 = 0;
		game.total3 = (game.l3zipm >= lBI(1e10)? game.total3: lBI(0));
		game.total4 += game.l4mul * game.dresult * pow(game.dice3c, lBI(100));
		game.pointcc = 0;
		game.autor = 0;
		game.layer1a = (game.l3zipm >= lBI(100)? game.layer1a: lBI(0));
		game.bl1auc = (game.l3zipm >= lBI(100)? game.bl1auc: lBI(0));
		if (game.l3zipm < lBI(10000))
		{
			for (int i = 0; i <= 4; i ++)
			{
				cha[i] = 0;
			}		
		}
		if (game.l3zipm < lBI(1e10))
		{
			for (int i = 0; i <= 4; i ++)
			{
				phq[i] = 0;
			}
		}
		now_cha = 0;
		cha_sta_tim = 0;
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
		game.l4u01c = 1;
		game.l4u02c = 1;
		game.l4u03c = 2;
		game.total1 = 0;
		game.total2 = 0;
		game.total3 = 0;
		game.total4 = 0;
		game.pointcc = 0;
		game.autor = 0;
		game.layer1a = 0;
		game.bl1auc = 0;
		game.dice1c = 0;
		game.dice2c = 0;
		game.dice3c = 0;
		game.dresult = 1;
		for (int i = 0; i <= 4; i ++)
		{
			cha[i] = 0;
		}
		for (int i = 0; i <= 4; i ++)
		{
			phq[i] = 0;
		}
		now_cha = 0;
		cha_sta_tim = 0;
		game.total5 += LAYER4MUL;
		game.l5point += LAYER4MUL;
		game.l5time ++;
	}	
	if (layer == 4)
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
		unlock = max(unlock, 6);
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
		game.l4u01c = 1;
		game.l4u02c = 1;
		game.l4u03c = 2;
		game.total1 = 0;
		game.total2 = 0;
		game.total3 = 0;
		game.total4 = 0;
		game.pointcc = 0;
		game.autor = 0;
		game.layer1a = 0;
		game.bl1auc = 0;
		game.dice1c = 0;
		game.dice2c = 0;
		game.dice3c = 0;
		game.dresult = 1;
		for (int i = 0; i <= 4; i ++)
		{
			cha[i] = 0;
		}
		for (int i = 0; i <= 4; i ++)
		{
			phq[i] = 0;
		}
		now_cha = 0;
		cha_sta_tim = 0;
		game.total5 = 0;
		game.l5point = 0;
		game.l5d0 = 0;
		game.l5d1 = 0;
		game.l5d2 = 0;
		game.l5d3 = 0;
		game.l5d4 = 0;		
		game.l5d0c = 0;
		game.l5d1c = 0;
		game.l5d2c = 0;
		game.l5d3c = 0;
		game.l5d4c = 0;
		game.l5dr1 = 0;
		game.l5dr2 = 0;
		game.l5dr3 = 0;
		game.l5dr4 = 0;
		game.l5time = 0;
	}
}
void savegame(string filep)
{
	ofstream fout(filep);
	fout << Version << endl;
	fout << game.break_infinity << endl;
	if (game.break_infinity)
	{
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
		fout << game.pointcc.x << " " << game.pointcc.e << endl;
		fout << game.autor << endl;
		fout << game.layer1a.x << " " << game.layer1a.e << endl;
		fout << game.bl1auc.x << " " << game.bl1auc.e << endl;
		fout << game.dice1c.x << " " << game.dice1c.e << endl;
		fout << game.dice2c.x << " " << game.dice2c.e << endl;	
		fout << game.dice3c.x << " " << game.dice3c.e << endl;	
		fout << game.dresult.x << " " << game.dresult.e << endl;
		fout << game.l3zip << endl;
		fout << game.l3zipm.x << " " << game.l3zipm.e << endl;
		fout << game.l5point.x << " " << game.l5point.e << endl;
		fout << game.total5.x << " " << game.total5.e << endl;
		fout << game.l5time << endl;
		fout << game.l5d0.x << " " << game.l5d0.e << endl;
		fout << game.l5d1.x << " " << game.l5d1.e << endl;
		fout << game.l5d2.x << " " << game.l5d2.e << endl;
		fout << game.l5d3.x << " " << game.l5d3.e << endl;
		fout << game.l5d4.x << " " << game.l5d4.e << endl;
		fout << game.l5d0c.x << " " << game.l5d0c.e << endl;
		fout << game.l5d1c.x << " " << game.l5d1c.e << endl;
		fout << game.l5d2c.x << " " << game.l5d2c.e << endl;
		fout << game.l5d3c.x << " " << game.l5d3c.e << endl;
		fout << game.l5d4c.x << " " << game.l5d4c.e << endl;
		fout << game.l5dr1.x << " " << game.l5dr1.e << endl;
		fout << game.l5dr2.x << " " << game.l5dr2.e << endl;
		fout << game.l5dr3 << endl;
		fout << game.l5dr4 << endl;
		for (int i = 0; i <= 12; i ++)
		{
			fout << achs[i] << " ";
		}
		fout << endl;
		for (int i = 0; i <= 4; i ++)
		{
			fout << cha[i] << " ";
		}
		for (int i = 0; i <= 4; i ++)
		{
			fout << phq[i] << " ";
		}
		fout << endl;
		fout << now_cha << endl;
		fout << cha_sta_tim.x << " " << cha_sta_tim.e << endl;
	}
	else
	{
		fout << game.point.x << " " << game.point.e << endl;
		fout << game.stime << endl;
		fout << game.rtime << endl;	
	}
	fout << unlock << endl;
	fout << a << endl;
	fout << page << endl;
	fout.close();
}
void loadgame(string places)
{
	ifstream fin(places);
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
	if (x == "v1.2.4")
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
		fin >> game.pointcc;	
		fin >> unlock;
		fin >> a;
	}
	if (x == "v1.2.5" || x == "v1.2.6") 
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
		fin >> game.pointcc;
		fin >> game.autor;
		fin >> unlock;
		fin >> a;
	}
	if (x == "v1.2.7" || x == "v1.2.8" || x == "v1.2.9") 
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
		fin >> game.pointcc;
		fin >> game.autor;
		fin >> unlock;
		fin >> a;
		fin >> page;
	}
	if (x == "v1.3.0") 
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
		fin >> game.pointcc;
		fin >> game.autor;
		for (int i = 0; i <= 9; i ++)
		{
			fin >> achs[i];
		}
		fin >> unlock;
		fin >> a;
		fin >> page;
	}
	if (x == "v1.4.0")
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
		fin >> game.pointcc;
		fin >> game.autor;
		fin >> game.layer1a;
		fin >> game.bl1auc;
		for (int i = 0; i <= 9; i ++)
		{
			fin >> achs[i];
		}
		for (int i = 0; i <= 4; i ++)
		{
			fin >> cha[i];
		}
		for (int i = 0; i <= 4; i ++)
		{
			fin >> phq[i];
		}
		fin >> now_cha;
		fin >> cha_sta_tim;
		fin >> unlock;
		fin >> a;
		fin >> page;
	}
	if (x == "v1.4.1")
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
		fin >> game.pointcc;
		fin >> game.autor;
		fin >> game.layer1a;
		fin >> game.bl1auc;
		fin >> game.dice1c;
		fin >> game.dice2c;
		for (int i = 0; i <= 9; i ++)
		{
			fin >> achs[i];
		}
		for (int i = 0; i <= 4; i ++)
		{
			fin >> cha[i];
		}
		for (int i = 0; i <= 4; i ++)
		{
			fin >> phq[i];
		}
		fin >> now_cha;
		fin >> cha_sta_tim;
		fin >> unlock;
		fin >> a;
		fin >> page;
	}
	if (x == "v1.4.2" || x == "v1.4.3" || x == "v1.4.4")
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
		fin >> game.pointcc;
		fin >> game.autor;
		fin >> game.layer1a;
		fin >> game.bl1auc;
		fin >> game.dice1c;
		fin >> game.dice2c;
		fin >> game.dresult;
		for (int i = 0; i <= 9; i ++)
		{
			fin >> achs[i];
		}
		for (int i = 0; i <= 4; i ++)
		{
			fin >> cha[i];
		}
		for (int i = 0; i <= 4; i ++)
		{
			fin >> phq[i];
		}
		fin >> now_cha;
		fin >> cha_sta_tim;
		fin >> unlock;
		fin >> a;
		fin >> page;
	}
	if (x == "v1.4.5" || x == "v1.4.6" || x == "v1.4.7" || x == "v1.4.8" || x == "v1.4.9")
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
		fin >> game.pointcc;
		fin >> game.autor;
		fin >> game.layer1a;
		fin >> game.bl1auc;
		fin >> game.dice1c;
		fin >> game.dice2c;
		fin >> game.dice3c;
		fin >> game.dresult;
		for (int i = 0; i <= 9; i ++)
		{
			fin >> achs[i];
		}
		for (int i = 0; i <= 4; i ++)
		{
			fin >> cha[i];
		}
		for (int i = 0; i <= 4; i ++)
		{
			fin >> phq[i];
		}
		fin >> now_cha;
		fin >> cha_sta_tim;
		fin >> unlock;
		fin >> a;
		fin >> page;
	}	
	if (x == "1.4.X" || x == "1.4.X_1")
	{
		fin >> game.break_infinity;
		if (game.break_infinity)
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
			fin >> game.pointcc;
			fin >> game.autor;
			fin >> game.layer1a;
			fin >> game.bl1auc;
			fin >> game.dice1c;
			fin >> game.dice2c;
			fin >> game.dice3c;
			fin >> game.dresult;
			fin >> game.l3zip;
			fin >> game.l3zipm;
			fin >> game.l5point;
			fin >> game.total5;
			fin >> game.l5time;
			fin >> game.l5d0;
			fin >> game.l5d1;
			fin >> game.l5d2;
			fin >> game.l5d3;
			fin >> game.l5d4;
			fin >> game.l5d0c;
			fin >> game.l5d1c;
			fin >> game.l5d2c;
			fin >> game.l5d3c;
			fin >> game.l5d4c;
			fin >> game.l5dr1;
			fin >> game.l5dr2;
			fin >> game.l5dr3;
			fin >> game.l5dr4;
			for (int i = 0; i <= 12; i ++)
			{
				fin >> achs[i];
			}
			for (int i = 0; i <= 4; i ++)
			{
				fin >> cha[i];
			}
			for (int i = 0; i <= 4; i ++)
			{
				fin >> phq[i];
			}
			fin >> now_cha;
			fin >> cha_sta_tim;
		}
		else
		{
			fin >> game.point;
			fin >> game.stime;
			fin >> game.rtime;
		}
		fin >> unlock;
		fin >> a;
		fin >> page;	
	}
	fin.close();
	if (game.stime == 0)
	{
		game.stime = time(NULL);
	}
	else
	{
		long long lxsj = time(NULL) - ((long long)game.stime + game.rtime);
		if (loadTick >= lxsj)
		{
			for (long long i = 1; i <= lxsj; i ++)
			{
				update('\0', 1);
				cout << "============================" << endl;
				cout << "计算离线时间中...... " << double(i) / lxsj * 100 << "%" << endl;
			}
		}
		else
		{
			if (double(loadTick) / lxsj != 0)
			{
				for (long long i = 1; i <= loadTick; i ++)
				{
					update('\0', double(loadTick) / lxsj);
					cout << "============================" << endl;
					cout << "计算离线时间中...... " << double(i) / loadTick * 100 << "%" << endl;
				}
			}
			else
			{
				for (long long i = 1; i <= pow(10, floor(log10(lxsj)) - 8); i ++)
				{
					update('\0', pow(10, floor(log10(lxsj)) - 8) / lxsj);
					cout << "============================" << endl;
					cout << "计算离线时间中...... " << double(i) / pow(10, floor(log10(lxsj)) - 8) * 100 << "%" << endl;
				}
			}
		}
	}
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
void printscr_bi(int k, int x)
{
	#if defined(_WIN32)
	system("cls");
	#else
	system("clear");
	#endif
	#ifdef DEV_VERSION
	cout << "开发版本，不保证最终品质！" << endl;
	#endif
	cout << "============================" << endl;
	if (time(NULL) > prett + 4)
	{
		nowt = tips[rand() % tips.size()];
		prett = time(NULL);
	}
	cout << tonews(nowt) << endl;
	cout << "============================" << endl;
	if (k == 1)
	{
		if (x == 0)
		{
			cout << "========= 统计信息 =========" << endl;
			cout << "你实际玩了" << game.rtime << "秒。" << endl;
		}
		if (x == 1)
		{
			cout << "你有 " << game.point << " * Layer 0。" << endl;                                                                
		}
	}
	if (k == 2)
	{
		if (x == 0)
		{
			cout << "=========== 设置 ===========" << endl;
			cout << ")1 导入存档" << endl;
			cout << ")2 导出存档" << endl;
			cout << ")3 硬重置" << endl;
		}
	}
	if (k == 3)
	{
		if (x == 0)
		{
			cout << "=========== 作者 ===========" << endl;
			cout << "A Game of the Layer " + string(Version) << endl;
			cout << "作者：Loong_727384" << endl;
		}
	}
	cout << "============================" << endl;
	cout << "第 " << page << " 界面，共 " << 3 << " 界面；";
	cout << "第 " << a << " 页，共 " << unlock << " 页" << endl;
	if (k >= 2)
	{
		cout << ")W 上一界面" << endl;
	}
	if (k < 3)
	{
		cout << ")S 下一界面" << endl;
	}
	if (x >= 1)
	{
		cout << ")A 上一页" << endl;
	}
	if (x < unlock)
	{
		cout << ")D 下一页" << endl;
	}
	cout << ")0 退出游戏" << endl;	
}
void printscr(int k, int x)
{
	#if defined(_WIN32)
	system("cls");
	#else
	system("clear");
	#endif
	#ifdef DEV_VERSION
	cout << "开发版本，不保证最终品质！" << endl;
	#endif
	cout << "============================" << endl;
	if (time(NULL) > prett + 4)
	{
		nowt = tips[rand() % tips.size()];
		prett = time(NULL);
	}
	cout << tonews(nowt) << endl;
	cout << "============================" << endl;
	if (now_cha != 0)
	{
		cout << "你正处于 Layer 1 挑战 " << now_cha << " 当中。"  << endl;
		if (now_cha == 4)
		{
			cout << "Layer 1 挑战 4 使 Layer 0 生产 ^ " << pow(lBI(0.99), game.gtime - cha_sta_tim) << " 。" << endl;
		}
		if (now_cha == 5)
		{
			cout << "Layer 1 挑战 5 剩余时间： " << lBI(10) - (game.gtime - cha_sta_tim) << " 秒。" << endl;
		}
		cout << "============================" << endl;
	}
	if (game.l3zip)
	{
		cout << "你正处于 Layer 3 压缩中。" << endl;
		cout << "============================" << endl;
	}
	if (k == 1)
	{
		if (x == 0)
		{
			cout << "========= 统计信息 =========" << endl;
			cout << "你玩了" << game.gtime << "秒。" << endl;
			cout << "你实际玩了" << game.rtime << "秒。" << endl;
			if (game.total1 >= lBI_Infinity)
			{
				cout << "你在本次 Layer 0 中获得了 Infinity * Layer 0。" << endl;
			}
			else
			{
				cout << "你在本次 Layer 0 中获得了 " << game.total1 << " * Layer 0。" << endl;
			}
			if (unlock >= 2)
			{
				cout << "你在本次 Layer 1 中重置了 " << game.itimes << " 次 Layer 0。" << endl;
				if (game.total2 >= lBI_Infinity)
				{
					cout << "你在本次 Layer 1 中获得了 Infinity * Layer 1。" << endl;
				}
				else
				{
					cout << "你在本次 Layer 1 中获得了 " << game.total2 << " * Layer 1。" << endl;
				}
			}
			if (unlock >= 3)
			{
				cout << "你在本次 Layer 2 中重置了 " << game.etimes << " 次 Layer 1。" << endl;
				if (game.total3 >= lBI_Infinity)
				{
					cout << "你在本次 Layer 2 中获得了 Infinity * Layer 2。" << endl;
				}
				else
				{
					cout << "你在本次 Layer 2 中获得了 " << game.total3 << " * Layer 2。" << endl;
				}			
			}
			if (unlock >= 4)
			{
				cout << "你在本次 Layer 3 中重置了 " << game.l4time << " 次 Layer 2。" << endl;
				if (game.total4 >= lBI_Infinity)
				{
					cout << "你在本次 Layer 3 中获得了 Infinity * Layer 3。" << endl;
				}
				else
				{
					cout << "你在本次 Layer 3 中获得了 " << game.total4 << " * Layer 3。" << endl;
				}			
			}			
			if (unlock >= 5)
			{
				cout << "你在本次 Layer 4 中重置了 " << game.l5time << " 次 Layer 3。" << endl;
				if (game.total5 >= lBI_Infinity)
				{
					cout << "你在本次 Layer 4 中获得了 Infinity * Layer 4。" << endl;
				}
				else
				{
					cout << "你在本次 Layer 4 中获得了 " << game.total5 << " * Layer 4。" << endl;
				}	
			}
		}
		if (x == 1)
		{
			if (game.point < lBI_Infinity)
			{
				cout << "你有 " << game.point << " * Layer 0。" << endl;
				if (now_cha == 2)
				{
					cout << ")` Layer 0 点击被禁用（挑战2）" << endl;
				}
				else if (game.total3 >= 10000)
				{
					cout << ")` Layer 0 + " << game.ptplus * game.multi << endl;
				}
				else
				{
					cout << ")` Layer 0 + " << game.ptplus << endl;					
				}
				if (now_cha == 2)
				{
					cout << ")1 Layer 0 升级 1 被禁用（挑战2）" << endl;
				}
				else
				{
					cout << ")1 每次按键增加 Layer 0 + " << game.multi << " 价格：" << pow(lBI(1.05), game.ptpcnt) << " 当前： " << game.ptplus << endl;

				}
				cout << ")2 每秒增加 Layer 0 + " << game.multi << " 价格：" << pow(lBI(1.1), game.s1pcnt) * 10 << " 当前： " << game.s1plus << endl;
				cout << ")3 每秒增加每秒增加 Layer 0 + " << game.multi << " 价格：" << pow(lBI(1.2), game.s2pcnt) * 100 << " 当前： " << game.s2plus << endl;
				if (now_cha == 3)
				{
					cout << ")4 Layer 0 乘数被禁用（挑战3）" << endl;
				}
				else
				{
					if (achs[2])
					{
						cout << ")4 重置升级和 Layer 0，但将 Layer 0 乘数 * " << pow(max(log10(lBI(10) + game.point * lBI(0.01)), game.point / game.maxpoint * log10(lBI(10) + game.point * lBI(0.01))), game.rl0mul) << " 当前： " << game.multi << endl;
					}
					else
					{
						cout << ")4 重置升级和 Layer 0，但将 Layer 0 乘数 * " << pow(max(lBI(1), game.point / game.maxpoint), game.rl0mul) << " 当前： " << game.multi << endl;
					}
				}
			}                                                                  
			else                                                             
			{                                                                    
				cout << "你拥有的 Layer 0 太多了。" << endl;
				if (phq[1] && !phq[4])
				{
					if (cha[3])
					{
						cout << ")1 将 Layer 0 转换为 " << pow(game.ipmul, lBI(1.15)) << " * Layer 1" << endl;
					}
					else
					{
						cout << ")1 将 Layer 0 转换为 " << game.ipmul << " * Layer 1" << endl;
					}
				}
				else if (phq[3] && !phq[4])
				{
					if (cha[3])
					{
						cout << ")1 将 Layer 0 转换为 " << pow(pow(game.ipmul, lBI(1.15)), min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.0001) * game.layer1a))) << " * Layer 1" << endl;
					}
					else
					{
						cout << ")1 将 Layer 0 转换为 " << pow(game.ipmul, min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.0001) * game.layer1a))) << " * Layer 1" << endl;
					}
				}
				else
				{
					if (cha[3])
					{
						cout << ")1 将 Layer 0 转换为 " << pow(pow(game.ipmul, lBI(1.15)), min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.001) * game.layer1a))) << " * Layer 1" << endl;
					}
					else
					{
						cout << ")1 将 Layer 0 转换为 " << pow(game.ipmul, min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.001) * game.layer1a))) << " * Layer 1" << endl;
					}
				}
			}
		}
		if (x == 2)
		{
			if (game.ipoint < lBI_Infinity)
			{
				cout << "你有 " << game.ipoint << " * Layer 1。" << endl;
				cout << ")1 Layer 1 乘数 * 2 价格： " << pow(lBI(2), game.imucnt) << " 当前： " << game.ipmul << endl;
				cout << ")2 改进 Layer 0 乘数公式为 " << "(当前乘数 * 当前 Layer 0 / 上次重置最大获取 Layer 0) ^ " << game.rl0mul + 1 << " 价格：" << pow(game.rl0mul, lBI(2)) << " 当前： (当前乘数 * 当前 Layer 0 / 上次重置最大获取 Layer 0) ^ " << game.rl0mul << endl;
				cout << ")3 初始时每个 Layer 0 升级都升级了 " << game.l0supd + 10 << " 次 价格：" << pow(lBI(1.5), game.su0cnt) * 10 << " 当前： " << game.l0supd << endl;
				if (game.autor)
				{
					if (phq[2] && !phq[4])
					{
						cout << ")4 Layer 0 重置被禁用（平衡器3）" << endl;
					}
					else
					{
						cout << ")4 解锁自动 Layer 0 重置 价格：（已解锁）" << endl;
					}
				}
				else
				{
					if (phq[2] && !phq[4])
					{
						cout << ")4 解锁自动 Layer 0 重置（解锁后将被禁用：平衡器3） 价格：100000" << endl;
					}
					else
					{
						cout << ")4 解锁自动 Layer 0 重置 价格：100000" << endl;
					}
				}
			}
			else
			{
				cout << "你拥有的 Layer 1 太多了。" << endl;          
				if (phq[0])
				{                                          
					cout << ")1 将 Layer 1 转换为 " << pow(game.epmul, lBI(1.05)) << " * Layer 2" << endl;
				}
				else
				{
					cout << ")1 将 Layer 1 转换为 " << game.epmul << " * Layer 2" << endl;
				}
			}
		}
		if (x == 3)
		{
			if (game.epoint < lBI_Infinity)
			{
				cout << "你有 " << game.epoint << " * Layer 2。" << endl;
				cout << ")1 Layer 2 乘数 * 3 价格： " << pow(lBI(2.5), game.eu01ct) << " 当前： " << game.epmul << endl;
				if (now_cha == 5 && (phq[0] && !phq[4]))
				{
					cout << ")2 时间流速恒定为 1（挑战5 & 平衡器1）" << endl;
				}
				else if (now_cha == 5)
				{
					cout << ")2 时间流速恒定为 1（挑战5）" << endl;
				}
				else if (phq[0] && !phq[4])
				{
					cout << ")2 时间流速恒定为 1（平衡器1）" << endl;
				}
				else
				{
					cout << ")2 时间流速 * 2 价格： " << pow(lBI(3), game.eu02ct) * 10 << " 当前： " << game.timetime << endl;
				}
				cout << ")3 Layer 0 乘数初始为 " << pow(game.eu03ct, lBI(3)) << " 价格： " << pow(game.eu03ct, lBI(1.5)) * 100 << " 当前： " << pow(game.eu03ct - 1, lBI(3)) << endl;
				cout << ")4 每秒额外获得 Layer 0 * " << pow(lBI(15), game.pointcc + 1) - lBI(1) << " 价格： " << pow(game.pointcc, lBI(10)) * 100 << " 当前： " << pow(lBI(15), game.pointcc) - lBI(1) << endl;
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
				cout << "你有 " << game.l4point << " * Layer 3。" << endl;
				cout << ")1 Layer 3 乘数变为 " << pow(lBI(3.5), game.l4u01c) << " 价格： " << pow(game.l4u01c, lBI(3.5)) << " 当前： " << game.l4mul << endl;
				cout << ")2 Layer 0-3 初始有 " << pow(lBI(4), game.l4u02c) - 1 << " 个 价格： " << pow(game.l4u02c, lBI(4)) * 5 << " 当前： " << pow(lBI(4), game.l4u02c - 1) - 1 << endl;
				cout << ")3 Layer 1-3 乘数初始为 " << pow(game.l4u03c, game.l4u03c) << " 价格： " << pow(lBI(10), game.l4u03c + 2) << " 当前： " << pow(game.l4u03c - 1, game.l4u03c - 1) << endl;
			}
			else
			{
				cout << "你拥有的 Layer 3 太多了。" << endl;                                                            
				cout << ")1 将 Layer 3 转换为 " << LAYER4MUL << " * Layer 4" << endl;
			}
		}
		if (x == 5)
		{
			if (game.l5point < lBI_Infinity)
			{
				cout << "你有 " << game.l5point << " * Layer 4。" << endl;	
			}
			else
			{
				cout << "你拥有的 Layer 4 太多了。" << endl;                                                            
				cout << ")1 将 Layer 4 转换为 1 * Layer 5" << endl;
			}
		}
		if (x == 6)
		{
			cout << "..." << endl;
			cout << "现在就去打破无限吧" << endl;
			cout << "这里没有 Layer 5" << endl;
		}
	}
	if (k == 2)
	{
		if (x == 0)
		{
			cout << "=========== 设置 ===========" << endl;
			cout << ")1 导入存档" << endl;
			cout << ")2 导出存档" << endl;
			cout << ")3 硬重置" << endl;
		}
		if (x == 1)
		{
			cout << "======= Layer 0 成就 =======" << endl;
			cout << ")1 第一个不总是免费的：达到 1 * Layer 0。";
			if (achs[0])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")2 10000 个 Layer 0 有很多：达到 10000 Layer 0。";
			if (achs[1])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")3 GoogoLayer0：达到 10^100 * Layer 0。";
			cout << "奖励：基于 Layer 0 增加 Layer 0 乘数获得。当前：* " << log10(lBI(10) + game.point * lBI(0.01));
			if (achs[2])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")4 溢出：达到 1 * Layer 1。";
			if (achs[3])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")5 挑战达人：完成全部 Layer 1 挑战。";
			cout << "奖励：Layer 1a 加成上限改为 ^ 3。";
			if (achs[4])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")6 自动重置是怎么运作的？：解锁 Layer 1 升级 4。";
			if (achs[5])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")7 溢出^2：达到 1 * Layer 2。";
			if (achs[6])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")8 里程碑达人：完成全部 Layer 2 里程碑。";
			if (achs[7])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")9 溢出^3：达到 1 * Layer 3。";
			if (achs[8])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")10 忠诚的玩家：游玩 30 分钟。";
			if (achs[9])
			{
				cout << "（已完成）";
			}
			cout << endl;			
			cout << ")11 其实是 Layer 3/2：解锁 Layer 1a。";
			if (achs[10])
			{
				cout << "（已完成）";
			}
			cout << endl;			
			cout << ")12 这下爽了：购买平衡器 5。";
			if (achs[11])
			{
				cout << "（已完成）";
			}
			cout << endl;			
			cout << ")13 溢出^4：获得 1 * Layer 4。";
			if (achs[12])
			{
				cout << "（已完成）";
			}
			cout << endl;
			if (unlock >= 6)
			{
				cout << ")99 终局……？：解锁 Layer 5。（已完成）";
			}
			else
			{
				cout << ")99 终局：？？？";
			}
			cout << endl;
		}
		if (x == 2)
		{
			cout << "======= Layer 1 挑战 =======" << endl;
			cout << "挑战目标均为获得 1 * Layer 1。" << endl;
			cout << ")1 Layer 0 生产 ^0.95。";
			cout << "奖励：Layer 0 重置时，Layer 0 ^= 0.9 而不是重置。";
			if (now_cha == 1)
			{
				cout << "（进行中）";
			}
			else if (cha[0])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")2 无法通过点击获得 Layer 0，Layer 0 升级 1 无效且不可购买。";
			cout << "奖励：自动化 Layer 0 升级。";
			if (now_cha == 2)
			{
				cout << "（进行中）";
			}
			else if (cha[1])
			{
				cout << "（已完成）";
			}
			cout << endl;			
			cout << ")3 Layer 0 乘数无效，但 Layer 0 升级 ^1.1。";
			cout << "奖励：购买 Layer 0 和 Layer 1 升级只需达到。";
			if (now_cha == 3)
			{
				cout << "（进行中）";
			}
			else if (cha[2])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")4 Layer 0 生产随时间指数级减弱。";
			cout << "奖励：Layer 0 和 Layer 1 获取 ^1.15。";
			if (now_cha == 4)
			{
				cout << "（进行中）";
			}
			else if (cha[3])
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << ")5 你必须在游戏时间内 10 秒钟完成挑战。";
			if (unlock >= 3)
			{
				cout << "Layer 2 升级 2 已禁用。";
			}
			cout << "奖励：解锁 Layer 1a。";
			if (now_cha == 5)
			{
				cout << "（进行中）";
			}
			else if (cha[4])
			{
				cout << "（已完成）";
			}
			cout << endl;
		}
		if (x == 3)
		{
			cout << "====== Layer 2 里程碑 ======" << endl;
			cout << "累计 1 * Layer 2：Layer 1 升级 2 初始升级了 2 次。";
			if (game.total3 >= 1)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 2 * Layer 2：Layer 1 升级 3 初始升级了 10 次。";
			if (game.total3 >= 3)
			{
				cout << "（已完成）";
			}			
			cout << endl;
			cout << "累计 3 * Layer 2：Layer 1 升级 1 初始升级了 3 次。";
			if (game.total3 >= 3)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 5 * Layer 2：Layer 0 乘数初始为 5。";
			if (game.total3 >= 5)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 10 * Layer 2：保留 Layer 1 挑战。";
			if (game.total3 >= 10)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 20 * Layer 2：Layer 1 升级 2 初始升级了 24 次。";
			if (game.total3 >= 20)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 30 * Layer 2：Layer 0 乘数初始为 333。";
			if (game.total3 >= 30)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 50 * Layer 2：Layer 1 升级 1 初始升级了 7 次。";
			if (game.total3 >= 50)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 100 * Layer 2：保留 Layer 1 升级 4。";
			if (game.total3 >= 100)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 200 * Layer 2：保留 Layer 1 升级 2 和 3。";
			if (game.total3 >= 200)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 300 * Layer 2：保留 Layer 0 乘数。";
			if (game.total3 >= 300)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 500 * Layer 2：保留 Layer 1 升级 1。";
			if (game.total3 >= 500)
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "累计 1000 * Layer 2：Layer 0 点击变得更强。";
			if (game.total3 >= 1000)
			{
				cout << "（已完成）";
			}
			cout << endl;
		}
		if (x == 4)
		{
			cout << "======= Layer 3 压缩 =======" << endl;
			cout << "在 Layer 3 压缩中，Layer 0 生产取对数（最小为 0）。对 Layer 0 的加成依然有效。" << endl;
			cout << ")1 进入/退出 Layer 3 压缩 当前状态：" << game.l3zip << endl;
			if (game.l3zipm >= lBI_Infinity)
			{
				cout << "在 Layer 3 压缩达到的最高 Layer 0 （Infinity）将解锁以下加成：" << endl;
			}
			else
			{
				cout << "在 Layer 3 压缩达到的最高 Layer 0 （" << game.l3zipm << "）将解锁以下加成：" << endl;
			}
			cout << "1 * Layer 0：保留 Layer 0 升级。";
			if (game.l3zipm >= lBI(1))
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "10 * Layer 0：保留 Layer 1 升级。";
			if (game.l3zipm >= lBI(10))
			{
				cout << "（已完成）";
			}			
			cout << endl;
			cout << "100 * Layer 0：保留 Layer 1a。";
			if (game.l3zipm >= lBI(100))
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "10000 * Layer 0：保留 Layer 1 挑战和 Layer 2 升级。";
			if (game.l3zipm >= lBI(10000))
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "1e10 * Layer 0：保留 Layer 2 里程碑和 Layer 2 平衡器。";
			if (game.l3zipm >= lBI(1e10))
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "1e50 * Layer 0：解锁 Layer 3 骰子升级 1 和 2。";
			if (game.l3zipm >= lBI(1e50))
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "1e100 * Layer 0：Layer 3 升级 1 ^1.5。";
			if (game.l3zipm >= lBI(1e100))
			{
				cout << "（已完成）";
			}
			cout << endl;
			cout << "Infinity * Layer 0：解锁 Layer 3 骰子升级 3。";
			if (game.l3zipm >= lBI_Infinity)
			{
				cout << "（已完成）";
			}
			cout << endl;
		}		
		if (x == 5)
		{
			cout << "======= Layer 4 增量 =======" << endl;
			cout << "x = " << game.l5d0 << endl;
			cout << "x 以三层对数增加 Layer 4 获取。（当前：* " << LAYER4MUL << "）" << endl;
			cout << ")1 Δx = " << game.l5d1 << " ( " << game.l5d1c << " ) 价格：" << game.l5d1c + lBI(1) << endl;
			cout << ")2 ΔΔx = " << game.l5d2 << " ( " << game.l5d2c << " ) 价格：" << pow(game.l5d2c + lBI(1), lBI(3)) << endl;
			cout << ")3 ΔΔΔx = " << game.l5d3 << " ( " << game.l5d3c << " ) 价格：" << pow(lBI(10), game.l5d3c + lBI(1)) << endl;
			cout << ")4 ΔΔΔΔx = " << game.l5d4 << " ( " << game.l5d4c << " ) 价格：" << pow(lBI(3), lBI(5) * (game.l5d4c + lBI(1))) << endl;
		}
		if (x == 6)
		{
			cout << "..." << endl;
			cout << "现在就去打破无限吧" << endl;
			cout << "这里没有 Layer 5" << endl;
		}
	}
	if (k == 3)
	{
		if (x == 0)
		{
			cout << "=========== 作者 ===========" << endl;
			cout << "A Game of the Layer " + string(Version) << endl;
			cout << "作者：Loong_727384" << endl;
		}
		if (x == 1)
		{
			cout << "========= 打破无穷 =========" << endl;
			if (unlock < 6)
			{
				cout << ")1 打破无穷 价格：??????" << endl;
			}
			else
			{
				cout << ")1 打破无穷 价格：达到 Layer 5。" << endl;
			}
		}
		if (x == 2)
		{
			cout << "========= Layer 1a =========" << endl;
			if (cha[4])
			{
				if (phq[1] && !phq[4])
				{
					cout << "Layer 1a 被禁用。（平衡器2）";
				}
				else if (phq[3] && !phq[4])
				{
					cout << "你有 " << game.layer1a << " * Layer 1a，给 Layer 1 乘数 ^" << min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.0001) * game.layer1a));
					if (log10(lBI(10) + lBI(0.0001) * game.layer1a) >= (achs[4]? lBI(3): lBI(2)))
					{
						cout << "（被硬上限）";
					}
					cout << "（平衡器4）";
				}
				else
				{
					cout << "你有 " << game.layer1a << " * Layer 1a，给 Layer 1 乘数 ^" << min((achs[4]? lBI(3): lBI(2)), log10(lBI(10) + lBI(0.001) * game.layer1a));
					if (log10(lBI(10) + lBI(0.001) * game.layer1a) >= (achs[4]? lBI(3): lBI(2)))
					{
						cout << "（被硬上限）";
					}
				}
				cout << endl;
				cout << ")1 每秒获得 Layer 1a + 1 价格：100000 当前：" << game.bl1auc << endl;
			}
			else
			{
				cout << "完成 Layer 1 挑战 5 以解锁 Layer 1a。" << endl;
			}
		}
		if (x == 3)
		{
			cout << "======= Layer 2 平衡器 =======" << endl;
			cout << ")1 Layer 2 乘数 ^1.05，但 Layer 2 升级 2 无效 价格：10 当前：" << phq[0] << endl;
			cout << ")2 Layer 2 升级 2 ^1.25，但 Layer 1a 无效 价格：100 当前：" << phq[1] << endl;
			cout << ")3 启动 Layer 1 自动重置，但 Layer 0 自动重置失效 价格：1000 当前：" << phq[2] << endl;
			cout << ")4 重置保留 Layer 1a，但削弱 Layer 1a 加成公式 价格：100000 当前：" << phq[3] << endl;
			cout << ")5 Layer 2 平衡器负面作用消失（平衡器5除外），但所有平衡器都会保持打开状态 价格：1e10 当前：" << phq[4] << endl;
		}
		if (x == 4)
		{
			cout << "======== Layer 3 骰子 ========" << endl;
			if (game.l3zipm >= lBI(1e50))
			{
				cout << "掷骰子的结果将会给 Layer 3 提供乘数。" << endl;
				cout << "结果：" << game.dresult * pow(lBI(100), game.dice3c) << endl;
				cout << ")1 掷一次骰子 价格：" << pow(lBI(10), game.dice1c + lBI(1)) << endl;
				if (game.dice2c + lBI(6) >= lBI(32768))
				{
					cout << ")2 提升最大值 价格：（已达到最大） 当前：32768" << endl;
				}
				else
				{
					cout << ")2 提升最大值 价格：100 当前：" << game.dice2c + lBI(6) << endl;
				}
				if (game.l3zipm >= lBI_Infinity)
				{
					cout << ")3 骰子乘数 * 100 价格：1e10 当前：" << pow(lBI(100), game.dice3c) << endl;
				}
				else
				{
					cout << ")3 （未解锁）" << endl;
				}
			}
			else
			{
				cout << "在 Layer 3 压缩中达到 1e50 * Layer 0 以解锁 Layer 3 骰子。" << endl;
			}
		}
		if (x == 5)
		{
			cout << "======= Layer 4 升级 =======" << endl;
			cout << "Layer 4 升级不消耗 x。" << endl;
			cout << ")f 改进 Layer 4 乘数公式 价格：" << pow(lBI(3), game.l5dr1) << " x 当前：x 在公式内被视为 x ^ " << game.l5dr1 + lBI(1) << endl;
			cout << ")g x 增量增长速度 ^ 1.08（可叠加，加算） 价格：" << pow(lBI(5), game.l5dr2 * lBI(2)) << " x 当前：^" << lBI(1) + lBI(0.08) * game.l5dr2 << endl;
			cout << ")h 每秒获得 100% 重置时获得的 Layer 4 价格：1e20 x 当前：" << game.l5dr3 << endl;
			cout << ")j 累积 Layer 4 加成 x 获取 价格：1e55 x 当前：" << game.l5dr4 << endl;
		}
		if (x == 6)
		{
			cout << "..." << endl;
			cout << "现在就去打破无限吧" << endl;
			cout << "这里没有 Layer 5" << endl;
		}
	}
	cout << "============================" << endl;
	cout << "第 " << page << " 界面，共 " << 3 << " 界面；";
	cout << "第 " << a << " 页，共 " << unlock << " 页" << endl;
	if (k >= 2)
	{
		cout << ")W 上一界面" << endl;
	}
	if (k < 3)
	{
		cout << ")S 下一界面" << endl;
	}
	if (x >= 1)
	{
		cout << ")A 上一页" << endl;
	}
	if (x < unlock)
	{
		cout << ")D 下一页" << endl;
	}
	cout << ")0 退出游戏" << endl;	
}
void update(char t, lBI gtick)
{
	isexit = 0;
	if (!game.break_infinity)
	{
		if (game.l3zip)
		{
			game.l3zipm = max(game.l3zipm, game.point);
		}
		if ((phq[0] && !phq[4]) || now_cha == 5)
		{
			game.gtime += 1.0 / gtick;
			game.layer1a += game.bl1auc / gtick;
		}
		else if (phq[1])
		{
			game.gtime += 1.0 / gtick * pow(game.timetime, lBI(1.25));
			game.layer1a += game.bl1auc / gtick * pow(game.timetime, lBI(1.25));
		}
		else
		{
			game.gtime += 1.0 / gtick * game.timetime;
			game.layer1a += game.bl1auc / gtick * game.timetime;
		}
		game.rtime = time(NULL) - game.stime;
		lBI pointplus = game.s1plus / gtick;
		lBI pointplus2 = (pow(lBI(15), game.pointcc) - lBI(1)) / gtick;
		lBI pointsplusplus = game.s2plus / gtick;
		if (!((phq[0] && !phq[4]) || now_cha == 5))
		{
			if (phq[1])
			{
				pointplus *= pow(game.timetime, lBI(1.25));
				pointplus2 *= pow(game.timetime, lBI(1.25));
				pointsplusplus *= pow(game.timetime, lBI(1.25));
			}
			else
			{
				pointplus *= game.timetime;
				pointplus2 *= game.timetime;
				pointsplusplus *= game.timetime;
			}
		}
		if (now_cha == 1)
		{
			pointplus = pow(pointplus, lBI(0.95));
			pointplus2 = pow(pointplus2, lBI(0.95));
			pointsplusplus = pow(pointsplusplus, lBI(0.95));			
		}
		if (now_cha == 3)
		{
			pointplus = pow(pointplus, lBI(1.1));
			pointplus2 = pow(pointplus2, lBI(1.1));
			pointsplusplus = pow(pointsplusplus, lBI(1.1));			
		}
		if (now_cha == 4)
		{
			pointplus = pow(pointplus, pow(lBI(0.99), game.gtime - cha_sta_tim));
			pointplus2 = pow(pointplus2, pow(lBI(0.99), game.gtime - cha_sta_tim));
			pointsplusplus = pow(pointsplusplus, pow(lBI(0.99), game.gtime - cha_sta_tim));			
		}
		if (cha[4])
		{
			pointplus = pow(pointplus, lBI(1.15));
			pointplus2 = pow(pointplus2, lBI(1.15));
			pointsplusplus = pow(pointsplusplus, lBI(1.15));	
		}
		if (game.l3zip)
		{
			pointplus = max(lBI(0), log10(pointplus));
			pointplus2 = max(lBI(0), log10(pointplus2));
			pointsplusplus = max(lBI(0), log10(pointsplusplus));
		}
		game.point += pointplus + pointplus2;
		game.total1 += pointplus + pointplus2;
		game.s1plus += pointsplusplus;
		if (phq[1])
		{		
			if (game.l5dr4)
			{
				game.l5d3 += pow(pow(game.l5d4 * pow(game.timetime, lBI(1.25)), lBI(1) + lBI(0.08) * game.l5dr2), log10(game.total5) * lBI(3)) / gtick;
				game.l5d2 += pow(pow(game.l5d3 * pow(game.timetime, lBI(1.25)), lBI(1) + lBI(0.08) * game.l5dr2), log10(game.total5) * lBI(3)) / gtick;
				game.l5d1 += pow(pow(game.l5d2 * pow(game.timetime, lBI(1.25)), lBI(1) + lBI(0.08) * game.l5dr2), log10(game.total5) * lBI(3)) / gtick;
				game.l5d0 += pow(pow(game.l5d1 * pow(game.timetime, lBI(1.25)), lBI(1) + lBI(0.08) * game.l5dr2), log10(game.total5) * lBI(3)) / gtick;
			}
			else
			{
				game.l5d3 += pow(game.l5d4 * pow(game.timetime, lBI(1.25)), lBI(1) + lBI(0.08) * game.l5dr2) / gtick;
				game.l5d2 += pow(game.l5d3 * pow(game.timetime, lBI(1.25)), lBI(1) + lBI(0.08) * game.l5dr2) / gtick;
				game.l5d1 += pow(game.l5d2 * pow(game.timetime, lBI(1.25)), lBI(1) + lBI(0.08) * game.l5dr2) / gtick;
				game.l5d0 += pow(game.l5d1 * pow(game.timetime, lBI(1.25)), lBI(1) + lBI(0.08) * game.l5dr2) / gtick;
			}
		}
		else
		{		
			if (game.l5dr4)
			{
				game.l5d3 += pow(pow(game.l5d4 * game.timetime, lBI(1) + lBI(0.08) * game.l5dr2), log10(game.total5) * lBI(3)) / gtick;
				game.l5d2 += pow(pow(game.l5d3 * game.timetime, lBI(1) + lBI(0.08) * game.l5dr2), log10(game.total5) * lBI(3)) / gtick;
				game.l5d1 += pow(pow(game.l5d2 * game.timetime, lBI(1) + lBI(0.08) * game.l5dr2), log10(game.total5) * lBI(3)) / gtick;
				game.l5d0 += pow(pow(game.l5d1 * game.timetime, lBI(1) + lBI(0.08) * game.l5dr2), log10(game.total5) * lBI(3)) / gtick;
			}
			else
			{
				game.l5d3 += pow(game.l5d4 * game.timetime, lBI(1) + lBI(0.08) * game.l5dr2) / gtick;
				game.l5d2 += pow(game.l5d3 * game.timetime, lBI(1) + lBI(0.08) * game.l5dr2) / gtick;
				game.l5d1 += pow(game.l5d2 * game.timetime, lBI(1) + lBI(0.08) * game.l5dr2) / gtick;
				game.l5d0 += pow(game.l5d1 * game.timetime, lBI(1) + lBI(0.08) * game.l5dr2) / gtick;
			}
		}
		if (game.l5dr3)
		{
			game.l5point += LAYER4MUL;
			game.total5 += LAYER4MUL;
		}
		if (game.point >= 1)
		{
			achs[0] = 1;
		}
		if (game.point >= 10000)
		{
			achs[1] = 1;
		}
		if (game.point >= pow(lBI(10), lBI(100)))
		{
			achs[2] = 1;
		}
		if (game.ipoint >= 1)
		{
			achs[3] = 1;
		}
		if (cha[0] && cha[1] && cha[2] && cha[3] && cha[4])
		{
			achs[4] = 1;
		}
		if (game.autor)
		{
			achs[5] = 1;
		}
		if (game.epoint >= 1)
		{
			achs[6] = 1;
		}
		if (game.total3 >= 1000)
		{
			achs[7] = 1;
		}
		if (game.l4point >= 1)
		{
			achs[8] = 1;
		}
		if (game.rtime >= 30 * 60)
		{
			achs[9] = 1;
		}
		if (cha[4])
		{
			achs[10] = 1;
		}
		if (phq[4])
		{
			achs[11] = 1;
		}
		if (game.l5point >= 1)
		{
			achs[12] = 1;
		}
		if (game.ipoint >= lBI_Infinity && phq[2])
		{
			layerreset(1);
		}
		if (game.point >= lBI_Infinity && game.autor && (!phq[2] || phq[4]))
		{
			layerreset(0);
		}
		if (game.point / game.maxpoint > lBI(1) && game.autor && (!phq[2] || phq[4]) && now_cha != 3)
		{
			layerreset(-1);
		}
		if (cha[2] && game.point >= pow(lBI(1.05), game.ptpcnt) && now_cha != 2)
		{
			buy(0, 1);
		}
		if (cha[2] && game.point >= pow(lBI(1.1), game.s1pcnt) * 10 && now_cha != 2)
		{
			buy(0, 2);
		}
		if (cha[2] && game.point >= pow(lBI(1.2), game.s2pcnt) * 100 && now_cha != 2)
		{
			buy(0, 3);
		}
		if (t == '`' && game.point < lBI_Infinity && now_cha != 2)
		{
			if (now_cha == 1)
			{
				if (game.total3 >= 10000)
				{
					game.point += pow(game.ptplus * game.multi, lBI(0.95));
					game.total1 += pow(game.ptplus * game.multi, lBI(0.95));
				}
				else
				{
					game.point += pow(game.ptplus, lBI(0.95));
					game.total1 += pow(game.ptplus, lBI(0.95));
				}
			}
			else if (now_cha == 3)
			{
				if (game.total3 >= 10000)
				{
					game.point += pow(game.ptplus, lBI(1.1));
					game.total1 += pow(game.ptplus, lBI(1.1));
				}
				else
				{
					game.point += pow(game.ptplus, lBI(1.1));
					game.total1 += pow(game.ptplus, lBI(1.1));
				}
			}
			else if (now_cha == 4)
			{
				if (game.total3 >= 10000)
				{
					game.point += pow(game.ptplus * game.multi, pow(lBI(0.99), game.gtime - cha_sta_tim));
					game.total1 += pow(game.ptplus * game.multi, pow(lBI(0.99), game.gtime - cha_sta_tim));
				}
				else
				{
					game.point += pow(game.ptplus, pow(lBI(0.99), game.gtime - cha_sta_tim));
					game.total1 += pow(game.ptplus, pow(lBI(0.99), game.gtime - cha_sta_tim));
				}
			}
			else if (game.l3zip)
			{			
				if (game.total3 >= 10000)
				{
					game.point += max(lBI(0), log10(game.ptplus * game.multi));
					game.total1 += max(lBI(0), log10(game.ptplus * game.multi));
				}
				else
				{
					game.point += max(lBI(0), log10(game.ptplus));
					game.total1 += max(lBI(0), log10(game.ptplus));
				}
			}
			else
			{
				if (game.total3 >= 10000)
				{
					game.point += game.ptplus * game.multi;
					game.total1 += game.ptplus * game.multi;
				}
				else
				{
					game.point += game.ptplus;
					game.total1 += game.ptplus;
				}
			}
		}
		if (page == 1)
		{
			if (a == 0)
			{
			}
			if (a == 1)
			{
				if (t == '1' && game.point >= lBI_Infinity)
				{
					layerreset(0);
				}
				else if (t == '4' && game.point < lBI_Infinity && pow(max(lBI(1), game.point / game.maxpoint), game.rl0mul) > lBI(1) && now_cha != 3)
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
					if ('1' <= t && t <= '4')
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
					if ('1' <= t && t <= '4')
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
			if (a == 5)
			{
				if (t == '1' && game.l5point >= lBI_Infinity)
				{
					layerreset(4);
				}
			}
		}
		if (page == 2)
		{
			if (a == 0)
			{
				if (t == '1')
				{
					#if defined(_WIN32)
					system("cls");
					#else
					system("clear");
					#endif
					string tmp;
					cout << "（注意，导入后将覆盖原存档数据，如需退出，请键入save1.txt）请输入存档位置：";
					cin >> tmp;
					loadgame(tmp);
				}
				if (t == '2')
				{
					#if defined(_WIN32)
					system("cls");
					#else
					system("clear");
					#endif
					string tmp;
					cout << "（如需退出，请键入" + string(splace) + "）请输入导出位置：";
					cin >> tmp;
					savegame(tmp);
				}
				if (t == '3')
				{
					#if defined(_WIN32)
					system("cls");
					#else
					system("clear");
					#endif
					string tmp;
					cout << "你真的要硬重置吗？（yes/no）：";
					cin >> tmp;
					if (tmp == "yes")
					{
						layerreset(-2);
					}
				}
			}
			if (a == 1)
			{
			}
			if (a == 2)
			{
				if (t == '1')
				{
					game.l3zip = 0;
					layerreset(-3);
					if (now_cha == 1)
					{
						now_cha = 0;
					}
					else
					{
						now_cha = 1;
					}
				}
				if (t == '2')
				{
					game.l3zip = 0;
					layerreset(-3);
					if (now_cha == 2)
					{
						now_cha = 0;
					}
					else
					{
						now_cha = 2;
					}
				}
				if (t == '3')
				{
					game.l3zip = 0;
					layerreset(-3);
					if (now_cha == 3)
					{
						now_cha = 0;
					}
					else
					{
						now_cha = 3;
					}
				}			
				if (t == '4')
				{
					game.l3zip = 0;
					layerreset(-3);
					cha_sta_tim = game.gtime;
					if (now_cha == 4)
					{
						now_cha = 0;
					}
					else
					{
						now_cha = 4;
					}
				}			
				if (t == '5')
				{
					game.l3zip = 0;
					layerreset(-3);
					cha_sta_tim = game.gtime;
					if (now_cha == 5)
					{
						now_cha = 0;
					}
					else
					{
						now_cha = 5;
					}
				}
			}
			if (a == 3)
			{
			}
			if (a == 4)
			{
				if (t == '1')
				{
					now_cha = 0;
					game.l3zip = !game.l3zip;
					layerreset(-3);
				}
			}
			if (a == 5)
			{
				if ('1' <= t && t <= '4')
				{
					buy(4, t - '0');
				}	
			}
		}
		if (page == 3)
		{
			if (a == 0)
			{
			}
			if (a == 1)
			{
				if (t == '1' && unlock >= 6)
				{
					layerreset(-4);
				}
			}
			if (a == 2)
			{
				if (t == '1' && game.ipoint >= lBI(100000))
				{
					game.bl1auc += 1;
					game.ipoint -= 100000;
				}
			}
			if (a == 3)
			{
				if (t == '1' && game.epoint >= lBI(10) && phq[4] != 1)
				{
					phq[0] = !phq[0];
					game.epoint -= 10;
				}
				if (t == '2' && game.epoint >= lBI(100) && phq[4] != 1)
				{
					phq[1] = !phq[1];
					game.epoint -= 100;
				}
				if (t == '3' && game.epoint >= lBI(1000) && phq[4] != 1)
				{
					phq[2] = !phq[2];
					game.epoint -= 1000;
				}
				if (t == '4' && game.epoint >= lBI(100000) && phq[4] != 1)
				{
					phq[3] = !phq[3];
					game.epoint -= 100000;
				}
				if (t == '5' && game.epoint >= lBI(1e10) && phq[4] != 1)
				{
					phq[4] = 1;
					phq[0] = 1;
					phq[1] = 1;
					phq[2] = 1;
					phq[3] = 1;
					game.epoint -= 1e10;
				}
			}
			if (a == 4)
			{
				if (t == '1' && game.l4point >= pow(lBI(10), game.dice1c + lBI(1)) && game.l3zipm >= lBI(1e50))
				{
					game.l4point -= pow(lBI(10), game.dice1c + lBI(1));
					game.dice1c ++;
					if (game.dice2c + lBI(6) >= lBI(32768))
					{
						game.dresult = lBI(rand() + 1);
					}
					else
					{
						game.dresult = lBI(rand() % int(game.dice2c + lBI(6)) + 1);
					}
				}
				if (t == '2' && game.l4point >= lBI(100) && game.dice2c + lBI(6) < lBI(32768) && game.l3zipm >= lBI(1e50))
				{
					game.dice2c ++;
					game.l4point -= lBI(100);
				}
				if (t == '3' && game.l4point >= lBI(1e10) && game.l3zipm >= Infinity)
				{
					game.dice3c ++;
					game.l4point -= lBI(1e10);
				}
			}
			if (a == 5)
			{
				if (t == 'f')
				{
					buy(4, 5);
				}
				if (t == 'g')
				{
					buy(4, 6);
				}
				if (t == 'h')
				{
					buy(4, 7);
				}
				if (t == 'j')
				{
					buy(4, 8);
				}
			}
		}
		if (t == 'w')
		{
			if (page >= 2)
			{
				page --;
			}
		}
		if (t == 's')
		{
			if (page < 3)
			{
				page ++;
			}
		}
		if (t == 'a')
		{
			if (a > 0)
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
		if (t == '0')
		{
			isexit = 1;
		}
		printscr(page, a);
	}
	else
	{
		game.rtime = time(NULL) - game.stime;
		if (page == 2)
		{
			if (a == 0)
			{
				if (t == '1')
				{
					#if defined(_WIN32)
					system("cls");
					#else
					system("clear");
					#endif
					string tmp;
					cout << "（注意，导入后将覆盖原存档数据，如需退出，请键入" + string(splace) + "）请输入存档位置：";
					cin >> tmp;
					loadgame(tmp);
				}
				if (t == '2')
				{
					#if defined(_WIN32)
					system("cls");
					#else
					system("clear");
					#endif
					string tmp;
					cout << "（如需退出，请键入" + string(splace) + "）请输入导出位置：";
					cin >> tmp;
					savegame(tmp);
				}
				if (t == '3')
				{
					#if defined(_WIN32)
					system("cls");
					#else
					system("clear");
					#endif
					string tmp;
					cout << "你真的要硬重置吗？（yes/no）：";
					cin >> tmp;
					if (tmp == "yes")
					{
						layerreset(-2);
					}
				}
			}
		}
		if (t == 'w')
		{
			if (page >= 2)
			{
				page --;
			}
		}
		if (t == 's')
		{
			if (page < 3)
			{
				page ++;
			}
		}
		if (t == 'a')
		{
			if (a > 0)
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
		if (t == '0')
		{
			isexit = 1;
		}
		printscr_bi(page, a);
	}
}
int main()
{
	#if defined(_WIN32)
	system("title A Game of the Layer");
	#else
	system("printf \"\e]2;A Game of the Layer\a\"");
	#endif
	srand(time(NULL));
	loadgame(splace);
	while (1)
	{
		Sleep(1000.0 / Tick);
		update(_lgetch(), Tick);
		savegame(splace);
		if (isexit)
		{
			break;
		}
	}
}