姓名: 吳信鋐
學號: 607415065
E-mail: ray114115@gmail.com

作業環境: Windows 10 64bits
編譯器: Vistual Studio 2015 / glut-3.7.6 / fltk-1.3.4.2


---指定功能:

part A(25%):
用OpenGL建出3D火車場景。
其中至少包含: 一個車身，一個駕駛艙，六個輪子，一個漏斗狀煙囪，鐵軌與平均分散的枕木，鐵軌終點有三個方塊堆疊的障礙物。

part B(49%，每項7%):
能夠用鍵盤觸發對應功能:
1. 鍵盤 '空白鍵' - 切換火車前進後退，輪胎必須相應滾動。(當火車正在前進，按下空白鍵後，則切換為後退，反之亦然。)
2. 鍵盤 'esc' - 結束程式。
3. 鍵盤 'o' - 切換為鳥瞰視角。
4. 鍵盤 'p' - 切換為駕駛艙第一人稱視角。
以下為鳥瞰視角時才有的功能:
5. 鍵盤 'w', 'a', 's', 'd' - 經由球面座標移動鳥瞰視角，'w' 與's' 調整elevation，'a' 與'd' 調整azimuth。
6. 鍵盤 'z' - zoom in，拉近相機與座標原點距離。
7. 鍵盤 'x' - zoom out，拉遠相機與座標原點距離。

part C(26%):
載入黃色小鴨的模型到場景中。(8%)
創建point light於場景中，並使光打在火車與小鴨上有明暗之分(給予法向量)。(8%)
提供選單能改變光源顏色(白、紅、綠、藍)。(10%)

---簡單敘述如何操作功能:

1.開啟檔案 : HW3\Debug\HW3.exe
2.火車移動時，按下'空白鍵'會切換狀態(前進變後退、後退變前進)
3.'Esc'與'Quit'皆為關閉程式
4.'x'和'z'拉遠與相機與座標原點距離
5.'w', 'a', 's', 'd' 移動相機的位置 (按兩下't'是xyz座標系統，預設是球型座標系統，按一下't'是第一人稱(鴨子)視角)
6.'o','p' 切換視角
7.滑鼠拖曳可看到'8'顆輪子
8.小鴨在車頭上
9.設計按鈕(白、紅、綠、藍)改變光源顏色


操作方式：
	w、a、s、d：改變視角位置
	z：zoom in
	x：zoom out
	o：切換為鳥瞰視角
	p：切換為駕駛艙第一人稱視角
	t：按順序切換視角
	m：使火車移動/靜止
	空白鍵：切換火車前進後退
	ESC：關閉程式
	滑鼠拖曳轉動視角

	P.S.按2下t到xyz座標系統後，wasd移動視角方式與球型座標系統移動視角方式不同
	


---額外Bonus操作功能:

1.用三條線顯示世界座標的x,y,z軸
2.顯示目前選到的開關狀態
3.增加quit開關
4.按鍵 'm' 讓火車移動/靜止
5.多一個turn off light 開關
6.按鍵 't' 改變視角，共有3個視角，分別為球型座標、鴨子視角(鎖定)、xyz座標
7.在xyz座標時，一樣可以用wsad改變視角位置，移動視角方式跟球型座標移動方式不同
8.在球型座標時，可以用滑鼠左鍵按著拖曳改變相機位置
9.demo影片 (demo.mp4)
10.更改SMFLoader.cpp，論壇上附的原檔allocate記憶體後沒有free，所以程式執行太久會當掉自動關閉，我更改後沒有這個問題