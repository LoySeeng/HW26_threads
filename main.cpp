#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <thread>

class Timer {
public:
	Timer() {
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer() {
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		std::cout << "Time = " << duration.count() << std::endl;
	}
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
};

const int N = 100000000;
int Arr[N];

int M = 10;

//int m_sum = 0;
int t_sum = 0;

void find_sum(int* Array, int Num_of_elements, int Num_of_threads, int Order_number, int& sum) {

	int n = Num_of_elements / Num_of_threads;

	if (Num_of_elements % Num_of_threads == 0) {
		for (int i = (Order_number * n); i < (Order_number * n + n); i++) {
			sum += Array[i];
		}
	}
}

int main() {

	Timer M_T;

	srand(time(NULL));

	for (int i = 0; i < N; i++) {
		Arr[i] = 1 + rand() % 10;
	}

	//for (int i = 0; i < N; i++) {
	//	m_sum += Arr[i];
	//}

	//std::cout << "Main result: " << m_sum << std::endl;


	std::thread t1(find_sum, Arr, N, M, 0, std::ref(t_sum));
	t1.join();
	std::thread t2(find_sum, Arr, N, M, 1, std::ref(t_sum));
	t2.join();
	std::thread t3(find_sum, Arr, N, M, 2, std::ref(t_sum));
	t3.join();
	std::thread t4(find_sum, Arr, N, M, 3, std::ref(t_sum));
	t4.join();
	std::thread t5(find_sum, Arr, N, M, 4, std::ref(t_sum));
	t5.join();
	std::thread t6(find_sum, Arr, N, M, 5, std::ref(t_sum));
	t6.join();
	std::thread t7(find_sum, Arr, N, M, 6, std::ref(t_sum));
	t7.join();
	std::thread t8(find_sum, Arr, N, M, 7, std::ref(t_sum));
	t8.join();
	std::thread t9(find_sum, Arr, N, M, 8, std::ref(t_sum));
	t9.join();
	std::thread t10(find_sum, Arr, N, M, 9, std::ref(t_sum));
	t10.join();


	std::cout << "Thread result: " << t_sum << std::endl;

	return 0;
}
