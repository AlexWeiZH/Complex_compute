#include<iostream>
#include<typeinfo>
#include "complex.h"
using namespace std;

CComplex::CComplex(CComplex &c){								//�������캯����ʵ��
	real=c.real; 
	imag=c.imag;
}

CComplex CComplex::Add(CComplex &c2){								//��һ�������ĸ����������ʵ��
	return CComplex(real+c2.real,imag+c2.imag);

}

CComplex CComplex::Sub(CComplex &c2){								//��һ�������ĸ����������ʵ��
	return CComplex(real-c2.real,imag-c2.imag);
}

CComplex CComplex::Mul(CComplex &c2){								//��һ�������ĸ����������ʵ��
	return CComplex(real*c2.real,imag*c2.imag);
}

CComplex CComplex::Div(CComplex &c2){								//��һ�������ĸ����������ʵ��
	if(c2.real==0||c2.imag==0){
		throw invalid_argument("��������Ϊ0!");
		return CComplex(99999.999,99999.999);	
	}
	else{
		return CComplex(real/c2.real,imag/c2.imag);
	}
}

CComplex CComplex::Add(double real1, double imag1){
	return CComplex(real+real1,imag+imag1);
}																//�����������ĸ����������ʵ��

CComplex CComplex::Sub(double real1, double imag1){
	return CComplex(real-real1,imag-imag1);
}																//�����������ĸ����������ʵ��

CComplex CComplex::Mul(double real1, double imag1){
	return CComplex(real*real1,imag*imag1);
}																//�����������ĸ����������ʵ��

CComplex CComplex::Div(double real1, double imag1){
	if(real==0||imag==0){
		cout<<"��������Ϊ0��"<<endl;
		return CComplex(99999,99999);
	}															//�����������ĸ����������ʵ��
	return CComplex(real/real1,imag/imag1);
}	


CComplex CComplex::operator + (const CComplex &c2) const{		//����+���������ʵ��
	return CComplex(real+c2.real,imag+c2.imag); 
}
	
CComplex CComplex::operator - (const CComplex &c2) const {		//����-���������ʵ��
	return CComplex(real-c2.real,imag-c2.imag); 
}

CComplex CComplex::operator * (const CComplex &c2) const {		//����*���������ʵ��
	return CComplex(real*c2.real,imag * c2.imag); 
}

CComplex CComplex::operator / (const CComplex &c2) const {		//����/���������ʵ��
	if(c2.imag==0||c2.real==0){
		throw invalid_argument("��������Ϊ0!");
		return CComplex(99999.999,99999.999);					//����Ϊ0�����
	}
	return CComplex(real/c2.real,imag/c2.imag); 
}

CComplex CComplex::operator = (const CComplex &c2)  {			//����=���������ʵ��
	return CComplex(real=c2.real,imag=c2.imag); 
}

CComplex operator + (const CComplex &c1, const CComplex &c2) {	//��Ԫ�������������+����ʵ��
	return CComplex(c1.real+c2.real,c1.imag+c2.imag); 
}

CComplex operator - (const CComplex &c1, const CComplex &c2) {	//��Ԫ�������������-����ʵ��
	return CComplex(c1.real - c2.real, c1.imag - c2.imag); 
}

CComplex operator * (const CComplex &c1, const CComplex &c2) {	//��Ԫ�������������*����ʵ��
	return CComplex(c1.real * c2.real, c1.imag * c2.imag); 
}

CComplex operator / (const CComplex &c1, const CComplex &c2) { 
	if(c2.imag==0||c2.real==0){
		throw invalid_argument("��������Ϊ0!");
		return CComplex(99999.999,99999.999);					//����Ϊ0�����
	}																		
	return CComplex(c1.real / c2.real, c1.imag / c2.imag); 
}
void CComplex::Print(CComplex c2)  {							//�������������ʵ��
	cout<<"("<<c2.real<<","<<c2.imag<<")"<<endl;	
}

double CComplex::Root(CComplex c2)								//������ģ������ʵ��
{
        return sqrt(c2.real*c2.real+c2.imag*c2.imag);
}

int main(){
	double a,b,c,d;
	char k;

	cout<<"������������������ʵ�����鲿"<<endl;
	cout<<"��һ��������ʵ��Ϊ��";
	cin>>a;
	cout<<"��һ���������鲿Ϊ��";
	cin>>b;
	CComplex c1(a,b);

	cout<<endl;
	cout<<"�ڶ���������ʵ��Ϊ��";
	cin>>c;
	cout<<"�ڶ����������鲿Ϊ��";
	cin>>d;

	CComplex c2(c,d);

	cout<<"��Ҫ���� + ���㣬������1"<<endl;
	cout<<"��Ҫ���� - ���㣬������2"<<endl;
	cout<<"��Ҫ���� * ���㣬������3"<<endl;
	cout<<"��Ҫ���� / ���㣬������4"<<endl;
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
				cout<<"��Ҫ���� + ���㣬������1"<<endl;
				cout<<"��Ҫ���� - ���㣬������2"<<endl;
				cout<<"��Ҫ���� * ���㣬������3"<<endl;
				cout<<"��Ҫ���� / ���㣬������4"<<endl;
				cout<<"��Ҫ�˳���������0"<<endl;
				cin>>k;
				if(k=='1'||k=='2'||k=='3'||k=='4')
				{
					cout<<"������������������ʵ�����鲿"<<endl;
					cout<<"��һ��������ʵ��Ϊ��";
					cin>>a;
					cout<<"��һ���������鲿Ϊ��";
					cin>>b;
					c1.setComplex(a,b);

					cout<<endl;
					cout<<"�ڶ���������ʵ��Ϊ��";
					cin>>c;
					cout<<"�ڶ����������鲿Ϊ��";
					cin>>d;
					c2.setComplex(c,d);
				}
				else if(k!='0'&&k!='1'&&k!='2'&&k!='3'&&k!='4'){cout<<"�������˴�������֣�����������"<<endl;cin>>k;break;}
				else if(k=='0'){break;}
				break;
			case '2':
				c1.getComplex(c1,a,b);
				c2.getComplex(c2,c,d);
				cout<<"("<<a<<","<<b<<"i)"<<"-"<<"("<<c<<","<<d<<"i)"<<"=";
				c1=c1.Sub(c2);
				c1.Print(c1);
				cout<<"��Ҫ���� + ���㣬������1"<<endl;
				cout<<"��Ҫ���� - ���㣬������2"<<endl;
				cout<<"��Ҫ���� * ���㣬������3"<<endl;
				cout<<"��Ҫ���� / ���㣬������4"<<endl;
				cout<<"��Ҫ�˳���������0"<<endl;
				cin>>k;
				if(k=='1'||k=='2'||k=='3'||k=='4')
				{
					cout<<"������������������ʵ�����鲿"<<endl;
					cout<<"��һ��������ʵ��Ϊ��";
					cin>>a;
					cout<<"��һ���������鲿Ϊ��";
					cin>>b;
					c1.setComplex(a,b);

					cout<<endl;
					cout<<"�ڶ���������ʵ��Ϊ��";
					cin>>c;	
					cout<<"�ڶ����������鲿Ϊ��";
					cin>>d;	
					c2.setComplex(c,d);
				}
				else if(k!='0'&&k!='1'&&k!='2'&&k!='3'&&k!='4'){cout<<"�������˴�������֣�����������"<<endl;cin>>k;break;}
				else if(k=='0'){break;}
				break;

			case '3':
				c1.getComplex(c1,a,b);
				c2.getComplex(c2,c,d);
				cout<<"("<<a<<","<<b<<"i)"<<"*"<<"("<<c<<","<<d<<"i)"<<"=";
				c1=c1.Mul(c2);
				c1.Print(c1);
				cout<<"��Ҫ���� + ���㣬������1"<<endl;
				cout<<"��Ҫ���� - ���㣬������2"<<endl;
				cout<<"��Ҫ���� * ���㣬������3"<<endl;
				cout<<"��Ҫ���� / ���㣬������4"<<endl;
				cout<<"��Ҫ�˳���������0"<<endl;
				cin>>k;
				if(k=='1'||k=='2'||k=='3'||k=='4')
				{
					cout<<"������������������ʵ�����鲿"<<endl;
					cout<<"��һ��������ʵ��Ϊ��";
					cin>>a;		
					cout<<"��һ���������鲿Ϊ��";
					cin>>b;		
					c1.setComplex(a,b);

					cout<<endl;
					cout<<"�ڶ���������ʵ��Ϊ��";
					cin>>c;
					cout<<"�ڶ����������鲿Ϊ��";
					cin>>d;		
					c2.setComplex(c,d);
				}
				else if(k!='0'&&k!='1'&&k!='2'&&k!='3'&&k!='4'){cout<<"�������˴�������֣�����������"<<endl;cin>>k;break;}
				else if(k=='0'){break;}
				break;

			case '4':try{
					c1.getComplex(c1,a,b);
					c2.getComplex(c2,c,d);
					cout<<"("<<a<<","<<b<<"i)"<<"/"<<"("<<c<<","<<d<<"i)"<<"=";
					c1=c1.Div(c2);
					c1.Print(c1);
				   }catch(exception &e){cout << "Error: " << e.what() << endl;}
				cout<<"��Ҫ���� + ���㣬������1"<<endl;
				cout<<"��Ҫ���� - ���㣬������2"<<endl;
				cout<<"��Ҫ���� * ���㣬������3"<<endl;
				cout<<"��Ҫ���� / ���㣬������4"<<endl;
				cout<<"��Ҫ�˳���������0"<<endl;
				cin>>k;
				if(k=='1'||k=='2'||k=='3'||k=='4')
				{
					cout<<"������������������ʵ�����鲿"<<endl;
					cout<<"��һ��������ʵ��Ϊ��";
					cin>>a;
					cout<<"��һ���������鲿Ϊ��";
					cin>>b;
					c1.setComplex(a,b);

					cout<<endl;
					cout<<"�ڶ���������ʵ��Ϊ��";
					cin>>c;
					cout<<"�ڶ����������鲿Ϊ��";
					cin>>d;
					c2.setComplex(c,d);
				}
			    else if(k!='0'&&k!='1'&&k!='2'&&k!='3'&&k!='4'){cout<<"�������˴�������֣�����������"<<endl;cin>>k;break;}
				else if(k=='0'){break;}
				break;
		default:
			cout<<"�������˴�������֣�������1--4֮�������"<<endl;
			cout<<"��Ҫ���� + ���㣬������1"<<endl;
			cout<<"��Ҫ���� - ���㣬������2"<<endl;
			cout<<"��Ҫ���� * ���㣬������3"<<endl;
			cout<<"��Ҫ���� / ���㣬������4"<<endl;
			cout<<"��Ҫ�˳���������0"<<endl;
			cin>>k;
			if(k!='0'&&k!='1'&&k!='2'&&k!='3'&&k!='4'){cout<<"�������˴�������֣�����������"<<endl;cin>>k;break;}
			else if(k=='0'){break;}
			else break;
	}
}
	system("pause");
	return 0;
}