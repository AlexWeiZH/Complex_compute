class CComplex {	//�����ඨ��
public:	
	CComplex();//ȱʡ�Ĺ��캯��
	CComplex(double r = 0.0, double i = 0.0) : real(r), imag(i){}//�������Ĺ��캯��
	CComplex(CComplex &c);//�������캯��

	CComplex Add(CComplex &c2);							//��һ�������ĸ���������
	CComplex Sub(CComplex &c2);							//��һ�������ĸ���������
	CComplex Mul(CComplex &c2);							//��һ�������ĸ���������
	CComplex Div(CComplex &c2);							//��һ�������ĸ���������

	CComplex Add(double real1, double imag1);				//�����������ĸ���������
	CComplex Sub(double real1, double imag1);				//�����������ĸ���������
	CComplex Mul(double real1, double imag1);				//�����������ĸ���������
	CComplex Div(double real1, double imag1);				//�����������ĸ���������

	CComplex operator + (const CComplex &c2) const ;//���������+
	CComplex operator - (const CComplex &c2) const ;//���������-
	CComplex operator * (const CComplex &c2) const ;//���������*
	CComplex operator / (const CComplex &c2) const ;//���������/

	CComplex operator = (const CComplex &c2);	    //���������=,�򳣳�Ա���������¶�������ݳ�Ա�����в�������Ϊ������

	friend CComplex operator + (const CComplex &c1, const CComplex &c2);	//�����Ԫ����,ʵ�������+���أ�����Ϊ����
	friend CComplex operator - (const CComplex &c1, const CComplex &c2);	//�����Ԫ����,ʵ�������-���أ�����Ϊ����
	friend CComplex operator * (const CComplex &c1, const CComplex &c2);	//�����Ԫ����,ʵ�������*���أ�����Ϊ����
	friend CComplex operator / (const CComplex &c1, const CComplex &c2);	//�����Ԫ����,ʵ�������/���أ�����Ϊ����

	void Print(CComplex c2) ;	//�������
	double Root(CComplex c2);	//������ģ����
	void setComplex(double real1,double imag1){
		real=real1;
		imag=imag1;															//����set�����Ըı�ʵ�����鲿��ֵ
	}
	void getComplex(CComplex c2,double &a,double &b){
		a=c2.real;
		b=c2.imag;
	}														//����get������ȡ��ʵ�����鲿��ֵ
private:	//˽�����ݳ�Ա
	double real;	//����ʵ��
	double imag;	//�����鲿
};