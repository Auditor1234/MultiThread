#include <iostream>
#include <mutex>
#include <future>
#include <cmath>
#include <thread>

using namespace std;

static const int MAX = 1e6;
static double sum = 0;

void worker(int min, int max) {
	cout << "work_thread_id" << this_thread::get_id() << endl;
	for (int i = min; i <= MAX; ++i) {
		sum += sqrt(i);
	}
}

int main() {
	sum = 0;
	cout << "main_thread_id:" << this_thread::get_id() << endl;
	// launch::async会新开一个线程，而launch::deferred则在原线程中调用get或wait时顺序执行
	auto f1 = async(launch::async, worker, 0, MAX);
	auto f2 = async(launch::async, worker, 0, MAX);
	cout << "Async task triggered" << endl;
	f1.wait();
	f2.wait();
	cout << "Async task finish, result: " << sum << endl;

	return 0;
}
