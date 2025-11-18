//#include <Windows.h>
//#include <cstdio>
//
///*
//	Выдача приоритета потокам с помощью функции SetThreadPriority()
//
//	BOOL SetThreadPriority
//	(
//		[in] HANDLE hThread,
//		[in] int    nPriority
//	);
//
//	Уровни приоритета в каждом классе приоритета:
//	THREAD_PRIORITY_IDLE
//	THREAD_PRIORITY_LOWEST
//	THREAD_PRIORITY_BELOW_NORMAL
//	THREAD_PRIORITY_NORMAL
//	THREAD_PRIORITY_ABOVE_NORMAL
//	THREAD_PRIORITY_HIGHEST
//	THREAD_PRIORITY_TIME_CRITICAL
//
//	Всем потокам изначальнно выдается THREAD_PRIORITY_NORMAL,
//	т.е. приоритет процесса
//
//	GetThreadPriority() рассказывает о приоритете потока
//	Возвращает псевдо-дескриптор (не наследуется)
//*/
//
//DWORD WINAPI myThread(__in LPVOID lpParameter)
//{
//	DWORD error;
//
//	// Set low-priority with THREAD_MODE_BACKGROUND_BEGIN
//	if (!SetThreadPriority(GetCurrentThread(), THREAD_MODE_BACKGROUND_BEGIN))
//	{
//		error = GetLastError();
//
//		if (ERROR_THREAD_MODE_ALREADY_BACKGROUND == error)
//		{
//			printf("Already in background mode\n");
//		}
//		else { printf("Failed to enter background mode (%d)\n", error); }
//	}
//
//	DWORD threadPri;
//
//	// Display thread priority
//	threadPri = GetThreadPriority(GetCurrentThread());
//	printf("Current thread priority is 0x%x\n", threadPri);
//
//	// Perform background work
//
//	if (!SetThreadPriority(GetCurrentThread(), THREAD_MODE_BACKGROUND_END))
//	{
//		printf("Failed to end background mode (%d)\n", GetLastError());
//	}
//
//	return 0;
//}
//
//int main(int argc, char* argv[])
//{
//	HANDLE myHandle;
//	DWORD myThreadID;
//
//	myHandle = CreateThread(0, 0, myThread, 0, 0, &myThreadID); 
//
//	WaitForSingleObject(myHandle, INFINITE);
//
//	CloseHandle(myHandle);
//
//	return 0;
//}
