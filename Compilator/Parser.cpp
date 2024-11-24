#pragma once
#include "Parser.h"
using namespace std;
ofstream out("Tree_Parse.txt");
void Parser::getLexeme()
{
	if (i <= text.size()) {
		lexeme = text[i];
		i++;
	}
}
void Parser::printparse()
{
	ofstream out("Tree_Parse.txt");
	for (int i = 0;i < text.size();i++) {
		out << text[i].getLexem();
	}
}
Parser::Parser(vector<Token> tok)
{
	i = 0;
	text = tok;
}
void Parser::parse() {
//	printparse();
	Begin();
	Descriptions();
	Op();
	End();
}

void Parser::Begin()
{
	ofstream out("Tree_Parse.txt");
//	out << "kzkzkkz";
	if (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	match("KeyWord_float_int");
	match("VAR");
	match2("(");
	match2(")");
	match2("{");
}

void Parser::Descriptions()
{
	Descr();
	while (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	while (text[i].getLexemType() != "KeyWord_return" && text[i].getLexemType() != "VAR") {
		Descr();
	}
}
void Parser::Descr()
{
	type();
	varlist();
	match2(";");
}
void Parser::type()
{
	while (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	if (text[i].getLexem() == "int" || text[i].getLexem() == "float") {
		i++;
	}
	else {
		out << "Строка" << ": " << stroka << " Ожидалось:" << "int or float" << "получено: " << text[i].getLexem() << endl;
	}
}
void Parser::ID()
{
	if (text[i].getLexemType() == "VAR") {
		i++;
	}
	else {
		out << "Строка" << ": " << stroka << " Ожидалось:" << "VAR" << "получено: " << text[i].getLexemType() << endl;
	}
}
void Parser::varlist()
{
	ID();
	while (text[i].getLexem() != ";") {
		match2(",");
		if(text[i-1].getLexem()==",")
			ID();
	}
}
void Parser::Operators()
{
//	Op();
	while (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	if (text[i].getLexemType() != "KeyWord_return") {
		Op();
	}
}
void Parser::Op()
{
	while (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	ID();
	match2("=");
	expr();
	match2(";");
	if(text[i-1].getLexem()==(";"))
		Operators();
	else {
		while (text[i].getLexemType() == "end") {
			stroka++;
			i++;
		}
		i++;
	}
}
void Parser::expr()
{
	while (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	term();
	while (text[i].getLexem() == "+" || text[i].getLexem() == "-") {
		i++;
		term();
	}
}
void Parser::term()
{
	while (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	simpleExpr();
	while (text[i].getLexem() == "*" || text[i].getLexem() == "%" || text[i].getLexem() == "/") {
		i++;
		simpleExpr();
	}

}
void Parser::simpleExpr()
{
	while (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	if (text[i].getLexemType() == "VAR") {
		ID();
	}
	else if (text[i].getLexemType() == "CONST_INT" || text[i].getLexemType() == "CONST_DOUBLE") {
		constant();
	}
	else if (text[i].getLexem() == "(") {
		match2("(");
		expr();
		match2(")");
	}
	else {
		out << "Строка" << ": " << stroka << " Ожидалось:" << "identifier, constant, or expression" << "получено: " << text[i].getLexemType() << endl;
	}
}
void Parser::constant()
{
	if (text[i].getLexemType() != "CONST_INT" && text[i].getLexemType() != "CONST_DOUBLE") {
		out << "Строка" << ": " << stroka << " Ожидалось:" << "CONST" << "получено: " << text[i].getLexemType() << endl;
	}
	i++;
}
void Parser::End()
{
	while (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	match("KeyWord_return");
	ID();
	match2(";");
	match2("}");
	while (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	if (text.size() > i+1) {
		out << "Строка" << ": " << stroka << " Ожидалось:" << "ничего " << "получено: " << text[i].getLexem() << endl;
	}
}

void Parser::match(string s)
{
	if (text[i].getLexemType() == s) {
		i++;
	}
	else {
		out << "Строка" << ": " << stroka << " Ожидалось:" << s  <<"получено: "<< text[i].getLexem() << endl;
		i++;
	}
}
void Parser::match2(string s)
{
	while (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	if (text[i].getLexem() == s) {
		i++;
	}
	else {
		out << "Строка" << ": " << stroka << " Ожидалось:" << s << "получено: " << text[i].getLexem() << endl;
		i++;
	}
}


