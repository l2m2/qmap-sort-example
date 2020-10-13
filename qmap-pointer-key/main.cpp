#include <QCoreApplication>
#include <QtCore>

struct Person {
    quint8 age;
    QString name;
};

inline QDebug operator<< (QDebug d, const Person *model) {
    d << "Name: " << model->name << ",Age: " << model->age;
    return d;
}

template<> inline bool qMapLessThanKey<Person *>(Person * const & key1, Person * const & key2)
{
    return key1->age < key2->age;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<Person *, QString> map1;
    map1.insert(new Person{34, "Leon"}, QString("leon"));
    map1.insert(new Person{24, "Jim"}, QString("jim"));
    map1.insert(new Person{45, "Lin Tao"}, QString("lintao"));
    map1.insert(new Person{28, "Han meimei"}, QString("hanmeimei"));

    for (QMap<Person *, QString>::const_iterator it = map1.constBegin(); it != map1.constEnd(); it++) {
        qDebug() << it.key() << it.value();
    }

    return a.exec();
}
