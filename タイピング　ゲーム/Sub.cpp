//ここに基本となるソースを書いていく。
//今後追加したいもの⇒ファイルにデータを保存してランキング１０までと、新記録できたら新記録達成と出す
//　　　　　　　　　⇒いいえで終了させる


#pragma once

#include "DxLib.h"
#include "Util.h"
#include "config.h"

typedef enum state{
	state_shoki,
	state_start_1,
	state_start_2,
	state_play_1,
	state_play_2,
	state_end_1,
	state_end_2,

};

int state_;
int tHandle;
int t_1Handle;
int t_2Handle;
char queue_ans[STR_MAX];//解答用の文字列キュー
char queue_show[STR_MAX];//提示/問題用の文字列キュー
char queue_show_1[STR_MAX];
char queue_show_2[STR_MAX];
char queue_show_3[STR_MAX];
int push_num=0;//現在の入力数

int level = 1;//問題のレベル
int score = 0;//得点(得点が一定毎にレベルをあげる)
int ancer_count;

int time_counter = 0;//タイマー(実行処理依存、簡単に言えば1フレーム毎)
int time_limit =  TIME_LIMIT;//問題ごとのリミットタイム
int over_Time = 0;
bool stateflag = false; //false...問題が用意されていない。

int MouseX=0,MouseY=0;
int MouseInput;
int ButtonA;

//ファイル内部用関数//
void Start(void);
void KeyInput(void);//キー入力から文字列への代入を行う。
void QuestionGenerate(void);//問題生成用
void QuestionGenerate_2(void);
void CheckStrings_1(void);//文字列比較とその周辺の処理
void CheckStrings_2(void);
void init();
void init_1();
void init_2();
void Start_1();
void Start_2();
void End_1();
void End_2();
//基本の関数_main.cppに呼び出される
void SubFunc(){

	gpUpdateKey();//キー入力更新

	KeyInput();

	switch(state_){
	case state_shoki:
		Start();
		break;
	case state_start_1:
		Start_1();
		break;
	case state_start_2:
		Start_2();
		break;
	case state_play_1:
	//デバッグストリング
	CheckStrings_1();

	DrawFormatStringToHandle( 0 , 300 ,GetColor(255,255,255),t_2Handle ,"ANS = %s",queue_ans);
	DrawFormatStringToHandle( 0 , 100 ,GetColor(255,255,255),t_2Handle ,"SHOW = %s",queue_show);
	DrawFormatStringToHandle( 210 , 160 ,GetColor(255,255,255),t_2Handle ,"%s",queue_show_1);
	DrawFormatStringToHandle( 400 , 0 ,GetColor(255,255,255),t_2Handle ,"num = %d",push_num);
	DrawFormatStringToHandle( 0 , 0 ,GetColor(255,255,255),t_2Handle ,"%d",ancer_count-1);



	time_counter++;
	if( time_counter == 3000 ){
		state_ += 2;
	}
	break;
	case state_play_2:
	CheckStrings_2();
	//デバッグストリング
	DrawFormatStringToHandle( 0 , 300 ,GetColor(255,255,255),t_2Handle ,"ANS = %s",queue_ans);
	DrawFormatStringToHandle( 0 , 100 ,GetColor(255,255,255),t_2Handle ,"SHOW = %s",queue_show_2);
	DrawFormatStringToHandle( 210 , 160 ,GetColor(255,255,255),t_2Handle ,"%s",queue_show_3);
	DrawFormatStringToHandle( 400 , 0 ,GetColor(255,255,255),t_2Handle ,"num = %d",push_num);
	DrawFormatStringToHandle( 0 , 0 ,GetColor(255,255,255),t_2Handle ,"%d",ancer_count-1);

	time_counter++;
	if( time_counter == 3000 ){
		state_ += 2;
	}
	break;
	
	case state_end_1:
		End_1();
		break;
	case state_end_2:
		End_2();
		break;
	}



}


//機能系の関数群============================================================

void KeyInput(){//各キーの動作詳細

	bool pushed_flag = false;//押下フラグ

	//ゴリ押し式タイプ文字列挿入
	//もっといい方法あればそっちに変えても良い

	if(Key[KEY_INPUT_A] == 1 ) {//「==1」は入力の1フレーム目(入力した瞬間)を取得するため
		queue_ans[push_num] = 'a';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_B] == 1 ) {
		queue_ans[push_num] = 'b';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_C] == 1 ) {
		queue_ans[push_num] = 'c';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_D] == 1 ) {
		queue_ans[push_num] = 'd';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_E] == 1 ) {
		queue_ans[push_num] = 'e';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_F] == 1 ) {
		queue_ans[push_num] = 'f';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_G] == 1 ) {
		queue_ans[push_num] = 'g';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_H] == 1 ) {
		queue_ans[push_num] = 'h';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_I] == 1 ) {
		queue_ans[push_num] = 'i';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_J] == 1 ) {
		queue_ans[push_num] = 'j';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_K] == 1 ) {
		queue_ans[push_num] = 'k';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_L] == 1 ) {
		queue_ans[push_num] = 'l';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_M] == 1 ) {
		queue_ans[push_num] = 'm';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_N] == 1 ) {
		queue_ans[push_num] = 'n';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_O] == 1 ) {
		queue_ans[push_num] = 'o';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_P] == 1 ) {
		queue_ans[push_num] = 'p';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_Q] == 1 ) {
		queue_ans[push_num] = 'q';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_R] == 1 ) {
		queue_ans[push_num] = 'r';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_S] == 1 ) {
		queue_ans[push_num] = 's';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_T] == 1 ) {
		queue_ans[push_num] = 't';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_U] == 1 ) {
		queue_ans[push_num] = 'u';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_V] == 1 ) {
		queue_ans[push_num] = 'v';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_W] == 1 ) {
		queue_ans[push_num] = 'w';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_X] == 1 ) {
		queue_ans[push_num] = 'x';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_Y] == 1 ) {
		queue_ans[push_num] = 'y';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_Z] == 1 ) {
		queue_ans[push_num] = 'z';
		pushed_flag = true;
	}
	if(Key[KEY_INPUT_MINUS] == 1 ) {
		queue_ans[push_num] = '-';
		pushed_flag = true;
	}
	if( (Key[KEY_INPUT_BACK]==1 )&&( push_num > 0 ) ){//文字の消去
		push_num--;
		queue_ans[push_num] = ' ';

	}

	//フラグによって現在の文字数の増加を行う
	if( pushed_flag ){
		push_num++;
		pushed_flag = false; 
	}

}

void QuestionGenerate(void){//問題用の文字列生成

	int rnd = GetRand( 36 );//ランダムな番号を生成(数はレベル×10としてある)


	//ゴリ押しスイッチ分岐法。何か良い方法あれば変更しても良い
	switch(rnd){
	case 0:
		strcpy( queue_show , "pikachuu" );
		strcpy( queue_show_1,"ピカチュウ");
		break;
	case 1:
		strcpy( queue_show , "husigidane" );
		strcpy( queue_show_1,"フシギダネ");
		break;
	case 2:
		strcpy( queue_show , "zenigame" );
		strcpy( queue_show_1,"ゼニガメ");
		break;
	case 3:
		strcpy( queue_show , "hitokage" );
		strcpy( queue_show_1,"ヒトカゲ");
		break;
	case 4:
		strcpy( queue_show , "husigibana" );
		strcpy( queue_show_1,"フシギバナ");
		break;
	case 5:
		strcpy( queue_show , "riza-donn" );
		strcpy( queue_show_1,"リザードン");
		break;
	case 6:
		strcpy( queue_show , "kamekkusu" );
		strcpy( queue_show_1,"カメックス");
		break;
	case 7:
		strcpy( queue_show , "tikori-ta" );
		strcpy( queue_show_1,"チコリータ");
		break;
	case 8:
		strcpy( queue_show , "hinoarasi" );
		strcpy( queue_show_1,"ヒノアラシ");
		break;
	case 9:
		strcpy( queue_show , "waninoko" );
		strcpy( queue_show_1,"ワニノコ");
		break;
	case 10:
		strcpy( queue_show , "meganiumu" );
		strcpy( queue_show_1,"メガニウム");
		break;
	case 11:
		strcpy( queue_show , "bakuhu-nn" );
		strcpy( queue_show_1,"バクフーン");
		break;
	case 12:
		strcpy( queue_show , "o-dairu" );
		strcpy( queue_show_1,"オーダイル");
		break;
	case 13:
		strcpy( queue_show , "kimori" );
		strcpy( queue_show_1,"キモリ");
		break;
	case 14:
		strcpy( queue_show , "achamo" );
		strcpy( queue_show_1,"アチャモ");
		break;
	case 15:
		strcpy( queue_show , "mizugorou" );
		strcpy( queue_show_1,"ミズゴロウ");
		break;
	case 16:
		strcpy( queue_show , "jukainn" );
		strcpy( queue_show_1,"ジュカイン");
		break;
	case 17:
		strcpy( queue_show , "basha-mo" );
		strcpy( queue_show_1,"バシャーモ");
		break;
	case 18:
		strcpy( queue_show , "ragura-zi" );
		strcpy( queue_show_1,"ラグラージ");
		break;
	case 19:
		strcpy( queue_show , "naetoru" );
		strcpy( queue_show_1,"ナエトル");
		break;
	case 20:
		strcpy( queue_show , "hikozaru" );
		strcpy( queue_show_1,"ヒコザル");
		break;
	case 21:
		strcpy( queue_show , "pocchama" );
		strcpy( queue_show_1,"ポッチャマ");
		break;
	case 22:
		strcpy( queue_show , "dodaitosu" );
		strcpy( queue_show_1,"ドダイトス");
		break;
	case 23:
		strcpy( queue_show , "goukazaru" );
		strcpy( queue_show_1,"ゴウカザル");
		break;
	case 24:
		strcpy( queue_show , "ennperuto" );
		strcpy( queue_show_1,"エンペルト");
		break;
	case 25:
		strcpy( queue_show , "tuta-ja" );
		strcpy( queue_show_1,"ツタージャ");
		break;
	case 26:
		strcpy( queue_show , "pokabu" );
		strcpy( queue_show_1,"ポカブ");
		break;
	case 27:
		strcpy( queue_show , "mijumaru" );
		strcpy( queue_show_1,"ミジュマル");
		break;
	case 28:
		strcpy( queue_show , "jaro-da" );
		strcpy( queue_show_1,"ジャローダ");
		break;
	case 29:
		strcpy( queue_show , "ennbuo-" );
		strcpy( queue_show_1,"エンブオー");
		break;
	case 30:
		strcpy( queue_show , "daikennki" );
		strcpy( queue_show_1,"ダイケンキ");
		break;
	case 31:
		strcpy( queue_show , "harimaronn" );
		strcpy( queue_show_1,"ハリマロン");
		break;
	case 32:
		strcpy( queue_show , "fokko" );
		strcpy( queue_show_1,"フォッコ");
		break;
	case 33:
		strcpy( queue_show , "keromatu" );
		strcpy( queue_show_1,"ケロマツ");
		break;
	case 34:
		strcpy( queue_show , "burigaronn" );
		strcpy( queue_show_1,"ブリガロン");
		break;
	case 35:
		strcpy( queue_show , "mafokusi-" );
		strcpy( queue_show_1,"マフォクシー");
		break;
	case 36:
		strcpy( queue_show , "gekkouga" );
		strcpy( queue_show_1,"ゲッコウガ");
		break;

	
	}


}

void QuestionGenerate_2(void){//問題用の文字列生成

	int rnd = GetRand( 18 );//ランダムな番号を生成(数はレベル×10としてある)


	//ゴリ押しスイッチ分岐法。何か良い方法あれば変更しても良い
	switch(rnd){
	case 0:
		strcpy( queue_show_2 , "hatanojunn" );
		strcpy( queue_show_3 , "波多野　純" );
		break;
	case 1:
		strcpy( queue_show_2 , "niwazirou" );
		strcpy( queue_show_3 , "丹羽　次郎" );
		break;
	case 2:
		strcpy( queue_show_2 , "takasehirosi" );
		strcpy( queue_show_3 , "高瀬　浩史" );
		break;
	case 3:
		strcpy( queue_show_2 , "shoudouzitutomu" );
		strcpy( queue_show_3 , "正道寺　勉" );
		break;
	case 4:
		strcpy( queue_show_2 , "kannbayasiyasusi" );
		strcpy( queue_show_3 , "神林　靖" );
		break;
	case 5:
		strcpy( queue_show_2 , "kumenohumihiro" );
		strcpy( queue_show_3 , "粂野　文洋" );
		break;
	case 6:
		strcpy( queue_show_2 , "sinndouyosiaki" );
		strcpy( queue_show_3 , "新藤　義昭" );
		break;
	case 7:
		strcpy( queue_show_2 , "matudahirosi" );
		strcpy( queue_show_3 , "松田　洋" );
		break;
	case 8:
		strcpy( queue_show_2 , "etoukaoru" );
		strcpy( queue_show_3 , "江藤　香" );
		break;
	case 9:
		strcpy( queue_show_2 , "hasiurahiroaki" );
		strcpy( queue_show_3 , "橋浦　弘明" );
		break;
	case 10:
		strcpy( queue_show_2 , "katumatamasasi" );
		strcpy( queue_show_3 , "勝間田　仁" );
		break;
	case 11:
		strcpy( queue_show_2 , "isikawatakasi" );
		strcpy( queue_show_3 , "石川　孝" );
		break;
	case 12:
		strcpy( queue_show_2 , "tuzimurayasuhiro" );
		strcpy( queue_show_3 , "辻村　泰寛" );
		break;
	case 13:
		strcpy( queue_show_2 , "kitakubosigeru" );
		strcpy( queue_show_3 , "北久保　茂" );
		break;
	case 14:
		strcpy( queue_show_2 , "katayamasigetomo" );
		strcpy( queue_show_3 , "片山　茂友" );
		break;
	case 15:
		strcpy( queue_show_2 , "yamatihidemi" );
		strcpy( queue_show_3 , "山地　秀美" );
		break;
	case 16:
		strcpy( queue_show_2 , "isiharazirou" );
		strcpy( queue_show_3 , "石原　次郎" );
		break;
	case 17:
		strcpy( queue_show_2 , "nakamurakazuhiro" );
		strcpy( queue_show_3 , "中村　一博" );
		break;
	case 18:
		strcpy( queue_show_2 , "oohasiyuutarou" );
		strcpy( queue_show_3 , "大橋　裕太郎" );
		break;

	}


}

void CheckStrings_1(void){//解答が正解かどうかと、問題の生成が必要かどうかの２つのチェック

	if(stateflag){//問題生成されている

		//文字列の比較で常時監視する。

		if( (strcmp( queue_ans , queue_show ) == 0) && ( Key[ KEY_INPUT_RETURN ] == 1 ) ){//文字列が一致し、エンターで入力したら
		//->正当時はその処理を行う。

			memset( queue_ans , '\0' , STR_MAX );//NULL文字でリセット
			memset( queue_show , '\0' , STR_MAX );
			memset( queue_show_1, '\0',STR_MAX );
			stateflag = false;
			push_num = 0;						//押した文字数をリセット
		}


	}else{//問題生成されていない
		//レベルに応じた問題生成を行う。


		//ここにタイマーの更新処理を入れてもよい
		QuestionGenerate();
		stateflag = true;//忘れずにフラグを立てる。
		ancer_count += 1;
	
	}




}


void CheckStrings_2(void){//解答が正解かどうかと、問題の生成が必要かどうかの２つのチェック

	if(stateflag){//問題生成されている

		//文字列の比較で常時監視する。

		if( (strcmp( queue_ans , queue_show_2 ) == 0) && ( Key[ KEY_INPUT_RETURN ] == 1 ) ){//文字列が一致し、エンターで入力したら
		//->正当時はその処理を行う。

			memset( queue_ans , '\0' , STR_MAX );//NULL文字でリセット
			memset( queue_show_2 , '\0' , STR_MAX );
			memset( queue_show_3, '\0',STR_MAX );
			stateflag = false;
			push_num = 0;						//押した文字数をリセット
		}


	}else{//問題生成されていない
		//レベルに応じた問題生成を行う。


		//ここにタイマーの更新処理を入れてもよい
		QuestionGenerate_2();
		stateflag = true;//忘れずにフラグを立てる。
		ancer_count += 1;
	
	}




}

void Start(){
	int Cr = GetColor(255,255,255);
	int MOUSEX,MOUSEY;
	int G = LoadGraph("haikei.png");
	/*DrawGraph( 0 , 0 , G, 0);*/
	DrawRotaGraph( 0 , 0 , 0.9 , 0 , G , 0 , 1 );
	//SetFontSize(64); 
	//DrawString( 120 , 320 ,"初級",Cr);
	DrawStringToHandle( 325 , 320 , "NORMAL",GetColor(0,0,0), tHandle );
	DrawStringToHandle( 350 , 240 , "HARD" ,GetColor(0,0,0), tHandle );
	//DrawBox( 325 , 320 , 550 , 380 , GetColor(255,255,255),TRUE);
	//DrawBox( 350 , 240 , 525 , 300 , GetColor(255,255,255) , TRUE );

	GetMousePoint(&MOUSEX,&MOUSEY);
	//NORMAL
	if( ((325 < MOUSEX) && (MOUSEX < 550)) && ((320 < MOUSEY) && (MOUSEY < 380)) ){
		if(( GetMouseInput() & MOUSE_INPUT_LEFT ) != 0){
			state_ += 1;
			
		}
	}
	//HARD
	if(((350<MOUSEX && MOUSEX<525) && (240<MOUSEY && MOUSEY<300))){
		if( (GetMouseInput() & MOUSE_INPUT_LEFT ) != 0 ){
			state_ += 2;
		}
	}

}

void init(){
	tHandle = CreateFontToHandle( "MS明朝" , 64 , 10 );
	
}

void init_1(){
	t_1Handle = CreateFontToHandle("MS明朝" , 30 , 10 );
}

void init_2(){
	t_2Handle = CreateFontToHandle("MSゴシック" , 60 , 10);
}
void Start_1(){
	time_counter = 0;
	ancer_count = 0;
	memset( queue_ans , '\0' , STR_MAX );//NULL文字でリセット
	memset( queue_show , '\0' , STR_MAX );
	memset( queue_show_1, '\0',STR_MAX );
	stateflag = false;
	push_num = 0;		
	DrawStringToHandle( 300 , 240 , "Enterキーで",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 200 , 270 , "NORMALステージスタート！！",GetColor(255,255,255),t_1Handle);
	if(CheckHitKey(KEY_INPUT_RETURN) == 1){
		state_ += 2;
	}
}

void Start_2(){
	time_counter = 0;
	ancer_count = 0;
	memset( queue_ans , '\0' , STR_MAX );//NULL文字でリセット
	memset( queue_show , '\0' , STR_MAX );
	memset( queue_show_1, '\0',STR_MAX );
	stateflag = false;
	push_num = 0;	
	DrawStringToHandle( 300 , 240 , "Enterキーで",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 200 , 270 , "HARDステージスタート！！",GetColor(255,255,255),t_1Handle);
	if(CheckHitKey(KEY_INPUT_RETURN) == 1){
		state_ += 2;
	}
}

void End_1(){

	FILE *fp;
	fp = fopen("Data.txt","wb");
	if( fp == NULL ){
		DrawStringToHandle( 0 , 0 , "ファイルを開くのに失敗しました",GetColor(255,255,255),t_1Handle);
	}
	fwrite( &ancer_count, sizeof(int), 1, fp );
	fclose(fp);


	int MOUSEX,MOUSEY;
	GetMousePoint(&MOUSEX,&MOUSEY);

	DrawStringToHandle( 300 , 0 , "お疲れ様でした。",GetColor(255,255,255),t_1Handle);
	DrawFormatStringToHandle( 50 , 50 ,GetColor(255,255,255),tHandle ,"今回の回答数は%dでした。",ancer_count-1);
	DrawStringToHandle( 260 , 400 , "もう一度やりますか？",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 300 , 450 , "はい",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 430 , 450 , "いいえ",GetColor(255,255,255),t_1Handle);
	//DrawBox( 300 , 450 , 360 , 480 , GetColor(255,255,255),TRUE);
	//DrawBox( 430 , 450 , 520 , 480 , GetColor(255,255,255),TRUE);
	if(((300<MOUSEX && MOUSEX<360) && (450<MOUSEY && MOUSEY<480))){
		if( (GetMouseInput() & MOUSE_INPUT_LEFT ) != 0 ){
			state_ = 1;
		}
	}
	if(((430<MOUSEX && MOUSEX<520) && (450<MOUSEY && MOUSEY<480))){
		if( (GetMouseInput() & MOUSE_INPUT_LEFT ) != 0 ){
			DxLib_End() ;
		}
	}
}
void End_2(){
	int MOUSEX,MOUSEY;
	GetMousePoint(&MOUSEX,&MOUSEY);

	DrawStringToHandle( 300 , 0 , "お疲れ様でした。",GetColor(255,255,255),t_1Handle);
	DrawFormatStringToHandle( 50 , 50 ,GetColor(255,255,255),tHandle ,"今回の回答数は%dでした。",ancer_count-1);
	DrawStringToHandle( 260 , 400 , "もう一度やりますか？",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 300 , 450 , "はい",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 430 , 450 , "いいえ",GetColor(255,255,255),t_1Handle);
	if(((300<MOUSEX && MOUSEX<360) && (450<MOUSEY && MOUSEY<480))){
		if( (GetMouseInput() & MOUSE_INPUT_LEFT ) != 0 ){
			state_ = 2;
		}
	}
	if(((430<MOUSEX && MOUSEX<520) && (450<MOUSEY && MOUSEY<480))){
		if( (GetMouseInput() & MOUSE_INPUT_LEFT ) != 0 ){
			DxLib_End() ;
		}
	}
}