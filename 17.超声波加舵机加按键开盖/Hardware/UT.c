#include "UT.h"

void UTStart(){
	Trig = 0;
	Trig = 1;
	Delay10us();
	Trig = 0;
}


double Get_Distance(){
	double Time;
	//��ʼ��ʱ
	UTStart();
	//�ȴ�Echo����
	while(!Echo);
	//��ʼ��ʱ
	Timer1_ON();
	//�ȴ�Echo����
	while(Echo);
	//�رռ�ʱ
	Timer1_OFF();
	//����ʱ��
	Time = 1.085 * (TH1 * 256 +TL1);
	//���ؾ���
	return (0.017 * Time);
}