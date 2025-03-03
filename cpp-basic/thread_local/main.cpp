#include <iostream>
#include <thread>

thread_local int t_data = 0;

void thread_func() {
	t_data = 1;
	std::cout << "Thread ID: "
		  << std::this_thread::get_id()
		  << "\n"
		  << "t_data: " << t_data << "\n"
		  << std::endl;
}

int main() {
	std::thread t1(thread_func);
	std::thread t2(thread_func);

	t1.join();
	t2.join();

	return 0;
}