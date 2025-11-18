//#include <Windows.h>
//#include <process.h>
//#include <cstdio>
//
///*
//	Рекомендуется уничтожение потока вследствие выхода из функции,
//	которую он выполнял
//
//	Например, здесь поток выводит свой ID и уничтожается 
//
//	DWORD WINAPI mythreadA(__in LPVOID lpParameter)
//	{
//		printf("CreateThread %d \n", GetCurrentThreadId());
//		return 0;
//	}
//
//	Также можно уничтожать потоки, используя:
//
//	ExitThread() или TerminateThread()
//
//	_endthread() or _endthreadex()  (после освобождения ресурсов)
//	(все еще нужно вызывать CloseHandle() при _endthreadex())
//
//	WaitForSingleObject() и WaitForMultipleObjects()
//	Ждут выполнения потока (массив потоков)
//	В параметры передается дескриптор и квант времени ожидания
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
//	HANDLE myhandle[2];
//
//	myhandle[0] = (HANDLE)_beginthreadex(0, 0, &mythread, 0, 0, 0);
//	myhandle[1] = (HANDLE)_beginthreadex(0, 0, &mythread, 0, 0, 0);
//
//	WaitForSingleObject(myhandle[0], INFINITE);
//	WaitForSingleObject(myhandle[1], INFINITE);
//
//	// Кол-во ожидаемых потоков, массив дескрипторов потоков,
//	// true — ф-ция возвращает при уничтожении всех потоков,
//	// квант ожидания
//	// 
//	// WaitForMultipleObjects(2, myhandle, true, INFINITE);
//
//	CloseHandle(myhandle[0]);
//	CloseHandle(myhandle[1]);
//
//	return 0;
//}