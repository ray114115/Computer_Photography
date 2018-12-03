姓名: 吳信鋐
學號: 607415065
E-mail: ray114115@gmail.com

作業環境: Windows 10 64bits
編譯器: Vistual Studio 2010 / glut-3.7.6 / fltk-1.3.4.2


---指定功能:

1. Load Image(10%): 能夠讀入A, A', B三張影像，並顯示在螢幕上。
2. image analogies algorithm(90%): 實作該論文演算法來產生B'影像，並顯示在螢幕上。

---簡單敘述如何操作功能:

有三個按鈕結合file_chooser用來讀入A、A'、B，並用Run按鈕跑出B'

原論文在填補B'時，會先搜尋A、A'圖中近似B、B'的Feature位置，再計算Best Match的像素值，中間用ANN、Gaussian pyramid輔助尋找適合的像素值，也有給出Best Match的算法

我的程式在B'中，可以很明顯看到A、A'圖的輪廓，這是因為原論文在填補像素時，會用Gaussian pyramid結合approximate-nearest-neighbor search去尋找Best Match的像素值，但ANN的部分我沒有實現，所以要填補的像素值就比較難找，我就直接用B的該位置去作相對應的近似改變。

我的程式大致完成了3.4節的Luminance remapping，在亮度的部分作到類比的功能，可以把A、A'圖一樣用bird，B圖用blur，可以看到B'圖明顯變亮。

如果要實作這篇論文，我認為比較好的方法是要去找ANN的code，在這邊套用，但評分標準特別要求我們自己實作，又強調"抄襲一率0分"，所以我就沒有去找。
我想了解的是，這篇論文的code在網路上可以直接下載，如果有人直接下載code後改圖片路徑交出來，助教會怎麼給分數呢？


---額外Bonus操作功能:

1.作demo影片
2.作GUI介面，可直接改變A、A'、B的圖