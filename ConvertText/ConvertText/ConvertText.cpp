

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <Windows.h>


char* convertRus(char* test, int sizeTest, int numChar) {

	char ch = test[numChar];

	if (ch >= 'А' && ch <= 'Я') {
		ch += 'а'-'А';
	}
	
	if (ch == 'Ё') {
		ch = 'ё';
	} // конвертация буквы "Ё"
	
	
	test[numChar] = ch;
	return test;
}



char* CheckChar(char* test, int sizeTest, int numChar) {
	// конвертация символов в "(" или ")"
	char buffer = test[numChar];
	bool Found = false;
	for (int i = 0; i < sizeTest; ++i) // поиск повторяющихся символов
		if (i != numChar) {
			if (buffer == test[i]) {
				test[numChar] = 41;
				test[i] = 41;      
				Found = true;
			}
		};
	if (Found == false) {
		test[numChar] = 40;
	}
			
			
	
	

	return test;
}


int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	std::string text;
	char* test;

#define ever (;;) // бесконечный цикл

	for ever
	{
		
		


		std::cout << "Input: ";

		getline(std::cin, text);

		test = const_cast<char*>(text.c_str());

		const int sizeTest = text.length();
		
	    for (int numChar = 0; numChar < sizeTest; ++numChar)
			test[numChar] = toupper(test[numChar]);  // конвертация всех строчных символов латиницы в прописные

		
		for (int numChar = 0; numChar < sizeTest; ++numChar)
			convertRus(test, sizeTest, numChar); // конвертация всех прописных символов кириллицы в строчные
		
		
		for (int numChar = 0; numChar < sizeTest; ++numChar)
			test = CheckChar(test, sizeTest, numChar); // вызов конвертации символов
		
		std::cout << "Output: " << text << std::endl;

	}



}

