#pragma once
#include <windows.h>

class SonyCamera {
public:
	SonyCamera() {};
	~SonyCamera() {};

private:
	//�Q�l�Fhttp://7ujm.net/C++/Sendkey.html
	//���z�L�[�R�[�h���A�N�e�B�u�E�B���h�E�ɑ��M���邱�Ƃ��ł��܂�
	void SendKey(unsigned char code)
	{
		keybd_event(code, 0x00, KEYEVENTF_EXTENDEDKEY | 0, 0);
		keybd_event(code, 0x00, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	}

	//���z�L�[�R�[�h���������̏ꍇ
	void SendKey(unsigned char code1, unsigned char code2)
	{
		keybd_event(code1, 0x00, KEYEVENTF_EXTENDEDKEY | 0, 0);
		SendKey(code2);
		keybd_event(code2, 0x00, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	}
	//a����z�AA����Z�A0����9�A�X�y�[�X �ɂč쐬���ꂽ�������
	//���z�L�[�R�[�h�ɕϊ����ăA�N�e�B�u�E�B���h�E�ɑ��M���邱�Ƃ��ł��܂�
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

	//"Remote"�A�v�����A�N�e�B�u�E�B���h�E�ɂ���
	void active(int _cameraID) {
		HWND hCalc;
		if ((hCalc = FindWindow(NULL, L"Remote")) != NULL) {
			if (SetForegroundWindow(hCalc)) {
				// �A�v���P�[�V������`�̃��b�Z�[�W�� (WM_USER + X) �̌`�Œ�`
				PostMessage(hCalc, WM_USER + 0x0104, 0, 0);
			};
		}
	}

	//�Î~��B�e
	void capture() {
		//active(0);
		SendKey('1');
	}

	//����B�e�i�J�n���A�I�����Ƃ��Ɂj
	void movieCapture() {
		active(0);
		SendKey(VK_CONTROL, 'R');
	}

	//�V���b�^�[������
	void autoFocus() {
		active(0);
		SendKey('G');
	}

};



