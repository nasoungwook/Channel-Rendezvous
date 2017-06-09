# Channel-Rendezvous
채널 랑데부
  ■ 체널 랑데부 프로그램 개요
    1. 채널의 개수 선택
    2. SEQ-R 및 DRSEQ 시퀸스 출력
    3. SER-R 및 DRSEQ의 start time에서 end time까지의 시간
    rendezvous time 1000회를 측정 및 출력
    4. 평균 만나는데 걸리는 시간 각각 출력

  ■ 구현한 클레스 설명
  
    ● Rnd 클래스는 설정한 범위 중 숫자를 난수 생성하는 기능을 가진 클래스이다.
      1. 기본 생성자
        - 0~9 까지 범위 초기화
      2. void setRange(int pStart, int pEnd)
        - 범위를 pStart~pEnd까지 설정한다.
      3. int get RNumber()
        - rand함수로 난수를 생성한다. 

    ● SEQ_R 클래스는 매개변수 생성자, 소멸자, seq_rSet(), print(), nodecompare()로 구성 되어있다.
      1. 매개변수 생성자
        - 사용자가 입력한 채널의 개수를 SEQ_R 클래스에 저장한다.
      2. 소멸자
        - 동적할당 받은 변수를 delete 시켜준다.
      3. void seq_rSet()
        - SEQ-R 채널 랑데부 노드를 배열에 저장시킨다.
      4. void print()
        - SEQ-R 채널 랑데부 노드를 배열을 출력한다.
      5. int nodecompare()
        - 만들어 놓은 채널 랑데부 노드를 시작점을 달리해서 두개의 노드를 만든다. 
          그리고 두 노드를 비교해서 언제 만나는지 확인한 후 반환한다.
  
    ● DRSEQ클래스는 매개변수 생성자, 소멸자, dresqSet(), print(), nodecompare()로 구성 되어있다.
      1. 매개변수 생성자
        - 사용자가 입력한 채널의 개수를 SEQ_R 클래스에 저장한다.
      2. 소멸자
        - 동적할당 받은 변수를 delete 시켜준다.
      3. void dresqSet()
        - DRESQ 채널 랑데부 노드를 배열에 저장시킨다.
          e 는 랜덤으로 입력해서 확률을 높인다.
      4. void print()
         - DRESQ 채널 랑데부 노드를 배열을 출력 시킨다.
      5. int nodecompare()
        - 만들어 놓은 채널 랑데부 노드를 시작점을 달리해서 두개의 노드를 만든다. 
          그리고 두 노드를 비교해서 언제 만나는지 확인한 후 반환한다.

■ 메인함수
- 채널의 개수를 입력 받아 클래스에 입력한다
- 1000회 동안 걸리는 시간을 계산에서 평균을 출력한다. 
