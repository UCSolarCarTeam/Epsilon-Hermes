#include "DebugHandler.h"
#include "../ConnectionService/I_ConnectionService.h"
#include "../DataParser/I_DataParser.h"
#include "../DataPopulator/DataPopulator.h"

DebugHandler::DebugHandler(I_ConnectionService& connectionService, I_DataParser& dataParser, QString filename)
: logTxtFile_(filename)
, logCsvFile_(filename)
, connectionService_(connectionService)
, dataParser_(dataParser)
{
    /********************Connections********************/
    connect(&connectionService, SIGNAL(sendDebugMessage(QString)),
            this, SLOT (receivedConnectionService(QString)));
    //RAW String
    connect(&dataParser, SIGNAL(sendDebugMessage(QString)),
            this, SLOT (receivedDebugDataParser(QString)));                 //notes, RAW string ends with a \n
    //PARSED values
    connect(&dataParser, SIGNAL(dataReceived(int,double)),
            this, SLOT (receivedParsedDataParser(int, double)));

    /********************File Initializing********************/
    QDateTime date = QDateTime::currentDateTime();
    QString DebugFilePath("DebugLogs/"); //can only create ONE NEW folder.
    if(!QDir(DebugFilePath).exists())
        QDir().mkdir(DebugFilePath);


    filename.prepend(date.toString("yyyy.MM.dd_hh.mm.ss")); //following Canadian Standard 'ISO 8601'
    filename.prepend(DebugFilePath);

    /*Log Csv File*/
    logCsvFile_.setFileName(filename + ".csv");
    if(logCsvFile_.open(QIODevice::WriteOnly | QIODevice::Text))    //optional text can go be initialized here
    {

    }


    /*Log Text File*/
    logTxtFile_.setFileName(filename + ".txt");
    if(logTxtFile_.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream writer(&logTxtFile_);
        writer << "|======================";
        writer << date.toString("ddd MMM d yyyy");
        writer << "======================|" << endl;
        writer <<  "                     SOLARCAR  DEBUG  LOG" << endl;
        writer << "|===========================================================|" << endl;
    }
    /*
    storeCsv2DArray(5,5);
    storeCsv2DArray(5,5);
    storeCsv2DArray(5,5);
    storeCsv2DArray(5,5);
    storeCsv2DArray(22,22);
    storeCsv2DArray(24,24);
    storeCsv2DArray(24,24);
    storeCsv2DArray(25,25);
    storeCsv2DArray(25,25);
    storeCsv2DArray(25,25);
    int temp = (csv2DArray_[5][0]);
    printf("csv2DArray_[0].at(0) = %d\n",temp);
    */

}

DebugHandler::~DebugHandler()
{
    /*write to file before closing*/
    printf("Writing to File\n");
    printToDebuglogCsvFile();
    logTxtFile_.close();
    logCsvFile_.close();
}


/** public functions **/
void DebugHandler::receivedConnectionService(QString debugMessage)
{
   emit sendDebugMessageToPresenter(debugMessage);
}

//gets the original RAW string that dataparse receieves (this will just be sent to the debuglogTxtFile)
void DebugHandler::receivedDebugDataParser(QString debugMessage)
{
    QString messageToFile("             | RAW-STRING   : "); //Optional String prepending Message
    messageToFile.append(debugMessage);
    printlnToDebuglogTxtFile(messageToFile);
}

//gets the parsed values that dataparser emits and translates it to a human readable format
//and sends it to the debuglogTxtFile
void DebugHandler::receivedParsedDataParser(int id, double value)
{
    QDateTime date = QDateTime::currentDateTime();
    QString messageToFile(" | PARSED-STRING: "); //Optional String prepending Message.
    messageToFile.prepend(date.toString("hh:mm:ss:zzz"));

    messageToFile.append(convertIDtoString(id));
    messageToFile.append(QString::number(value)); //May need to change this if we don't want raw 'value' going in.

    printlnToDebuglogTxtFile(messageToFile);

    storeCsv2DArray(id, value);
}


/** private **/

//Orientation of the Vectors is Vectors pointing downwards. Each Vector represents a columnn
void DebugHandler::storeCsv2DArray(int id, int value)
{
    int currentMaxId = csv2DArray_.length(); //Number of Columns there are.
    int missing = id - currentMaxId + 1;

    if(missing > 0)    //if missing is postive, id doesn't have a spot within the array yet
    {
        for(int i = 0; i < missing; i++)
        {
            QVector<int> newColumn;
            csv2DArray_.push_back(newColumn);
        }
    }

    csv2DArray_[id].push_back(value);
}

void DebugHandler::printlnToDebuglogTxtFile(QString debugMessage)
{
    QTextStream writer(&logTxtFile_);
    writer << debugMessage << endl;
}

void DebugHandler::printToDebuglogCsvFile(void)
{

    QTextStream writer(&logCsvFile_);
    QString messageToFile(""); //Optional String prepending Message.
    int numOfColumns = csv2DArray_.length();
    int longestColumnLength = 0;

    messageToFile.clear();
    for(int i = 0; i < numOfColumns; i++)
    {
       // messageToFile.append(QString::number(i));
       messageToFile.append(convertIDtoString(i));
       messageToFile.append(",");
    }
    messageToFile.append("\n");
    writer << messageToFile;

    /*finds longest column*/
    for(int i = 0; i < numOfColumns; i++)
    {
        if(longestColumnLength < csv2DArray_.at(i).length())
            longestColumnLength = csv2DArray_.at(i).length();

    }
    printf("The Longest Length was: %d\n",longestColumnLength);
    for(int currentRow = 0; currentRow < longestColumnLength; currentRow++)
    {
        messageToFile.clear();
        for(int index = 0; index < numOfColumns; index++)
        {
            if(csv2DArray_[index].length() > currentRow) //if true,[index].at(currentRow) exists
            {
                printf("Value found at: csv2DArray[%d][%d] = %d\n",index, currentRow,csv2DArray_[index][currentRow] );
                messageToFile.append(QString::number(csv2DArray_[index].at(currentRow)));
            }
            messageToFile.append(",");
        }
        messageToFile.append("\n");
        printf("writing string: %s\n", messageToFile.toStdString().c_str());
        writer << messageToFile;
    }
}

QString DebugHandler::convertIDtoString(int id)
{
   QString convertedID("");//Optional String prepending Converted ID.

   switch(id)
   {
   case DataPopulator::DriverSetSpeedRPM:
      convertedID.append("DriverSetSpeedRPM:");
      break;
   case DataPopulator::DriverSetCurrent:
      convertedID.append("DriverSetCurrent:");
      break;
   case DataPopulator::VehicleVelocity:
      convertedID.append("VehicleVelocity:");
      break;
   case DataPopulator::BusCurrentA:
      convertedID.append("BusCurrentA:");
      break;
   case DataPopulator::BusVoltage:
      convertedID.append("BusVoltage:");
      break;
   case DataPopulator::MotorVelocityRpm:
      convertedID.append("MotorVelocityRpm:");
      break;
   case DataPopulator::MotorVoltageReal:
      convertedID.append("MotorVoltageReal:");
      break;
   case DataPopulator::MotorCurrentReal:
      convertedID.append("MotorCurrentReal:");
      break;
   case DataPopulator::BackEmfImaginary:
      convertedID.append("BackEmfImaginary:");
      break;
   case DataPopulator::IpmHeatSinkTemp:
      convertedID.append("IpmHeatSinkTemp:");
      break;
   case DataPopulator::DspBoardTemp:
      convertedID.append("DspBoardTemp:");
      break;
   case DataPopulator::DcBusAmpHours:
      convertedID.append("DcBusAmpHours:");
      break;
   case DataPopulator::ReceivedErrorCount:
      convertedID.append("ReceivedErrorCount:");
      break;
   case DataPopulator::TransmittedErrorCount:
      convertedID.append("TransmittedErrorCount:");
      break;

   case DataPopulator::Mod0PcbTemperature:
      convertedID.append("Mod0PcbTemperature:");
      break;
   case DataPopulator::Mod0CellTemperature:
      convertedID.append("Mod0CellTemperature:");
      break;
   case DataPopulator::Mod0CellVoltage0:
      convertedID.append("Mod0CellVoltage0:");
      break;
   case DataPopulator::Mod0CellVoltage1:
      convertedID.append("Mod0CellVoltage1:");
      break;
   case DataPopulator::Mod0CellVoltage2:
      convertedID.append("Mod0CellVoltage2:");
      break;
   case DataPopulator::Mod0CellVoltage3:
      convertedID.append("Mod0PcbTemperature:");
      break;
   case DataPopulator::Mod0CellVoltage4:
      convertedID.append("Mod0CellVoltage4:");
      break;
   case DataPopulator::Mod0CellVoltage5:
      convertedID.append("Mod0CellVoltage5:");
      break;
   case DataPopulator::Mod0CellVoltage6:
      convertedID.append("Mod0CellVoltage6:");
      break;
   case DataPopulator::Mod0CellVoltage7:
      convertedID.append("Mod0CellVoltage7:");
      break;

   case DataPopulator::Mod1PcbTemperature:
      convertedID.append("Mod1PcbTemperature:");
      break;
   case DataPopulator::Mod1CellTemperature:
      convertedID.append("Mod1CellTemperature:");
      break;
   case DataPopulator::Mod1CellVoltage0:
      convertedID.append("Mod1CellVoltage0:");
      break;
   case DataPopulator::Mod1CellVoltage1:
      convertedID.append("Mod1CellVoltage1:");
      break;
   case DataPopulator::Mod1CellVoltage2:
      convertedID.append("Mod1CellVoltage2:");
      break;
   case DataPopulator::Mod1CellVoltage3:
      convertedID.append("Mod1CellVoltage3:");
      break;
   case DataPopulator::Mod1CellVoltage4:
      convertedID.append("Mod1CellVoltage4:");
      break;
   case DataPopulator::Mod1CellVoltage5:
      convertedID.append("Mod1CellVoltage5:");
      break;
   case DataPopulator::Mod1CellVoltage6:
      convertedID.append("Mod1CellVoltage6:");
      break;
   case DataPopulator::Mod1CellVoltage7:
      convertedID.append("Mod1CellVoltage7:");
      break;

   case DataPopulator::Mod2PcbTemperature:
       convertedID.append("Mod2PcbTemperature:");
       break;
   case DataPopulator::Mod2CellTemperature:
        convertedID.append("Mod2CellTemperature:");
      break;
   case DataPopulator::Mod2CellVoltage0:
        convertedID.append("Mod2CellVoltage0:");
      break;
   case DataPopulator::Mod2CellVoltage1:
        convertedID.append("Mod2CellVoltage1:");
      break;
   case DataPopulator::Mod2CellVoltage2:
        convertedID.append("Mod2CellVoltage2:");
      break;
   case DataPopulator::Mod2CellVoltage3:
        convertedID.append("Mod2CellVoltage3:");
      break;
   case DataPopulator::Mod2CellVoltage4:
        convertedID.append("Mod2CellVoltage4:");
      break;
   case DataPopulator::Mod2CellVoltage5:
        convertedID.append("Mod2CellVoltage5:");
      break;
   case DataPopulator::Mod2CellVoltage6:
        convertedID.append("Mod2CellVoltage6:");
      break;
   case DataPopulator::Mod2CellVoltage7:
        convertedID.append("Mod2CellVoltage7:");
      break;

   case DataPopulator::Mod3PcbTemperature:
        convertedID.append("Mod3PcbTemperature:");
      break;
   case DataPopulator::Mod3CellTemperature:
        convertedID.append("Mod3CellTemperature:");
      break;
   case DataPopulator::Mod3CellVoltage0:
        convertedID.append("Mod3CellVoltage0:");
      break;
   case DataPopulator::Mod3CellVoltage1:
        convertedID.append("Mod3CellVoltage1:");
      break;
   case DataPopulator::Mod3CellVoltage2:
        convertedID.append("Mod3CellVoltage2:");
      break;
   case DataPopulator::Mod3CellVoltage3:
        convertedID.append("Mod3CellVoltage3:");
      break;
   case DataPopulator::Mod3CellVoltage4:
        convertedID.append("Mod3CellVoltage4:");
      break;
   case DataPopulator::Mod3CellVoltage5:
        convertedID.append("Mod3CellVoltage5:");
      break;
   case DataPopulator::Mod3CellVoltage6:
        convertedID.append("Mod3CellVoltage6:");
      break;
   case DataPopulator::Mod3CellVoltage7:
        convertedID.append("Mod3CellVoltage7:");
      break;

   case DataPopulator::BatteryVoltage:
        convertedID.append("BatteryVoltage:");
      break;
   case DataPopulator::BatteryCurrent:
        convertedID.append("BatteryCurrent:");
      break;
   case DataPopulator::BatteryVoltageThresholdRising:
        convertedID.append("BatteryVoltageThresholdRising:");
      break;
   case DataPopulator::BatteryVoltageThresholdFalling:
        convertedID.append("BatteryVoltageThresholdFalling:");
      break;
   }

return convertedID;
}
