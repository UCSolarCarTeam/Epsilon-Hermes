#include <QByteArray>
#include <gmock/gmock.h>

#include "CommunicationLayer/CommDeviceControl/I_MessageForwarder.h"

class MockMessageForwarder : public I_MessageForwarder
{
public:
    MOCK_METHOD1(forwardData, void(QByteArray));
    MOCK_METHOD1(forwardServerData, void(QByteArray));
};
