#pragma once

//Util 機能色々

//#define  GetColor(,,)
#define RED GetColor(255,000,000)
#define GREEN GetColor(000,255,00)
#define BLUE GetColor(000,000,255)
#define WHITE GetColor(255,255,255)
#define BLACK GetColor(000,000,000)


int Key[256];//全てのキー情報を格納する


int gpUpdateKey();


