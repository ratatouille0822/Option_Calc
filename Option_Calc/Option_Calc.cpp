// Option_Calc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>

#include <cmath>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <math.h>


using namespace std;


int main()
{
    std::cout << "Hello World!\n"; 


	int T = 4;
	int n = 8;
	double S0 = 140;
	vector<vector<double>> tprice;
	vector<double> line_tprice;
	vector<vector<double>> payoff;
	vector<double> line_payoff;
	double r = 0.075;
	double u = 1.35;
	double d = 0.75;
	double K = 140;
	int number_of_lines;
	double m = 50;//for space use
	double f = 6;//for space use
	double number_of_price = 0;
	double x = 2;
	double ppprice = 0;
	double p = (exp(r / 2) - d) / (u - d);

/**************************** Calculate the first Triangle *************************************/

	cout << "the binoial tree of stock price:" << endl;
	for (int line_index = 0; line_index <= n; line_index++)
	{
		int number_of_spaces = m - f * line_index;
		for (int i = 0; i < number_of_spaces; i++)
		{
			cout << ".";
		}

		number_of_price = line_index + 1;

		for (int i = 0; i < number_of_price; i++)
		{
			line_tprice.push_back(S0 * pow(u, line_index - i)*pow(d, i));
			cout << setw(3) << fixed << setprecision(6) << line_tprice[i] << "__";
			
		}
		tprice.push_back(line_tprice);
		line_tprice.clear();

		cout << endl;
	}
	cout << " " << endl;

	/**************************** Calculate the second Triangle *************************************/

	cout << "the binoial tree of values of the call option:" << endl;
	for (vector<vector<double>>::iterator it = tprice.begin(); it != tprice.end(); it++)
	{
		int number_of_spaces = m - f * (it-tprice.begin()); // it-tprice.begin() 相当于之前循环中的i，它的取值是从0开始，一直到tprice的个数-1；
		for (int i = 0; i < number_of_spaces; i++)
		{
			cout << ".";
		}
		for(vector<double>::iterator it1 = it->begin();it1 != it->end();it1++)
		{
			if (*it1 - K > 0)
			{
				cout << setw(3) << fixed << setprecision(6) << *it1-K << "  ";
			}
			else
			{
				cout << setw(3) << fixed << setprecision(6) << 0.00 << "  ";
			}
			
		}
		cout << endl;
	}
	cout << "  " << endl;

	/**************************** Calculate the third Triangle *************************************/

	vector<double>price(tprice.back());
	
	cout << "This is the values in the vector Prise " << endl;

	for (vector<double>::iterator it = price.begin(); it != price.end(); it++)
	{
		if (*it - K > 0)
		{
			*it -= K;
		}
		else
		{
			*it = 0;
		}
	}

	

	for (int line_index = 0; line_index < n; line_index++)
	{
		int number_of_spaces = f * line_index;
		
		for (int i = 0; i < number_of_spaces; i++)
		{
			cout << ".";
		}

		number_of_price = n - line_index;
		if (line_index < price.size()-2)
		{
			for (int i = 0; i < number_of_price; i++)
			{
				price[i] = (p*price[i] + (1 - p)*price[i+1]) / exp(r / 2);
				cout << setw(3) << fixed << setprecision(6) << price[i] << "  ";

			}
		}
		else
		{
			for (int i = 0; i < number_of_price; i++)
			{
				price[i] = (p*price[i] + (1 - p)*price[i + 1]) / exp(r / 2);
				cout << setw(3) << fixed << setprecision(6) << price[i] << "  " << endl;
				ppprice = price[0];
				cout << "the price of the option call price is " << price[0] << endl;

			}
		}

		cout << endl;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
