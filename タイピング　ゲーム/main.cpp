
#include "DxLib.h"
#include "config.h"
#include "Sub.h"

//!==�A�h�o�C�X
//���C���ɂ̓V�X�e�����������āA���̕����ɒ����R�[�h���������ق������₷���B
//��{�͊֐��̂܂Ƃ܂�ɂ��āA���̊֐��Q��g�ݍ��킹�Ē����v���O���������B
//���x���g�������͊֐��ɂ��āA�Ȃ�ׂ��������̂������Ȃ��B

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){

		ChangeWindowMode(TRUE);	//window���[�h��L����
		SetGraphMode(WINDOW_X,WINDOW_Y,32);//��ʃT�C�Y�w��,�J���[�r�b�g�l�w��(16or32)
		//��SetGraphMode���g���ƁA�O���t�B�b�N�n���h���ƃt�H���g�n���h���������������̂Œ��ӁB
		DxLib_Init();

		SetDrawScreen( DX_SCREEN_BACK ); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
		init();
		init_1();
		init_2();
	while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)

		SubFunc();// -> Sub.cpp

	}

        DxLib_End(); // DX���C�u�����I������
        return 0;
}
  