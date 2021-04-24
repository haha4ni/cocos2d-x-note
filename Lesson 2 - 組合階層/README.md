# 2.組合階層
這一章節我們來處理階層，先**了解基本階層的架構以及如何新增節點**  
篇幅關係我不會特別講解.h檔裡面定義了什麼，基本上一看就懂；特別逐字說明顯得有點冗長  
大家先載下我的Source Code，把檔案都加進`.\Classes`資料夾內並且覆蓋  

## 類別關係
Cocos2D-x的標準結構是由<font color=red>一位</font>導演(Director)來控制切換不同場景(Scene)，  
某個場景可以包含很多的圖層(Layer)，某個圖層裡會包含很多個精靈(Sprite)  

遊戲引擎會根據節點

![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%202%20-%20%E7%B5%84%E5%90%88%E9%9A%8E%E5%B1%A4/2-1.png?raw=true)**圖2-1**


但前一章節我們使用官方的Sample Code並把Sprite放進程式碼中，實際上的結構只寫到如**圖2-2**  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%202%20-%20%E7%B5%84%E5%90%88%E9%9A%8E%E5%B1%A4/2-2.png?raw=true)**圖2-2**

Sample Code並沒有Layer層，而Sprite放進了Scene層，  
雖然這樣寫也不會有什麼大問題，但往後遊戲規模一大，沒有好好的分配元件應有的位置很容易造成往後擴充功能困難  
因此我們要做一下改變，變成如**圖2-3**  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%202%20-%20%E7%B5%84%E5%90%88%E9%9A%8E%E5%B1%A4/2-3.png?raw=true)**圖2-3**


## 組合
我會從低至高依序把它組合起來，  

#### 精靈(Sprite) -> 圖層(Layer)
Sprite在上一步驟已經建出來了，但bool HelloWorld::init()函式往上追，你會發現是他在Scene類別底下  
因此要在Scene與Sprite之間新建一個繼承Layer的類別出來, 把原本在Scene的Sprite挪進Layer裡  
```C++
#ifndef __HELLOWORLD_LAYER_H__
#define __HELLOWORLD_LAYER_H__

#include "cocos2d.h"

class HahaWorldLayer : public cocos2d::Layer
{
public:
    bool init();

    CREATE_FUNC(HelloWorldLayer);
};

#endif // __HELLOWORLD_LAYER_H__
```

```C++
bool HelloWorldLayer::init()
{
    //取得視窗的大小
    Size visibleSize = Director::getInstance()->getVisibleSize();

    //加入一個Sprite物件
    Sprite* hero = Sprite::create("hero.png");
    hero->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    
    //加進Scene節點內
    this->addChild(hero, 0);

    return true;
}
```
建立一個名叫MyLayer的Layer類別，在初始化的時候建立Sprite並放入MyLayer的節點  

#### 圖層(Layer) -> 場景(Scene)
同樣的套路再來一次，把Layer放進Scene裡，
這邊我把類別名稱從HahaWorld改成了HahaWorldLayer
也順便把不必要的函式通通砍掉了，只留了init()與CREATE_FUNC()
把剛剛建的HahaWorldLayer塞進Scene的子節點裡
```C++
bool HelloWorldScene::init()
{
    Layer* layer = HahaWorldLayer::create();
    this->addChild(layer);

    return true;
}
```

#### 場景(Scene) -> 導演(Director)
導演這物件只有一個，範例碼已經幫我們開好了  
你可以到AppDelegate.cpp中的AppDelegate::applicationDidFinishLaunching()找到他  
director->runWithScene()設定導演正在導的場景  
Scene的名稱被我們修改過了，要改成HelloWorldScene::createScene()去替換原本範例碼的HelloWorld::createScene()  
```C++
//AppDelegate.cpp

    register_all_packages();

    // create a scene. it's an autorelease object
    auto scene = HelloWorldScene::create();

    // run
    director->runWithScene(scene);

    return true;
```

## 編譯結果
好！繞了一圈，跟上一章節編譯出一樣的畫面。  
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%202%20-%20%E7%B5%84%E5%90%88%E9%9A%8E%E5%B1%A4/2-4.png?raw=true)
