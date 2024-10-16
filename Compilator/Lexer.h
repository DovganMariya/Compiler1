#include "includes.h"

using namespace std;
class Lexer 
{
private:
	HashTable Tokens;
	void CreateToken(vector<char>& alphabet, string& s, ofstream& out)
	{
		if (s.size() != 0)
		{
			if (dfa(countStatesKeyWord, alphabet, finalStatesKeyWord, transitFunctionKeyWord).isAccept(s))
			{
				Token token = Token(s, "KeyWord");
				Tokens.add(token);
				s.clear();
				return;
			}
			else if (dfa(countStatesKeyWords, alphabet, finalStatesKeyWords, transitFunctionKeyWords).isAccept(s))
			{
				Token token = Token(s, "KeyWord");
				Tokens.add(token);
				s.clear();
				return;
			}
			else if (dfa(countStatesVar, alphabet, finalStatesVar, transitFunctionVar).isAccept(s))
			{
				Token token = Token(s, "VAR");
				Tokens.add(token);
				s.clear();
				return;
			}
			else if (dfa(countStatesConst, alphabet, finalStatesConst, transitFunctionConst).isAccept(s))
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
		string alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.+-,;*/%(){}=\n";
		char a;
		string s;
		ofstream out("errors.txt");
		while (!inp.eof())
		{
			inp.get(a);
			if (a == ';')
			{
				CreateToken(alphabet, s, out);
				Token token = Token(";", "SEP");
				Tokens.add(token);
			}
			else if (a == ',')
			{
				CreateToken(alphabet, s, out);
				Token token = Token(",", "SEP");
				Tokens.add(token);
			}
			else if (a == '{')
			{
				CreateToken(alphabet, s, out);
				Token token = Token("{", "SEP");
				Tokens.add(token);
			}
			else if (a == '}')
			{
				CreateToken(alphabet, s, out);
				Token token = Token("}", "SEP");
				Tokens.add(token);

			}
			else if (a == '(')
			{
				CreateToken(alphabet, s, out);
				Token token = Token("(", "SEP");
				Tokens.add(token);
			}
			else if (a == ')')
			{
				CreateToken(alphabet, s, out);
				Token token = Token(")", "SEP");
				Tokens.add(token);
			}
			else if (a == ' ')
			{
				CreateToken(alphabet, s, out);
			}
			else if (a == '+' || a == '-' || a == '*' || a == '%' || a=='=' || a=='/')
			{
				CreateToken(alphabet, s, out);
				string oper = "";
				oper += a;
				Token token = Token(oper, "OPER");
				Tokens.add(token);
			}
			else if (!IsValidChar(a, alp)) {
				CreateToken(alphabet, s, out);
				out << "Неопределённый символ: " <<a<<endl;
			}
			else if (a == '\n')
			{
				CreateToken(alphabet, s, out);
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
