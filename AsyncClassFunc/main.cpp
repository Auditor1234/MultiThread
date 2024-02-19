#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <set>
#include <string>
#include <future>
#include <cmath>

/**
 * 异步执行类函数
*/
using namespace std;

class Worker {
public:
	Worker(int min, int max) : m_min(min), m_max(max){}
	double work() {
		m_result = 0;
		for (int i = m_min; i <= m_max; ++i) {
			m_result += sqrt(i);
		}
		return m_result;
	}

	double getResult() {
		return m_result;
	}


private:
	int m_min;
	int m_max;
	double m_result;
};


int main() {
	Worker w(0, 1e8);
	cout << "Task in class triggered" << endl;
	auto f3 = async(&Worker::work, &w);
	f3.wait();
	cout << "Task in class finish, result: " << w.getResult() << endl;
	return 0;
}
