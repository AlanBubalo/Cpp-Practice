#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string rijec;
	int duljina;
	cout << "Upisi rijec:";
	cin >> rijec;
	duljina = 20 - rijec.size();
	if (duljina > 0) rijec.append(duljina, 'a');
	cout << rijec << endl;
	system ("pause");
	return 0;
}
