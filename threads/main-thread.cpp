///*
//	1) Поток имеет свой стек процедур и регистры, и общее с процессом адресное пространство
//	2) Стандарт размера потока в Windows — 1Мегабайт стека
//	3) Максимум потоков в процессе в Windows — 2048 (MSDN)
//	4) Терминация (прекращение) потока не обязательно удалит объект с ОС
//		объект удален, когда последний дескриптор (handle) был освобожден
//*/
//
//#include <Windows.h>  // Win32 API: For multithreading functions
//#include <iostream>
//
//// Каждый процесс Win32 имеет хотя бы один — главный поток
//// поток инкрементирует счетчик myCounter в ф-ции myThread
//
//DWORD WINAPI myThread(LPVOID lpParameter)  // DWORD is uint32, LPVOID is pointer to a void object
//{
//	unsigned int& myCounter = *((unsigned int*)lpParameter);  // using function pointers. lpParameter is void function
//	while (myCounter < 0xFFFFFFFF) ++myCounter;  // 0xFFFFFFFF hex = 4294967295 decimal = max DWORD
//	return 0;
//}
//
//int main(int argc, char* argv[])
//{
//
//	unsigned int myCounter = 0;
//
//
//	DWORD myThreadID;
//
//	/*
//		HANDLE WINAPI CreateThread
//		(
//			__in_opt LPSECURITY_ATTRIBUTES lpThreadAttributes,
//			__in SIZE_T dwStackSize,
//			__in LPTHREAD_START_ROUTINE lpStartAddress,  
//			__in_opt LPVOID lpParameter,
//			__in DWORD dwCreationFlags,
//			__out_opt LPDWORD lpThreadId
//		);
//
//		1. Наследственность дескриптора присоединенными потоками (детям)
//
//		2. Размер стека передается вторым аргументом. Если размер (int) указан 0,
//		то размер стека будет равен стандартному размеру 1МБ.
//
//		3. Выполнение потока начинается с вызова ф-ции, в процессе создания потока. 
//		Третий параметр CreateThread: указатель (начальный адрес потока) на myThread — ф-цию потока. 
//		Выполнение происходит, пока функция не вернет значение (return). 
//
//		4. Указатель на переменную, передаваемую в поток
//
//		5. Флаги контроля создания потока
//
//		6. Указатель на переменную, сохраняющий (и возвращающий) ID потока
//
//	*/
//
//	// Возвращаемое значение при вызове функции CreateThread() — это дескриптор для потока
//	HANDLE myHandle = CreateThread(0, 0, myThread, &myCounter, 0, &myThreadID);
//	
//	// Функция ждет символ getchar() 
//	char myChar = ' ';
//	while (myChar != 'q') {  // if 'q' — quit program, terminate the thread
//		std::cout << myCounter << std::endl;  // Выводит значение счетчика my Counter
//		myChar = getchar();
//	}
//
//	// Освободим дескриптор myHandle => уничтожаем поток (т. к. функция потока уже возвратила значение)
//	CloseHandle(myHandle);
//	return 0;
//}
