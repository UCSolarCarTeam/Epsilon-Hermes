#pragma once

#include <QByteArray>

namespace MessageDecodingHelpers
{
float getFloat(const QByteArray& data, int startIndex);
unsigned short getUnsignedShort(const QByteArray& data, int startIndex);
unsigned char getUnsignedChar(const QByteArray& data, int startIndex);
unsigned int getUnsignedInt(const QByteArray& data, int startIndex);
}
