#include<iostream>
#include<cstdlib>
#include<time.h>
#include<Windows.h>
using namespace std;
class Rnd// �������ڸ� ����� Ŭ����
{
private:
	int start;
	int end;        
public:
	Rnd()
	{
		start =0;end = 9;
	}	
	void setRange(int pStart, int pEnd)
	{		
		start = pStart;
		end = pEnd;
	}
	int getRNumber() 
	{
		int rn = (int)( (rand() % (end-start+1)) + start ); 
		return rn;      
	}
};
class SEQ_R//SEQ-R������ Ŭ����
{
private:
	int num; // ä�� ����
	int a; // ��� ����
	int* numarr; // ä�� �迭
	int* node; // ��� �迭

public:
	SEQ_R(int x)
	{
		num=x; // ����ڰ� �Է��� ���ڸ� Ŭ������ �Է��Ѵ�.

	}
	~SEQ_R()
	{
		delete[] numarr;
		delete[] node;
	}
	void seq_rSet()
	{
		int i,j,k;
		int x;
		Rnd R;

		numarr = new int[num];

		a = num*(num+1); // ���� �Է��� ���ڸ� ������ �迭�� ���� �Ҵ��Ѵ�.
		node = new int[a];

		R.setRange(1,num);

		for(i=0; i<num ; i++)//�ߺ����� ����ڰ� �Է��Ѽ��� �迭�� �ִ´�.
		{
			x = R.getRNumber();
			numarr[i] = x;
			for(j=0 ; j<i ; j++)
			{
				if(numarr[j] == x)
				{
					i--;
					break;
				}
			}
		}

		for(i=0,k=0 ; i<a,k<num ; i++,k++)//�������� ���� �迭�� ������ SEQ-R ��带 �����.
		{
			node[i] = numarr[k];
			for(j=0 ; j<num ; j++,i++)
			{
				if(j==0)
				{
					i++;
					node[i]=numarr[j];
				}
				else
				{
					node[i]=numarr[j];
				}
			}
			i--;
		}
	}
	void print()//�⺻��带 ����Ѵ�
	{
		int i;

		for(i=0 ; i<a ; i++)
		{
			cout << " " << node[i];
		}
		cout << "\n";
	}
	int nodecompare()//SEQ-R�� ���Ͽ� �ΰ��� ��带 ����ڿ� ���Ѵ�.
	{
		Rnd R;
		int i,j,k;

		int startTime1=0;//���1�� �迭�� ������
		int startTime2=0;//���2�� �迭�� ������
		int rendezvousTime=0; // �󸶳� �ɷȴ��� Ȯ���� ��ȯ��
		int* ST1arr;
		int* ST2arr;

		ST1arr = new int[a];
		ST2arr = new int[a];

		R.setRange(1,a-1);// �������� ������ ����

		startTime1 = R.getRNumber();//���1�� ������ �������� ����
		startTime2 = R.getRNumber();//���2�� ������ �������� ����

		for(i=0, j=startTime1 ,k=startTime2 ; i<a,j<a,k<a ; i++,j++,k++) // ���1,2�� �迭 ����
		{
			ST1arr[i]=node[j];
			ST2arr[i]=node[k];
			if(j==a-1)
			{
				j=-1;
			}
			if(k==a-1)
			{
				k=-1;
			}
			if(i==a)
			{
				break;
			}
		}
		for(i=0 ; i<a ; i++)
		{
			if(ST1arr[i] == ST2arr[i])
			{
				rendezvousTime = i+1; 
				break;
			}
		}
		return rendezvousTime;
	}
};

class DRSEQ
{
private:
	int num; // ä�� ����
	int a; // ��� ����
	int* numarr; // ä�� �迭
	int* node; // ��� �迭

public:
	DRSEQ(int x)// ������� ä���� ������ �Է¹޴´�.
	{
		num=x;

	}
	~DRSEQ()
	{
		delete[] numarr;
		delete[] node;
	}
	void drseqSet()
	{
		int i,j;
		int e=0; // e�� �ش� 
		Rnd R;

		numarr = new int[num];

		a = num*2+1;// ���� �迭�� ������ �����Ѵ�.
		node = new int[a];

		R.setRange(1,num);
		e=R.getRNumber(); // e�� �ش�,e���� ������ �ִ´�. 

		for(i=0,j=1; i<num ; i++,j++)//numarr�� ä�μ��ڸ� ������� �Է��Ѵ�.
		{
			numarr[i] = j;
		}

		for(i=0 ; i<num ; i++)//node�� 1~ä�μ� ���� �Է��Ѵ�.
		{
			node[i] = numarr[i];
		}

		node[i] = e;//ä�μ� �Է´��� e(����)�� �Է��Ѵ�.
		i++;
		for(j=num-1 ; j>=0 ; i++,j--)//node�� ä�μ�~1���� �ݴ�� �Է��Ѵ�.
		{
			node[i] = numarr[j];
		}
	}
	void print()//�⺻��带 ����Ѵ�.
	{
		int i;

		for(i=0 ; i<a ; i++)
		{
			cout << " " << node[i];
		}
		cout << "\n";
	}
	int nodecompare()// �������� �ٸ� �γ�带 ���� ���Ѵ�.
	{
		Rnd R;
		int i,j,k;

		int startTime1=0;//���1���� ������
		int startTime2=0;//���2���� ������
		int rendezvousTime=0;//���°�� ���������� ��ȯ��
		int* ST1arr;
		int* ST2arr;

		ST1arr = new int[a];
		ST2arr = new int[a];

		R.setRange(1,a-1);//������ ��������


		startTime1 = R.getRNumber();//���1�� ������ �������� ����
		startTime2 = R.getRNumber();//���2�� ������ �������� ����

		for(i=0, j=startTime1 ,k=startTime2 ; i<a,j<a,k<a ; i++,j++,k++) // ���1,2�� �迭 ����
		{
			ST1arr[i]=node[j];
			ST2arr[i]=node[k];
			if(j==a-1)
			{
				j=-1;
			}
			if(k==a-1)
			{
				k=-1;
			}
			if(i==a)
			{
				break;
			}
		}
		for(i=0 ; i<a ; i++)
		{
			if(ST1arr[i] == ST2arr[i])
			{
				rendezvousTime = i+1; 
				break;
			}
		}

		return rendezvousTime;
	}
};
int main(void) 
{
	int x;
	int i;
	int seqr=0;
	int Ssum=0;
	double Savr=0.0;
	int dresq=0;
	int Dsum=0;
	double Davr=0.0;
	srand((unsigned int)time(NULL));

	cout << "ä���� ������ �����ϼ���<3~10>: ";
	cin >> x;

	SEQ_R s(x);
	s.seq_rSet();
	DRSEQ d(x);
	d.drseqSet();
	cout << "SEQ-R ������: " ;
	s.print();
	cout << "DRSEQ ������ : ";
	d.print();

	for(i=1 ; i<1001 ; i++)
	{
		seqr=s.nodecompare();
		dresq=d.nodecompare();
		cout << "[" << i << "��° �õ�] <SEQ-R, DRSEQ>=<"<<seqr<<","<<dresq<<">"<<endl;
		Ssum = Ssum + seqr;
		Dsum = Dsum + dresq;
	}
	Savr = Ssum / 1000.0;
	Davr = Dsum / 1000.0;
	cout << "SEQ-R �����µ� �ɸ��� ��� : "<< Savr<<endl;
	cout << "DRESQ �����µ� �ɸ��� ��� : "<< Davr<<endl;

	return 0;
}
