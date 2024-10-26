#include "includes.h"
using namespace std;
class Lexer 
{

private:
	HashTable Tokens;
	void CreateToken(string& s, ofstream& out,dfa &KEY, dfa& KEY2, dfa& var,dfa& cons)
	{
		
		if (s.size() != 0)
		{
			
			if (KEY.isAccept(s))
			{
				Token token = Token(s, "KeyWord");
				Tokens.add(token);
				s.clear();
				return;
			}
			else if (KEY2.isAccept(s))
			{
				Token token = Token(s, "KeyWord");
				Tokens.add(token);
				s.clear();
				return;
			}
			else if (var.isAccept(s))
			{
				Token token = Token(s, "VAR");
				Tokens.add(token);
				s.clear();
				return;
			}
			else if (cons.isAccept(s))
			{
				Token token = Token(s, "CONST");
				Tokens.add(token);
				s.clear();
				return;
			}
			out << "Не удалось распознать лексему: " << s << '\n';
			s.clear();
		}
	}

public:
	bool IsValidChar(char c, const std::string& alphabet) {
		for (char validChar : alphabet) {
			if (c == validChar) {
				return true;
			}
		}
		return false;
	}
	Lexer (ifstream& inp)
	{
		vector<char> alphabet;
		for (char c = 'a'; c <= 'z'; c++)
		{
			alphabet.push_back(c);
		}
		for (char c = 'A'; c <= 'Z'; c++)
		{
			alphabet.push_back(c);
		}
		for (char c = '0'; c <= '9'; c++)
		{
			alphabet.push_back(c);
		}
		alphabet.push_back('.');
		alphabet.push_back('+');
		alphabet.push_back('-');
		alphabet.push_back(',');
		alphabet.push_back(';');
		alphabet.push_back('*');
		alphabet.push_back('/');
		alphabet.push_back('%');
		alphabet.push_back('(');
		alphabet.push_back(')');
		alphabet.push_back('{');
		alphabet.push_back('}');
		alphabet.push_back('=');
		dfa KEY = dfa(countStatesKeyWord, alphabet, finalStatesKeyWord, transitFunctionKeyWord);
		dfa KEY2 = dfa(countStatesKeyWords, alphabet, finalStatesKeyWords, transitFunctionKeyWords);
		dfa var = dfa(countStatesVar, alphabet, finalStatesVar, transitFunctionVar);
		dfa cons = dfa(countStatesConst, alphabet, finalStatesConst, transitFunctionConst);
		string alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.+-,;*/%(){}=\n";
		char a;
		string s;
		ofstream out("errors.txt");
		while (!inp.eof())
		{
			
			inp.get(a);
			if (a == ';')
			{
				CreateToken(s, out,KEY,KEY2,var,cons);
				Token token = Token(";", "SEP");
				Tokens.add(token);
			}
			else if (a == ',')
			{
				CreateToken(s, out, KEY, KEY2, var, cons);
				Token token = Token(",", "SEP");
				Tokens.add(token);
			}
			else if (a == '{')
			{
				CreateToken( s, out, KEY, KEY2, var, cons);
				Token token = Token("{", "SEP");
				Tokens.add(token);
			}
			else if (a == '}')
			{
				CreateToken(s, out, KEY, KEY2, var, cons);
				Token token = Token("}", "SEP");
				Tokens.add(token);

			}
			else if (a == '(')
			{
				CreateToken(s, out, KEY, KEY2, var, cons);
				Token token = Token("(", "SEP");
				Tokens.add(token);
			}
			else if (a == ')')
			{
				CreateToken(s, out, KEY, KEY2, var, cons);
				Token token = Token(")", "SEP");
				Tokens.add(token);
			}
			else if (a == ' ')
			{
				CreateToken( s, out, KEY, KEY2, var, cons);
			}
			else if (a == '+' || a == '-' || a == '*' || a == '%' || a=='=' || a=='/')
			{
				CreateToken(s, out, KEY, KEY2, var, cons);
				string oper = "";
				oper += a;
				Token token = Token(oper, "OPER");
				Tokens.add(token);
			}
			else if (!IsValidChar(a, alp)) {
				CreateToken(s, out, KEY, KEY2, var, cons);
				out << "Неопределённый символ: " <<a<<endl;
			}
			else if (a == '\n')
			{
				CreateToken(s, out, KEY, KEY2, var, cons);
			}

			else
			{
				s += a;

			}
			


		}
	}
	HashTable getHashTable()
	{
		return this->Tokens;
	}
};
