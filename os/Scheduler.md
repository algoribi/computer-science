# 스케줄러(Scheduler)

> ready queue에 있는 프로세스들에 대해 프로세서(CPU)를 할당하는 과정

</br>

## 장기 스케줄러(Long-term scheduler) : 작업 스케줄러(job scheduler)

> 디스크 내의 프로세스를 어떤 순서로 메모리를 할당하여 ready queue로 보낼지 결정한다.

- 메모리와 디스크 사이의 스케줄링을 담당한다.
- CPU 위주의 연산과 I/O 위주의 연산을 적절히 혼용하여 스케줄링한다.
- new -> ready

</br>

## 단기 스케줄러(Short-term scheduler) : 프로세스 스케줄러(Process scheduler)

> ready queue에 있는 프로세스 중 어떤 프로세스를 running 시킬지 결정한다.

- CPU와 메모리 사이의 스케줄링을 담당한다.
- ready queue에 있는 프로세스 중 먼저 도착한 프로세스에 CPU를 할당한다. (= dispatcher)
- ready -> running -> waiting -> ready

</br>

## 중기 스케줄러(Medium-term scheduler) : Swapper

> 프로세스 간의 CPU 선점 경쟁이 심해지면 swapping 기법을 통해 메모리를 관리한다.

- 메모리에 너무 많은 프로그램이 올라가는 것을 조절한다.
- 프로세스를 통째로 메모리에서 디스크로 쫓아낸다. (swap out)
- ready -> suspended
  - suspended : 외부적인 이유로 프로세스의 수행이 정지된 상태로 프로세스 통째로 swap out 된다. blocked 상태와는 다르게 suspended는 외부적 이유로 suspending 되었기 때문에 스스로 ready state에 돌아갈 수 없다.

</br>

---

# CPU 스케줄러

> 다중 프로그램을 지원하는 운영체제는 CPU의 효율을 극대화하기 위한 CPU 스케줄링이 필수

- 선점형 운영체제(Preemptive OS) : 현재 실행 중인 프로세스보다 높은 우선순위를 가진 프로세스가 등장하면 스케줄러에 의해 실행 순서가 조정된다.
- 비선점형 운영체제(non-Preemptive OS) : 현재 실행 중인 프로세스가 끝나야 다음 프로세스가 CPU를 할당받을 수 있다.

</br>

## 선점 스케줄링

- SRT(Shortest Remaining time First)
  - 처리가 완료되는데 가장 짧은 시간이 소요된다고 판단되는 프로세스를 먼저 수행한다.
  - 새로운 프로세스가 도착할 때마다 새로운 스케줄링이 이루어진다.
    > 매번 스케줄링이 다시 이루어지기 때문에 CPU burst time(사용 시간)의 측정이 불가능하다.
- RR(Round-Robin)
  - 각 프로세스는 같은 크기의 할당 시간(time quantum)을 가지며 선입선출(FIFO)로 진행된다.
    > time quantum이 커지면 FIFO 스케줄링과 같아지고, 너무 작아지면 overhead가 발생한다. 따라서 적절한 time quantum 배분이 중요하다.

</br>

## 비선점 스케줄링

- FCFS(First Come First Served, = FIFO)
  - ready queue에 도착한 순서대로 CPU를 할당받으며 작업이 완료될 때까지 CPU를 반환하지 않는다.
    > 작업 완료 시간을 예측할 수 있는 장점이 있지만 덜 중요한 작업에 의해 효율성이 떨어질 수 있는 문제점이 있다.
- SJF(Shortest Job First)
  - 도착 순서에 상관없이 CPU burst time(사용 시간)이 짧은 순서대로 할당된다.
    > 사용 시간이 긴 프로세스는 거의 영원히 CPU를 할당받을 수 없는 문제점이 있다.

</br>

- Priority Scheduling
  - 우선순위가 가장 높은 프로세스에 CPU를 할당한다.
    > - **선점형 스케줄링 방식**
    >   > 더 높은 우선순위를 가진 프로세스가 도착하면 실행 중인 프로세스를 중단하고 CPU를 선점한다.
    > - **비선점형 스케줄링 방식**
    >   > 더 높은 우선순위를 가진 프로세스가 도착하면 ready queue의 head에 넣는다.
    >
    > 이때 ready queue에서 우선순위에 밀려 무한히 대기하는 상태인 무기한 봉쇄(Indefinite blocking)가 일어날 수 있다.
    >
    > 해결책으로 아무리 우선순위가 낮더라도 오래 기다리면 우선순위를 높여주는 방법이 있다.
