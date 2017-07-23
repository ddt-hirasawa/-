

getJsonFile = function(jsonPath){
		//一時的に値を保存する変数tmpを宣言する。
		var tmp;

		//Ajax通信でjsonファイルを取得する。
		$.ajax({
			type: 'GET',
			//jsonファイルのURLを指定する。
			url: jsonPath,
			//取得するファイルの形式をJSONに指定する。
			//dataType: 'txt',
			//同期通信を行う。
			async: false,
			//キャッシュを無効にする。
			//cache:false,
			//通信完了時の処理を記述する。
			success: function(){

					console.log("ファイルの取得に成功しました");

			}
		});
		
		return tmp;	//取得したデータを返す
	};