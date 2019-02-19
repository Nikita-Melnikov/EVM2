#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

/*
#define 10 ;
#define 11 ;
#define 20 ;
#define 21 ;
#define 30 ;
#define 31 ;
#define 32 ;
#define 33 ;
*/
int massive[100];//, value;

int value;

int flag; //registr = registr & (~(1 << (k вЂ“ 1)));

int registr;

int sc_memoryInit(void);

int sc_memorySet(int adress, int value);

int sc_memoryGet(int adress, int *value);

int sc_memorySave(char *filename);

int sc_memoryLoad(char *filename);

int sc_regInit(void);

int sc_regSet(int register, int value);

int sc_regGet(int register, int *value);

int main(void)
{
	system("clear");
	int adress;
	//char registr;
	char* File = "file.bin"; // warning
	sc_memoryInit();
	std::cout << "Input ur adress: ";
	std::cin >> adress;
	std::cout << std::endl;
	int memorySet = sc_memorySet(adress, value); // = value
	int memoryGet = sc_memoryGet(adress, &value); // = *value
	if(memorySet != -1 && memoryGet != -1)
	{
		std::cout << "Array[" << adress << "] = " << memorySet << "\n";
		std::cout << "Array[" << adress << "] has cell of memory: " << &value << "\n";
	}
	sc_memorySave(&*File);
	int memoryLoad = sc_memoryLoad(&*File);
	//if (memoryLoad != -1)
	flag = sc_regInit();
	sc_regSet(registr, value);
	sc_regSet(registr, &value);
	system("pause");
	return 0;
}

int sc_memoryInit(void)
{
	for(auto i = 0; i < 100; i++)
		massive[i] = 0;
}

int sc_memorySet(int adress, int value)
{
	if(adress > 99 || adress < 0)
	{
		std::cout << "Wrong number of memeory!(sc_memorySet)\n";
		return -1;
	}
	else
	{
		std::cout << "Input the value of massive[" << adress << "]: ";
		std::cin >> value; std::cout << std::endl;
		massive[adress] = value;
	}
	return value;
}

int sc_memoryGet(int adress, int *value)
{
	if(adress > 99 || adress < 0)
	{
		std::cout << "Wrong number of memeory!(sc_memoryGet)\n";
		return -1;
	}
	else
	{
		*value = massive[adress];
		return *value;
	}
}

int sc_memorySave(char *filename)
{
	std::ofstream file_open(filename, std::ios::binary);
    file_open.write((char*) &massive, sizeof(int));
    file_open.close();
}

int sc_memoryLoad(char *filename)
{
	int new_massive[100];
    std::ifstream file_open(filename, std::ios::binary);
    while(file_open.read((char *) &massive, sizeof(int)))
    {
    	for(auto i = 0; i < 100; i++)
        	file_open >> new_massive[i];
    }
    file_open.close();
    std::cout << "\n\nBinary vision of massive memory: \n";
    for(auto i = 0; i < 100; i++)
    	std::cout << "Array[" << i << "] = " << &new_massive[i] << "\t\t";
    std::cout << "\n";
    return 1;
}

int sc_regInit(void)
{
	flag = 0;
	return 0;
}

int sc_regSet(int register, int value)
{
	//zadat' tipo registr i value i s nimi operacii(1)
}

int sc_regGet(int register, int *value)
{
	//
}
