#include <QApplication>
#include <QProcess>
#include <iostream>
#include <QRegExp>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const QRegExp rxFirst("\"");
    const QRegExp rxSecond("\" \"");

    QProcess myProcess;
    QString program = "lspci -mmnn";
    myProcess.start(program);
    myProcess.waitForFinished();

    QByteArray result = myProcess.readAllStandardOutput();
    QTextStream all(result);

    while(!all.atEnd()){
        QString str = all.readLine();
        QStringList list = str.split(rxSecond, QString::SkipEmptyParts);
        std::cout << "VendorID: ";
        std::cout << list[1].toStdString() ;
        std::cout << "\t DeviceID: ";
        std::cout << list[2].split(rxFirst, QString::SkipEmptyParts)[0].toStdString() << std::endl;
    }

    return a.exec();
}

