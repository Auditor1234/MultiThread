#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <set>
#include <string>
#include <condition_variable>

using namespace std;

class Account {
public:
	Account(string name, double money) : m_name(name), m_money(money) {};

public:
	void changeMoney(double amount) {
		// 这里只能使用unique_lock，因为lock_guard没有下面wait中不满足条件就继续休眠的接口
		unique_lock<mutex> lock(m_mtx);
		// 第二个lambda函数如果返回true，则继续往下面执行，否则持续等待
		m_condition.wait(lock, [this, amount]() {
			return m_money + amount > 0;
		});
		m_money += amount;
		m_condition.notify_all();
	}

	string getName() {
		return m_name;
	}

	double getMoney() {
		return m_money;
	}

	mutex* getLock() {
		return &m_mtx;
	}

private:
	string m_name;
	double m_money;
	mutex m_mtx;
	condition_variable m_condition;
};

class Bank {
public:
	void addAccount(Account *account) {
		m_Accounts.insert(account);
	}

	bool transferMoney(Account* accountA, Account* accountB, double amount) {
		accountA->changeMoney(-amount);
		accountB->changeMoney(+amount);
		return true;
	}

	double totalMoney() const {
		double sum = 0;
		for (auto a : m_Accounts) {
			sum += a->getMoney();
		}
		return sum;
	}

private:
	set<Account*> m_Accounts;
};

void randomTransfer(Bank* bank, Account* accountA, Account* accountB) {
	static mutex s_mtx;
	for(int i = 0; i < 50; i++) {
		double randomMoney = ((double)rand() / RAND_MAX) * 100;
		{
			lock_guard<mutex> lock(s_mtx);
			std::cout << "Transfer " << randomMoney << " from " 
				<< accountB->getName()
				<< " to " << accountB->getName()
				<< ", Bank totalMoney: " << bank->totalMoney() << endl;
		}
		bank->transferMoney(accountA, accountB, randomMoney);
	}
}

int main() {
	Account a("Paul", 100.0);
	Account b("Moiral", 100.0);

	Bank bank;
	bank.addAccount(&a);
	bank.addAccount(&b);

	thread t1(randomTransfer, &bank, &a, &b);
	thread t2(randomTransfer, &bank, &b, &a);

	t1.join();
	t2.join();

	return 0;
}
