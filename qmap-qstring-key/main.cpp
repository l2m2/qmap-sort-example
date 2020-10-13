#include <QCoreApplication>
#include <QtCore>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, QString> map1;
    map1.insert(QString("2"), QString("value2"));
    map1.insert(QString("1"), QString("value1"));
    map1.insert(QString("11"), QString("value11"));
    map1.insert(QString("5"), QString("value5"));

    for (QMap<QString, QString>::const_iterator it = map1.constBegin(); it != map1.constEnd(); it++) {
        qDebug() << it.key() << it.value();
    }

    return a.exec();
}
