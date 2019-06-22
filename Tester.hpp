#pragma once

#include "ColorLog.hpp"
#include <QDebug>
#include <QString>
#include <QList>

#include <functional>
#include <chrono>
template <class T>
bool isSameList(const QList<T> &list1, const QList<T> &list2)
{
    if (list1.size() != list2.size())
    {
        return false;
    }
    for (int i = 0; i < list1.size(); ++i)
    {
        if (list1.at(i) != list2.at(i))
        {
            return false;
        }
    }
    return true;
}

class Tester {
public:
    using ProcessCallback = std::function<QStringList(const QStringList &origin)>;
    void addData(const QString &tag, const QStringList &origin, const QStringList &expect)
    {
        m_datas[tag] = QPair<QStringList, QStringList>(origin, expect);
    }
    void setProcessCallback(const ProcessCallback &callBack)
    {
        m_callback = callBack;
    }
    void run()
    {
        int count = 0;
        for (auto tag: m_datas.uniqueKeys())
        {
            auto pair = m_datas.value(tag);
            auto startPoint = std::chrono::high_resolution_clock::now();
            auto res = m_callback(pair.first);
            auto endPoint = std::chrono::high_resolution_clock::now();
            auto cost = std::chrono::duration_cast<std::chrono::milliseconds>(endPoint- startPoint).count();
            if (isSameList(res, pair.second)) {
                qInfo() << logCommands[enumToInt(LogType::FrontGreen)] << tag << "pass" << logCommands[0] << "cost time" << cost << "ms";
                count++;
            } else {
                qInfo() << logCommands[enumToInt(LogType::FrontRed)] << tag << "failed" << logCommands[0] << "cost time" << cost << "ms";
            }
        }
        qInfo() << logCommands[enumToInt(LogType::FrontGreen)] << "total:" << m_datas.size() << "pass:" << count << logCommands[0];
    }
private:
    QMap<QString , QPair<QStringList, QStringList>> m_datas;
    ProcessCallback m_callback;
};
