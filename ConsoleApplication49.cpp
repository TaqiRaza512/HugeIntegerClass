#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<fstream>
#include"HugeInteger.h"
using namespace std;


void Read(HugeInteger*&H,int &size)
{
	ifstream Rdr("Hs.txt");
	Rdr>>size;
	H = new HugeInteger[size];
	for (int ri=0;ri<size;ri++)
	{
		Rdr>> H[ri];
		H[ri].Trim();
	}

}
void PrintLine(int size)
{
	if (size < 100)
	{
		cout << "\t\t";

	}
	for (int ri=0;ri<size;ri++)
	{
		cout << "_";

	}
}
void MainMenu()
{
	cout << "\n\tPress 1 for the calculator type Hi=Hj+Hk\n";
	cout << "\n\tPress 2 for the calculator type Hi+=Hj\n";
	cout << "\n\tPress 3 for the calculator type Hi>=Hj\n";
	cout << "\n\tPress 4 for the calculator type ++Hi\n";
	cout << "\n\tPress 5 for the calculator type Hi++\n";
	cout << "\n\tPress 6 for the input or output of the HugeInteger\n";
	cout << "\n\tPress 7 for the calculator type Hi>Hj\n";

	cout << endl << endl;
}
void Print(HugeInteger* H, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\t\t" << i + 1 << ".\t\t" << H[i];
		cout << endl;
		PrintLine(45);
		cout << endl;

	}
}
void Menu(HugeInteger*& H, int& size)
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "\n\t\t=================Huge_Integers===============\n\n";
	Print(H, size);
	cout << "\n\t\t=============================================\n\n\n"; 	
	PrintLine(125);
	cout << endl;

}

void Menu1()
{
	cout << "\n\t\tPress H1=H1+H2 for addition. \n";
	cout << "\n\t\tPress H1=H1-H2 for subtraction. \n";
	cout << "\n\t\tPress H1=H1*H2 for multiplication. \n";
	cout << "\n\t\tPress H1=H1/H2 for division. \n";
	cout << "\n\t\tPress H1=H1%H2 for module. \n";

}
void Calculator(HugeInteger*& H, int& size)
{
	

	int resi, pi, di;
	char d;
	char oprt;
	char tocont;
	
	do
	{
		Menu(H,size);
		Menu1();
		cin >> d >> resi >> d >> d >> pi >> oprt >> d >> di;
		resi--;
		pi--;
		di--;
		switch (oprt)
		{
		case '+':
			H[resi] = H[pi] + H[di];
			cout << "Hence the addition of H[" << pi + 1 << "] and H[" << di+1 << "] is " << H[resi];

			break;
		case '-':
			H[resi] = H[pi] - H[di];
			cout << "Hence the subtraction of H[" << pi + 1 << "] and H[" << di+1 << "] is " << H[resi];

			break;
		case '*':
			H[resi] = H[pi] * H[di];
			cout << "Hence the multiplication of H[" << pi + 1 << "] and H[" << di+1 << "] is " << H[resi];
			break;
		case '%':
				H[resi] = H[pi] % H[di];
				cout << "Hence the mode of H[" << pi + 1 << "] and H[" << di+1 << "] is " << H[resi];
				break;
		case '/':
			H[resi] = H[pi] / H[di];
			cout << "Hence the division of H[" << pi + 1 << "] and H[" << di + 1 << "] is " << H[resi];
			break;
		default:
			cout << "\nplease enter the valid operation \n";
		}
		cout << "\nDo you want to continue with calculator 1 (Y/N)";
		cin >> tocont;

	} while (tocont == 'y' or tocont == 'Y');
}

void Menu2()
{
	cout << "\n\t\tPress H1+=H2 for addition. \n";
	cout << "\n\t\tPress H1-=H2 for subtraction. \n";
	cout << "\n\t\tPress H1*=H2 for multiplication. \n";
	cout << "\n\t\tPress H1/=H2 for division. \n";
	cout << "\n\t\tPress H1%=H2 for module. \n";

}
void Calculator2(HugeInteger*& H, int& size)
{

	int resi, pi;
	char d;
	char oprt;
	char tocont;

	do
	{
		Menu(H, size);
		Menu2();
		cin >> d >> resi >>oprt>> d >>d>> pi;
		resi--;
		pi--;
		switch (oprt)
		{
		case '+':
			H[resi]+= H[pi];
			cout << "Hence H["<<resi+1<<"] becomes : "<<H[resi];

			break;
		case '-':
			H[resi] -= H[pi];

			cout << "Hence H[" << resi+1 << "] becomes : " << H[resi];

			break;
		case '*':
			H[resi] *= H[pi];
			cout << "Hence H[" << resi+1 << "] becomes : " << H[resi];

			break;
		case '%':
			H[resi] %= H[pi];
			cout << "Hence H[" << resi+1 << "] becomes : " << H[resi];

			break;
		case '/':
			H[resi] /= H[pi];
			cout << "Hence H[" << resi+1 << "] becomes : " << H[resi];
			break;
		default:
			cout << "\nplease enter the valid operation \n";
		}
		cout << "\nDo you want to continue with calculator type 2 (Y/N)";
		cin >> tocont;

	} while (tocont == 'y' or tocont == 'Y');
}


void Menu3()
{
	cout << "\n\t\tPress H1>=H2 to check greater than equal to...";
	cout << "\n\t\tPress H1<=H2 to check less than equal to...";
	cout << "\n\t\tPress H1==H2 to check the equality ...";
	cout << endl << endl;

}
void Calculator3(HugeInteger*& H, int& size)
{

	int resi, pi, di;
	char d;
	char oprt;
	char tocont;
	bool ch;
	do
	{
		Menu(H, size);
		Menu3();
		cin >> d >> resi >> oprt >> d >> d >> pi;
		resi--;
		pi--;
		switch (oprt)
		{
		case '>':
			ch=(H[resi] >= H[pi]);
			cout << ch;

			break;
		case '<':
			ch = (H[resi]<=H[pi]);
			cout << ch;


			break;
		case '=':
			ch = (H[resi] == H[pi]);
			cout << ch;

			break;	
		default:
			cout << "\nplease enter the valid operation \n";
			break;
		}
		cout << "\nDo you want to continue with calculator type 3 (Y/N)";
		cin >> tocont;

	} while (tocont == 'y' or tocont == 'Y');
}

void Menu4()
{
	cout << "\n\t\tPress ++Hi for the pre incremenet...";
	cout << "\n\t\tPress --Hi for the pre decremenet...";
	cout << endl << endl;

}
void Calculator4(HugeInteger*& H, int& size)
{
	int resi, pi, di;
	char d;
	char oprt;
	char tocont;
	bool ch;
	do
	{
		Menu(H, size);
		Menu4();
		//++Hi
		cin >> oprt >> oprt >> d >> resi;;
		resi--;
		switch (oprt)
		{
		case '+':
			cout << ++H[resi];

			break;
		case '-':
			cout << ++H[resi];
			break;	

		default:
			cout << "\nplease enter the valid operation \n";
			break;

		}
		cout << "\nDo you want to continue with calculator type 4 (Y/N)";
		cin >> tocont;

	} while (tocont == 'y' or tocont == 'Y');
}

void Menu5()
{
	cout << "\n\t\tPress Hi++ for the post incremenet...";
	cout << "\n\t\tPress Hi-- for the post decremenet...";
	cout << endl << endl;

}
void Calculator5(HugeInteger*& H, int& size)
{
	int resi, pi, di;
	char d;
	char oprt;
	char tocont;
	bool ch;
	do
	{
		Menu(H, size);
		Menu5();
		//Hi++
		cin >> d>> resi>> oprt>> d;
		resi--;
		switch (oprt)
		{
		case '+':
			cout << H[resi]++;
			break;
		case '-':
			cout << H[resi]--;
		
			break;

		default:
			cout << "\nplease enter the valid operation \n";
			break;

		}
		cout << "\nDo you want to continue with calculator type 5 (Y/N)";
		cin >> tocont;

	} while (tocont == 'y' or tocont == 'Y');
}

void Menu6()
{
	cout << "\n\tPress cin>>Hi for the the input of the integer...";
	cout << "\n\tPress out<<Hi for the the output of the integer...";
	cout << endl << endl;

}
void Calculator6(HugeInteger*& H, int& size)
{
	int resi, pi, di;
	char d;
	char oprt;
	char tocont;
	bool ch;
	do
	{
		Menu(H, size);
		//cin>>H
		Menu6();

		cin >> d >> d >> d>> oprt >> d>>d>>resi;
		resi--;
		switch (oprt)
		{
		case '>':
			cout << "Please enter any integer : ";			
			cin >> H[resi];

			break;
		case '<':
			cout << "Hence the value of H[" << resi + 1 << "] is : ";
			cout << H[resi];
			break;

		default:
			cout << "\nplease enter the valid operation \n";
			break;

		}
		cout << "\nDo you want to continue with calculator type 6 (Y/N)";
		cin >> tocont;

	} while (tocont == 'y' or tocont == 'Y');
}

void Menu7()
{
	cout << "\n\tPress H1>H2 to check if H1 greater than H2...";
	cout << "\n\tPress H1<H2 to check if H1 Less than H2...";
	cout << endl << endl;

}
void Calculator7(HugeInteger*& H, int& size)
{

	int resi, pi, di;
	char d;
	char oprt;
	char tocont;
	bool ch;
	do
	{
		Menu(H, size);
		Menu7();
		//H1>H2
		cin >> d >> resi >> oprt >> d >> pi;
		resi--;
		pi--;
		switch (oprt)
		{
		case '>':
			ch = (H[resi] > H[pi]);
			cout << ch;

			break;
		case '<':
			ch = (H[resi] < H[pi]);
			cout << ch;
			break;
		

		default:
			cout << "\nplease enter the valid operation \n";
			break;

		}
		cout << "\nDo you want to continue with calculator type 7 (Y/N)";
		cin >> tocont;

	} while (tocont == 'y' or tocont == 'Y');
}

int main()
{
	HugeInteger* H;
	int size;
	int opt;
	char tocont;
	Read(H,size);
	do
	{
		system("cls");
		MainMenu();
		do
		{
			system("color 8B");
			if (_kbhit())
			{
				break;
			}
			Sleep(1000);
			system("color 06");
			if (_kbhit())
			{
				break;
			}
			Sleep(1000);
			system("color F9");
			if (_kbhit())
			{
				break;
			}
			Sleep(1000);


		} while (!_kbhit());

		cin >> opt;

		switch (opt)
		{
		case 1:
			Calculator(H, size);
			break;
		case 2:
			Calculator2(H, size);
			break;
		case 3:
			Calculator3(H, size);
		case 4:
			Calculator4(H, size);
			break;
		case 5:
			Calculator5(H, size);
			break;
		case 6:
			Calculator6(H, size);
			break;
		case 7:
			Calculator7(H, size);
			break;
		default:
			cout << "\nPlease input valid operations ...\n";
		}

		cout << "\nDo you want to continue with calculator\n";
		cin >> tocont;
	} while (tocont=='Y' or tocont=='y');
}