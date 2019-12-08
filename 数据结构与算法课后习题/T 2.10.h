//Programer: Luchangcheng  2019/12/8
//Compiler: gcc version 4.9.2 (x86_64-posix-seh-rev1, Built by MinGW-W64 project)  tested on VSCode  --std = C++11
unsigned long long Fibonacci(unsigned long long n)
{
	if (n == 1 || n == 0)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
