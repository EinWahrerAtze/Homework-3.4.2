#include <iostream>
#include <fstream>
#include <string>
#include "Address.h"

void sort(Address* addresses, unsigned short size)
{
	Address* temp = new Address();
	bool swapped = false;

	do
	{
		swapped = false;
		
		for (int i = size - 1; i > 0; --i)
		{
			if (addresses[i - 1].get_city() > addresses[i].get_city())
			{
				*temp = addresses[i - 1];
				addresses[i - 1] = addresses[i];
				addresses[i] = *temp;
				swapped = true;
			}
		}
	}
	while (swapped);

	delete temp;
}

int main()
{
	wchar_t in_filename[] = L"in.txt";
	std::wifstream fin(in_filename);

	if (!fin.is_open())
	{
		std::wcout << L"Could not open " << in_filename << L" for reading.\n";
		std::wcout << L"Programm terminating.";
		exit(EXIT_FAILURE);
	}

	unsigned short size = 0;
	fin >> size;

	Address* addresses = new Address[size];
	std::wstring city;
	std::wstring building;
	unsigned short build_num = 0;
	unsigned short flat_num = 0;

	for (int i = 0; i < size; ++i)
	{
		fin >> city >> building >> build_num >> flat_num;
		addresses[i] = Address(city, building, build_num, flat_num);
	}

	if (fin.eof())
	{
		std::wcout << L"End of file reached.\n";
	}
	else if (fin.fail())
	{
		std::wcout << L"Input terminated by data mismatch.\n";
	}
	else
	{
		std::wcout << L"Input terminated by unknown reason.\n";
	}

	fin.close();
	std::wcout << L"Before sorting:\n";

	for (int i = 0; i < size; ++i)
	{
		addresses[i].show();
	}

	sort(addresses, size);
	std::wcout << L"\nAfter sorting:\n";

	for (int i = 0; i < size; ++i)
	{
		addresses[i].show();
	}

	wchar_t out_filename[] = L"out.txt";
	std::wofstream fout(out_filename);

	if (!fout.is_open())
	{
		std::wcout << L"Could not open " << out_filename << L" for writing.\n";
		std::wcout << L"Programm terminating.";
		exit(EXIT_FAILURE);
	}

	fout << size << std::endl;

	for (int i = 0; i < size; ++i)
	{
		fout << addresses[i].get_output_string();
	}
	
	if (fout.good())
	{
		std::wcout << L"\nFile " << out_filename << L" successfully written.\n";
	}
	else if (fout.fail())
	{
		std::wcout << L"\nOutput terminated by data mismatch.\n";
	}
	else
	{
		std::wcout << L"\nOutput terminated by unknown reason.\n";
	}

	fout.close();
	delete[] addresses;
	return 0;
}