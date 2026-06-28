#include<iostream>
using namespace std;
#include"bank.cpp"
int main()
{
	Bank ser1(1000, "12345678");
	bool Exit = false;
	int language, operation, count = 0;
	string interPassword;
	double interCash, interDeposit;
	string answer;
	do
	{
		if (count == 0)
		{
			cout << "\n\n\t\t\t\t\t\tWelcome to Banque Misr\n\n";
			cout << "Choose the language\n\n1.English\n\n2.يبرع\n\n=> ";
			cin >> language;
			system("cls");
		}
		if (language == 1)
		{
			if (count == 0)
			{
				cout << "Entre your password\n\n=> ";
				cin >> interPassword;
			}
			if (ser1.checkpass(interPassword))
			{
				system("cls");
				cout << "Choose the operation\n\n";
				cout << "1.Balance Check\n\n2.Withdrawal\n\n3.Deposit\n\n=> ";
				cin >> operation;
				if (operation == 1)
				{
					system("cls");
					cout << "Current Balance : " << ser1.getbalance() << "\n";
				}
				else if (operation == 2)
				{
					system("cls");
					cout << "Enter the Amount to withdraw\n\n=> ";
					cin >> interCash;
					if (ser1.Withdrawal(interCash))
					{
						cout << "Withdrawal Successful\n\n";
					}
					else
					{
						cout << "Not enough balance\n\n";
					}
				}
				else if (operation == 3)
				{
					system("cls");
					cout << "Enter the Amount to deposit\n\n=> ";
					cin >> interDeposit;
					if (ser1.Deposit(interDeposit))
					{
						cout << "Deposit Successful\n\n";
					}
					else
					{
						cout << "Rejected Transaction\n\n";
					}
				}
				else
				{
					cout << "Invalid operation.\n\n";
				}
				cout << "Do you want to do anther operation?\n";
				cin >> answer;
				for (int i = 0; i < answer.size(); i++)
				{
					answer[i] = tolower(answer[i]);
				}
				if (answer == "yes")
				{
					system("cls");
					Exit = true;
				}
				else
				{
					system("cls");
					cout << "\t\t\t\t\tThank you for using Banque Misr services\n\n";
					Exit = false;
				}
				count++;
			}
			else
			{
				cout << "Wrong Password.";
				system("cls");
				Exit = true;
			}
		}
		else if (language == 2)
		{
			if (count == 0)
			{
				cout << "يرسلا مقرلا لخدا\n\n=> "; // ادخل الرقم السري
				cin >> interPassword;
			}
			if (ser1.checkpass(interPassword))
			{
				system("cls");
				cout << "ةيلمعلا رتخا\n\n"; // اختر العمليه 
				cout << "ديصرلا نع مالعتسإ .1\n\n"; // استعلام عن الرصيد
				cout << "غلبم بحس .2\n\n"; // سحب مبلغ
				cout << "غلبم عاديإ .3\n\n=> "; // ايداع مبلغ
				cin >> operation;
				if (operation == 1)
				{
					system("cls");
					cout << ser1.getbalance() << " : يلاحلا كديصر" << "\n\n"; // رصيدك الحالي
				}
				else if (operation == 2)
				{
					system("cls");
					cout << "هبحس دارملا غلبملا لخدا\n\n=> "; // ادخل المبلغ المراد سحبه
					cin >> interCash;
					if (ser1.Withdrawal(interCash))
					{
						cout << "\nحاجنب بحسلا ةيلمع تمت\n\n"; // تمت عملية السحب بنجاح	
					}
					else
					{
						cout << "\nفاك ريغ كديصر\n\n"; // رصيد غير كافٍ

					}
				}
				else if (operation == 3)
				{
					system("cls");
					cout << "هعاديإ دارملا غلبملا لخدا\n\n=> "; // ادخل المبلغ المراد إيداعه
					cin >> interDeposit;
					if (ser1.Deposit(interDeposit))
					{
						cout << "\nحاجنب عاديإلا ةيلمع تمت\n\n"; // تمت عملية الإيداع بنجاح
					}
					else
					{
						cout << "ةضوفرم ةيلمعلا\n\n";
					}
				}
				else
				{
					cout << "ةحيحص ريغ ةيلمع\n\n"; // عملية غير صحيحة
				}
				cout << "؟ىرخأ ةيلمعب مايقلا ديرت له\n\n"; // هل تريد القيام بعملية أخرى؟
				cin >> answer;
				if (answer == "نعم")
				{
					Exit = true;
					system("cls");
				}
				else
				{
					system("cls");
					cout << "\t\t\t\t\t\tرصم كنب تامدخ كمادختسال اًركش\n\n"; // شكراً لاستخدامك خدمات بنك مصر
					Exit = false;
				}
				count++;
			}
			else
			{
				cout << "حيحص ريغ يرس مقر!\n";
				system("cls");
				Exit = true;
			}
		}
		else
		{
			cout << "Invalid language.";
			Exit = true;
		}
	} while (Exit);
	return 0;
}