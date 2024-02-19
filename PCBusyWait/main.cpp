#include <iostream>
#include <thread>
#include <pthread.h>

using namespace std;

/**
 * 会忙等的生产者，消费者程序例子
 * 
*/
bool ready = true;
bool shutdown = false;
int product = 0;
int total = 100;


void producer(pthread_mutex_t *mutex) {
    while(product < total) {
        pthread_mutex_lock(mutex);
        if(!ready) {
            pthread_mutex_unlock(mutex);
            continue;
        }
        product++;
        std::cout << "producer: " << product << std::endl;
        ready = false;
        if(product >= total) {
            std::cout << "producer done." << std::endl;
        }
        pthread_mutex_unlock(mutex);
    }

}

void consumer(char *name, pthread_mutex_t *mutex) {
    while(product <= total) {
        if(shutdown) {
            std::cout << "consumer " << name << " done." << std::endl;
            return;
        }
        pthread_mutex_lock(mutex);
        if(ready) {
            pthread_mutex_unlock(mutex);
            continue;
        }
        std::cout << "consumer " << name << ": " << product << std::endl;
        if(product >= total) {
            shutdown = true;
        }
        ready = true;
        pthread_mutex_unlock(mutex);
    }
}

int main() {
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, nullptr);

    std::thread prod(producer, &mutex);
    char name1[] = "number 1";
    char name2[] = "number 2";
    std::thread con1(consumer, name1, &mutex);
    std::thread con2(consumer, name2, &mutex);

    prod.join();
    con1.join();
    con2.join();

    return 0;
}