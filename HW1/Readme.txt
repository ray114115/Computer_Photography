姓名: 吳信鋐
學號: 607415065
E-mail: ray114115@gmail.com

作業環境: Windows 10 64bits
編譯器: Vistual Studio 2015 / glut-3.7.6 / fltk-1.3.4.2


---指定功能:

part A(20%):
繪製出如投影片第一頁圖片的主窗口，大小500 x 500。
圓形: 要有陰影效果
橢圓: 短軸是長軸的60%
正方形: 繪製多層正方形
三角形: 有顏色漸變效果

part B:
在子窗口繪製橢圓，並設計能改變子窗口背景顏色的選單。(10%)
在標題為"window 2"的視窗，繪製圓形與三角形，當視窗縮放，圖形會跟著縮放。(10%)
左鍵點擊主窗口時，在點擊位置繪製隨機顏色的圓形。(10%)

動畫部分(30%):
主視窗右鍵產生選單，控制停止或播放動畫，改變正方形顏色。
正方形: 逆時針旋轉
三角形: 順時針旋轉
圓形: 縮小放大

part C(20%):
以讀pixel的方式，將bmp圖檔繪製於另一視窗上。

---簡單敘述如何操作功能:

1.檢視功能:exe檔的資料夾內需含有glut32.dll
PartA 開法 : 找到 HW1_partA\Debug\glut32.exe
PartB 開法 : 找到 HW1_partB\Debug\HW1_partB.exe
PartC 開法 : 找到 HW1_partC\Debug\HW1_partC.exe

2.partA 
主窗口是 500 x 500
圓形: 有陰影效果
橢圓: 短軸是長軸的60%
正方形: 繪製多層正方形
三角形: 有顏色漸變效果

3.partB
* windows1 *
橢圓形小窗口處(白色部分)按下滑鼠右鍵可以選擇背景顏色(白/黑/紅/綠/藍)
持續旋轉的正方形窗口按下滑鼠右鍵可以有:停止動畫/播放動畫/改變正方形顏色(白/紅/綠)
正方形: 逆時針旋轉
* windows2 *
三角形: 順時針旋轉
圓形: 縮小放大
測量方式為:將windows2 使用滑鼠左鍵拖曳，即可看出圓形會跟著放大或縮小

4.partC
以讀pixel的方式，將bmp圖檔繪製於另一視窗上。


---額外Bonus操作功能:


partC <使用fltk+opengl>
1.創造兩個400*400的框，右框讀取pan.bmp
2.用一個change image的按鈕切換image，可選任何BMP檔
3.按下 Line/Circle/Rectangle 可以在左邊框內畫出相對應形狀
4.按鈕設計 : Draw/Line/Circle/Rectangle/Quit
5.拖拉式選擇的狀態 : 會跟按鈕連結，小黃點提示目前選到的按鈕
6.按下 Selection 可以拖曳畫出的形狀
7.按下Quit離開程式
8.錄製Demo Video : HW1_partB.mkv以及HW1_partC.mkv

