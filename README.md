# Cocos2d-x 4.0

## 介紹
在學這個引擎的時候前期很痛苦，
在網路上中文的教學零零散散，常常講的東一塊西一塊，也沒付上完整的代碼
初學者會很容易迷失方向，不知道那些碼到底要複製到哪邊才能正確RUN出來

本教學不會著墨太多底層的細節，主要是想讓大家快速、有系統的完成一款遊戲
有了基本知識再去google會變得簡單很多

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

5. 進入專案並編譯後會發生錯誤，會看到  
Unable to start program ‘X:\PATH_TO_TEST\proj.win32\Debug\ALL_BUILD’.  
原因是要要設定開始的program，把圖中該檔案右鍵點選set as startup project  
接著重新編譯一次就正式完成環境架設了  

### Hello World
你會看到圖中的畫面  


cocos2d-x C++環境架設就是這麼難用  

### 備註
[1] 在CMD輸入cocos new -h可以看到cocos new參數詳細的用途, 寫得很詳細這邊就不多加補充  









## 1.加入角色
上一章節我們單純執行官方寫好的Hello World 這一章節要加入一個角色進去我們的遊戲裡，並把整個環境整頓好  

###加入角色
在專案主目錄中的.\Resources是預設的資源讀取路徑 Visual Studio如何管理資源路徑這邊就不提了  
先把我們要加入的角上塞進資料夾裡
接著去找bool HelloWorld::init()這個函式把裡面的內容移除並加入一個sprite進去  
```
bool HelloWorld::init()
{
    // 確認有無初始化過Scene
    if ( !Scene::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Sprite* hero = Sprite::create("hero.png");
    hero->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(hero, 0);
}
```
執行後的結果如附圖

## 2.組合階層
這一章節我們來處理階層，讓大家了解一下基本階層的架構以及如何新增節點  
### 類別關係
Cocos2D-x的標準結構是由一個導演(Director)來控制切換不同場景(Scene)，某個場景可以包含很多的圖層(Layer)，某個圖層裡會包含很多個精靈(Sprite)  

![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%202%20-/2-1.png?raw=true)


但前一章節我們使用官方的Sample Code並把Sprite放進程式碼中，實際上的結構只寫到如圖2-2  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%202%20-/2-2.png?raw=true)

Sample Code並沒有Layer層，而Sprite放進了Scene層，  
雖然這樣寫也不會有什麼大問題，但往後遊戲規模一大，沒有好好的分配元件應有的位置很容易造成往後擴充功能困難  
因此我們要做一下改變，變成如圖2-3  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%202%20-/2-3.png?raw=true)


### 組合
我會從低至高依序把它組合起來
HelloWorldScene.cpp與HelloWorldScene.h檔案已經用不到了，我把他從專案內移除  
##### 精靈(Sprite) -> 圖層(Layer)
Sprite在上一步驟已經建出來了，但bool HelloWorld::init()函式往上追，你會發現是他在Scene類別底下  
因此要新建一個父類別為Layer的類別出來, 把Sprite加進Layer裡  
```C++
//File:LayerMgt.cpp

bool MyLayer::init()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Sprite* hero = Sprite::create("hero.png");
    hero->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(hero, 0);

    return true;
}
```
建立一個名叫MyLayer的Layer類別，在初始化的時候建立Sprite並放入MyLayer的節點  

##### 圖層(Layer) -> 場景(Scene)
同樣的套路再來一次，把圖層放進場景
```C++
//SceneMgt.cpp

bool MyScene::init()
{
    Layer* layer = MyLayer::createLayer();
    this->addChild(layer);

    return true;
}
```

##### 場景(Scene) -> 導演(Director)
導演這物件只有一個，範例碼已經幫我們開好了  
你可以到AppDelegate.cpp中的AppDelegate::applicationDidFinishLaunching()找到他  
director->runWithScene()設定導演正在導的場景  
把我們寫的MyScene建立出來去替換原本範例碼的MyScene::createScene()  
```C++
//AppDelegate.cpp

    register_all_packages();

    // create a scene. it's an autorelease object
    auto scene = MyScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
```

### 編譯結果
好！繞了一圈，跟上一章節編譯出一樣的畫面。

## 3. 按鍵控制
## 4. 計時器
## 5. 動畫
## 6. 碰撞


