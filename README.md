# sonyCamera_Controller
Sony camera controller for C++ using "Remote" App


Sonyが提供するPC用撮影アプリケーションをC++で操作して撮影を行うプログラムです。

SonyのカメラをC++で制御できるツールが見当たらなかったため作成しました。

動作環境：

- Visual Studio 2017
- Windows 10
- Sony α7SII


## 使い方

### 1. 下記ウェブサイトより「Imaging Edge (Remote/Viewer/Edit)」Windows版をダウンロード後、指示通りインストール。

https://imagingedge.sony.net/ja-jp/ie-desktop.html

### 2. "Remote"アプリを起動して使用するカメラとUSB（もしくはWifi）接続を行う。

カメラ接続方法：
https://support.d-imaging.sony.co.jp/app/imagingedge/ja/instruction/4_1_connection.php

### 3. プログラムを実行する。

実行中は撮影以外のPC作業は不可能。連続撮影を行う場合、設定から撮影ごとに"Viewer"が立ち上がるというオプションを外すと良い。
