// sonyCamera_Controller.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>


int main()
{
	SonyCamera cam;
	cam.active(0);

	cam.capture();
	Sleep(5000);		//連続で撮影する場合、待ち時間を入れる（シャッタースピード依存）
	cam.capture();

}
