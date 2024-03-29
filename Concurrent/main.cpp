#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cmath>

/**
 * 并发程序
*/

using namespace std;

static const int MAX = 10e7;
static double sum = 0;

static mutex exclusive;

void concurrent_worker(int min, int max) {
	double dTmp = 0;
	for (int i = min; i <= max; ++i) {
		dTmp += sqrt(i);
	}

	exclusive.lock();
	sum += dTmp;
	exclusive.unlock();
}

void concurrent_task(int min, int max) {
	auto start_time = chrono::steady_clock::now();
	unsigned concurrent_count = thread::hardware_concurrency();
	cout << "hardware_concurrency:" << concurrent_count << endl;
	vector<thread> threads;
	min = 0;
	sum = 0;
	for (int t = 0; t < concurrent_count; ++t) {
		int range = max / concurrent_count * (t + 1);
		threads.push_back(thread(concurrent_worker, min, range));
		min = range + 1;
	}

	for (int i = 0; i < threads.size(); ++i) {
		threads[i].join();
	}

	auto end_time = chrono::steady_clock::now();
	auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
	cout << "Concurrent task finish, " << ms << "ms consumed, Result: " << sum << endl;

}

int main() {
	concurrent_task(0, MAX);
	return 0;
}
