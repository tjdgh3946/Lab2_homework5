#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <windows.h>

int balance=50000000; 
float ETH_volume = 0;
float ETH_price = 0.0;
float unit_price = 0.0; 
char current_time[15]; 
using namespace std;


void notion()
{
	float total = balance + ETH_price * ETH_volume; 
	cout.precision(8);
	cout << "���� �ܰ�: " << balance /10000<< "���� ���� �̴����� ����: " << ETH_volume << " ��ܰ�: "<< unit_price /10000<<"���� "<< "�� �����ڻ�:"<<total/10000<<"����\n"<<endl;
}

void Buy_market_order(float price)
{

	/**TODO: volume, balance, unit_price ������Ʈ**/

	cout << current_time << "�� " << "�̴����� " << volume << "��" <<" ���尡 " <<ETH_price/10000<< "������ �ż��ֹ��� ü��Ǿ����ϴ�." << endl;
	notion();
}

void Sell_market_order(float volume)
{

	cout << current_time << "�� " << "�̴����� " << volume << "��" <<" ���尡 " << ETH_price / 10000<< "������ �ŵ��ֹ��� ü��Ǿ����ϴ�." << endl;
	notion(); 
}

int main() {
	char cstr[512];
	fstream fs;
	ifstream myfile("ETH_chart.csv");
	string piece; 

	int count = 0; 
	while (myfile.peek() != EOF) {
		myfile.getline(cstr, 20);
		stringstream stream(cstr);
		for (int i = 0; i < 2; i++)
		{
			getline(stream, piece, ',');
		
			if (i == 1){
				ETH_price = stof(piece);
			}
			else {
				strcpy_s(current_time, piece.c_str());
			}
		}

		/*�ż� ��Ʈ */
	
		
		/*�ŵ� ��Ʈ*/
	

	}
	
	return 0; 
}