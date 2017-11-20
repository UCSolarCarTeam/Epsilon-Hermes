#include "MessageDecodingHelpers.h"

#include <QDebug>
#include <QDataStream>

namespace
{
    const int UNION_SIZE = 4;

    enum Type { FLOAT = 1, UNSIGNED_SHORT = 2, UNSIGNED_CHAR = 3, UNSIGNED_INT = 4 };

    int numberOfBytesInData(Type type)
    {
        switch (type)
        {
            case FLOAT:
                return sizeof(float);
                break;

            case UNSIGNED_SHORT:
                return sizeof(unsigned short);
                break;

            case UNSIGNED_CHAR:
                return sizeof(unsigned char);
                break;

            case UNSIGNED_INT:
                return sizeof(unsigned int);
                break;

            default:
                qCritical() << "MessageDecodingHelpers: Invalid type";
                return -1;
        }
    }
}

float MessageDecodingHelpers::getFloat(const QByteArray& data, int startIndex)
{
    return data.mid(startIndex, numberOfBytesInData(Type::FLOAT)).toFloat();
}

unsigned short MessageDecodingHelpers::getUnsignedShort(const QByteArray& data, int startIndex)
{
    return data.mid(startIndex, numberOfBytesInData(Type::UNSIGNED_SHORT)).toUShort();
}

unsigned char MessageDecodingHelpers::getUnsignedChar(const QByteArray& data, int startIndex)
{
    return static_cast<unsigned char>(data.at(startIndex));
}

unsigned int MessageDecodingHelpers::getUnsignedInt(const QByteArray& data, int startIndex)
{
    return data.mid(startIndex, numberOfBytesInData(Type::UNSIGNED_INT)).toUInt();
}


