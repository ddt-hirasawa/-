#include<iostream>
#include<mysql.h>
#include<string>
#include<cstdlib>

using namespace std;

//ŠÖ”ƒwƒbƒ_
int db_connect();

int main()
{
	//const char* answer = "Content-Type:text/html;charset=utf-8\n\n";
	const char* answer = "Content-Type:text/html;charset=utf-8\n\n";

	if (db_connect() == 1) {
		cout << answer;
		string result = "success: \"db_connect\", value2 : \"ddthink\"";
		cout << "{" << result << "}";
	}
	else {

		return -1;
	}

	return 0;
}

int db_connect() {

	const char host[] = "localhost";
	const char user[] = "root";
	const char pass[] = "";
	const char db_name[] = "ddthink-com00006";
	const char sql[] = "select * from test";


	MYSQL* mysql;
	MYSQL_RES* res;
	MYSQL_FIELD* field;
	MYSQL_ROW row;

	mysql = mysql_init(0);

	if (mysql_real_connect(mysql, host, user, pass, db_name, 3306, NULL, 0) == NULL) {

		cout << mysql_error(mysql);
		return -1;
	}
	return 1;
}