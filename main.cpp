#include "StringComp.hpp"
#include "Tester.hpp"

int main(int argc, char *argv[])
{
//    qInfo() << (chineseToNum(u8"十") == 10);
//    qInfo() << (chineseToNum(u8"三十") == 30);
//    qInfo() << (chineseToNum(u8"一百") == 100);
//    qInfo() << (chineseToNum(u8"三十九") == 39);
//    qInfo() << (chineseToNum(u8"四百八十万") == 4800000);
//    qInfo() << (chineseToNum(u8"九千一百") == 9100);
//    qInfo() << (chineseToNum(u8"九千") == 9000);
//    qInfo() << (chineseToNum(u8"一百零一") == 101);
//    qInfo() << (chineseToNum(u8"九百二十一") == 921);
//    qInfo() << (chineseToNum(u8"五十六万零一十") == 560010);
//    qInfo() << (chineseToNum(u8"一万亿零二千一百零一") == 1000000002101);
//    qInfo() << (chineseToNum(u8"一万亿二千一百万零一百零一") == 1000021000101);
//    qInfo() << (chineseToNum(u8"一万零二百三十亿四千万零七千八百九十") == 1023040007890);

    Tester tester;

//    tester.addData("zero1",
//                   QStringList{QString{"1"}, QString {"0"}},
//                   QStringList{QString{"0"}, QString{"1"}});
//    tester.addData("zero2",
//                   QStringList{QString{u8"1层"}, QString {u8"0层"}},
//                   QStringList{QString{u8"0层"}, QString{u8"1层"}});
//    tester.addData("zero3",
//                   QStringList{QString{u8"1层"}, QString {u8"基础层"}},
//                   QStringList{QString{u8"基础层"}, QString{u8"1层"}});
//    tester.addData("zero4",
//                   QStringList{QString{"1"}, QString {"0"}, QString{"2"}},
//                   QStringList{QString{"0"}, QString{"1"}, QString{"2"}});
//    tester.addData("zero5",
//                   QStringList{QString{u8"1层"}, QString {u8"0层"}, QString{u8"2层"}},
//                   QStringList{QString{u8"0层"}, QString{u8"1层"}, QString{u8"2层"}});
//    tester.addData("zero6",
//                   QStringList{QString{u8"1层"}, QString {u8"基础层"}, QString{u8"2层"}},
//                   QStringList{QString{u8"基础层"}, QString{u8"1层"}, QString{u8"2层"}});
//    tester.addData("zero7",
//                   QStringList{QString{"1"}, QString {"2"}, QString{"3"}, QString{"0"}, QString{"4"}},
//                   QStringList{QString{"0"}, QString {"1"}, QString{"2"}, QString{"3"}, QString{"4"}});

//    tester.addData("nagetive1",
//                   QStringList{QString{"1"}, QString {"0"}, QString {"-1"}, QString {"-2"}, QString {"-3"}},
//                   QStringList{QString {"0"}, QString{"-3"}, QString {"-2"}, QString {"-1"}, QString {"1"}});

//    tester.addData("nagetive2",
//                   QStringList{QString{"1"}, QString {"0"}, QString {u8"负一"}, QString {u8"负二"}, QString {u8"负三"}},
//                   QStringList{QString {"0"}, QString{u8"负三"}, QString {u8"负二"}, QString {u8"负一"}, QString {"1"}});

//    tester.addData("nagetive3",
//                   QStringList{QString{"1"}, QString {"0"}, QString {u8"地下一"}, QString {u8"地下二"}, QString {u8"地下三"}},
//                   QStringList{QString {"0"}, QString{u8"地下三"}, QString {u8"地下二"}, QString {u8"地下一"}, QString {"1"}});

//    tester.addData("postive1",
//                   QStringList{QString{"1"}, QString {"0"}, QString {u8"三楼"}, QString {u8"五楼"}, QString {u8"四层"}},
//                   QStringList{QString{"0"}, QString {"1"}, QString {u8"三楼"}, QString {u8"四层"}, QString {u8"五楼"}});

        tester.addData("zero5",
                       QStringList{QString{u8"1层"}, QString {u8"0层"}, QString{u8"2层"}, QString{u8"3层"}, QString{u8"1.4层"},QString{u8"2.5层"}},
                   QStringList{QString{u8"0层"}, QString {u8"1层"}, QString{u8"1.4层"}, QString{u8"2层"}, QString{u8"2.5层"},QString{u8"3层"}});
    tester.setProcessCallback([](const QStringList &origin)->QStringList{
        QStringList res = origin;
        qSort(res.begin(), res.end(), stringComp);
        return res;
    });
    tester.run();
    return 0;
}
