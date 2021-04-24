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
![image](https://github.com/haha4ni/cocos2d-x-note/blob/master/Lesson%201%20-%20%E5%8A%A0%E5%85%A5%E8%A7%92%E8%89%B2/1-1.png?raw=true)
