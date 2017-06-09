#include<iostream>
#include<cstdlib>
#include<time.h>
#include<Windows.h>
using namespace std;
class Rnd// 랜덤숫자를 만드는 클레스
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
class SEQ_R//SEQ-R에대한 클래스
{
private:
	int num; // 채널 개수
	int a; // 노드 개수
	int* numarr; // 채널 배열
	int* node; // 노드 배열

public:
	SEQ_R(int x)
	{
		num=x; // 사용자가 입력한 숫자를 클레스에 입력한다.

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

		a = num*(num+1); // 내가 입력한 숫자를 가지고 배열을 동적 할당한다.
		node = new int[a];

		R.setRange(1,num);

		for(i=0; i<num ; i++)//중복없이 사용자가 입력한수를 배열에 넣는다.
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

		for(i=0,k=0 ; i<a,k<num ; i++,k++)//랜덤으로 뽑은 배열을 가지고 SEQ-R 노드를 만든다.
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
	void print()//기본노드를 출력한다
	{
		int i;

		for(i=0 ; i<a ; i++)
		{
			cout << " " << node[i];
		}
		cout << "\n";
	}
	int nodecompare()//SEQ-R에 대하여 두개의 노드를 만든뒤에 비교한다.
	{
		Rnd R;
		int i,j,k;

		int startTime1=0;//노드1번 배열의 시작점
		int startTime2=0;//노드2번 배열의 시작점
		int rendezvousTime=0; // 얼마나 걸렸는지 확인후 반환값
		int* ST1arr;
		int* ST2arr;

		ST1arr = new int[a];
		ST2arr = new int[a];

		R.setRange(1,a-1);// 시작점의 범위를 설정

		startTime1 = R.getRNumber();//노드1의 시작점 램덤으로 설정
		startTime2 = R.getRNumber();//노드2의 시작점 랜덤으로 설정

		for(i=0, j=startTime1 ,k=startTime2 ; i<a,j<a,k<a ; i++,j++,k++) // 노드1,2의 배열 설정
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
	int num; // 채널 개수
	int a; // 노드 개수
	int* numarr; // 채널 배열
	int* node; // 노드 배열

public:
	DRSEQ(int x)// 사용자의 채널의 갯수를 입력받는다.
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
		int e=0; // e에 해당 
		Rnd R;

		numarr = new int[num];

		a = num*2+1;// 동적 배열의 갯수를 설정한다.
		node = new int[a];

		R.setRange(1,num);
		e=R.getRNumber(); // e에 해당,e에는 난수를 넣는다. 

		for(i=0,j=1; i<num ; i++,j++)//numarr에 채널숫자를 순서대로 입력한다.
		{
			numarr[i] = j;
		}

		for(i=0 ; i<num ; i++)//node에 1~채널수 까지 입력한다.
		{
			node[i] = numarr[i];
		}

		node[i] = e;//채널수 입력다음 e(난수)를 입력한다.
		i++;
		for(j=num-1 ; j>=0 ; i++,j--)//node에 채널수~1까지 반대로 입력한다.
		{
			node[i] = numarr[j];
		}
	}
	void print()//기본노드를 출력한다.
	{
		int i;

		for(i=0 ; i<a ; i++)
		{
			cout << " " << node[i];
		}
		cout << "\n";
	}
	int nodecompare()// 시작점이 다른 두노드를 서로 비교한다.
	{
		Rnd R;
		int i,j,k;

		int startTime1=0;//노드1번의 시작점
		int startTime2=0;//노드2번의 시작점
		int rendezvousTime=0;//몇번째레 같아지는지 반환값
		int* ST1arr;
		int* ST2arr;

		ST1arr = new int[a];
		ST2arr = new int[a];

		R.setRange(1,a-1);//시작점 범위설정


		startTime1 = R.getRNumber();//노드1의 시작점 램덤으로 설정
		startTime2 = R.getRNumber();//노드2의 시작점 랜덤으로 설정

		for(i=0, j=startTime1 ,k=startTime2 ; i<a,j<a,k<a ; i++,j++,k++) // 노드1,2의 배열 설정
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

	cout << "채널의 개수를 선택하세요<3~10>: ";
	cin >> x;

	SEQ_R s(x);
	s.seq_rSet();
	DRSEQ d(x);
	d.drseqSet();
	cout << "SEQ-R 시퀸스: " ;
	s.print();
	cout << "DRSEQ 시퀸스 : ";
	d.print();

	for(i=1 ; i<1001 ; i++)
	{
		seqr=s.nodecompare();
		dresq=d.nodecompare();
		cout << "[" << i << "번째 시도] <SEQ-R, DRSEQ>=<"<<seqr<<","<<dresq<<">"<<endl;
		Ssum = Ssum + seqr;
		Dsum = Dsum + dresq;
	}
	Savr = Ssum / 1000.0;
	Davr = Dsum / 1000.0;
	cout << "SEQ-R 만나는데 걸리는 평균 : "<< Savr<<endl;
	cout << "DRESQ 만나는데 걸리는 평균 : "<< Davr<<endl;

	return 0;
}
