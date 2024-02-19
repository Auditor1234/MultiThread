#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

/**
 * 不会忙等的生产者，消费者程序例子
 * 
*/
int total = 100;
int mydata;
bool ready = false;
std::mutex mtx;  
bool shutdown = false;  //拓展，消费者不管生产者生产了多少数据，消费者始终进行消费
std::condition_variable cv;

void producer() {
	for (int i = 0; i <= total; i++) {
		std::unique_lock<std::mutex>lock(mtx);
		while (ready) {
			cv.wait(lock);
		}
	
		mydata = i;
		printf("producer: %d\n", mydata);
		ready = true;
		cv.notify_all();
	}
	shutdown = true;
	printf("producer done.\n");
}

void consumer(char *name) {
	while(!shutdown) {
		std::unique_lock<std::mutex>lock(mtx);
		while (!ready) {
			cv.wait(lock);
		}
		cout << name << " consume: " << mydata << endl;
		if(!shutdown) {
			ready = false;
		}else {
			cout << name << " consumer done." << endl;
		}
		cv.notify_all();
	}
}

int main() {
	thread prod(producer);
    char name1[] = "number 1";
    char name2[] = "number 2";
	thread con1(consumer, name1);
    thread con2(consumer, name2);

	prod.join();
	con1.join();
    con2.join();
	return 0;
}
