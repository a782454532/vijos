//1) Ժʿ��ѧ��ÿ��8000Ԫ����ĩƽ���ɼ�����80�֣�>80���������ڱ�ѧ���ڷ���1ƪ��1ƪ�����۵�ѧ�����ɻ�ã�
//2) ���Ľ�ѧ��ÿ��4000Ԫ����ĩƽ���ɼ�����85�֣�>85�������Ұ༶����ɼ�����80�֣�>80����ѧ�����ɻ�ã�
//3) �ɼ����㽱��ÿ��2000Ԫ����ĩƽ���ɼ�����90�֣�>90����ѧ�����ɻ�ã�
//4) ������ѧ��ÿ��1000Ԫ����ĩƽ���ɼ�����85�֣�>85��������ʡ��ѧ�����ɻ�ã�
//5) �༶���׽���ÿ��850Ԫ���༶����ɼ�����80�֣�>80����ѧ���ɲ����ɻ�ã�
//�����ʽ
//
//����ĵ�һ����һ������N��1 <= N <= 100������ʾѧ����������������N��ÿ����һλѧ�������ݣ�����������������������ĩƽ���ɼ����༶����ɼ����Ƿ���ѧ���ɲ����Ƿ�������ʡ��ѧ�����Լ�����������������ɴ�СдӢ��ĸ��ɵĳ��Ȳ�����20���ַ����������ո񣩣���ĩƽ���ɼ��Ͱ༶����ɼ�����0��100֮�������������0��100�����Ƿ���ѧ���ɲ����Ƿ�������ʡ��ѧ���ֱ���һ���ַ���ʾ��Y��ʾ�ǣ�N��ʾ���ǣ������������0��10������������0��10��ÿ��������������֮����һ���ո�ָ�
//�����ʽ
//
//����������У���һ���ǻ����ཱ���ѧ�����������ڶ���������ѧ����õĽ��������������λ����λ���ϵ�ѧ����õĽ�����࣬�������֮����������г��������ѧ������������������N��ѧ����õĽ�ѧ�������
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Mate{
	private:
		double average;
		double evaluation;
		char cadres;
		char west_province;
		int paper_num;
		int fun1();
		int fun2();
		int fun3();
		int fun4();
		int fun5();
	public:
		string name;
		void input();
		int money();
};
int Mate::fun1(){
	if(average>80&&paper_num>0)
		return 8000;
	return 0;
}

int Mate::fun2(){
	if(average>85&&evaluation>80) return 4000;
	return 0;
}

int Mate::fun3(){
	if(average>90) return 2000;
	return 0;
}

int Mate::fun4(){
	if(average>85&&west_province=='Y') return 1000;
	else return 0;
}

int Mate::fun5(){
	if(evaluation>80&&cadres=='Y') return 850;
	else return 0;
}

int Mate::money(){
	return fun1()+fun2()+fun3()+fun4()+fun5();
}

void Mate::input(){
	cin >> name >> average >> evaluation >> cadres >> west_province >> paper_num;
}

int main(){
	int num;
	cin>>num;
	vector<Mate> person(num);
	for (int i = 0; i < num; i++)
		person[i].input();
	int maxmoney=0;
	int maxsite=-1;
	int moneynum=0;
	for(int i=0;i<num;i++){
		int moneyOne=person[i].money();
		if(moneyOne>maxmoney) {
			maxmoney=moneyOne;
			maxsite=i;
		}
		moneynum+=moneyOne;
	}
	cout<<person[maxsite].name<<endl<<maxmoney<<endl<<moneynum;
	return 0;
}
