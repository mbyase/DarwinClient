#include "requestmessage.h"

#include <QString>
#include <QMapIterator>

QString RequestMessage::first_line() const
{
    return QString("%1 %2 %3\r\n")
            .arg(request_type, resource_type, _version);
}

QString RequestMessage::header() const
{
    QString header_string;
    for (auto iter = _header_map.cbegin();
         iter != _header_map.cend(); ++iter) {
        header_string +=QString("%1: %2\r\n")
                .arg(iter.key(), iter.value());
    }
    return header_string;
}


QMap<QString, QString> & RequestMessage::header_map()
{
    return _header_map;
}

QString & RequestMessage::version()
{
    return _version;
}

QByteArray & RequestMessage::data()
{
    return _data;
}

QByteArray RequestMessage::toByteArray() const
{
    return first_line().toLocal8Bit() + header().toLocal8Bit() + "\r\n" + _data;
}
