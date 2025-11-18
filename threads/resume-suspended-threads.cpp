//#include <Windows.h>
//#include <process.h>
//#include <cstdio>
//
///*
//	Возобновление потоков из состояния приостановки:
//	готовности, ожидания или блокирования (семафора)
//	
//	Потоки могут быть созданы в состоянии остановки.
//	
//	ResumeThread() принимает дескриптор потока, возобновляет поток
//
//	SuspendThread() приостановит поток
//*/
//
//unsigned int __stdcall mythread(void* data)
//{
//	printf("Thread %d\n", GetCurrentThreadId());
//	return 0;
//}
//
//int main(int argc, char* argv[])
//{
//	HANDLE myhandle;
//
//	// Создаем поток в состоянии остановки
//	myhandle = (HANDLE)_beginthreadex(0, 0, &mythread, 0, CREATE_SUSPENDED, 0);
//	getchar();
//
//	// Возобновляем поток
//	ResumeThread(myhandle);
//
//	// Ждем ввод
//	getchar();
//
//	// Ждем выполнения потока
//	WaitForSingleObject(myhandle, INFINITE);
//
//	// Освобождаем дескриптор потока, после его уничтожения и получения дескриптора после ожидания выполнения
//	CloseHandle(myhandle);
//
//	return 0;
//}
//
///*
//	Остановка и возобновление потока содержатся на счетчике.
//	Т.е. кол-во вызовов к SuspendThread() (++suspendCounter) и ResumeThread() (++suspendCounter)
//	должно совпадать, чтобы suspendCounter = 0 и поток возобновился
//*/