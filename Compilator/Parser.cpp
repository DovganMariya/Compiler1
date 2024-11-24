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
void Parser::printparse(vector<Token> text)
{
	ofstream out("Tree_Parse.txt");
	for (int i = 0;i < text.size();i++) {
		out << text[i].getLexem();
	}
}
Parser::Parser(vector<Token> tok)
{
	text = tok;
	printparse(tok);
}
void Parser::parse() {
	Begin();
	Descr();
	Op();
	End();
}

void Parser::Begin()
{
//	ofstream out("Tree_Parse.txt");
//	out << "kzkzkkz";
	if (text[i].getLexemType() == "end") {
		stroka++;
		i++;
	}
	if (text[i].getLexemType() == "KeyWord_float_int") {

	}
	else {
		out << "Строка" << ": " << stroka << "Ожидалось:" << "KeyWord_float_int получено"<<text[i].getLexemType();
	}
	
}

void Parser::Descr()
{

}
void Parser::Op()
{

}
void Parser::End()
{

}

