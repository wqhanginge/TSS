## **目录**  
- - -
+ <font size=3>**[名词解释](#名词解释)**</font>
    + **[Game Mode](#game-mode)**
    + **[Game State](#game-state)**
    + **[Map Unit](#map-unit)**
    + **[Map Unit Index/X/Y](#map-unit-indexxy)**
    + **[Map Unit State (MUState)](#map-unit-state-mustate)**
    + **[Neighbors](#neighbors)**
    + **[Question Mark](#question-mark)**
    + **[Width, Height, Size, Mines](#width-height-size-mines)**
+ <font size=3>**[数据结构](#数据结构)**</font>
    + **[GameInfo](#gameinfo)**
    + **[GameScore](#gamescore)**
    + **[map_unit](#map_unit)**
    + **[Neighbor](#neighbor)**
+ <font size=3>**[参数宏](#参数宏)**</font>
    + **[GETMUMINES](#getmumines)**
    + **[GETMUSTATE](#getmustate)**
    + **[ISCRUSH](#iscrush)**
    + **[ISGAMESET](#isgameset)**
    + **[MAX_SIZE](#max_size)**
    + **[MUISMINE](#muismine)**
    + **[MUISUPDATE](#muisupdate)**
    + **[REMMUUPDATE](#remmuupdate)**
    + **[SETMUMINES](#setmumines)**
    + **[SETMUSTATE](#setmustate)**
    + **[SETMUUPDATE](#setmuupdate)**
+ <font size=3>**[函数](#函数)**</font>
    + **[clickUnit](#clickunit)**
    + **[createGameMap](#creategamemap)**
    + **[digNeighbors](#digneighbors)**
    + **[gameSet](#gameset)**
    + **[gameStart](#gamestart)**
    + **[getNeighbors](#getneighbors)**
    + **[getpRecordName](#getprecordname)**
    + **[getRecordTime](#getrecordtime)**
    + **[index2x, index2y](#index2x-index2y)**
    + **[isGameSuccessful](#isgamesuccessful)**
    + **[openBlanks](#openblanks)**
    + **[resetGame](#resetgame)**
    + **[resetRecord](#resetrecord)**
    + **[setGameMode](#setgamemode)**
    + **[setGameState](#setgamestate)**
    + **[setGameTime](#setgametime)**
    + **[setMark](#setmark)**
    + **[setRecordTime](#setrecordtime)**
    + **[stepGameTime](#stepgametime)**
    + **[uncovAllMines](#uncovallmines)**
    + **[xy2index](#xy2index)**
- - -
- - -


## **名词解释**  
- - -

### ***Game Mode***  
游戏模式；定义游戏的地图大小和地雷数量，可能的值如下  
|值|解释|
|:--|:--|
|JUNIOR<br>0    |初级<br>9 x 9，10地雷总数|
|MIDDLE<br>1    |中级<br>16 x 16，40地雷|
|SENIOR<br>2    |高级<br>30 x 16，99地雷|
|CUSTOM<br>3    |自定义<br>范围由`MAX_WIDTH`，`MAX_HEIGHT`等宏规定，此处不再列出|
|CRUSH<br>4     |未知/已损坏<br>非有效模式，表示相关参数存在错误或游戏数据处于不可用状态，亦用作判断边界|
- - -

### ***Game State***  
游戏状态；定义游戏当前状态，可能的值如下  
|值|解释|
|:--|:--|
|INIT<br>0      |初始化<br>准备好开始一局新游戏|
|PROGRESS<br>1  |进行中|
|SUCCESS<br>2   |游戏获胜|
|FAIL<br>3      |游戏失败|
|UNKONW<br>4    |未知<br>非正常游戏状态，仅用作判断边界|
- - -

### ***Map Unit***  
地图单元/地图格；扫雷地图上的一格  
- - -

### ***Map Unit Index/X/Y***  
地图格的下标值/x坐标值/y坐标值；用于定位一个地图格  
游戏地图中的格有两种表示方法，一种是将地图看作开始于左上角的一维数组，下标从左到右、从上到下，范围从`0`到`Size - 1`；另一种是使用坐标定位法，左上角为坐标原点，x轴为列增长，y轴为行增长；具体如下图所示：  
```C++
       x
      ----->
       0   1   2   3
     +---+---+---+---+
 y| 0| 0 | 1 | 2 | 3 |    eg: index = 2  <==>  (x, y) = (2, 0)
  |  +---+---+---+---+
  v 1| 4 |...index...|
     +---+---+---+---+
```  
- - -

### ***Map Unit State (MUState)***  
地图格的状态；可能的状态如下  
|值|解释|
|:--|:--|
|MUS_COVER<br>0x00  |地图格未打开|
|MUS_FLAG<br>0x10   |该格被标记为地雷|
|MUS_MARK<br>0x20   |该格被标记为问号|
|MUS_UNCOV<br>0x30  |地图格已打开|
|MUS_BOMB<br>0x40   |该格中的地雷被引爆|
|MUS_WRONG<br>0x50  |该格被错误标记为地雷|
- - -

### ***Neighbors***  
邻居；地图上某一格的周围的八格  
- - -

### ***Question Mark***  
问号标记；指使用问号去标记地图上的某一格  
游戏默认使用红旗标记可能的地雷所在的格，被标记后该格不能被打开；若启用问号标记，则可以额外使用问号标记一格，被标记的格依然可以被打开；当不确定某一格是否是地雷时可使用问号标记辅助推理  
- - -

### ***Width, Height, Size, Mines***  
与游戏地图相关的名称，详细解释如下  
|名称|解释|
|:--|:--|
|Width  |游戏地图的宽度，指每行的格数|
|Height |游戏地图的高度，指每列的格数|
|Size   |游戏地图的大小，指总格数|
|Mines  |游戏地图的地雷数，指地图中含有的地雷总数|
- - -
- - -


## **数据结构**  
- - -

### **GameInfo**  
封装游戏进行必须的各项信息  

#### **原型**  
```C++
struct GameInfo {
    byte    mode;
    byte    state;
    bool    mark;
    byte    width;
    byte    height;
    word    size;
    word    mines;
    short   mine_remains;
    word    uncov_units;
    word    time;
    byte    map[MAX_SIZE];
};
```  

#### **成员**  
`mode`  
游戏模式，可能的取值参看[Game Mode](#game-mode)小节  

`state`  
游戏状态，可能的取值参看[Game State](#game-state)小节  

`mark`  
是否启用问号标记，`true`则启用，`false`则禁用  
关于问号标记参看[Question Mark](#question-mark)小节  

`width, height, size`  
地图宽度、高度、大小  

`mines`  
地图中含有地雷的总数  

`mine_remains`  
当前地图中还未被标记的地雷总数  

`uncov_units`  
当前地图中已被打开的地图单元数  

`time`  
当前游戏进行的时间  

`map`  
游戏地图数据，为地图单元的数组  
地图空间为提前分配量，由`MAX_SIZE`定义，特定游戏过程中仅有前`size`个地图单元的空间有效，注意访问越界问题

#### **备注**  
这里不提供直接读取`GameInfo`成员信息的函数，可以直接访问成员变量读取信息  
强烈建议使用提供的修改函数对`GameInfo`的信息进行修改，而不是直接修改成员变量，以免造成数据不一致，导致游戏出现不可预测行为  
- - -

### **GameScore**  
定义与游戏纪录相关的信息  

#### **原型**  
```C++
struct GameScore {
    word    junior_time;
    word    middle_time;
    word    senior_time;
    TCHAR   junior_name[SCORE_NAME_LEN];
    TCHAR   middle_name[SCORE_NAME_LEN];
    TCHAR   senior_name[SCORE_NAME_LEN];
};
```  

#### **成员**  
`junior_time, middle_time, senior_time`  
初级、中级、高级的最佳时间纪录  

`junior_name, middle_name, senior_name`  
初级、中级、高级的玩家名称纪录，注意字符串访问越界问题  

#### **备注**  
建议使用提供的读写函数对`GameScore`的信息进行读写，也可以直接读写成员变量  
- - -

### **map_unit**  
定义一个地图单元存储的信息和格式  

#### **原型**  
```C++
byte map_unit;

 7 6 5 4 3 2 1 0
+-+-+-+-+-+-+-+-+
|U|  S  |   M   |
+-+-+-+-+-+-+-+-+
    map_unit
```  

#### **成员**  
`U`  
更新位，标记该地图单元是否需要更新/重绘，为`1`则需要更新， 为`0`则不需要更新  

`S`  
记录该地图单位当前的状态，可能的值参看[Map Unit State](#map-unit-state-mustate)小节  

`M`  
记录该地图单元的邻居中含有的地雷总数，若该地图单元本身是地雷则值为`MUM_MINE`  

#### **备注**  
建议使用提供的读写函数/宏对地图单元数据进行读写，以免造成数据错误，导致游戏出现不可预测行为  
- - -

### **Neighbor**  
存储某地图单元及其所有邻居的下标  

#### **原型**  
```C++
typedef int Neighbor[9];

 order in 2D:
 +---+---+---+
 | 1 | 2 | 3 |           transform to arrary:
 +---+---+---+      +---+---+---+---+---+---+---+---+---+
 | 4 | 0 | 5 | ---> | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
 +---+---+---+      +---+---+---+---+---+---+---+---+---+
 | 6 | 7 | 8 |                     Neighbor
 +---+---+---+
```  

#### **成员**  
无  

#### **备注**  
地图单元自身的下标位于数组`0`位置，若某邻居不存在，则其下标为`-1`  
- - -
- - -


## **参数宏**  
- - -

### **GETMUMINES**  
获取地图单元中记录的地雷数  

#### **宏原型**
```C++
byte GETMUMINES(unit);
```  

#### **参数**  
`unit`  
指定的地图单元  

#### **返回值**  
给定地图单元记录的地雷数  
若该地图单元是地雷，则返回值为`MUM_MINE`；若该地图单元不是地雷，则返回值为其周围八个邻居中的地雷总数，不包括自己  

#### **备注**  
游戏状态为`INIT`或`UNKNOW`时，游戏地图为无效，此时宏的返回值是无意义的  
- - -

### **GETMUSTATE**  
获取地图单元的状态  

#### **宏原型**
```C++
byte GETMUSTATE(unit);
```  

#### **参数**  
`unit`  
指定的地图单元  

#### **返回值**  
给定地图单元的状态  
可能的返回值参看[Map Unit State](#map-unit-state-mustate)小节  

#### **备注**  
游戏状态为`INIT`或`UNKNOW`时，游戏地图为无效，此时宏的返回值是无意义的  
- - -

### **ISCRUSH**  
判断游戏模式是否非法  

#### **宏原型**
```C++
bool ISCRUSH(Mode);
```  

#### **参数**  
`Mode`  
待判断的游戏模式  

#### **返回值**  
若`Mode`不在`[JUNIOR, MIDDLE, SENIOR, CUSTOM]`之内则返回`true`，否则返回`false`  
- - -

### **ISGAMESET**  
判断游戏状态是否非法  

#### **宏原型**
```C++
bool ISGAMESET(State);
```  

#### **参数**  
`State`  
待判断的游戏状态  

#### **返回值**  
若`State`既不是`INIT`也不是`PROGRESS`则返回`true`，否则返回`false`  
- - -

### **MAX_SIZE**  
计算指定地图大小下允许的最大地雷个数  

#### **宏原型**
```C++
word MAX_SIZE(Size);
```  

#### **参数**  
`Size`  
游戏地图的大小，即地图总格子数  
对于 w x h 的地图则`Size = w * h`  

#### **返回值**  
地雷个数  

#### **备注**  
参数`Size`被作为无符号短整型处理，若传入更宽的数据类型则可能会被截断  
- - -

### **MUISMINE**  
判断地图单元是否是地雷  

#### **宏原型**
```C++
bool MUISMINE(unit);
```  

#### **参数**  
`unit`  
指定的地图单元  

#### **返回值**  
若该地图格是地雷则返回`true`，否则返回`false`  

#### **备注**  
游戏状态为`INIT`或`UNKNOW`时，游戏地图为无效，此时宏的返回值是无意义的  
- - -

### **MUISUPDATE**  
判断地图单元是否需要更新/重绘  

#### **宏原型**
```C++
bool MUISUPDATE(unit);
```  

#### **参数**  
`unit`  
指定的地图单元  

#### **返回值**  
若该地图格需要更新（即设置了更新/重绘标志）则返回`true`，否则返回`false`  
- - -

### **REMMUUPDATE**  
移除地图单元的更新/重绘标志  

#### **宏原型**
```C++
void REMMUUPDATE(unit);
```  

#### **参数**  
`unit`  
指定的地图单元  

#### **返回值**  
无  
- - -

### **SETMUMINES**  
修改地图单元中记录的地雷数  

#### **宏原型**
```C++
void SETMUMINES(m, unit);
```  

#### **参数**  
`m`  
将要设置的新地雷数  

`unit`  
指定的地图单元  

#### **返回值**  
无  

#### **备注**  
参数`m`将被强制转化为单个字节处理，若传入更宽的数据类型则可能会被截断  
此宏不检查参数的合理性，请确保传入参数的合理，否则程序可能出现未知行为  
- - -

### **SETMUSTATE**  
修改地图单元的状态  

#### **宏原型**
```C++
void SETMUSTATE(S, unit);
```  

#### **参数**  
`S`  
将要设置的新状态  
可选的参数值参看[Map Unit State](#map-unit-state-mustate)小节  

`unit`  
指定的地图单元  

#### **返回值**  
无  

#### **备注**  
此宏不检查参数的合理性，请确保传入参数的合理，否则程序可能出现未知行为  
- - -

### **SETMUUPDATE**  
将地图单元标记为需要更新/重绘  

#### **宏原型**
```C++
void SETMUUPDATE(unit);
```  

#### **参数**  
`unit`  
指定的地图单元  

#### **返回值**  
无  
- - -
- - -


## **函数**  
- - -

### **clickUnit**  
打开指定的地图单元  

#### **函数原型**  
```C++
int clickUnit(int x, int y);
int clickUnit(int index);
```  

#### **参数**  
`x, y`  
指定地图单元的 x-o-y 坐标值  

`index`  
指定地图单元的下标值  

#### **返回值**  
返回该地图单元邻居中包含的地雷总数，若指定的地图单元是地雷则返回`-1`，若指定的地图单元无法被打开则返回`-2`  

#### **备注**  
函数在返回前会将该地图单元的更新标记置位，关于更新标记参看[map_unit](#map_unit)结构  
关于地图单元的表示参看[Map Unit Index/X/Y](#map-unit-indexxy)小节  
- - -

### **createGameMap**  
生成一张新的游戏地图  

#### **函数原型**  
```C++
int createGameMap(int x, int y);
int createGameMap(int index);
```  

#### **参数**  
`x, y`  
指定的开始位置的地图单元的 x-o-y 坐标值  

`index`  
指定的开始位置的地图单元的下标值  

#### **返回值**  
正常则返回`0`，若调用时游戏状态不是`INIT`则返回`-1`  

#### **备注**  
新地图在指定的开始位置及其邻居处不会生成地雷，即保留一个“安全区”，其余地图区域的地雷为随机生成  
函数在返回前会置位所有地图单元的更新标记，关于更新标记参看[map_unit](#map_unit)结构  
关于开始位置的表示参看[Map Unit Index/X/Y](#map-unit-indexxy)小节  
- - -

### **digNeighbors**  
打开指定地图单元没有红旗标记的所有邻居，该地图单元必须已经打开，且其邻居内包含的地雷数等于其邻居被标记为地雷的个数  

#### **函数原型**  
```C++
int digNeighbors(int x, int y);
int digNeighbors(int index);
```  

#### **参数**  
`x, y`  
指定地图单元的 x-o-y 坐标值  

`index`  
指定地图单元的下标值  

#### **返回值**  
正常返回`0`，若打开过程中遇到地雷则返回`-1`，若出错则返回`-2`  

#### **备注**  
问号标记不被认为是地雷标记，有问号标记的地图单元将被当作一般地图单元打开  
函数会在返回前置位所有相关地图单元的更新标记，关于更新标记参看[map_unit](#map_unit)结构  
关于地图单元的表示参看[Map Unit Index/X/Y](#map-unit-indexxy)小节  
- - -

### **gameSet**  
结束一场游戏  

#### **函数原型**  
```C++
int gameSet();
```  

#### **参数**  
无  

#### **返回值**  
若游戏获胜且打破纪录则返回`1`，否则返回`0`  

#### **备注**  
此函数封装了结束游戏时的基本过程，包括【判断胜负--显示所有地雷--判断纪录】，游戏状态由`PROGRESS`-->`SUCCESS/FAIL`  
函数会在返回前置位相关地图单元的更新标记，关于更新标记参看[map_unit](#map_unit)结构  
- - -

### **gameStart**  
从指定的地图单元处开始一场新游戏  

#### **函数原型**  
```C++
int gameStart(int x, int y);
int gameSrart(int index);
```  

#### **参数**  
`x, y`  
指定地图单元的 x-o-y 坐标值  

`index`  
指定地图单元的下标值  

#### **返回值**  
正常则返回`0`，若游戏获胜则返回`1`，若遇到地雷则返回`-1`，若出错则返回`-2`  

#### **备注**  
此函数封装了从初始状态开始一局新游戏的基本过程，包括【选择位置--生成地图--更新游戏状态--打开指定位置--打开空白单元--判断游戏胜负】，游戏状态由`INIT`-->`PROGRESS`  
函数会在返回前置位所有地图单元的更新标记，关于更新标记参看[map_unit](#map_unit)结构  
关于地图单元的表示参看[Map Unit Index/X/Y](#map-unit-indexxy)小节  
- - -

### **getNeighbors**  
获取给定地图单元的所有邻居  

#### **函数原型**  
```C++
int getNeighbors(Neighbor& neighbor, int x, int y);
int getNeighbors(Neighbor& neighbor, int index);
```  

#### **参数**  
`neighbor`  
用于存储给定地图单元和其所有邻居的下标，详细参看[Neighbor](#neighbor)结构，此函数获取的数据将存储在此变量中  

`x, y`  
给定地图单元的 x-o-y 坐标值  

`index`  
给定地图单元的下标值  

#### **返回值**  
正常返回`0`，若给定地图单元不存在则返回`-1`  

#### **备注**  
当函数返回非零值时，不能保证`neighbor`中的数据是有意义的  
关于地图单元的表示参看[Map Unit Index/X/Y](#map-unit-indexxy)小节  
- - -

### **getpRecordName**  
获取指向指定游戏模式下纪录的玩家名称的指针  

#### **函数原型**  
```C++
TCHAR* getpRecordName(byte gamemode);
```  

#### **参数**  
`gamemode`  
指定的游戏模式  
可能的参数值参看[Game Mode](#game-mode)小节  

#### **返回值**  
该模式下纪录的玩家名称的指针，若出错则返回`nullptr`  

#### **备注**  
该函数获取的是字符串空间的起始指针，该字符串空间大小由`SCORE_NAME_LEN`指定，读写时注意访问越界问题  
- - -

### **getRecordTime**  
获取指定游戏模式下的纪录时间  

#### **函数原型**  
```C++
dword getRecordTime(byte gamemode);
```  

#### **参数**  
`gamemode`  
指定的游戏模式  
可能的参数值参看[Game Mode](#game-mode)小节  

#### **返回值**  
该模式下的纪录时间，若出错则返回`(dword)-1`  
- - -

### **index2x, index2y**  
将下标表示的地图单元转换为 x-o-y 表示  

#### **函数原型**  
```C++
int index2x(int index);
int index2y(int index);
```  

#### **参数**  
`index`  
地图单元的下标，从`0`开始  

#### **返回值**  
地图单元的 x 值或 y 值，从`0`开始  

#### **备注**  
此函数不检查参数合法性，请确保使用时传入合适的参数  
关于地图单元的表示参看[Map Unit Index/X/Y](#map-unit-indexxy)小节  
- - -

### **isGameSuccessful**  
判断游戏是否获胜  

#### **函数原型**  
```C++
bool isGameSuccessful();
```  

#### **参数**  
无  

#### **返回值**  
游戏获胜则返回`true`，否则返回`false`  

#### **备注**  
游戏状态为`PROGRESS`时函数的返回值才有意义，函数返回`false`时并不代表游戏失败  
- - -

### **openBlanks**  
打开指定地图单元的所有邻居，该地图单元必须已经打开，且其邻居内不包含地雷  

#### **函数原型**  
```C++
int openBlanks(int x, int y);
int openBlanks(int index);
```  

#### **参数**  
`x, y`  
指定地图单元的 x-o-y 坐标值  

`index`  
指定地图单元的下标值  

#### **返回值**  
正常返回`0`，出错则返回`-1`  

#### **备注**  
若邻居的邻居也不包含地雷，则此函数将递归调用自身并打开所有符合条件的地图单元  
函数会在返回前置位所有相关地图单元的更新标记，关于更新标记参看[map_unit](#map_unit)结构  
关于地图单元的表示参看[Map Unit Index/X/Y](#map-unit-indexxy)小节  
- - -

### **resetGame**  
重置游戏到初始状态并清空地图  

#### **函数原型**  
```C++
void resetGame();
```  

#### **参数**  
无

#### **返回值**  
无
- - -

### **resetRecord**  
重置游戏纪录  

#### **函数原型**  
```C++
void resetRecord();
```  

#### **参数**  
无  

#### **返回值**  
无  
- - -

### **setGameMode**  
使用给定的参数设定游戏模式  

#### **函数原型**  
```C++
void setGameMode(byte mode, byte width = 0, byte height = 0, word mines = 0);
```  

#### **参数**  
`mode`  
指定的游戏模式  
可选的游戏模式参看[Game Mode](#game-mode)小节  

`width`  
指定的地图宽度，若选择了标准游戏模式（非`CUSTOM`）则此参数被忽略  

`height`  
指定的地图高度，若选择了标准游戏模式（非`CUSTOM`）则此参数被忽略  

`mines`  
指定的地雷总数，若选择了标准游戏模式（非`CUSTOM`）则此参数被忽略  

#### **返回值**  
无  

#### **备注**  
若参数`mode`指定了标准游戏模式，即`[JUNIOR, MIDDLE, SENIOR]`之一，则其他三个参数都将被忽略  
若参数`mode`指定了非正常的游戏模式，则函数默认将游戏模式设为`JUNIOR`  
函数执行后会将游戏状态重置为`INIT`并清空游戏地图  
- - -

### **setGameState**  
将游戏状态设为给定的状态  

#### **函数原型**  
```C++
int setGameState(byte state);
```  

#### **参数**  
`state`  
指定的游戏状态  
可选的参数值参看[Game State](#game-state)小节  

#### **返回值**  
若正常则返回`0`，若指定了非正常的游戏状态则返回`-1`  
- - -

### **setGameTime**  
将游戏时间设为给定值  

#### **函数原型**  
```C++
int setGameTime(word time);
```  

#### **参数**  
`time`  
给定的游戏时间  

#### **返回值**  
若正常则返回`0`，若指定的时间大于`MAX_TIME`则返回`-1`  
- - -

### **setMark**  
设定是否启用问号标记  

#### **函数原型**  
```C++
void setMark(bool enable);
```  

#### **参数**  
`enable`  
是否启用问号标记，`true`为启用，`false`为禁用  

#### **返回值**  
无  

#### **备注**  
关于问号标记参看[Question Mark](#question-mark)小节  
- - -

### **setRecordTime**  
设置指定游戏模式下的纪录时间为指定时间  

#### **函数原型**  
```C++
int setRecordTime(byte gamemode, word besttime);
```  

#### **参数**  
`gamemode`  
指定的游戏模式  
可能的参数值参看[Game Mode](#game-mode)小节  

`besttime`  
指定的时间  

#### **返回值**  
正常则返回`0`，出错则返回`-1`  
- - -

### **stepGameTime**  
令游戏时间进行一次自增  

#### **函数原型**  
```C++
void stepGameTime();
```  

#### **参数**  
无  

#### **返回值**  
无  
- - -

### **uncovAllMines**  
游戏失败时显示所有地雷的正确位置，或游戏获胜时标记剩余未标记的地雷  

#### **函数原型**  
```C++
void uncovAllMines();
```  

#### **参数**  
无  

#### **返回值**  
无  

#### **备注**  
函数会在返回前置位所有相关地图单元的更新标记，关于更新标记参看[map_unit](#map_unit)结构  
- - -

### **xy2index**  
将 x-o-y 表示的地图单元转换为下标表示  

#### **函数原型**  
```C++
int xy2index(int x, int y);
```  

#### **参数**  
`x`  
地图单元的 x 坐标值，原点为左上角，从`0`开始  

`y`  
地图单元的 y 坐标值，原点为左上角，从`0`开始  

#### **返回值**  
地图单元的下标值，从`0`开始  

#### **备注**  
此函数不检查参数合法性，请确保使用时传入合适的参数  
关于地图单元的表示参看[Map Unit Index/X/Y](#map-unit-indexxy)小节  
- - -
- - -
