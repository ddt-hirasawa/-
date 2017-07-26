/* 概要 Ajax通信でれクエスト情報を取得するテスト
* HttpRequestの代用
*
* 作成日 2017年7月24日
*
* 作成者 平澤敬介
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<map>
#include<ctype.h>
#include"picojson.h"

using namespace std;
/*
//関数ヘッダ
bool isLF(const string& str,
	const string::size_type& length,
	string::size_type& index,
	char* tmpStr);
string UrlDecorde(const string& str);
char HexToChar(char first, char second);
string UTF8toSjis(string srcUTF8);
std::string SjistoUTF8(std::string srcSjis);
*/
//  文字列を置換する
string Replace(string String1, string String2, string String3);

#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(push) 
#pragma warning(disable:4996) 
#endif 

int main()
{
	// 環境変数[REQUEST_METHOD]に送信されたメソッド[GET/POST]が入ります。  
	std::string request_method = getenv("REQUEST_METHOD");
	if (request_method != "POST")
	{
		cout << "REQUEST_METHOD : " << request_method << endl;
		return 0;
	}

	// 送信されたサイズを取得します。  
	const char* lengthStr = getenv("CONTENT_LENGTH");
	int length = atoi(lengthStr);


	// 送信されたデータを保存する文字列のメモリを確保します。  
	char* tmpBuf = new char[length + 1];
	if (!tmpBuf)
	{
		cout << "Allocate is failed." << endl;
		return 0;
	}

	// 標準入力からPOSTされたデータを取得します。  
	if (fread(tmpBuf, 1, length, stdin) != length)
	{
		cout << "fread is failed." << endl;
		return 0;
	}
	tmpBuf[length] = '\0';
	string result = tmpBuf;

	//デコードだと対処できない
	//string decode = UrlDecorde(result);

	//ベタ打ちテスト用 後で関数化する必要あり
	//簡易的な自作デコード
	result = Replace(result, "=", ":\"");
	result = Replace(result, "%5B", "\"");
	result = Replace(result, "%5D", "\"");
	result = Replace(result, "&", ",");
	int search = result.find(",");
	result.insert(search,"\"");
	result = Replace(result, "json", "");
	result += "\"";

	const char* answer = "Content-Type:text/html;charset=utf-8\n\n";

	cout << answer;
	//cout << "{\"test\":\"" << result << "\"}";
	cout << "{" << result << "}";

	return 0;
}


#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(pop) 
#endif 

//  文字列を置換する
string Replace(string String1, string String2, string String3)
{
	string::size_type  Pos(String1.find(String2));

	while (Pos != string::npos)
	{
		String1.replace(Pos, String2.length(), String3);
		Pos = String1.find(String2, Pos + String3.length());
	}

	return String1;
}