# qt5模板库,工具类

## QString字符串

### 1操作字符串

#### 1.1.1连接/组合字符串

>- +
>- append()
>- sprintf()
>- arg()
>- ...

```c++
	QString str1 = "loveMiaoW";
    qDebug() << str1 << endl;
    QString str2;
    str2 = QString("%1 is bron %2.").arg("loveMiaoW").arg(2000);
    qDebug() << str2 << endl;
    QString str3;
    str3.sprintf("%s %s","we are","you");
    qDebug() << str3 << endl;
```

#### 1.1.2组合字符串

>- insert()
>- prepend()
>- replace()
>- trimmed()
>- simplified()

### 2查找字符串

>- startsWith()
>- endsWith()
>- contains()

### 3字符串转化

>- toInt():两个参数(bool,int) bool返回转换状态,转化基数
>- toAscii()
>- toLatin1()
>- toUth8()
>- toLocal8Bit()
>- QByteArray()

```c++
QString str = "loveMiaoW";
QByteArray ba = str.toAscii();		//toAscii() 有问题
qDebug() << ba;
ba.append("hello");
aDebug() << ba;
```

>NULL 和 empty的区别
>
>一个NULL 字符串使用默认构造函数`(const char*)0`作为参数的构造函数创建的对象
>
>一个空字符串是一个大小为0的字符串
>
>一个NULL 字符串一定是一个空字符,而一个空字符串不一定是NULL字符串

```c++
	qDebug() << QString().isNull();
    qDebug() << QString().isEmpty();
    qDebug() << QString("").isNull();
    qDebug() << QString("").isEmpty();
```

## 容器类

### 1QList类

>继承的子类
>
>QItemSelection，QQueue，QSignalSpy，QStringList，QTestEventList

```c++
 	QList<QString> list;
    {
        QString str("This is a test string");
        list << str;
    }
    qDebug() << list[0/1] <<"loveMiaoW";//index out of range
```

### 2QLinkedList类

### 3QVector类

>继承子类
>
>QPolygon，QPolygonF，QStack

```c++
//遍历QList/QLinkendList/QVector
//只读 QList<T>::const_iterator 
//读写 QLsit<T>::iterator
for(int i = 0;i < 10;i++)
    {
        list.insert(list.end(),i);
    }
    for(QList<int>::iterator i = list.begin();i != list.end();++i)
    {
        qDebug() << (*i);
    }
    for(QList<int>::const_iterator j = list.begin();j != list.end();++j)
    {
        qDebug() << (*j);
    }
```

### 4QMap QHash

### 5QVariant

>包含
>
>QColor，QBrush，QFont，QPen，QRect，QString，QSize

## 算法及正则表达式

### 1常用算法

>- qAbs 绝对值
>- qMax 两个数值最大值
>- qRound 四舍五入
>- qSwap 交换两个数
>- 

### 2正则表达式

>由表达式(expressions)，量词(quantifiers)，断言(assertions)

```c++
[AEIOU]	//匹配一个字符,字符是[]中任意一个
[^AEIOU]	//匹配一个字符不是[]中的字符,除去[]字符都能匹配
[a-z]	//匹配一个a-z的字符
x[1,2]	//x至少有一个，最多有两个
    
//
[A-Za-z]+[A-Za-z_0-9]*
//+至少出现一次,可以出现多次
//*可以出现零次或者多次
```

```c++
//量词
E? 匹配0次或者1次
E+ 匹配1次或者多次
E* 匹配0次或多次
E[n] 匹配n次
E[n,]至少匹配n次
E[,m]最多匹配m次
E[n,m]最少n次，最多m次
```

```c++
//断言
^ 在字符串开头匹配
$ 在字符串结尾匹配
\b 单词边界
\B 非单词边界
(?=E)表达式后紧随E才匹配
(?!E)表达式后不是E才匹配
    
//
using(?=E\s+namespace)
```

