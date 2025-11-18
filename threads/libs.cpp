//#include <Windows.h>
//#include <process.h>  // _beginthread, _beginthreadex
//#include <cstdio>
//
///*
//	Ф-ция CreateThread() говорит ОС создать новый поток, возвратить его дескриптор,
//	но библиотеки среды выполнения (Win32) не создали стек и регистры для потока
//
//	Т. е. вместо CreateThread() используем функции:
//	_beginthread(), _beginthreadex()
//
//	uintptr_t _beginthread
//	(
//		void( *start_address )( void * ),
//		unsigned stack_size,
//		void *arglist
//	);
//
//	uintptr_t _beginthreadex
//	(
//	   void *security,
//	   unsigned stack_size,
//	   unsigned ( *start_address )( void * ),
//	   void *arglist,
//	   unsigned initflag,
//	   unsigned *thrdaddr
//	);
//
//	1. Начальный адрес процедуры, начинающий выполнение нового потока
//
//	2. Размер стека
//
//	3. Аргументы, пердаваемые потоку
//
//	4. Наследуемость дескриптора потомками
//
//	5. Первоначальное состояние потока
//
//	6. ID потока (uint32_t)
//
//	_beginthread() сама освободит дескриптор, когда поток закроется
//	Для _beginthreadex() исп. CloseHandle()
//
//	Возвращают дескрипторы (тип uintptr_t)
//*/
//
//DWORD WINAPI mythreadA(__in LPVOID lpParameter)
//{
//	printf("CreateThread %d \n", GetCurrentThreadId());
//	return 0;
//}
//
//unsigned int __stdcall mythreadB(void* data)
//{
//	printf("_beginthreadex %d \n", GetCurrentThreadId());
//	return 0;
//}
//
//void mythreadC(void* data)  // void ends by returning implicitly or calling _endthread()
//{
//	printf("_beginthread %d \n", GetCurrentThreadId());
//}
//
//int main(int argc, char* argv[])
//{
//	HANDLE myhandleA, myhandleB, myhandleC;
//
//	// OS level
//	myhandleA = CreateThread(0, 0, mythreadA, 0, 0, 0);  // can also call WaitForSingleObject() after creating a thread
//	CloseHandle(myhandleA);
//
//	// handle control
//	myhandleB = (HANDLE)_beginthreadex(0, 0, &mythreadB, 0, 0, 0);
//	WaitForSingleObject(myhandleB, INFINITE);  // wait bcs we need to receive a real handle (not a pseudo-copy) after the thread is terminated
//	CloseHandle(myhandleB);
//
//	// _beginthread returns uintptr_t, we have no access to myhandleC
//	myhandleC = (HANDLE)_beginthread(&mythreadC, 0, 0);
//
//	return 0;
//}