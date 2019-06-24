- [ChineseStringComp](#ChineseStringComp)
  - [联系方式](#%E8%81%94%E7%B3%BB%E6%96%B9%E5%BC%8F)
  - [赞助](#%E8%B5%9E%E5%8A%A9)

# ChineseStringComp

中文数字转阿拉伯数字算法，C++/Qt实现。

测试用例如下：

```C++
    qInfo() << (chineseToNum(u8"十") == 10);
    qInfo() << (chineseToNum(u8"三十") == 30);
    qInfo() << (chineseToNum(u8"一百") == 100);
    qInfo() << (chineseToNum(u8"三十九") == 39);
    qInfo() << (chineseToNum(u8"四百八十万") == 4800000);
    qInfo() << (chineseToNum(u8"九千一百") == 9100);
    qInfo() << (chineseToNum(u8"九千") == 9000);
    qInfo() << (chineseToNum(u8"一百零一") == 101);
    qInfo() << (chineseToNum(u8"九百二十一") == 921);
    qInfo() << (chineseToNum(u8"五十六万零一十") == 560010);
    qInfo() << (chineseToNum(u8"一万亿零二千一百零一") == 1000000002101);
    qInfo() << (chineseToNum(u8"一万亿二千一百万零一百零一") == 1000021000101);
    qInfo() << (chineseToNum(u8"一万零二百三十亿四千万零七千八百九十") == 1023040007890);
```

(代码还附带正则表达式提取中文数字的案例)

## 联系方式

***

| 作者 | 涛哥                           |
| ---- | -------------------------------- |
|开发理念 | 弘扬鲁班文化，传承工匠精神 |
| 博客 | https://jaredtao.github.io/ |
|知乎专栏| https://zhuanlan.zhihu.com/TaoQt |
|微信公众号| Qt进阶之路 |
| 邮箱 | jared2020@163.com                |
| 微信 | xsd2410421                       |
| QQ、TIM | 759378563                      |

***

QQ(TIM)、微信二维码

<img src="https://github.com/jaredtao/jaredtao.github.io/blob/master/img/qq_connect.jpg?raw=true" width="30%" height="30%" /><img src="https://github.com/jaredtao/jaredtao.github.io/blob/master/img/weixin_connect.jpg?raw=true" width="30%" height="30%" />


****** 请放心联系我，乐于提供咨询服务，也可洽谈有偿技术支持相关事宜。

***
## 赞助
<img src="https://github.com/jaredtao/jaredtao.github.io/blob/master/img/weixin.jpg?raw=true" width="30%" height="30%" /><img src="https://github.com/jaredtao/jaredtao.github.io/blob/master/img/zhifubao.jpg?raw=true" width="30%" height="30%" />

****** 觉得分享的内容还不错, 就请作者喝杯奶茶吧~~
***

