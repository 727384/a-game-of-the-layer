#ifndef ibi
#define ibi
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#define lBI_E loong::lBI(M_E)
#define lBI_PI loong::lBI(M_PI)
#define lBI_Infinity loong::pow(loong::lBI(2, 0), loong::lBI(1.024, 3))
#define lBI_Nev_Infinity loong::neg(loong::pow(loong::lBI(2, 0), loong::lBI(1.024, 3)))
#define lBI_True_Infinity loong::lBI(INFINITY, INFINITY)
#define lBI_Nev_True_Infinity loong::lBI(- INFINITY, - INFINITY)
#define Infinity loong::pow(loong::lBI(2, 0), loong::lBI(1.024, 3))
#define Nev_Infinity loong::neg(loong::pow(loong::lBI(2, 0), loong::lBI(1.024, 3)))
#define True_Infinity loong::lBI(INFINITY, INFINITY)
#define Nev_True_Infinity loong::lBI(- INFINITY, - INFINITY)
#define lBI_NAN loong::lBI(NAN, NAN)
#if __cplusplus <= 199711L
#define max(a, b) ((a > b)? (a): (b))
#define min(a, b) ((a > b)? (b): (a))
#endif
#if !(!defined(__STRICT_ANSI__) || defined(_POSIX_C_SOURCE) || defined(_POSIX_SOURCE) || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE) || defined(_USE_MATH_DEFINES))
#define M_E	2.7182818284590452354
#define M_PI 3.14159265358979323846
#endif
namespace loong
{
	struct lBI;
	lBI int_to_lBI(double a = 0);
	lBI str_to_lBI(std::string a = "");
	lBI str_to_lBI(const char* a = NULL);
	lBI lBI_plus(lBI a, lBI b);
	lBI lBI_minus(lBI a, lBI b);
	lBI lBI_multi(lBI a, lBI b);
	lBI lBI_div(lBI a, lBI b);
	lBI lBI_mod(lBI a, lBI b);
	lBI floor(lBI a);
	lBI ceil(lBI a);
	lBI round(lBI a);
	lBI log(lBI a);
	lBI log10(lBI a);
	lBI logx(lBI a, lBI b);
	lBI pow(lBI a, lBI b);
	lBI sqrtx(lBI a, lBI b);
	lBI hypot(lBI a, lBI b);
	lBI sqrt(lBI a);
	lBI exp(lBI a);
	lBI abs(lBI a);
	lBI reci(lBI a);
	lBI neg(lBI a);
	lBI frexp(lBI a, lBI* b);
	lBI ldexp(lBI a, lBI b);
	lBI cos(lBI a);
	lBI sin(lBI a);
	lBI tan(lBI a);
	lBI cosh(lBI a);
	lBI sinh(lBI a);
	lBI tanh(lBI a);
	lBI acos(lBI a);
	lBI asin(lBI a);
	lBI atan(lBI a);
	lBI atan2(lBI a, lBI b);
	bool isnan(lBI a);
	lBI lBI_format(lBI a);
	lBI print_lBI(lBI a, int b, bool c);
	double lBI_to_int(lBI a);
	#if __cplusplus >= 201103L
	std::string lBI_to_str_old(lBI a, int b = 9);
	#endif
    std::string lBI_to_str(lBI a, int b = 9);
    const char* lBI_to_c_str(lBI a, int b = 9);
	std::istream& operator>>(std::istream& is, lBI& p);
	std::ostream& operator<<(std::ostream& os, const lBI& p);
	struct lBI
	{
		double x;
		double e;
		lBI input()
		{
			std::string tmp;
			getline(std::cin, tmp);
			return *this = str_to_lBI(tmp);
		}
		lBI print(int a = 9, bool b = 0)
		{
			if (a == 0)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else
				{
					printf("%lfe%lg", x, e);	
				}
			}
			else if (a == 1)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else
				{
					printf("%lf %lg", x, e);
				}
			}
			else if (a == 2)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else
				{
					printf("%lfx10^%lg", x, e);
				}
			}
			else if (a == 3)
			{				
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else
				{
					printf("%lf*10^%lg", x, e);
				}
			}
			else if (a == 4)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else if (x < 0)
				{
					printf("-e%lg", log10(neg(*this)).to_int());
				}
				else if (x == 0)
				{
					printf("e(-inf)");
				}
				else
				{
					printf("e%lg", log10(*this).to_int());
				}
			}
			else if (a == 5)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else if (x < 0)
				{
					printf("-e%lg", e);
				}
				else
				{
					printf("e%lg", e);
				}
			}
			else if (a == 6)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else if (x == 0)
				{
					printf("e(-e(inf))");
				}
				else if (x < 0)
				{
					if (log10(neg(*this)) > lBI(0, 0))
					{
						printf("-ee%lg", log10(log10(neg(*this))).to_int());
					}
					else if (log10(neg(*this)) == lBI(0, 0))
					{
						printf("-ee(-inf)");
					}
					else
					{
						printf("-e(-e%lg)", log10(neg(log10(neg(*this)))).to_int());
					}
				}
				else
				{
					if (log10(*this) > lBI(0, 0))
					{
						printf("ee%lg", log10(log10(*this)).to_int());
					}
					else if (log10(*this) == lBI(0, 0))
					{
						printf("ee(-inf)");
					}
					else
					{
						printf("e(-e%lg)", log10(neg(log10(*this))).to_int());
					}
				}
			}
			else if (a == 7)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else if (x == 0)
				{
					printf("10^(-10^(inf))");
				}
				else if (x < 0)
				{
					if (log10(neg(*this)) > lBI(0, 0))
					{
						printf("-10^^%lg", log10(log10(neg(*this))).to_int());
					}
					else if (log10(neg(*this)) == lBI(0, 0))
					{
						printf("-10^^(-inf)");
					}
					else
					{
						printf("-10^(-10^%lg)", log10(neg(log10(neg(*this)))).to_int());
					}
				}
				else
				{
					if (log10(*this) > lBI(0, 0))
					{
						printf("10^^%lg", log10(log10(*this)).to_int());
					}
					else if (log10(*this) == lBI(0, 0))
					{
						printf("10^^(-inf)");
					}
					else
					{
						printf("10^(-10^%lg)", log10(neg(log10(*this))).to_int());
					}
				}
			}
			else if (a == 8)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else
				{
					printf("%lg", lBI_to_int(*this));
				}
			}
			else if (a == 9)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else if (std::fabs(e) < 6)
				{
					printf("%lg", lBI_to_int(*this));
				}
				else if (fabs(e) < 1e6)
				{
					printf("%lfe%lg", x, e);
				}
				else 
				{
					if (x < 0)
					{
						printf("-e%lg", log10(neg(*this)).to_int());
					}
					else
					{	
						printf("e%lg", log10(*this).to_int());
					}
				}
			}			
			else if (a == 10)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else if (std::fabs(e) < 6)
				{
					printf("%lg", lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e6)
				{
					printf("%lf*10^%lg", x, e);
				}
				else 
				{
					if (x < 0)
					{
						printf("-10^%lg", log10(neg(*this)).to_int());
					}
					else
					{
						printf("10^%lg", log10(*this).to_int());
					}
				}
			}			
			else if (a == 11)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else if (std::fabs(e) < 6)
				{
					printf("%lg", lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e6)
				{
					printf("%lfx10^%lg", x, e);
				}
				else 
				{
					if (x < 0)
					{
						printf("-10^%lg", log10(neg(*this)).to_int());
					}
					else
					{
						printf("10^%lg", log10(*this).to_int());
					}
				}
			}
			else
			{
				if (std::isnan(x) || std::isnan(e))
				{
					printf("nan");
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					printf("inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					printf("-inf");
				}
				else if (std::fabs(e) < 6)
				{
					printf("%lg", lBI_to_int(*this));
				}
				else if (fabs(e) < 1e6)
				{
					printf("%lfe%lg", x, e);
				}
				else 
				{
					if (x < 0)
					{
						printf("-e%lg", log10(neg(*this)).to_int());
					}
					else
					{	
						printf("e%lg", log10(*this).to_int());
					}
				}
			}		
			if (b)
			{
				printf("\n");
			}
			return *this;
		}
		#if __cplusplus >= 201103L
		std::string to_str_old(int a = 9)
		{
			if (a == 0)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else
				{
					return std::to_string(x) + "e" + std::to_string(e);
				}
			}
			else if (a == 1)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else
				{
					return std::to_string(x) + " " + std::to_string(e);
				}
			}
			else if (a == 2)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else
				{
					return std::to_string(x) + "x10^" + std::to_string(e);
				}
			}
			else if (a == 3)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else
				{			
					return std::to_string(x) + "*10^" + std::to_string(e);
				}
			}
			else if (a == 4)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else if (x < 0)
				{
					return "-e" + std::to_string(log10(neg(*this)).to_int());
				}
				else if (x == 0)
				{
					return "e(-inf)";
				}
				else
				{
					return "e" + std::to_string(log10(*this).to_int());
				}
			}
			else if (a == 5)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else if (x < 0)
				{
					return "-e" + std::to_string(e);
				}
				else
				{
					return "e" + std::to_string(e);
				}
			}
			else if (a == 6)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else if (x == 0)
				{
					return "e(-e(inf))";
				}
				else if (x < 0)
				{
					if (log10(neg(*this)) > lBI(0, 0))
					{
						return "-ee" + std::to_string(log10(log10(neg(*this))).to_int());
					}
					else if (log10(neg(*this)) == lBI(0, 0))
					{
						return "-ee(-inf)";
					}
					else
					{
						return "-e(-e" + std::to_string(log10(neg(log10(neg(*this)))).to_int()) + ")";
					}
				}
				else
				{
					if (log10(*this) > lBI(0, 0))
					{
						return "ee" + std::to_string(log10(log10(*this)).to_int());
					}
					else if (log10(*this) == lBI(0, 0))
					{
						return "ee(-inf)";
					}
					else
					{
						return "e(-e" + std::to_string(log10(neg(log10(*this))).to_int()) + ")";
					}
				}
			}
			else if (a == 7)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else if (x == 0)
				{
					return "10^(-10^(inf))";
				}
				else if (x < 0)
				{
					if (log10(neg(*this)) > lBI(0, 0))
					{
						return "-10^^" + std::to_string(log10(log10(neg(*this))).to_int());
					}
					else if (log10(neg(*this)) == lBI(0, 0))
					{
						return "-10^^(-inf)";
					}
					else
					{
						return "-10^(-10^" + std::to_string(log10(neg(log10(neg(*this)))).to_int()) + ")";
					}
				}
				else
				{
					if (log10(*this) > lBI(0, 0))
					{
						return "10^^" + std::to_string(log10(log10(*this)).to_int());
					}
					else if (log10(*this) == lBI(0, 0))
					{
						return "10^^(-inf)";
					}
					else
					{
						return "10^(-10^" + std::to_string(log10(neg(log10(*this))).to_int()) + ")";
					}
				}
			}
			else if (a == 8)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else
				{
					return std::to_string(lBI_to_int(*this));
				}
			}
			else if (a == 9)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else if (std::fabs(e) < 6)
				{
					return std::to_string(lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e6)
				{
					return std::to_string(x) + "e" + std::to_string(e);
				}
				else 
				{
					return "e" + std::to_string(log10(*this).to_int());
				}
			}
			else if (a == 10)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else if (std::fabs(e) < 6)
				{
					return std::to_string(lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e6)
				{
					return std::to_string(x) + "*10^" + std::to_string(e);
				}
				else 
				{
					return "10^" + std::to_string(log10(*this).to_int());
				}
			}
			else if (a == 11)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else if (std::fabs(e) < 6)
				{
					return std::to_string(lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e6)
				{
					return std::to_string(x) + "x10^" + std::to_string(e);
				}
				else 
				{
					return "10^" + std::to_string(log10(*this).to_int());
				}
			}
			else
			{
				if (std::isnan(x) || std::isnan(e))
				{
					return "nan";
				}				
				else if (x == INFINITY || e == INFINITY)
				{
					return "inf";
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					return "-inf";
				}
				else if (std::fabs(e) < 6)
				{
					return std::to_string(lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e6)
				{
					return std::to_string(x) + "e" + std::to_string(e);
				}
				else 
				{
					return "e" + std::to_string(log10(*this).to_int());
				}
			}
		}
		#endif
        std::string to_str(int a = 9)
		{
            char buff[1024];
			if (a == 0)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else
				{
					sprintf(buff, "%lfe%lg", x, e);	
				}
			}
			else if (a == 1)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else
				{
					sprintf(buff, "%lf %lg", x, e);
				}
			}
			else if (a == 2)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else
				{
					sprintf(buff, "%lfx10^%lg", x, e);
				}
			}
			else if (a == 3)
			{				
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else
				{
					sprintf(buff, "%lf*10^%lg", x, e);
				}
			}
			else if (a == 4)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else if (x < 0)
				{
					sprintf(buff, "-e%lg", log10(neg(*this)).to_int());
				}
				else if (x == 0)
				{
					sprintf(buff, "e(-inf)");
				}
				else
				{
					sprintf(buff, "e%lg", log10(*this).to_int());
				}
			}
			else if (a == 5)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else if (x < 0)
				{
					sprintf(buff, "-e%lg", e);
				}
				else
				{
					sprintf(buff, "e%lg", e);
				}
			}
			else if (a == 6)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else if (x == 0)
				{
					sprintf(buff, "e(-e(inf))");
				}
				else if (x < 0)
				{
					if (log10(neg(*this)) > lBI(0, 0))
					{
						sprintf(buff, "-ee%lg", log10(log10(neg(*this))).to_int());
					}
					else if (log10(neg(*this)) == lBI(0, 0))
					{
						sprintf(buff, "-ee(-inf)");
					}
					else
					{
						sprintf(buff, "-e(-e%lg)", log10(neg(log10(neg(*this)))).to_int());
					}
				}
				else
				{
					if (log10(*this) > lBI(0, 0))
					{
						sprintf(buff, "ee%lg", log10(log10(*this)).to_int());
					}
					else if (log10(*this) == lBI(0, 0))
					{
						sprintf(buff, "ee(-inf)");
					}
					else
					{
						sprintf(buff, "e(-e%lg)", log10(neg(log10(*this))).to_int());
					}
				}
			}
			else if (a == 7)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else if (x == 0)
				{
					sprintf(buff, "10^(-10^(inf))");
				}
				else if (x < 0)
				{
					if (log10(neg(*this)) > lBI(0, 0))
					{
						sprintf(buff, "-10^^%lg", log10(log10(neg(*this))).to_int());
					}
					else if (log10(neg(*this)) == lBI(0, 0))
					{
						sprintf(buff, "-10^^(-inf)");
					}
					else
					{
						sprintf(buff, "-10^(-10^%lg)", log10(neg(log10(neg(*this)))).to_int());
					}
				}
				else
				{
					if (log10(*this) > lBI(0, 0))
					{
						sprintf(buff, "10^^%lg", log10(log10(*this)).to_int());
					}
					else if (log10(*this) == lBI(0, 0))
					{
						sprintf(buff, "10^^(-inf)");
					}
					else
					{
						sprintf(buff, "10^(-10^%lg)", log10(neg(log10(*this))).to_int());
					}
				}
			}
			else if (a == 8)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else
				{
					sprintf(buff, "%lg", lBI_to_int(*this));
				}
			}
			else if (a == 9)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else if (std::fabs(e) < 6)
				{
					sprintf(buff, "%lg", lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e6)
				{
					sprintf(buff, "%lfe%lg", x, e);
				}
				else 
				{
					if (x < 0)
					{
						sprintf(buff, "-e%lg", log10(neg(*this)).to_int());
					}
					else
					{
						sprintf(buff, "e%lg", log10(*this).to_int());
					}
				}
			}			
			else if (a == 10)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else if (std::fabs(e) < 6)
				{
					sprintf(buff, "%lg", lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e6)
				{
					sprintf(buff, "%lf*10^%lg", x, e);
				}
				else 
				{
					if (x < 0)
					{
						sprintf(buff, "-10^%lg", log10(neg(*this)).to_int());
					}
					else
					{
						sprintf(buff, "10^%lg", log10(*this).to_int());
					}
				}
			}			
			else if (a == 11)
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else if (std::fabs(e) < 6)
				{
					sprintf(buff, "%lg", lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e6)
				{
					sprintf(buff, "%lfx10^%lg", x, e);
				}
				else 
				{
					if (x < 0)
					{
						sprintf(buff, "-10^%lg", log10(neg(*this)).to_int());
					}
					else
					{
						sprintf(buff, "10^%lg", log10(*this).to_int());
					}
				}
			}
			else
			{
				if (std::isnan(x) || std::isnan(e))
				{
					sprintf(buff, "nan");
				}			
				else if (x == INFINITY || e == INFINITY)
				{
					sprintf(buff, "inf");
				}
				else if (x == - INFINITY || e == - INFINITY)
				{
					sprintf(buff, "-inf");
				}
				else if (std::fabs(e) < 6)
				{
					sprintf(buff, "%lg", lBI_to_int(*this));
				}
				else if (std::fabs(e) < 1e6)
				{
					sprintf(buff, "%lfe%lg", x, e);
				}
				else 
				{
					if (x < 0)
					{
						sprintf(buff, "-e%lg", log10(neg(*this)).to_int());
					}
					else
					{
						sprintf(buff, "e%lg", log10(*this).to_int());
					}
				}
			}	
            std::string ans = buff;
			return ans;
		}
        const char* to_c_str(int a = 9)
		{
            return to_str(a).c_str();
		}
		double to_int()
		{			
			if (x == INFINITY)
			{
				return INFINITY;
			}
			else if (x == - INFINITY)
			{
				return - INFINITY;
			}
			else if (std::isnan(x) || std::isnan(e))
			{
				return NAN;
			}
			else
			{
				return x * std::pow(10, e);
			}
		}
		lBI format()
		{
			if (std::isnan(x) || std::isnan(e))
			{
				return lBI(NAN, NAN);
			}
			else if (x == INFINITY || e == INFINITY)
			{
				return lBI(INFINITY, INFINITY);
			}
			else if (x == - INFINITY)
			{
				return lBI(- INFINITY, - INFINITY);
			}
			else
			{
				if (std::floor(e) != e)
				{
					x *= std::pow(10, e - std::floor(e));
					e = std::floor(e);
				}
				if (x == 0)
				{
					x = 0;
					e = 0;
				}
				else if (x < 1)
				{
					e += std::floor(std::log10(std::fabs(x)));
					x = x / std::pow(10, std::floor(std::log10(std::fabs(x))));
				}
				else if (x >= 10)
				{
					e += std::floor(std::log10(std::fabs(x)));
					x = x / std::pow(10, std::floor(std::log10(std::fabs(x))));
				}
				else
				{
					x = x;
					e = e;
				}
				return *this;
			}
		}
		lBI operator+(const lBI t) const
		{
			lBI tmp(0, 0);
			if (t.e > e)
			{
				tmp = lBI(t.x + x * std::pow(10, e - t.e), t.e);
			}
			else if (t.e < e)
			{
				tmp = lBI(t.x * std::pow(10, t.e - e) + x, e);
			}
			else
			{
				tmp = lBI(t.x + x, e);
			}
			return tmp.format();
		}
		lBI operator-(const lBI t) const
		{
			lBI tmp(0, 0);
			if (e > t.e)
			{
				tmp = lBI(x - t.x * std::pow(10, t.e - e), e);
			}
			else if (e < t.e)
			{
				tmp = lBI(x * std::pow(10, e - t.e) - t.x, t.e);
			}
			else
			{
				tmp = lBI(x - t.x, e);
			}
			return tmp.format();
		}
		lBI operator*(const lBI t) const
		{
			lBI tmp(0, 0);
			if ((t.e == - INFINITY && e == INFINITY) || (t.e == INFINITY && e == - INFINITY))
			{
				tmp = lBI(- INFINITY, - INFINITY);
			}
			else
			{
				tmp = lBI(t.x * x, t.e + e);
			}
			return tmp.format();
		}
		lBI operator/(const lBI t) const
		{
			if (t.x == 0)
			{
				if (x > 0)
				{
					return lBI(INFINITY, INFINITY);
				}
				else if (x < 0)
				{
					return lBI(- INFINITY, - INFINITY);
				}
				else
				{
					return lBI(NAN, NAN);
				}
			}
			lBI tmp(x / t.x, e - t.e);
			return tmp.format();
		}
		lBI operator%(const lBI t) const
		{
			if (std::isnan(x) || std::isnan(e) || std::isnan(t.x) || std::isnan(t.e))
			{
				return lBI(NAN, NAN);
			}
			else if (x == INFINITY || x == - INFINITY)
			{
				return lBI(NAN, NAN);
			}
			else if (t == lBI(0, 0))
			{
				return lBI(NAN, NAN);
			}
			else if (t.x == INFINITY || t.x == - INFINITY)
			{
				return *this;
			}
			else if (*this == lBI(0, 0))
			{
				return lBI(0, 0);
			}
			else if (lBI(std::fabs(x), e) < t)
			{
				return *this;
			}
			else if (lBI(std::fabs(x), e) < lBI_Infinity && lBI(std::fabs(t.x), t.e) < lBI_Infinity)
			{
				return lBI(std::fmod(lBI_to_int(*this), lBI_to_int(t)));
			}
			else
			{ 
		     	lBI tmp = *this / t;
		     	if (tmp >= lBI_Infinity)
		     	{
		     		return lBI(0, 0);
				}
				else
				{
					return lBI(std::fmod(lBI_to_int(tmp), 1.0)) * t;
				}
			}
		}
		lBI operator+() const
		{
			return lBI_format(*this);
		}
		lBI operator-() const
		{
			lBI tmp = *this;
			tmp = lBI(0, 0) - tmp;
			return tmp.format();
		}
		lBI operator<<(const lBI t) const
		{
			lBI tmp = *this;
			return tmp * pow(lBI(2, 0), t);
		}
		lBI operator>>(const lBI t) const
		{
			lBI tmp = *this;
			return tmp / pow(lBI(2, 0), t);
		}
		lBI operator~() const
		{
			return - *this - lBI(1, 0);
		}
		bool operator>(const lBI t) const
		{
			lBI tmp = *this;
			lBI ttmp(t.x, t.e);
			tmp.format();
			ttmp.format();
			if (tmp.x <= 0 && ttmp.x > 0)
			{
				return false;
			}
			if (tmp.x < 0 && ttmp.x >= 0)
			{
				return false;
			}
			if (tmp.x > 0 && ttmp.x <= 0)
			{
				return true;
			}
			if (tmp.x >= 0 && ttmp.x < 0)
			{
				return true;
			}
			if (tmp.x >= 0 && ttmp.x >= 0)
			{
				if (tmp.e > ttmp.e)
				{
					return true;
				}
				else if (tmp.e < ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x > ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				if (tmp.e < ttmp.e)
				{
					return true;
				}
				else if (tmp.e > ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x > ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		bool operator>=(const lBI t) const
		{
			lBI tmp = *this;
			lBI ttmp(t.x, t.e);
			tmp.format();
			ttmp.format();
			if (tmp.x <= 0 && ttmp.x > 0)
			{
				return false;
			}
			if (tmp.x < 0 && ttmp.x >= 0)
			{
				return false;
			}
			if (tmp.x > 0 && ttmp.x <= 0)
			{
				return true;
			}
			if (tmp.x >= 0 && ttmp.x < 0)
			{
				return true;
			}
			if (tmp.x >= 0 && ttmp.x >= 0)
			{
				if (tmp.e > ttmp.e)
				{
					return true;
				}
				else if (tmp.e < ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x >= t.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				if (tmp.e < ttmp.e)
				{
					return true;
				}
				else if (tmp.e > ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x >= t.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		bool operator<(const lBI t) const
		{
			lBI tmp = *this;
			lBI ttmp(t.x, t.e);
			tmp.format();
			ttmp.format();
			if (tmp.x <= 0 && ttmp.x > 0)
			{
				return true;
			}
			if (tmp.x < 0 && ttmp.x >= 0)
			{
				return true;
			}
			if (tmp.x > 0 && ttmp.x <= 0)
			{
				return false;
			}
			if (tmp.x >= 0 && ttmp.x < 0)
			{
				return false;
			}
			if (tmp.x >= 0 && ttmp.x >= 0)
			{
				if (tmp.e < ttmp.e)
				{
					return true;
				}
				else if (tmp.e > ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x < ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				if (tmp.e > ttmp.e)
				{
					return true;
				}
				else if (tmp.e < ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x < ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		bool operator<=(const lBI t) const
		{
			lBI tmp = *this;
			lBI ttmp(t.x, t.e);
			tmp.format();
			ttmp.format();
			if (tmp.x <= 0 && ttmp.x > 0)
			{
				return true;
			}
			if (tmp.x < 0 && ttmp.x >= 0)
			{
				return true;
			}
			if (tmp.x > 0 && ttmp.x <= 0)
			{
				return false;
			}
			if (tmp.x >= 0 && ttmp.x < 0)
			{
				return false;
			}
			if (tmp.x >= 0 && ttmp.x >= 0)
			{
				if (tmp.e < ttmp.e)
				{
					return true;
				}
				else if (tmp.e > ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x <= ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				if (tmp.e > ttmp.e)
				{
					return true;
				}
				else if (tmp.e < ttmp.e)
				{
					return false;
				}
				else
				{
					if (tmp.x <= ttmp.x)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
		bool operator==(const lBI t) const
		{
			lBI tmp = *this;
			lBI ttmp(t.x, t.e);
			tmp.format();
			ttmp.format();
			if (tmp.e == ttmp.e && tmp.x == ttmp.x)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool operator!=(const lBI t) const
		{
			lBI tmp = *this;
			lBI ttmp(t.x, t.e);
			tmp.format();
			ttmp.format();
			if (tmp.e != ttmp.e || tmp.x != ttmp.x)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		lBI operator+=(const lBI t)
		{
			lBI tmp = *this;
			*this = t + tmp;
			return t + tmp;
		}
		lBI operator-=(const lBI t)
		{
			lBI tmp = *this;
			*this = tmp - t;
			return tmp - t;
		}
		lBI operator*=(const lBI t)
		{
			lBI tmp = *this;
			*this = t * tmp;
			return t * tmp;
		}
		lBI operator/=(const lBI t)
		{
			lBI tmp = *this;
			*this = tmp / t;
			return tmp / t;
		}
		lBI operator%=(const lBI t)
		{
			lBI tmp = *this;
			*this = tmp % t;
			return tmp % t;
		}
		lBI operator++()
		{
			lBI tmp = *this;
			*this = tmp + lBI(1, 0);
			return tmp + lBI(1, 0);
		}
		lBI operator--()
		{
			lBI tmp = *this;
			*this = *this - lBI(1, 0);
			return tmp - lBI(1, 0);
		}
		lBI operator++(int)
		{
			lBI tmp = *this;
			*this = tmp + lBI(1, 0);
			return tmp;
		}
		lBI operator--(int)
		{
			lBI tmp = *this;
			*this = *this - lBI(1, 0);
			return tmp;
		}
		lBI operator<<=(const lBI t)
		{
			lBI tmp = *this;
			*this = tmp << t;
			return tmp << t;
		}
		lBI operator>>=(const lBI t)
		{
			lBI tmp = *this;
			*this = tmp >> t;
			return tmp >> t;
		}
		operator double() const
		{
        	return lBI_to_int(*this);
    	}
		lBI()
		{
			this -> x = 0;
			this -> e = 0;			 
		}
		lBI(double a)
		{
			lBI tmp = int_to_lBI(a);
			this -> x = tmp.x;
			this -> e = tmp.e;
		}
		lBI(double a, double b)
		{
			this -> x = a;
			this -> e = b;
		}	
	};
	lBI int_to_lBI(double a)
	{
		if (std::isnan(a))
		{
			return lBI(NAN, NAN);
		}
		else if (a == INFINITY)
		{
			return lBI(INFINITY, INFINITY);
		}
		else if (a == - INFINITY)
		{
			return lBI(- INFINITY, - INFINITY);
		}
		else if (a < 0)
		{
			return lBI(a / std::pow(10, std::floor(std::log10(std::abs(a)))), std::floor(std::log10(std::abs(a))));
		}
		else if (a == 0)
		{
			return lBI(0, 0);
		}
		else
		{
			return lBI(a / std::pow(10, std::floor(std::log10(a))), std::floor(std::log10(a)));
		}
	}
	#if __cplusplus >= 201103L
	lBI str_to_lBI(std::string a)
	{
		try
		{
			int e_count = 0;
			int first_e_pos = 0;
			int second_e_pos = 0;
			lBI ans = lBI(0, 0);
			if (a == "Infinity" || a == "inf")
			{
				return lBI(INFINITY, INFINITY);
			}
			if (a == "-Infinity" || a == "-inf")
			{
				return lBI(- INFINITY, - INFINITY);
			}
			if (a == "NaN" || a == "nan")
			{
				return lBI(NAN, NAN);
			}
			if (a.length() == 0)
			{
				return ans;
			}
			for (int i = 0; i < a.length(); i ++)
			{
				if (a[i] == 'e' || a[i] == 'E' || a[i] == ' ')
				{
					if (first_e_pos == 0 && e_count == 0)
					{
						first_e_pos = i;
					}
					else if (second_e_pos == 0)
					{	
						second_e_pos = i;
					}
					e_count ++;
				}
			}
			if (e_count == 0)
			{
				ans = int_to_lBI(stod(a));
			}
			else
			{
				if (first_e_pos == 0)
				{
					ans.x = 1;
					if (second_e_pos == 1)
					{
						ans.e = std::pow(10, stod(a.substr(2)));
					}
					else
					{
						ans.e = stod(a.substr(1));
					}
				}
				else
				{
					ans.x = stod(a.substr(0, first_e_pos));
					ans.e = stod(a.substr(first_e_pos + 1));
				}
			}
			return ans.format();
		}
		catch (...)
		{
			return lBI(0, 0);
		}
	}
	lBI str_to_lBI(const char* a)
	{
		if (a == NULL)
		{
			return str_to_lBI(std::string(""));
		}
		else
		{
			return str_to_lBI(std::string(a));
		}
	}
	#else
	lBI str_to_lBI(const char* a)
	{
		int e_count = 0;
		int first_e_pos = 0;
		int second_e_pos = 0;
		lBI ans = lBI(0, 0);
		if (a == NULL)
		{
			return ans;
		}
		if (strcmp(a, "Infinity") == 0 || strcmp(a, "inf") == 0)
		{
			return lBI(INFINITY, INFINITY);
		}
		if (strcmp(a, "-Infinity") == 0 || strcmp(a, "-inf") == 0)
		{
			return lBI(- INFINITY, - INFINITY);
		}
		if (strcmp(a, "NaN") == 0 || strcmp(a, "nan") == 0)
		{
			return lBI(NAN, NAN);
		}
		if (strlen(a) == 0)
		{
			return ans;
		}
		for (int i = 0; i < strlen(a); i ++)
		{
			if (a[i] == 'e' || a[i] == 'E' || a[i] == ' ')
			{
				if (first_e_pos == 0 && e_count == 0)
				{
					first_e_pos = i;
				}
				else if (second_e_pos == 0)
				{	
					second_e_pos = i;
				}
				e_count ++;
			}
		}
		if (e_count == 0)
		{
			ans = int_to_lBI(strtod(a, NULL));
		}
		else
		{
			if (first_e_pos == 0)
			{
				ans.x = 1;
				if (second_e_pos == 1)
				{	
					char buff[1024];
					memcpy(buff, a + 2, strlen(a) - 1);
					ans.e = pow(10, strtod(buff, NULL));
				}
				else
				{
					char buff[1024];
					memcpy(buff, a + 1, strlen(a));
					ans.e = strtod(buff, NULL);
				}
			}
			else
			{
				char buffa[1024], buffb[1024];
				memcpy(buffa, a, first_e_pos);
				buffa[first_e_pos] = '\0';
				memcpy(buffb, a + first_e_pos + 1, strlen(a) - first_e_pos);
				ans.x = strtod(buffa, NULL);
				ans.e = strtod(buffb, NULL);
			}
		}
		return ans.format();
	}
	lBI str_to_lBI(std::string a)
	{
		return str_to_lBI(a.c_str());
	}
	#endif
	lBI lBI_plus(lBI a, lBI b)
	{
		return a + b;
	}
	lBI lBI_minus(lBI a, lBI b)
	{
		return a - b;
	}
	lBI lBI_multi(lBI a, lBI b)
	{
		return a * b;
	}
	lBI lBI_div(lBI a, lBI b)
	{
		return a / b;
	}
	lBI lBI_mod(lBI a, lBI b)
	{
		return a % b;
	}
	lBI floor(lBI a)
	{
		return a - a % lBI(1, 0);
	}
	lBI ceil(lBI a)
	{
		if (a % lBI(1, 0) != lBI(0, 0))
		{
			return floor(a) + lBI(1, 0);
		}
		else
		{
			return a;
		}
	}
	lBI round(lBI a)
	{
		if (a % lBI(1, 0) >= lBI(5, -1))
		{
			return floor(a) + lBI(1, 0);
		}
		else
		{
			return floor(a);
		}
	}
	lBI log(lBI a)
	{
		return logx(a, lBI_E);
	}
	lBI log10(lBI a)
	{
		if (std::isnan(a.x) || std::isnan(a.e))
		{
			return lBI(NAN, NAN);
		}
		else if (a == lBI(INFINITY, INFINITY))
		{
			return lBI(INFINITY, INFINITY);
		}
		else if (a == lBI(- INFINITY, - INFINITY))
		{
			return lBI(NAN, NAN);
		}
		else if (a < lBI(0, 0))
		{
			return lBI(NAN, NAN);
		}
		else if (a == lBI(0, 0))
		{
			return lBI(- INFINITY, - INFINITY);
		}
		else
		{
			return int_to_lBI(std::log10(a.x)) + int_to_lBI(a.e);
		}
	}
	lBI logx(lBI a, lBI b = lBI(1, 1))
	{
		return log10(a) / log10(b);
	}
	lBI pow(lBI a, lBI b)
	{
		lBI tmp = lBI(0, 0);
		if (std::isnan(a.x) || std::isnan(a.e) || std::isnan(b.x) || std::isnan(b.e))
		{
			tmp.x = NAN;
			tmp.e = NAN;
		}
		else if (a.x == 0)
		{
			if (b.x < 0)
			{
				tmp.x = INFINITY;
				tmp.e = INFINITY;
			}
			else
			{
				tmp.x = 0;
				tmp.e = 0;
			}
		}
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			if (b.x > 0)
			{
				tmp.x = INFINITY;
				tmp.e = INFINITY;
			}
			else if (b.x == 0)
			{
				tmp.x = 1;
				tmp.e = 0;
			}
			else
			{
				tmp.x = 0;
				tmp.e = 0;
			}
		}
		else if (a.x == 1)
		{
			if (a.e == 0 && (b.x == INFINITY || b.e == INFINITY))
			{
				tmp.x = 1;
				tmp.e = 0;
			}
			else
			{
				tmp.e = (int_to_lBI(a.e) * b).to_int();
				tmp.x = 1;
			}
		}
		else if (a.x > 1)
		{
			tmp.e = (int_to_lBI(a.e) * b + b * int_to_lBI(std::log10(a.x))).to_int();
			tmp.x = 1;
		}
		else
		{
			tmp.x = NAN;
			tmp.e = NAN;
		}
		tmp.format();
		return tmp;
	}
	lBI sqrtx(lBI a, lBI b = lBI(2, 0))
	{
		lBI tmp = pow(a, lBI(1, 0) / b);
		return tmp;
	}
	lBI hypot(lBI a, lBI b)
	{
		return sqrt(a * a + b * b);
	}
	lBI sqrt(lBI a)
	{
		return sqrtx(a, lBI(2, 0));
	}
	lBI cbrt(lBI a)
	{
		if (std::isnan(a.x) || std::isnan(a.e))
		{
			return lBI(NAN, NAN);
		}
		else if (a.x >= 0)
		{
			return pow(a, lBI(1, 0) / lBI(3, 0));
		}
		else 
		{
			return - pow(- a, lBI(1, 0) / lBI(3, 0));
		}
	}
	lBI exp(lBI a)
	{
		return pow(lBI_E, a);
	}
	lBI abs(lBI a)
	{
		return lBI(std::fabs(a.x), a.e);
	}
	lBI reci(lBI a)
	{
		return lBI(1, 0) / a;
	}
	lBI neg(lBI a)
	{
		return - a;
	}
	lBI frexp(lBI a, lBI* b)
	{
		if (std::isnan(a.x) || std::isnan(a.e))
		{
			b -> x = NAN;
			b -> e = NAN;
			return lBI(NAN, NAN);
		}
		else if (a.x == INFINITY || a.e == INFINITY)
		{
			b -> x = INFINITY;
			b -> e = INFINITY;
			return lBI(INFINITY, INFINITY);
		}
		else if (a.x == - INFINITY || a.e == - INFINITY)
		{
			b -> x = - INFINITY;
			b -> e = - INFINITY;
			return lBI(- INFINITY, - INFINITY);
		}
		else if (a == lBI(0, 0))
		{
			b -> x = 0;
			b -> e = 0;
			return lBI(0, 0); 
		}
		else if (a < lBI(0, 0))
		{
			lBI tmp = logx(- a, lBI(2, 0));
			if (ceil(tmp) == tmp)
			{
				if (tmp < lBI(0, 0))
				{
					*b = tmp + lBI(1, 0);
				}
				else
				{
					*b = tmp - lBI(1, 0);
				}
				return lBI(-5, -1);
			}
			else
			{
				*b = ceil(tmp);
				return - a / pow(lBI(2, 0), ceil(tmp));
			}
		}
		else
		{
			lBI tmp = logx(a, lBI(2, 0));
			if (ceil(tmp) == tmp)
			{
				if (tmp < lBI(0, 0))
				{
					*b = tmp + lBI(1, 0);
				}
				else
				{
					*b = tmp - lBI(1, 0);
				}
				return lBI(5, -1);
			}
			else
			{
				*b = ceil(tmp);
				return a / pow(lBI(2, 0), ceil(tmp));
			}
		}
	}
	lBI ldexp(lBI a, lBI b)
	{
		return a * pow(lBI(2, 0), b);
	}
	lBI cos(lBI a)
	{
		return int_to_lBI(std::cos(lBI_to_int(a % (lBI(2, 0) * lBI_PI))));
	}
	lBI sin(lBI a)
	{
		return int_to_lBI(std::sin(lBI_to_int(a % (lBI(2, 0) * lBI_PI))));
	}
	lBI tan(lBI a)
	{
		return sin(a) / cos(a);
	}
	lBI cosh(lBI a)
	{
		return (pow(lBI_E, a) + pow(lBI_E, - a)) / lBI(2, 0);
	}
	lBI sinh(lBI a)
	{
		return (pow(lBI_E, a) - pow(lBI_E, - a)) / lBI(2, 0);
	}
	lBI tanh(lBI a)
	{
		return sinh(a) / cosh(a);
	}
	lBI acos(lBI a)
	{
		if (lBI(-1, 0) <= a && a <= lBI(1, 0))
		{
			return lBI(std::acos(lBI_to_int(a)));
		}
		else
		{
			return lBI(NAN, NAN);
		}
	}
	lBI asin(lBI a)
	{
		if (lBI(-1, 0) <= a && a <= lBI(1, 0))
		{
			return lBI(std::asin(lBI_to_int(a)));
		}
		else
		{
			return lBI(NAN, NAN);
		}
	}
	lBI atan(lBI a)
	{
		return int_to_lBI(std::atan(lBI_to_int(a)));
	}
	lBI atan2(lBI a, lBI b)
	{
		return int_to_lBI(std::atan2(lBI_to_int(a), lBI_to_int(b)));
	}
	bool isnan(lBI a)
	{
		if (std::isnan(a.x) || std::isnan(a.e))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	lBI lBI_format(lBI a)
	{
		return a.format();
	}
	lBI print_lBI(lBI a, int b = 9, bool c = 0)
	{
		return a.print(b, c);
	}
	double lBI_to_int(lBI a)
	{
		return a.to_int();
	}
	#if __cplusplus >= 201103L
	std::string lBI_to_str_old(lBI a, int b)
	{
		return a.to_str_old(b);
	}
	#endif
    std::string lBI_to_str(lBI a, int b)
    {
        return a.to_str(b);
    }
    const char* lBI_to_c_str(lBI a, int b)
    {
        return a.to_c_str(b);
    }
	std::istream& operator>>(std::istream& is, lBI& p) 
	{
		std::string tmp = "";
		is >> std::ws;
		getline(is, tmp);
	    p = str_to_lBI(tmp);
	    return is; 
	}
	std::ostream& operator<<(std::ostream& os, const lBI& p) 
	{		
		if (std::isnan(p.x) || std::isnan(p.e))
		{
			os << "nan";
		}
		else if (p.x == INFINITY || p.e == INFINITY)
		{
			os << "inf";
		}
		else if (p.x == - INFINITY || p.e == - INFINITY)
		{
			os << "-inf";
		}
		else if (std::fabs(p.e) < 6)
		{
			os << lBI_to_int(p);
		}
		else if (std::fabs(p.e) < 1e6)
		{
			os << p.x << "e" << p.e;
		}
		else 
		{
			if (p.x < 0)
			{
				os << "-e" << log10(neg(p)).to_int();
			}
			else
			{
				os << "e" << log10(p).to_int();
			}
		}
	    return os; 
	}
	lBI operator+(lBI tmp1, int tmp2)
	{
		return tmp1 + lBI(tmp2);
	}
	lBI operator+(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 + lBI(tmp2);
	}
	lBI operator+(lBI tmp1, long tmp2)
	{
		return tmp1 + lBI(tmp2);
	}
	lBI operator+(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 + lBI(tmp2);
	}
	lBI operator+(lBI tmp1, long long tmp2)
	{
		return tmp1 + lBI(tmp2);
	}
	lBI operator+(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 + lBI(tmp2);
	}		
	lBI operator+(lBI tmp1, float tmp2)
	{
		return tmp1 + lBI(tmp2);
	}	
	lBI operator+(lBI tmp1, double tmp2)
	{
		return tmp1 + lBI(tmp2);
	}	
	lBI operator+(lBI tmp1, long double tmp2)
	{
		return tmp1 + lBI(tmp2);
	}	
	lBI operator-(lBI tmp1, int tmp2)
	{
		return tmp1 - lBI(tmp2);
	}
	lBI operator-(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 - lBI(tmp2);
	}
	lBI operator-(lBI tmp1, long tmp2)
	{
		return tmp1 - lBI(tmp2);
	}
	lBI operator-(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 - lBI(tmp2);
	}
	lBI operator-(lBI tmp1, long long tmp2)
	{
		return tmp1 - lBI(tmp2);
	}
	lBI operator-(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 - lBI(tmp2);
	}	
	lBI operator-(lBI tmp1, float tmp2)
	{
		return tmp1 - lBI(tmp2);
	}	
	lBI operator-(lBI tmp1, double tmp2)
	{
		return tmp1 - lBI(tmp2);
	}	
	lBI operator-(lBI tmp1, long double tmp2)
	{
		return tmp1 - lBI(tmp2);
	}	
	lBI operator-(lBI tmp1, const char* tmp2)
	{
		return tmp1 - lBI(tmp2);
	}	
	lBI operator*(lBI tmp1, int tmp2)
	{
		return tmp1 * lBI(tmp2);
	}
	lBI operator*(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 * lBI(tmp2);
	}
	lBI operator*(lBI tmp1, long tmp2)
	{
		return tmp1 * lBI(tmp2);
	}
	lBI operator*(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 * lBI(tmp2);
	}
	lBI operator*(lBI tmp1, long long tmp2)
	{
		return tmp1 * lBI(tmp2);
	}
	lBI operator*(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 * lBI(tmp2);
	}	
	lBI operator*(lBI tmp1, float tmp2)
	{
		return tmp1 * lBI(tmp2);
	}	
	lBI operator*(lBI tmp1, double tmp2)
	{
		return tmp1 * lBI(tmp2);
	}	
	lBI operator*(lBI tmp1, long double tmp2)
	{
		return tmp1 * lBI(tmp2);
	}	
	lBI operator/(lBI tmp1, int tmp2)
	{
		return tmp1 / lBI(tmp2);
	}
	lBI operator/(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 / lBI(tmp2);
	}
	lBI operator/(lBI tmp1, long tmp2)
	{
		return tmp1 / lBI(tmp2);
	}
	lBI operator/(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 / lBI(tmp2);
	}
	lBI operator/(lBI tmp1, long long tmp2)
	{
		return tmp1 / lBI(tmp2);
	}
	lBI operator/(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 / lBI(tmp2);
	}	
	lBI operator/(lBI tmp1, float tmp2)
	{
		return tmp1 / lBI(tmp2);
	}	
	lBI operator/(lBI tmp1, double tmp2)
	{
		return tmp1 / lBI(tmp2);
	}	
	lBI operator/(lBI tmp1, long double tmp2)
	{
		return tmp1 / lBI(tmp2);
	}	
	lBI operator%(lBI tmp1, int tmp2)
	{
		return tmp1 % lBI(tmp2);
	}
	lBI operator%(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 % lBI(tmp2);
	}
	lBI operator%(lBI tmp1, long tmp2)
	{
		return tmp1 % lBI(tmp2);
	}
	lBI operator%(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 % lBI(tmp2);
	}
	lBI operator%(lBI tmp1, long long tmp2)
	{
		return tmp1 % lBI(tmp2);
	}
	lBI operator%(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 % lBI(tmp2);
	}	
	lBI operator%(lBI tmp1, float tmp2)
	{
		return tmp1 % lBI(tmp2);
	}	
	lBI operator%(lBI tmp1, double tmp2)
	{
		return tmp1 % lBI(tmp2);
	}	
	lBI operator%(lBI tmp1, long double tmp2)
	{
		return tmp1 % lBI(tmp2);
	}	
	bool operator>(lBI tmp1, int tmp2)
	{
		return tmp1 > lBI(tmp2);
	}
	bool operator>(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 > lBI(tmp2);
	}
	bool operator>(lBI tmp1, long tmp2)
	{
		return tmp1 > lBI(tmp2);
	}
	bool operator>(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 > lBI(tmp2);
	}
	bool operator>(lBI tmp1, long long tmp2)
	{
		return tmp1 > lBI(tmp2);
	}
	bool operator>(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 > lBI(tmp2);
	}
	bool operator>(lBI tmp1, float tmp2)
	{
		return tmp1 > lBI(tmp2);
	}	
	bool operator>(lBI tmp1, double tmp2)
	{
		return tmp1 > lBI(tmp2);
	}	
	bool operator>(lBI tmp1, long double tmp2)
	{
		return tmp1 > lBI(tmp2);
	}	
	bool operator>=(lBI tmp1, int tmp2)
	{
		return tmp1 >= lBI(tmp2);
	}
	bool operator>=(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 >= lBI(tmp2);
	}
	bool operator>=(lBI tmp1, long tmp2)
	{
		return tmp1 >= lBI(tmp2);
	}
	bool operator>=(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 >= lBI(tmp2);
	}
	bool operator>=(lBI tmp1, long long tmp2)
	{
		return tmp1 >= lBI(tmp2);
	}
	bool operator>=(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 >= lBI(tmp2);
	}	
	bool operator>=(lBI tmp1, float tmp2)
	{
		return tmp1 >= lBI(tmp2);
	}	
	bool operator>=(lBI tmp1, double tmp2)
	{
		return tmp1 >= lBI(tmp2);
	}	
	bool operator>=(lBI tmp1, long double tmp2)
	{
		return tmp1 >= lBI(tmp2);
	}	
	bool operator<(lBI tmp1, int tmp2)
	{
		return tmp1 < lBI(tmp2);
	}
	bool operator<(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 < lBI(tmp2);
	}
	bool operator<(lBI tmp1, long tmp2)
	{
		return tmp1 < lBI(tmp2);
	}
	bool operator<(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 < lBI(tmp2);
	}
	bool operator<(lBI tmp1, long long tmp2)
	{
		return tmp1 < lBI(tmp2);
	}
	bool operator<(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 < lBI(tmp2);
	}
	bool operator<(lBI tmp1, float tmp2)
	{
		return tmp1 < lBI(tmp2);
	}	
	bool operator<(lBI tmp1, double tmp2)
	{
		return tmp1 < lBI(tmp2);
	}	
	bool operator<(lBI tmp1, long double tmp2)
	{
		return tmp1 < lBI(tmp2);
	}	
	bool operator<=(lBI tmp1, int tmp2)
	{
		return tmp1 <= lBI(tmp2);
	}
	bool operator<=(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 <= lBI(tmp2);
	}
	bool operator<=(lBI tmp1, long tmp2)
	{
		return tmp1 <= lBI(tmp2);
	}
	bool operator<=(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 <= lBI(tmp2);
	}
	bool operator<=(lBI tmp1, long long tmp2)
	{
		return tmp1 <= lBI(tmp2);
	}
	bool operator<=(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 <= lBI(tmp2);
	}
	bool operator<=(lBI tmp1, float tmp2)
	{
		return tmp1 <= lBI(tmp2);
	}	
	bool operator<=(lBI tmp1, double tmp2)
	{
		return tmp1 <= lBI(tmp2);
	}	
	bool operator<=(lBI tmp1, long double tmp2)
	{
		return tmp1 <= lBI(tmp2);
	}	
	bool operator==(lBI tmp1, int tmp2)
	{
		return tmp1 == lBI(tmp2);
	}
	bool operator==(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 == lBI(tmp2);
	}
	bool operator==(lBI tmp1, long tmp2)
	{
		return tmp1 == lBI(tmp2);
	}
	bool operator==(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 == lBI(tmp2);
	}
	bool operator==(lBI tmp1, long long tmp2)
	{
		return tmp1 == lBI(tmp2);
	}
	bool operator==(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 == lBI(tmp2);
	}
	bool operator==(lBI tmp1, float tmp2)
	{
		return tmp1 == lBI(tmp2);
	}	
	bool operator==(lBI tmp1, double tmp2)
	{
		return tmp1 == lBI(tmp2);
	}	
	bool operator==(lBI tmp1, long double tmp2)
	{
		return tmp1 == lBI(tmp2);
	}	
	bool operator!=(lBI tmp1, int tmp2)
	{
		return tmp1 != lBI(tmp2);
	}
	bool operator!=(lBI tmp1, unsigned int tmp2)
	{
		return tmp1 != lBI(tmp2);
	}
	bool operator!=(lBI tmp1, long tmp2)
	{
		return tmp1 != lBI(tmp2);
	}
	bool operator!=(lBI tmp1, unsigned long tmp2)
	{
		return tmp1 != lBI(tmp2);
	}
	bool operator!=(lBI tmp1, long long tmp2)
	{
		return tmp1 != lBI(tmp2);
	}
	bool operator!=(lBI tmp1, unsigned long long tmp2)
	{
		return tmp1 != lBI(tmp2);
	}		
	bool operator!=(lBI tmp1, float tmp2)
	{
		return tmp1 != lBI(tmp2);
	}	
	bool operator!=(lBI tmp1, double tmp2)
	{
		return tmp1 != lBI(tmp2);
	}	
	bool operator!=(lBI tmp1, long double tmp2)
	{
		return tmp1 != lBI(tmp2);
	}
}
#if __cplusplus >= 201103L
namespace std 
{
    template <>
    struct hash<loong::lBI> 
	{
        size_t operator()(loong::lBI p) const 
		{
            return hash<double>()(p.x) ^ hash<double>()(p.e);
        }
    };
}
#endif
#endif
