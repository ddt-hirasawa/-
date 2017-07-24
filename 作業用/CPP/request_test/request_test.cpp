/* 概要 Ajax通信でれクエスト情報を取得するテスト
 * HttpRequestの代用
 *
 * 作成日 2017年7月24日
 *
 * 作成者 平澤敬介
 */

#include<iostream>
#include<cstdlib>
#include<string>
#include <boost/shared_ptr.hpp>

using namespace std;

int main(int argc,const char* argv[])
{
	//ヘッダ部を出力します。 CGI仕様
	cout << "Content-type: text/htmlcharset=utf-8\n\n";

	//メソッド（GETなのかPOSTなのか）を取得する
	char* str = getenv("REQUEST_METHOD");
	cout << str;
	char* tmp = getenv("CONTENT_LENGTH");
	cout << tmp;

	return 0;
}
