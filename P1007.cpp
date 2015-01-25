#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;
int main(){
	int num;
	cin >> num;
	double r;
	cin >> r;
	double sum = 0;
	vector<double> x(num);
	vector<double> y(num);
	for (int i = 0; i<num; i++)
		cin >> x[i] >> y[i];
	for (int i = 1; i<num; i++)
		sum += sqrt((x[i] - x[i - 1])*(x[i] - x[i - 1]) + (y[i] - y[i - 1])*(y[i] - y[i - 1]));
	sum += sqrt((x[num - 1] - x[0])*(x[num - 1] - x[0]) + (y[num - 1] - y[0])*(y[num - 1] - y[0]));
	sum += 2 * 3.1415926*r;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<sum<<endl;
	return 0;
}
