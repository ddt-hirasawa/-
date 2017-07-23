#include <iostream>
using namespace std;

int main()
{
	cout << "Content-type: text/html\n\n";
	cout << "{"
			"\"title\":\"サンプル\","
			"\"color\":"
			"["
			"{"
			"\"name\":\"赤色\","
			"\"colorName\": \"red\","
			"\"colorCode\": \"#ff0000\""
			"},"
			"{"
			"\"name\":\"青色\","
			"\"colorName\": \"blue\","
			"\"colorCode\": \"#0000ff\""
			"},"
			"{"
			"\"name\": \"緑色\","
			"\"colorName\": \"green\","
			"\"colorCode\": \"#008000\""
			"}"
			"]"
			"}";

	return 0;
}

