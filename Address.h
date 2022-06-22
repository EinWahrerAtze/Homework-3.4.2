#include <string>
#pragma once

class Address
{
public:
	std::wstring get_output_string(void) const;
	void show(void) const;
	const std::wstring& get_city(void) const;
	Address(void);
	Address(const std::wstring& m_city,
			const std::wstring& m_street,
			const unsigned short m_build_num,
			const unsigned short m_flat_num);
	~Address(void);
private:
	std::wstring city;
	std::wstring street;
	unsigned short build_num;
	unsigned short flat_num;
};