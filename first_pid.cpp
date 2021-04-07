#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

#define KPVALUE 1
#define KIVALUE 0
#define KDVALUE 0

const int setpoint = 50;

#define INTERFERENCE -10

int main(int argc, char const *argv[])
{
	srand( time(NULL) );
	double previous_error = 0;
	double integral = 0;

	double error;

	double measured_value = 50;
	
	int derivative;
	int output;

	double Kp = KPVALUE;
	double Ki = KIVALUE;
	double Kd = KDVALUE;
	
	for (int i = 0; i < 100; i++)
	{
		cout << "measured_value = " << measured_value << endl;
		measured_value = measured_value + output + INTERFERENCE;


	  	error = setpoint - measured_value;
  		integral = integral + error;
  		derivative = error - previous_error;
  		output = Kp*error + Ki*integral + Kd*derivative;
  		previous_error = error;
	}
  
	system("pause");
	return 0;
}