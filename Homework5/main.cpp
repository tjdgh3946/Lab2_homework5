#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <assert.h>

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
	cout << "계좌 잔고: " << balance /10000<< "만원 나의 이더리움 수량: " << ETH_volume << " 평단가: "<< unit_price /10000<<"만원 "<< "총 보유자산:"<<total/10000<<"만원\n"<<endl;
}

void Buy_market_order(float price)
{
	float volume = price / ETH_price; 
	balance -= price;
	float temp = (unit_price * ETH_volume + price) / (ETH_volume+volume); //평단가 
	unit_price = temp; 
	ETH_volume += volume;
	cout << current_time << "에 " << "이더리움 " << volume << "개" <<" 시장가 " <<ETH_price/10000<< "만원에 매수주문이 체결되었습니다." << endl;
	notion();
}

void Sell_market_order(float volume)
{
	balance += ETH_price*volume; 
	ETH_volume -= volume; 
	cout << current_time << "에 " << "이더리움 " << volume << "개" <<" 시장가 " << ETH_price / 10000<< "만원에 매도주문이 체결되었습니다." << endl;
	if (ETH_volume == 0.0) unit_price = 0.0;
	notion(); 
}

int main() {
	char cstr[512];
	fstream fs;
	ifstream myfile("ETH_chart.csv");
	string piece; 
	bool flag = false; 
	float old=0.0; 

	int count = 0; 
	while (myfile.peek() != EOF) {
		myfile.getline(cstr, 20);
		stringstream stream(cstr);

		for (int i = 0; i < 2; i++)
		{
			getline(stream, piece, ',');
		
			if (i == 1){
				ETH_price = stof(piece);
				if (old == ETH_price) {
					count += 1;
				}
				else count = 0; 
				old = ETH_price; 
			}
			else {
				strcpy_s(current_time, piece.c_str());
			}
		}
	
		/*매수 파트 */
		if (count == 6) Buy_market_order(balance * 0.5);
		if (count == 5) Buy_market_order(balance * 0.25);

		
		/*매도 파트*/
		if (1.011*unit_price <=  ETH_price && ETH_volume > 0.0) Sell_market_order(ETH_volume); 
		if (1.008*unit_price <= ETH_price && ETH_volume > 0.0) Sell_market_order(0.2 * ETH_volume);

	}
	
	return 0; 
}