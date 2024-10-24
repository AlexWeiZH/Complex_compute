#include<iostream>
#include<typeinfo>
#include "complex.h"
using namespace std;

CComplex::CComplex(CComplex &c){								//拷贝构造函数的实现
	real=c.real; 
	imag=c.imag;
}

CComplex CComplex::Add(CComplex &c2){								//带一个参数的复数加运算的实现
	return CComplex(real+c2.real,imag+c2.imag);

}

CComplex CComplex::Sub(CComplex &c2){								//带一个参数的复数减运算的实现
	return CComplex(real-c2.real,imag-c2.imag);
}

CComplex CComplex::Mul(CComplex &c2){								//带一个参数的复数乘运算的实现
	return CComplex(real*c2.real,imag*c2.imag);
}

CComplex CComplex::Div(CComplex &c2){								//带一个参数的复数除运算的实现
	if(c2.real==0||c2.imag==0){
		throw invalid_argument("除数不得为0!");
		return CComplex(99999.999,99999.999);	
	}
	else{
		return CComplex(real/c2.real,imag/c2.imag);
	}
}

CComplex CComplex::Add(double real1, double imag1){
	return CComplex(real+real1,imag+imag1);
}																//带两个参数的复数加运算的实现

CComplex CComplex::Sub(double real1, double imag1){
	return CComplex(real-real1,imag-imag1);
}																//带两个参数的复数减运算的实现

CComplex CComplex::Mul(double real1, double imag1){
	return CComplex(real*real1,imag*imag1);
}																//带两个参数的复数乘运算的实现

CComplex CComplex::Div(double real1, double imag1){
	if(real==0||imag==0){
		cout<<"除数不能为0！"<<endl;
		return CComplex(99999,99999);
	}															//带两个参数的复数除运算的实现
	return CComplex(real/real1,imag/imag1);
}	


CComplex CComplex::operator + (const CComplex &c2) const{		//重载+运算符函数实现
	return CComplex(real+c2.real,imag+c2.imag); 
}
	
CComplex CComplex::operator - (const CComplex &c2) const {		//重载-运算符函数实现
	return CComplex(real-c2.real,imag-c2.imag); 
}

CComplex CComplex::operator * (const CComplex &c2) const {		//重载*运算符函数实现
	return CComplex(real*c2.real,imag * c2.imag); 
}

CComplex CComplex::operator / (const CComplex &c2) const {		//重载/运算符函数实现
	if(c2.imag==0||c2.real==0){
		throw invalid_argument("除数不得为0!");
		return CComplex(99999.999,99999.999);					//除数为0的情况
	}
	return CComplex(real/c2.real,imag/c2.imag); 
}

CComplex CComplex::operator = (const CComplex &c2)  {			//重载=运算符函数实现
	return CComplex(real=c2.real,imag=c2.imag); 
}

CComplex operator + (const CComplex &c1, const CComplex &c2) {	//友元函数重载运算符+函数实现
	return CComplex(c1.real+c2.real,c1.imag+c2.imag); 
}

CComplex operator - (const CComplex &c1, const CComplex &c2) {	//友元函数重载运算符-函数实现
	return CComplex(c1.real - c2.real, c1.imag - c2.imag); 
}

CComplex operator * (const CComplex &c1, const CComplex &c2) {	//友元函数重载运算符*函数实现
	return CComplex(c1.real * c2.real, c1.imag * c2.imag); 
}

CComplex operator / (const CComplex &c1, const CComplex &c2) { 
	if(c2.imag==0||c2.real==0){
		throw invalid_argument("除数不得为0!");
		return CComplex(99999.999,99999.999);					//除数为0的情况
	}																		
	return CComplex(c1.real / c2.real, c1.imag / c2.imag); 
}
void CComplex::Print(CComplex c2)  {							//复数输出函数的实现
	cout<<"("<<c2.real<<","<<c2.imag<<")"<<endl;	
}

double CComplex::Root(CComplex c2)								//复数求模函数的实现
{
        return sqrt(c2.real*c2.real+c2.imag*c2.imag);
}

int main(){
	double a,b,c,d;
	char k;

	cout<<"请输入两个个复数的实部和虚部"<<endl;
	cout<<"第一个复数的实部为：";
	cin>>a;
	cout<<"第一个复数的虚部为：";
	cin>>b;
	CComplex c1(a,b);

	cout<<endl;
	cout<<"第二个复数的实部为：";
	cin>>c;
	cout<<"第二个复数的虚部为：";
	cin>>d;

	CComplex c2(c,d);

	cout<<"若要进行 + 运算，请输入1"<<endl;
	cout<<"若要进行 - 运算，请输入2"<<endl;
	cout<<"若要进行 * 运算，请输入3"<<endl;
	cout<<"若要进行 / 运算，请输入4"<<endl;
	cin>>k;
	while(k!='0'){
		double a,b,c,d;
		switch (k)
		{
			case '1':
				c1.getComplex(c1,a,b);
				c2.getComplex(c2,c,d);
				cout<<"("<<a<<","<<b<<"i)"<<"+"<<"("<<c<<","<<d<<"i)"<<"=";
				c1=c1.Add(c2);
				c1.Print(c1);
				cout<<"若要进行 + 运算，请输入1"<<endl;
				cout<<"若要进行 - 运算，请输入2"<<endl;
				cout<<"若要进行 * 运算，请输入3"<<endl;
				cout<<"若要进行 / 运算，请输入4"<<endl;
				cout<<"若要退出，请输入0"<<endl;
				cin>>k;
				if(k=='1'||k=='2'||k=='3'||k=='4')
				{
					cout<<"请输入两个个复数的实部和虚部"<<endl;
					cout<<"第一个复数的实部为：";
					cin>>a;
					cout<<"第一个复数的虚部为：";
					cin>>b;
					c1.setComplex(a,b);

					cout<<endl;
					cout<<"第二个复数的实部为：";
					cin>>c;
					cout<<"第二个复数的虚部为：";
					cin>>d;
					c2.setComplex(c,d);
				}
				else if(k!='0'&&k!='1'&&k!='2'&&k!='3'&&k!='4'){cout<<"您输入了错误的数字！请重新输入"<<endl;cin>>k;break;}
				else if(k=='0'){break;}
				break;
			case '2':
				c1.getComplex(c1,a,b);
				c2.getComplex(c2,c,d);
				cout<<"("<<a<<","<<b<<"i)"<<"-"<<"("<<c<<","<<d<<"i)"<<"=";
				c1=c1.Sub(c2);
				c1.Print(c1);
				cout<<"若要进行 + 运算，请输入1"<<endl;
				cout<<"若要进行 - 运算，请输入2"<<endl;
				cout<<"若要进行 * 运算，请输入3"<<endl;
				cout<<"若要进行 / 运算，请输入4"<<endl;
				cout<<"若要退出，请输入0"<<endl;
				cin>>k;
				if(k=='1'||k=='2'||k=='3'||k=='4')
				{
					cout<<"请输入两个个复数的实部和虚部"<<endl;
					cout<<"第一个复数的实部为：";
					cin>>a;
					cout<<"第一个复数的虚部为：";
					cin>>b;
					c1.setComplex(a,b);

					cout<<endl;
					cout<<"第二个复数的实部为：";
					cin>>c;	
					cout<<"第二个复数的虚部为：";
					cin>>d;	
					c2.setComplex(c,d);
				}
				else if(k!='0'&&k!='1'&&k!='2'&&k!='3'&&k!='4'){cout<<"您输入了错误的数字！请重新输入"<<endl;cin>>k;break;}
				else if(k=='0'){break;}
				break;

			case '3':
				c1.getComplex(c1,a,b);
				c2.getComplex(c2,c,d);
				cout<<"("<<a<<","<<b<<"i)"<<"*"<<"("<<c<<","<<d<<"i)"<<"=";
				c1=c1.Mul(c2);
				c1.Print(c1);
				cout<<"若要进行 + 运算，请输入1"<<endl;
				cout<<"若要进行 - 运算，请输入2"<<endl;
				cout<<"若要进行 * 运算，请输入3"<<endl;
				cout<<"若要进行 / 运算，请输入4"<<endl;
				cout<<"若要退出，请输入0"<<endl;
				cin>>k;
				if(k=='1'||k=='2'||k=='3'||k=='4')
				{
					cout<<"请输入两个个复数的实部和虚部"<<endl;
					cout<<"第一个复数的实部为：";
					cin>>a;		
					cout<<"第一个复数的虚部为：";
					cin>>b;		
					c1.setComplex(a,b);

					cout<<endl;
					cout<<"第二个复数的实部为：";
					cin>>c;
					cout<<"第二个复数的虚部为：";
					cin>>d;		
					c2.setComplex(c,d);
				}
				else if(k!='0'&&k!='1'&&k!='2'&&k!='3'&&k!='4'){cout<<"您输入了错误的数字！请重新输入"<<endl;cin>>k;break;}
				else if(k=='0'){break;}
				break;

			case '4':try{
					c1.getComplex(c1,a,b);
					c2.getComplex(c2,c,d);
					cout<<"("<<a<<","<<b<<"i)"<<"/"<<"("<<c<<","<<d<<"i)"<<"=";
					c1=c1.Div(c2);
					c1.Print(c1);
				   }catch(exception &e){cout << "Error: " << e.what() << endl;}
				cout<<"若要进行 + 运算，请输入1"<<endl;
				cout<<"若要进行 - 运算，请输入2"<<endl;
				cout<<"若要进行 * 运算，请输入3"<<endl;
				cout<<"若要进行 / 运算，请输入4"<<endl;
				cout<<"若要退出，请输入0"<<endl;
				cin>>k;
				if(k=='1'||k=='2'||k=='3'||k=='4')
				{
					cout<<"请输入两个个复数的实部和虚部"<<endl;
					cout<<"第一个复数的实部为：";
					cin>>a;
					cout<<"第一个复数的虚部为：";
					cin>>b;
					c1.setComplex(a,b);

					cout<<endl;
					cout<<"第二个复数的实部为：";
					cin>>c;
					cout<<"第二个复数的虚部为：";
					cin>>d;
					c2.setComplex(c,d);
				}
			    else if(k!='0'&&k!='1'&&k!='2'&&k!='3'&&k!='4'){cout<<"您输入了错误的数字！请重新输入"<<endl;cin>>k;break;}
				else if(k=='0'){break;}
				break;
		default:
			cout<<"你输入了错误的数字！请输入1--4之间的整数"<<endl;
			cout<<"若要进行 + 运算，请输入1"<<endl;
			cout<<"若要进行 - 运算，请输入2"<<endl;
			cout<<"若要进行 * 运算，请输入3"<<endl;
			cout<<"若要进行 / 运算，请输入4"<<endl;
			cout<<"若要退出，请输入0"<<endl;
			cin>>k;
			if(k!='0'&&k!='1'&&k!='2'&&k!='3'&&k!='4'){cout<<"您输入了错误的数字！请重新输入"<<endl;cin>>k;break;}
			else if(k=='0'){break;}
			else break;
	}
}
	system("pause");
	return 0;
}