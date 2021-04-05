# Cocos2d-x

## 介紹


## 0. 事前準備

### 準備工具

1. Python 2.x (2021年了還有人Python在用2.x)  
如果環境已經安裝了python 3.x會不給編譯，刪除重新安裝2.x的版本

2. CMake  
編譯環境的過程需要使用到

3. Visual Studio  
IDE我是使用地表最強編譯器，省得一些麻煩

4. Cocos2d-x 4.0安裝包  
官方載點https://www.cocos.com/cocos2dx


### 架設環境
1. 解壓縮Cocos2d-x 4.0  
安裝的時候此目錄相關資料夾會被寫進環境變數，所以挑個喜歡的目錄解壓縮  

2. 使用CMD進入其根目錄，並輸入指令python setup.py  
python沒有亂搞的話就會順利安裝完成  
當看到Please restart the terminal or restart computer to make added system variables take effect就是安裝成功了  

3. 建立cocos2d-x cpp專案  
安裝完成，py檔已經幫你把環境變數都建好，接著在CMD輸入  
cocos new Hello -l cpp -p com.helloworld -d \Users\%username%\Desktop <sup>[1]</sup>  

4. 編譯出sln檔  
建立好的專案沒有VS的檔案可以用，進到專案目錄的proj.win32資料夾  
在CMD裡面輸入cmake .. -A win32可以編譯出VS的專案檔sln  

### Hello World
進入專案後直接編譯完後會發生錯誤，會看到  
Unable to start program ‘X:\PATH_TO_TEST\proj.win32\Debug\ALL_BUILD’.  
原因是要要設定開始的program，把圖中該檔案右鍵點選set as startup project  
接著重新編譯一次就完成環境架設了，你會看到圖中的畫面  

cocos2d-x C++環境架設就是這麼難用  

### 備註
[1] 在CMD輸入cocos new -h可以看到cocos new參數詳細的用途, 寫得很詳細這邊就不多加補充

## 1. 輸出圖片
在前一章節編譯好環境了，但你會發現這個專案裡的資料夾與檔案怎麼這麼多  
我們只要先關注附圖上面中的AppDelegate與HelloWorldScene就行了  
此章節會說明這些檔案的用途，以及一個修改一些碼讓我們可以自己輸出一張圖片，以感受一下檔案之間的關係

## 2. Scene與Layer
## 3. 按鍵控制
## 4. 計時器
## 5. 動畫
## 6. 碰撞
