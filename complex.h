class CComplex {	//复数类定义
public:	
	CComplex();//缺省的构造函数
	CComplex(double r = 0.0, double i = 0.0) : real(r), imag(i){}//带参数的构造函数
	CComplex(CComplex &c);//拷贝构造函数

	CComplex Add(CComplex &c2);							//带一个参数的复数加运算
	CComplex Sub(CComplex &c2);							//带一个参数的复数减运算
	CComplex Mul(CComplex &c2);							//带一个参数的复数乘运算
	CComplex Div(CComplex &c2);							//带一个参数的复数除运算

	CComplex Add(double real1, double imag1);				//带两个参数的复数加运算
	CComplex Sub(double real1, double imag1);				//带两个参数的复数减运算
	CComplex Mul(double real1, double imag1);				//带两个参数的复数乘运算
	CComplex Div(double real1, double imag1);				//带两个参数的复数除运算

	CComplex operator + (const CComplex &c2) const ;//重载运算符+
	CComplex operator - (const CComplex &c2) const ;//重载运算符-
	CComplex operator * (const CComplex &c2) const ;//重载运算符*
	CComplex operator / (const CComplex &c2) const ;//重载运算符/

	CComplex operator = (const CComplex &c2);	    //重载运算符=,因常成员函数不更新对象的数据成员，所有不能声名为常函数

	friend CComplex operator + (const CComplex &c1, const CComplex &c2);	//添加友元函数,实现运算符+重载，参数为两个
	friend CComplex operator - (const CComplex &c1, const CComplex &c2);	//添加友元函数,实现运算符-重载，参数为两个
	friend CComplex operator * (const CComplex &c1, const CComplex &c2);	//添加友元函数,实现运算符*重载，参数为两个
	friend CComplex operator / (const CComplex &c1, const CComplex &c2);	//添加友元函数,实现运算符/重载，参数为两个

	void Print(CComplex c2) ;	//输出复数
	double Root(CComplex c2);	//复数求模函数
	void setComplex(double real1,double imag1){
		real=real1;
		imag=imag1;															//设置set方法以改变实部和虚部的值
	}
	void getComplex(CComplex c2,double &a,double &b){
		a=c2.real;
		b=c2.imag;
	}														//设置get方法以取得实部和虚部的值
private:	//私有数据成员
	double real;	//复数实部
	double imag;	//复数虚部
};