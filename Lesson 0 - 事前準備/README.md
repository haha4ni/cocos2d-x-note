# 環境架設

## 準備工具

1. Python 2.x (2021年了還有人Python在用2.x)  
如果環境已經安裝了python 3.x會不給編譯，刪除重新安裝2.x的版本

2. CMake  
編譯環境的過程需要使用到

3. Visual Studio  
IDE我是使用地表最強編譯器，省得一些麻煩

4. Cocos2d-x 4.0安裝包  
官方載點https://www.cocos.com/cocos2dx


## 架設環境
1. **解壓縮Cocos2d-x 4.0**  
安裝的時候此根目錄相關資料夾會被寫進環境變數，所以解壓縮後的資料夾請放在你想安裝的位置  

2. **使用CMD進入其根目錄，並輸入指令python setup.py**  
記得要安裝的是python2.x的版本，
python沒有亂搞的話，當看到   
Please restart the terminal or restart computer to make added system variables take effect就是安裝成功了  

3. **建立cocos2d-x cpp專案**  
安裝完成，py檔已經幫你把環境變數都建好，接著在CMD輸入  
`cocos new HelloWorld -l cpp -p com.helloworld -d C:\Users\%username%\Desktop` <sup>[1]</sup>  
這邊我預設的輸出路徑為桌面，完成後在桌面可以看到Haha的資料夾  

4. **編譯出sln檔**  
建立好的文件沒有VS可以用的檔案，先進到專案目錄的proj.win32資料夾  
在CMD裡面輸入`cmake .. -A win32`可以編譯出VS的專案檔；sln檔  

5. **進入專案並編譯後會發生錯誤**，會看到  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%200%20-%20%E4%BA%8B%E5%89%8D%E6%BA%96%E5%82%99/0-1.png?raw=true)  
Unable to start program ‘X:\PATH_TO_TEST\proj.win32\Debug\ALL_BUILD’.  
原因是要設定欲編譯的program，選擇HelloWorld專案右鍵點選set as startup project  
接著重新編譯一次就正式完成環境架設了  

## 編譯結果
以上步驟都有成功完成後的執行結果  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%200%20-%20%E4%BA%8B%E5%89%8D%E6%BA%96%E5%82%99/0-3.png?raw=true)  
