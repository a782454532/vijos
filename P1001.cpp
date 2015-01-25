//1) 院士奖学金，每人8000元，期末平均成绩高于80分（>80），并且在本学期内发表1篇或1篇以上论的学生均可获得；
//2) 五四奖学金，每人4000元，期末平均成绩高于85分（>85），并且班级评议成绩高于80分（>80）的学生均可获得；
//3) 成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）的学生均可获得；
//4) 西部奖学金，每人1000元，期末平均成绩高于85分（>85）的西部省份学生均可获得；
//5) 班级贡献奖，每人850元，班级评议成绩高于80分（>80）的学生干部均可获得；
//输入格式
//
//输入的第一行是一个整数N（1 <= N <= 100），表示学生的总数接下来的N行每行是一位学生的数据，从左向右依次是姓名，期末平均成绩，班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论数姓名是由大小写英字母组成的长度不超过20的字符串（不含空格）；期末平均成绩和班级评议成绩都是0到100之间的整数（包括0和100）；是否是学生干部和是否是西部省份学生分别用一个字符表示，Y表示是，N表示不是；发表的论数是0到10的整数（包括0和10）每两个相邻数据项之间用一个空格分隔
//输出格式
//
//输出包括三行，第一行是获得最多奖金的学生的姓名，第二行是这名学生获得的奖金总数如果有两位或两位以上的学生获得的奖金最多，输出他们之中在输入件中出现最早的学生的姓名第三行是这N个学生获得的奖学金的总数
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
