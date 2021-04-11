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









## 1. 框架建構
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

### 類別關係
看到這段Code會三個很陌生的類別，分別是Director、Scene以及Sprite
在往下推進前，我們要先搞懂此引擎的最基本類別關係





雖然很想直接開始寫程式，但寫之前還是有些東西必須要先知道
至少你要知道你要從哪個點開始寫，就好像C語言要從main()開始一樣，Cocos2d-x只是更複雜了一點點點
### 入口
你會看到我們前一步新建的專案裡頭有AppDelegate以及HelloWorldScene包含標頭檔等共四個文件
遊戲引擎的入口就寫在AppDelegate.cpp文件中
```
//遊戲入口
bool AppDelegate::applicationDidFinishLaunching() {
    // 初始化 director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("Hello", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("Hello");
#endif
        director->setOpenGLView(glview);
    }

    // 顯示顯示FPS數
    director->setDisplayStats(true);

    // 設定FPS 如果不呼叫這個函式 默認刷新率就是60FPS
    director->setAnimationInterval(1.0f / 60);

    // 設定解析度
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();

    // 創建名為HahaWorld的scene
    auto scene = HahaWorld::createScene();
    //執行此scene
    director->runWithScene(scene);

    return true;
}

```
由此程式碼你可以很清楚看到入口函式取得了一個Director class 並用此物件設定了FPS、解析度等定義
最後再創造了一個scene物件，並run他


### 結構
此引擎的結構是由一個導演(Director)來控制切換不同場景(Scene)，某個場景可以包含很多的圖層(Layer)，某個圖層裡會包含很多個角色Sprite


看到這段Code會開始想Director跟Scene是什麼鬼東西  
在開始製作前，我們要先搞懂此引擎的最基本結構關係，不然無法前進  
把遊戲想像成有個導演(Director)在作畫，作畫要把圖層(Scene、Layer、Sprite)職責分配明確 後續處理才會輕鬆  
整個框架會長得像如附圖這樣 從下到上介紹回去


#### Sprite


#### Layer


#### Scene
一個遊戲可以由多個Scene組成，他可以是主畫面選單、遊戲畫面、遊戲結束之類大方向的類型
由Director去切換要使用哪一個Scene

#### Director
負責整個遊戲運鏡，可以知道一個遊戲只有一個Director，負責控制遊戲幀數、解析度等等相關設定

















此章節會說明這些檔案的用途，以及一個修改一些碼讓我們可以自己輸出一張圖片，以感受一下檔案之間的關係











### 代碼

此章節會說明這些檔案的用途，以及一個修改一些碼讓我們可以自己輸出一張圖片，以感受一下檔案之間的關係
我們只要先關注附圖上面中的AppDelegate與HelloWorldScene就行了

## 2. Scene與Layer
## 3. 按鍵控制
## 4. 計時器
## 5. 動畫
## 6. 碰撞

