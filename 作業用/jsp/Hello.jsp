<%@page contentType="text/html; charset=utf-8"%>
<%
	// 以下のどちらか一方を出力します。両方出力するとJSONとしては認識できなくなります。
	// こんにちはと表示します。
	out.print("こんにちは");
	// {"value": "こんにちは"}と設定されたJSONを返却します。
	// out.print("{\"value\":\"こんにちは\"}");
%>