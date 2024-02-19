# C++多线程例子

### 该项目包括以下内容:
- 互斥量的使用 `./PC`
- 互斥量配合条件变量避免忙等 `./PCBusyWait`
- 多个线程初始化一次 `./CallOnce`
- 互斥量与锁控制并发程序 `./Concurrent`
- 避免死锁 `./AoidDeadLock`
- 条件变量优化死锁 `./CondDeadLock`
- 异步方式执行多线程 `./AsyncTask`
- 对类中函数执行异步线程操作 `./AsyncClassFunc`
- packaged_task获取异步操作结果的值 `./PackageTask`
- promise与future 任务结束与返回结果分开 `./PromiseFuture`

### 环境及配置
- g++ 11.4.0
- ubuntu 22.04.1 LTS
- cmake 3.22.1
- VSCode 1.86.1

### 使用方法
使用cmake配置生成，然后在终端运行生成的可执行文件，如`./build/PC/PC`