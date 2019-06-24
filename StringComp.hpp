#pragma once
#include <QString>
#include <QRegularExpression>
static bool isZero(const QString &str)
{
    if (str == QStringLiteral("0") || str == QStringLiteral("0层") || str == QStringLiteral("基础层"))
    {
        return true;
    }
    return false;
}
static qint64 chineseToNum(const QString &chinese)
{
    static const QMap<QString, qint64> chineseChar {
        {u8"零", 0},
        {u8"一", 1},
        {u8"二", 2},
        {u8"三", 3},
        {u8"四", 4},
        {u8"五", 5},
        {u8"六", 6},
        {u8"七", 7},
        {u8"八", 8},
        {u8"九", 9},
        {u8"壹", 1},
        {u8"贰", 2},
        {u8"叁", 3},
        {u8"肆", 4},
        {u8"伍", 5},
        {u8"陆", 6},
        {u8"柒", 7},
        {u8"捌", 8},
        {u8"玖", 9},
        };
    static const QMap<QString, qint64> chineseUnit {
        {u8"拾", 10},
        {u8"佰", 100},
        {u8"仟", 1000},
        {u8"萬", 10000},
        {u8"十", 10},
        {u8"百", 100},
        {u8"千", 1000},
        {u8"万", 10000},
        {u8"亿", 100000000},
        };
    qint64 ans = 0;
    qint64 firstUnit = 1;
    qint64 secondUnit = 1;
    qint64 tempUnit = 1;
    QChar ch;
    if (chinese.length() == 0) {
        return 0;
    } else if (chinese.length() == 1) {
        ch = chinese.at(0);
        if (chineseUnit.contains(ch)) {
            return chineseUnit.value(ch);
        } else if (chineseChar.contains(ch)) {
            return chineseChar.value(ch);
        } else {
            return 0;
        }
    }
    for(int i = chinese.length() - 1; i > -1; --i) {
        ch = chinese.at(i);
        tempUnit = chineseUnit.contains(ch) ? chineseUnit.value(ch) : 1;
        if (tempUnit > firstUnit) {
            firstUnit = tempUnit;
            secondUnit = 1;
            continue;
        } else if (tempUnit > secondUnit) {
            secondUnit = tempUnit;
            continue;
        }
        ans += firstUnit * secondUnit * (chineseChar.contains(ch) ? chineseChar.value(ch) : -1);
    }
    return ans;
}
static qint64 getValueByGroup(const QRegularExpressionMatch &match)
{
    if (!match.captured(QStringLiteral("floorNum1")).isEmpty()) {
        match.captured(QStringLiteral("floorNum1")).toLongLong();
    } else if (!match.captured(QStringLiteral("floorNum2")).isEmpty()) {
        match.captured(QStringLiteral("floorNum2")).toLongLong();
    } else if (!match.captured(QStringLiteral("floorChinese1")).isEmpty()) {
        return chineseToNum(match.captured(QStringLiteral("floorChinese1")));
    } else if (!match.captured(QStringLiteral("floorChinese2")).isEmpty()) {
        return chineseToNum(match.captured(QStringLiteral("floorChinese2")));
    }
    return 0;
}
static qint64 getMatchValue(const QString &str, bool &ok) noexcept
{
    ok = false;
    do {
        const static QString chineseNum = u8"零一二三四五六七八九十百千万亿壹贰叁肆伍陆柒捌玖拾佰仟萬";
        const static QRegularExpression reg(QString(u8R"(负(?<floorNum1>\d+)|负(?<floorChinese1>[%1]+)|地下(?<floorNum2>\d+)|地下(?<floorChinese2>[%1]+))").arg(chineseNum));

        auto match = reg.match(str);
        if (!match.hasMatch()) {
            break; //break means goto next compare
        }
        ok = true;
        return -getValueByGroup(match);
    } while(false);

    do {
        const static QString chineseNum = u8"零一二三四五六七八九十百千万亿壹贰叁肆伍陆柒捌玖拾佰仟萬";
        const static QRegularExpression reg(QString(u8R"((?<floorChinese>[%1]+))").arg(chineseNum));
        auto match = reg.match(str);
        if (!match.hasMatch()) {
            break;  //break means goto next compare
        }
        ok = true;
        return chineseToNum(match.captured(QStringLiteral("floorChinese")));
    } while(false);
    do {
        const static QRegularExpression reg(R"(-?\d+)");
        auto match = reg.match(str);
        if (!match.hasMatch()) {
            break;  //break means goto next compare
        }
        ok = true;
        return match.captured(0).toLongLong();
    } while(false);
    return 0;
}
static bool stringComp(const QString &str1, const QString &str2) noexcept
{
    if (isZero(str1))
    {
        return true;
    } else if (isZero(str2)) {
        return false;
    }
    qint64 value1, value2;
    bool ok;
    value1 = getMatchValue(str1, ok);
    if (!ok) {
        return false;
    }
    value2 = getMatchValue(str2, ok);
    if (!ok) {
        return false;
    }
    return value1 < value2;
}
