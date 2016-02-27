//�����Ɋ�{�ƂȂ�\�[�X�������Ă����B
//����ǉ����������́˃t�@�C���Ƀf�[�^��ۑ����ă����L���O�P�O�܂łƁA�V�L�^�ł�����V�L�^�B���Əo��
//�@�@�@�@�@�@�@�@�@�˂������ŏI��������


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
char queue_ans[STR_MAX];//�𓚗p�̕�����L���[
char queue_show[STR_MAX];//��/���p�̕�����L���[
char queue_show_1[STR_MAX];
char queue_show_2[STR_MAX];
char queue_show_3[STR_MAX];
int push_num=0;//���݂̓��͐�

int level = 1;//���̃��x��
int score = 0;//���_(���_����薈�Ƀ��x����������)
int ancer_count;

int time_counter = 0;//�^�C�}�[(���s�����ˑ��A�ȒP�Ɍ�����1�t���[����)
int time_limit =  TIME_LIMIT;//��育�Ƃ̃��~�b�g�^�C��
int over_Time = 0;
bool stateflag = false; //false...��肪�p�ӂ���Ă��Ȃ��B

int MouseX=0,MouseY=0;
int MouseInput;
int ButtonA;

//�t�@�C�������p�֐�//
void Start(void);
void KeyInput(void);//�L�[���͂��當����ւ̑�����s���B
void QuestionGenerate(void);//��萶���p
void QuestionGenerate_2(void);
void CheckStrings_1(void);//�������r�Ƃ��̎��ӂ̏���
void CheckStrings_2(void);
void init();
void init_1();
void init_2();
void Start_1();
void Start_2();
void End_1();
void End_2();
//��{�̊֐�_main.cpp�ɌĂяo�����
void SubFunc(){

	gpUpdateKey();//�L�[���͍X�V

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
	//�f�o�b�O�X�g�����O
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
	//�f�o�b�O�X�g�����O
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


//�@�\�n�̊֐��Q============================================================

void KeyInput(){//�e�L�[�̓���ڍ�

	bool pushed_flag = false;//�����t���O

	//�S���������^�C�v������}��
	//�����Ƃ������@����΂������ɕς��Ă��ǂ�

	if(Key[KEY_INPUT_A] == 1 ) {//�u==1�v�͓��͂�1�t���[����(���͂����u��)���擾���邽��
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
	if( (Key[KEY_INPUT_BACK]==1 )&&( push_num > 0 ) ){//�����̏���
		push_num--;
		queue_ans[push_num] = ' ';

	}

	//�t���O�ɂ���Č��݂̕������̑������s��
	if( pushed_flag ){
		push_num++;
		pushed_flag = false; 
	}

}

void QuestionGenerate(void){//���p�̕����񐶐�

	int rnd = GetRand( 36 );//�����_���Ȕԍ��𐶐�(���̓��x���~10�Ƃ��Ă���)


	//�S�������X�C�b�`����@�B�����ǂ����@����ΕύX���Ă��ǂ�
	switch(rnd){
	case 0:
		strcpy( queue_show , "pikachuu" );
		strcpy( queue_show_1,"�s�J�`���E");
		break;
	case 1:
		strcpy( queue_show , "husigidane" );
		strcpy( queue_show_1,"�t�V�M�_�l");
		break;
	case 2:
		strcpy( queue_show , "zenigame" );
		strcpy( queue_show_1,"�[�j�K��");
		break;
	case 3:
		strcpy( queue_show , "hitokage" );
		strcpy( queue_show_1,"�q�g�J�Q");
		break;
	case 4:
		strcpy( queue_show , "husigibana" );
		strcpy( queue_show_1,"�t�V�M�o�i");
		break;
	case 5:
		strcpy( queue_show , "riza-donn" );
		strcpy( queue_show_1,"���U�[�h��");
		break;
	case 6:
		strcpy( queue_show , "kamekkusu" );
		strcpy( queue_show_1,"�J���b�N�X");
		break;
	case 7:
		strcpy( queue_show , "tikori-ta" );
		strcpy( queue_show_1,"�`�R���[�^");
		break;
	case 8:
		strcpy( queue_show , "hinoarasi" );
		strcpy( queue_show_1,"�q�m�A���V");
		break;
	case 9:
		strcpy( queue_show , "waninoko" );
		strcpy( queue_show_1,"���j�m�R");
		break;
	case 10:
		strcpy( queue_show , "meganiumu" );
		strcpy( queue_show_1,"���K�j�E��");
		break;
	case 11:
		strcpy( queue_show , "bakuhu-nn" );
		strcpy( queue_show_1,"�o�N�t�[��");
		break;
	case 12:
		strcpy( queue_show , "o-dairu" );
		strcpy( queue_show_1,"�I�[�_�C��");
		break;
	case 13:
		strcpy( queue_show , "kimori" );
		strcpy( queue_show_1,"�L����");
		break;
	case 14:
		strcpy( queue_show , "achamo" );
		strcpy( queue_show_1,"�A�`����");
		break;
	case 15:
		strcpy( queue_show , "mizugorou" );
		strcpy( queue_show_1,"�~�Y�S���E");
		break;
	case 16:
		strcpy( queue_show , "jukainn" );
		strcpy( queue_show_1,"�W���J�C��");
		break;
	case 17:
		strcpy( queue_show , "basha-mo" );
		strcpy( queue_show_1,"�o�V���[��");
		break;
	case 18:
		strcpy( queue_show , "ragura-zi" );
		strcpy( queue_show_1,"���O���[�W");
		break;
	case 19:
		strcpy( queue_show , "naetoru" );
		strcpy( queue_show_1,"�i�G�g��");
		break;
	case 20:
		strcpy( queue_show , "hikozaru" );
		strcpy( queue_show_1,"�q�R�U��");
		break;
	case 21:
		strcpy( queue_show , "pocchama" );
		strcpy( queue_show_1,"�|�b�`���}");
		break;
	case 22:
		strcpy( queue_show , "dodaitosu" );
		strcpy( queue_show_1,"�h�_�C�g�X");
		break;
	case 23:
		strcpy( queue_show , "goukazaru" );
		strcpy( queue_show_1,"�S�E�J�U��");
		break;
	case 24:
		strcpy( queue_show , "ennperuto" );
		strcpy( queue_show_1,"�G���y���g");
		break;
	case 25:
		strcpy( queue_show , "tuta-ja" );
		strcpy( queue_show_1,"�c�^�[�W��");
		break;
	case 26:
		strcpy( queue_show , "pokabu" );
		strcpy( queue_show_1,"�|�J�u");
		break;
	case 27:
		strcpy( queue_show , "mijumaru" );
		strcpy( queue_show_1,"�~�W���}��");
		break;
	case 28:
		strcpy( queue_show , "jaro-da" );
		strcpy( queue_show_1,"�W�����[�_");
		break;
	case 29:
		strcpy( queue_show , "ennbuo-" );
		strcpy( queue_show_1,"�G���u�I�[");
		break;
	case 30:
		strcpy( queue_show , "daikennki" );
		strcpy( queue_show_1,"�_�C�P���L");
		break;
	case 31:
		strcpy( queue_show , "harimaronn" );
		strcpy( queue_show_1,"�n���}����");
		break;
	case 32:
		strcpy( queue_show , "fokko" );
		strcpy( queue_show_1,"�t�H�b�R");
		break;
	case 33:
		strcpy( queue_show , "keromatu" );
		strcpy( queue_show_1,"�P���}�c");
		break;
	case 34:
		strcpy( queue_show , "burigaronn" );
		strcpy( queue_show_1,"�u���K����");
		break;
	case 35:
		strcpy( queue_show , "mafokusi-" );
		strcpy( queue_show_1,"�}�t�H�N�V�[");
		break;
	case 36:
		strcpy( queue_show , "gekkouga" );
		strcpy( queue_show_1,"�Q�b�R�E�K");
		break;

	
	}


}

void QuestionGenerate_2(void){//���p�̕����񐶐�

	int rnd = GetRand( 18 );//�����_���Ȕԍ��𐶐�(���̓��x���~10�Ƃ��Ă���)


	//�S�������X�C�b�`����@�B�����ǂ����@����ΕύX���Ă��ǂ�
	switch(rnd){
	case 0:
		strcpy( queue_show_2 , "hatanojunn" );
		strcpy( queue_show_3 , "�g����@��" );
		break;
	case 1:
		strcpy( queue_show_2 , "niwazirou" );
		strcpy( queue_show_3 , "�O�H�@���Y" );
		break;
	case 2:
		strcpy( queue_show_2 , "takasehirosi" );
		strcpy( queue_show_3 , "�����@�_�j" );
		break;
	case 3:
		strcpy( queue_show_2 , "shoudouzitutomu" );
		strcpy( queue_show_3 , "�������@��" );
		break;
	case 4:
		strcpy( queue_show_2 , "kannbayasiyasusi" );
		strcpy( queue_show_3 , "�_�с@��" );
		break;
	case 5:
		strcpy( queue_show_2 , "kumenohumihiro" );
		strcpy( queue_show_3 , "�H��@���m" );
		break;
	case 6:
		strcpy( queue_show_2 , "sinndouyosiaki" );
		strcpy( queue_show_3 , "�V���@�`��" );
		break;
	case 7:
		strcpy( queue_show_2 , "matudahirosi" );
		strcpy( queue_show_3 , "���c�@�m" );
		break;
	case 8:
		strcpy( queue_show_2 , "etoukaoru" );
		strcpy( queue_show_3 , "�]���@��" );
		break;
	case 9:
		strcpy( queue_show_2 , "hasiurahiroaki" );
		strcpy( queue_show_3 , "���Y�@�O��" );
		break;
	case 10:
		strcpy( queue_show_2 , "katumatamasasi" );
		strcpy( queue_show_3 , "���ԓc�@�m" );
		break;
	case 11:
		strcpy( queue_show_2 , "isikawatakasi" );
		strcpy( queue_show_3 , "�ΐ�@�F" );
		break;
	case 12:
		strcpy( queue_show_2 , "tuzimurayasuhiro" );
		strcpy( queue_show_3 , "�ґ��@�׊�" );
		break;
	case 13:
		strcpy( queue_show_2 , "kitakubosigeru" );
		strcpy( queue_show_3 , "�k�v�ہ@��" );
		break;
	case 14:
		strcpy( queue_show_2 , "katayamasigetomo" );
		strcpy( queue_show_3 , "�ЎR�@�ΗF" );
		break;
	case 15:
		strcpy( queue_show_2 , "yamatihidemi" );
		strcpy( queue_show_3 , "�R�n�@�G��" );
		break;
	case 16:
		strcpy( queue_show_2 , "isiharazirou" );
		strcpy( queue_show_3 , "�Ό��@���Y" );
		break;
	case 17:
		strcpy( queue_show_2 , "nakamurakazuhiro" );
		strcpy( queue_show_3 , "�����@�ꔎ" );
		break;
	case 18:
		strcpy( queue_show_2 , "oohasiyuutarou" );
		strcpy( queue_show_3 , "�勴�@�T���Y" );
		break;

	}


}

void CheckStrings_1(void){//�𓚂��������ǂ����ƁA���̐������K�v���ǂ����̂Q�̃`�F�b�N

	if(stateflag){//��萶������Ă���

		//������̔�r�ŏ펞�Ď�����B

		if( (strcmp( queue_ans , queue_show ) == 0) && ( Key[ KEY_INPUT_RETURN ] == 1 ) ){//�����񂪈�v���A�G���^�[�œ��͂�����
		//->�������͂��̏������s���B

			memset( queue_ans , '\0' , STR_MAX );//NULL�����Ń��Z�b�g
			memset( queue_show , '\0' , STR_MAX );
			memset( queue_show_1, '\0',STR_MAX );
			stateflag = false;
			push_num = 0;						//�����������������Z�b�g
		}


	}else{//��萶������Ă��Ȃ�
		//���x���ɉ�������萶�����s���B


		//�����Ƀ^�C�}�[�̍X�V���������Ă��悢
		QuestionGenerate();
		stateflag = true;//�Y�ꂸ�Ƀt���O�𗧂Ă�B
		ancer_count += 1;
	
	}




}


void CheckStrings_2(void){//�𓚂��������ǂ����ƁA���̐������K�v���ǂ����̂Q�̃`�F�b�N

	if(stateflag){//��萶������Ă���

		//������̔�r�ŏ펞�Ď�����B

		if( (strcmp( queue_ans , queue_show_2 ) == 0) && ( Key[ KEY_INPUT_RETURN ] == 1 ) ){//�����񂪈�v���A�G���^�[�œ��͂�����
		//->�������͂��̏������s���B

			memset( queue_ans , '\0' , STR_MAX );//NULL�����Ń��Z�b�g
			memset( queue_show_2 , '\0' , STR_MAX );
			memset( queue_show_3, '\0',STR_MAX );
			stateflag = false;
			push_num = 0;						//�����������������Z�b�g
		}


	}else{//��萶������Ă��Ȃ�
		//���x���ɉ�������萶�����s���B


		//�����Ƀ^�C�}�[�̍X�V���������Ă��悢
		QuestionGenerate_2();
		stateflag = true;//�Y�ꂸ�Ƀt���O�𗧂Ă�B
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
	//DrawString( 120 , 320 ,"����",Cr);
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
	tHandle = CreateFontToHandle( "MS����" , 64 , 10 );
	
}

void init_1(){
	t_1Handle = CreateFontToHandle("MS����" , 30 , 10 );
}

void init_2(){
	t_2Handle = CreateFontToHandle("MS�S�V�b�N" , 60 , 10);
}
void Start_1(){
	time_counter = 0;
	ancer_count = 0;
	memset( queue_ans , '\0' , STR_MAX );//NULL�����Ń��Z�b�g
	memset( queue_show , '\0' , STR_MAX );
	memset( queue_show_1, '\0',STR_MAX );
	stateflag = false;
	push_num = 0;		
	DrawStringToHandle( 300 , 240 , "Enter�L�[��",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 200 , 270 , "NORMAL�X�e�[�W�X�^�[�g�I�I",GetColor(255,255,255),t_1Handle);
	if(CheckHitKey(KEY_INPUT_RETURN) == 1){
		state_ += 2;
	}
}

void Start_2(){
	time_counter = 0;
	ancer_count = 0;
	memset( queue_ans , '\0' , STR_MAX );//NULL�����Ń��Z�b�g
	memset( queue_show , '\0' , STR_MAX );
	memset( queue_show_1, '\0',STR_MAX );
	stateflag = false;
	push_num = 0;	
	DrawStringToHandle( 300 , 240 , "Enter�L�[��",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 200 , 270 , "HARD�X�e�[�W�X�^�[�g�I�I",GetColor(255,255,255),t_1Handle);
	if(CheckHitKey(KEY_INPUT_RETURN) == 1){
		state_ += 2;
	}
}

void End_1(){

	FILE *fp;
	fp = fopen("Data.txt","wb");
	if( fp == NULL ){
		DrawStringToHandle( 0 , 0 , "�t�@�C�����J���̂Ɏ��s���܂���",GetColor(255,255,255),t_1Handle);
	}
	fwrite( &ancer_count, sizeof(int), 1, fp );
	fclose(fp);


	int MOUSEX,MOUSEY;
	GetMousePoint(&MOUSEX,&MOUSEY);

	DrawStringToHandle( 300 , 0 , "�����l�ł����B",GetColor(255,255,255),t_1Handle);
	DrawFormatStringToHandle( 50 , 50 ,GetColor(255,255,255),tHandle ,"����̉񓚐���%d�ł����B",ancer_count-1);
	DrawStringToHandle( 260 , 400 , "������x���܂����H",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 300 , 450 , "�͂�",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 430 , 450 , "������",GetColor(255,255,255),t_1Handle);
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

	DrawStringToHandle( 300 , 0 , "�����l�ł����B",GetColor(255,255,255),t_1Handle);
	DrawFormatStringToHandle( 50 , 50 ,GetColor(255,255,255),tHandle ,"����̉񓚐���%d�ł����B",ancer_count-1);
	DrawStringToHandle( 260 , 400 , "������x���܂����H",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 300 , 450 , "�͂�",GetColor(255,255,255),t_1Handle);
	DrawStringToHandle( 430 , 450 , "������",GetColor(255,255,255),t_1Handle);
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