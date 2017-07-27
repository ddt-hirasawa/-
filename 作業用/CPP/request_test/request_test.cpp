/* 概要 Ajax通信でれクエスト情報を取得するテスト
* HttpRequestの代用
*
* 作成日 2017年7月24日
*
* 作成者 平澤敬介
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include"picojson.h"

using namespace std;
std::string UrlDecorde(const std::string & str);
char hexToChar(char first,char second);
bool isLF(const std::string & str,
const std::string::size_type& length,
std::string::size_type& index,
char* tmpStr);

int main()
{
	const char* answer = "Content-Type:text/html;charset=utf-8\n\n";

	cout << answer;

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

	string anset = UrlDecorde(result);

	//json= を削除
	anset.erase(anset.begin(), anset.begin() + 5);

	picojson::value pico;
	picojson::parse(pico, anset);
	picojson::object& obj = pico.get<picojson::object>();
	string set = obj["db_getQuery"].get<string>();

	//cout << picojson;
	cout << "{" << "\"testdb_getQuery\" : " << set << "}";

	return 0;
}

