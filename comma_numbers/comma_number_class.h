#ifndef COMMA_INPUT_NUMBER_H
#define COMMA_INPUT_NUMBER_H

#include "needed_functions.h"

class CommaInputNumber
{
	const long double* number;

public:

	CommaInputNumber()
		:number(new long double(0))
	{
	}

	CommaInputNumber(const long double& number)
		:number(new long double(number))
	{
	}

	CommaInputNumber(const std::string& input)
		:number(new long double(to_number(input)))
	{
	}

	CommaInputNumber(const CommaInputNumber& obj)
		:number(obj.number)
	{
	}

	CommaInputNumber(CommaInputNumber&& obj) noexcept
		:number(obj.number)
	{
		obj.number = nullptr;
	}

	~CommaInputNumber()
	{
		delete number;
	}

	CommaInputNumber& operator = (const CommaInputNumber& obj)
	{
		if (this == &obj)
			return *this;

		number = obj.number;

		return *this;
	}

	CommaInputNumber& operator = (CommaInputNumber&& obj) noexcept
	{
		if (this == &obj)
			return *this;

		number = obj.number;
		obj.number = nullptr;

		return *this;
	}

	CommaInputNumber operator + (const CommaInputNumber& obj)
	{
		return CommaInputNumber(*number + *obj.number);
	}

	CommaInputNumber operator - (const CommaInputNumber& obj)
	{
		return CommaInputNumber(*number - *obj.number);
	}

	CommaInputNumber operator * (const CommaInputNumber& obj)
	{
		return CommaInputNumber(*number * *obj.number);
	}

	CommaInputNumber operator / (const CommaInputNumber& obj)
	{
		return CommaInputNumber(*number / *obj.number);
	}

	CommaInputNumber operator % (const CommaInputNumber& obj)
	{
		return CommaInputNumber(fmod(*number, *obj.number));
	}

	void change(const std::string& input)
	{
		number = new long double(to_number(input));
	}

	friend std::ostream& operator << (std::ostream& os, const CommaInputNumber& obj)
	{
		return os << *obj.number;
	}
};

#endif