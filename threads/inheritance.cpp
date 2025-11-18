//#include <Windows.h>
//#include <cstdio>  // for printf
//
///*
//	Создание потока-наследника, используя CreateThread().
//	Вызов GetCurrentThreadID() возвращает int — ID созданного потока
//*/
//
//// Функция поток-наследник
//DWORD WINAPI myThread(__in LPVOID lpParameter) 
//{
//	printf("Thread inside %d \n", GetCurrentThreadId()); 
//	return 0;
//}
//
//// Функция main — поток-родитель (процесс, т.е. главный поток выполнения)
//int main(int argc, char* argv[])
//{
//	HANDLE myHandle;
//	DWORD myThreadID;
//
//	printf("Main thread ID: %d\n", GetCurrentThreadId());
//
//	// Создаем поток-наследник в главном потоке
//	myHandle = CreateThread(0, 0, myThread, 0, 0, &myThreadID);
//	WaitForSingleObject(myHandle, INFINITE);  // wait for the child thread to finish executing its function
//
//	// Continue main thread execution
//
//	CloseHandle(myHandle);
//
//	return 0;  // terminate main thread
//}