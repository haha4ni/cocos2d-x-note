# Cocos2d-x 4.0


## 版本注意
Cocos2d-x在3.14版之後的Sample Code有著不小的差異，普遍在網路查到的都是3.14版本之前  
而本教學使用的版本為4.0版，並且為PC版的教學，使用在行動裝置可能會有些取誤差  

## 前言
在學這個引擎的時候前期很痛苦，在網路上中文的教學零零散散，  
也不一定會付上完整的代碼，不知道那些碼到底要複製到哪邊才能正確RUN出來，初學者會很容易迷失方向  
希望看完本文章可以讓你快入上手，有了基本知識再去google會變得簡單很多  

建議大家從頭開始慢慢看，每章節算是有點小連貫，跳著看可能會看不懂  
慢慢來比較快。  


# 基礎篇
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

### 編譯結果
以上步驟都有成功完成後的執行結果  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%200%20-%20%E4%BA%8B%E5%89%8D%E6%BA%96%E5%82%99/0-3.png?raw=true)


cocos2d-x C++架環境就是這麼難搞  

### 備註
[1] 在CMD輸入cocos new -h可以看到cocos new參數詳細的用途, 寫得很詳細這邊就不多加補充  









## 1. 顯示圖片
上一章節我們單純執行官方寫好的Hello World 這一章節要加入一個角色進去我們的遊戲裡  

### 圖片路徑
在專案主目錄中的.\Resources是預設的資源讀取路徑，Visual Studio如何設定資源路徑這邊就不提了  
先把我們的庸者塞進資料夾裡  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%201%20-%20%E5%8A%A0%E5%85%A5%E8%A7%92%E8%89%B2/hero.png?raw=true)

### 加入精靈(Sprite)
Sprite字面的意思為精靈，通常在2D遊戲中指的是角色或者地圖的元件等等的圖像，也有人直接稱這些圖像檔案叫精靈圖  
而一個Sprite物件可以理解成是一張圖片的載體，  

找到HelloWorld::init()這個函式，暫且把這個函式當作程式入口，遊戲啟動時這個函式會被執行一次
把裡面的內容移除並加入一個Sprite  
```C+++
bool HelloWorld::init()
{
    // 確認有無初始化過Scene
    if ( !Scene::init() )
        return false;
    
    //取得視窗的大小
    Size visibleSize = Director::getInstance()->getVisibleSize();

    //加入一個Sprite物件
    Sprite* hero = Sprite::create("hero.png");
    hero->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    
    //加進Scene節點內
    this->addChild(hero, 0);
}
```

要把圖片畫到視窗上，需指定一塊畫布(Scene/Layer)，
你先了解到我們目前所在的函式，其物件就是一個Scene，我們把圖片加進它的節點裡

### 編譯結果
//TO DO





### 編譯結果

## 2.組合階層
這一章節我們來處理階層，先了解一下基本階層的架構以及如何新增節點  .
篇幅關係我不會特別講解.h檔裡面定義了什麼，基本上一看就懂；特別逐字說明顯得有點冗長  
大家先載下我的Source Code，把檔案都加進`.\Classes`資料夾內並且覆蓋  

### 類別關係
Cocos2D-x的標準結構是由<font color=red>一位</font>導演(Director)來控制切換不同場景(Scene)，  
某個場景可以包含很多的圖層(Layer)，某個圖層裡會包含很多個精靈(Sprite)  

![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%202%20-%20%E7%B5%84%E5%90%88%E9%9A%8E%E5%B1%A4/2-1.png?raw=true)**圖2-1**


但前一章節我們使用官方的Sample Code並把Sprite放進程式碼中，實際上的結構只寫到如**圖2-2**  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%202%20-%20%E7%B5%84%E5%90%88%E9%9A%8E%E5%B1%A4/2-2.png?raw=true)**圖2-2**

Sample Code並沒有Layer層，而Sprite放進了Scene層，  
雖然這樣寫也不會有什麼大問題，但往後遊戲規模一大，沒有好好的分配元件應有的位置很容易造成往後擴充功能困難  
因此我們要做一下改變，變成如**圖2-3**  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%202%20-%20%E7%B5%84%E5%90%88%E9%9A%8E%E5%B1%A4/2-3.png?raw=true)**圖2-3**


### 組合
我會從低至高依序把它組合起來，  

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


## 2. 鍵盤輸入
我們常常會通過鍵盤去做一些遊戲內的控制，本章節將會透過鍵盤讓我們的傭者可以在不同位置上出現  

### 鍵盤動作
鍵盤事件分別有按下與放開兩個觸發點，我們先寫好  
```C++
void MyScene::pressKey(EventKeyboard::KeyCode keycode, Event* event)
{
    switch (keycode)
    {
    case EventKeyboard::KeyCode::KEY_ESCAPE:
        Director::getInstance()->end();
        break;
    default:
        log("Key with keycode %d pressed", keycode);
        break;
    }
}

void MyScene::releaseKey(EventKeyboard::KeyCode keycode, Event* event)
{
    switch (keycode)
    {
    default:
        log("Key with keycode %d pressed", keycode);
        break;
    }
}
```
### 監聽鍵盤事件
我們需要建立鍵盤監聽所觸發的函式以及把監聽者註冊進事件管理器中  
```C++
    auto* keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(MyScene::pressKey, this);
    keyListener->onKeyReleased = CC_CALLBACK_2(MyScene::releaseKey, this);
    auto* dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
```
## 4. 計時器
## 5. 動畫
## 6. 碰撞

## 7. 物理世界

# 實戰篇
## 1. 建構主角


