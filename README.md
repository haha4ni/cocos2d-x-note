# Cocos2d-x

## 介紹


## 事前準備

### 準備工具

1. Python 2.x (2021年了還有人Python在用2.x)  
如果環境已經安裝了python 3.x會不給編譯，刪除重新安裝2.x的版本

2. CMake  

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
cocos new Hello -l cpp -p com.helloworld -d \Users\%username%\Desktop  

4. 編譯出sln檔  
建立好的專案沒有VS的檔案可以用，進到專案目錄的proj.win32資料夾  
在CMD裡面輸入cmake .. -A win32可以編譯出VS的專案檔sln  

5. 專案編譯  
進入專案後直接編譯完後會發生錯誤，會看到  
Unable to start program ‘X:\PATH_TO_TEST\proj.win32\Debug\ALL_BUILD’.  
原因是要要設定開始的program，把圖中該檔案右鍵點選set as startup project  
接著重新編譯一次就完成環境架設了，你會看到圖中的畫面  

cocos2d-x C++環境架設就是這麼難用  
