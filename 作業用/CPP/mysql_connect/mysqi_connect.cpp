/* 概要 DBに接続するためのテスト用プログラム xammpにインストールされているmysqlが対象
 *
 * 作成日 2017年7月24日
 *
 * 作成者 平澤敬介
 */

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysql_error.h>
#include <cppconn/Statement.h>
#include <cppconn/ResultSet.h>

using namespace std;

int main()
{
	sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
	unique_ptr<sql::Connection> con(driver->connect("jdbc:mariadb://localhost/ddthink-com00006",
			"rood", ""));
	unique_ptr<sql::Statement> stmt(con->createStatement());

	return 0;
}
