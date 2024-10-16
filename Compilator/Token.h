#pragma once
#include <string>
class Token
{
private:

	std::string token_name;
	std::string token_type;

public:

	Token();
	Token(const std::string& tokenName, const std::string& tokenType);
	std::string getLexem();
	std::string getLexemType();
	std::string setLexemName(std::string newName);
	std::string setLexemType(std::string newType);

};
