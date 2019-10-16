#pragma once
#include <windows.h>

class SonyCamera {
public:
	SonyCamera() {};
	~SonyCamera() {};

private:
	//参考：http://7ujm.net/C++/Sendkey.html
	//仮想キーコードをアクティブウィンドウに送信することができます
	void SendKey(unsigned char code)
	{
		keybd_event(code, 0x00, KEYEVENTF_EXTENDEDKEY | 0, 0);
		keybd_event(code, 0x00, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	}

	//仮想キーコード同時押しの場合
	void SendKey(unsigned char code1, unsigned char code2)
	{
		keybd_event(code1, 0x00, KEYEVENTF_EXTENDEDKEY | 0, 0);
		SendKey(code2);
		keybd_event(code2, 0x00, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	}
	//aからz、AからZ、0から9、スペース にて作成された文字列を
	//仮想キーコードに変換してアクティブウィンドウに送信することができます
	void SendStr(char*str) {
		while (*str) {
			if ('a' <= *str && 'z' >= *str) {
				SendKey(*str - 32);
			}
			else {
				SendKey(*str);
			}
			str++;
		}
	}

public:

	//"Remote"アプリをアクティブウィンドウにする
	void active(int _cameraID) {
		HWND hCalc;
		if ((hCalc = FindWindow(NULL, L"Remote")) != NULL) {
			if (SetForegroundWindow(hCalc)) {
				// アプリケーション定義のメッセージを (WM_USER + X) の形で定義
				PostMessage(hCalc, WM_USER + 0x0104, 0, 0);
			};
		}
	}

	//静止画撮影
	void capture() {
		//active(0);
		SendKey('1');
	}

	//動画撮影（開始時、終了時ともに）
	void movieCapture() {
		active(0);
		SendKey(VK_CONTROL, 'R');
	}

	//シャッター半押し
	void autoFocus() {
		active(0);
		SendKey('G');
	}

};



