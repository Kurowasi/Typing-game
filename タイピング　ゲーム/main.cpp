
#include "DxLib.h"
#include "config.h"
#include "Sub.h"

//!==アドバイス
//メインにはシステムだけ書いて、他の部分に長いコードを書いたほうが見やすい。
//基本は関数のまとまりにして、その関数群を組み合わせて長いプログラムを作る。
//何度も使う処理は関数にして、なるべく同じものを書かない。

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){

		ChangeWindowMode(TRUE);	//windowモードを有効に
		SetGraphMode(WINDOW_X,WINDOW_Y,32);//画面サイズ指定,カラービット値指定(16or32)
		//※SetGraphModeを使うと、グラフィックハンドルとフォントハンドルが初期化されるので注意。
		DxLib_Init();

		SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更と初期化と裏画面設定
		init();
		init_1();
		init_2();
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){// while(裏画面を表画面に反映, メッセージ処理, 画面クリア)

		SubFunc();// -> Sub.cpp

	}

        DxLib_End(); // DXライブラリ終了処理
        return 0;
}
  