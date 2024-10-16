#include "Token.h"
Token::Token()
{
	this->token_name = "";
	this->token_type = "";
}

Token::Token(const std::string& tokenName, const std::string& tokenType)
{
	this->token_name = tokenName;
	this->token_type = tokenType;
}

std::string Token::getLexem(){
	return this->token_name;
}

std::string Token::getLexemType() {
	return this->token_type;
}

std::string Token::setLexemName(std::string newName) {
	return this->token_name = newName;
}

std::string Token::setLexemType(std::string newType) {
	return this->token_type = newType;
}

