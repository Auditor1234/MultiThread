#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <set>
#include <string>

/**
 * 避免死锁
*/

using namespace std;

class Account {
public:
	Account(string name, double money) : m_name(name), m_money(money) {};

public:
	void changeMoney(double amount) {
		m_money += amount;
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
};

class Bank {
public:
	void addAccount(Account *account) {
		m_Accounts.insert(account);
	}

	bool transferMoney(Account* accountA, Account* accountB, double amount) {
		// 对两个同时上锁，如果一个没有锁住，另一个也会放开，不会造成死锁现象
		lock(*accountA->getLock(), *accountB->getLock());

		// lock_guard出了{}域后会自动释放互斥量，本身不会对互斥量加锁
		lock_guard<mutex> guardA(*accountA->getLock(), adopt_lock);
		lock_guard<mutex> guardB(*accountB->getLock(), adopt_lock);

		if (amount > accountA->getMoney()) {
			return false;
		}

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
		if (bank->transferMoney(accountA, accountB, randomMoney)) {
			// 防止异常退出导致死锁问题
			lock_guard<mutex> lock(s_mtx);
			std::cout << "Transfer " << randomMoney << " from " 
				<< accountB->getName()
				<< "to " << accountB->getName()
				<< ",Bank totalMoney:" << bank->totalMoney() << endl;
			
		}else {
			lock_guard<mutex> lock(s_mtx);
			cout << "Transfer failed, "
				 << accountA->getName() << " has only $" << accountA->getMoney() << ", but "
				 << randomMoney << " required" << endl;
		}
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
