#include <QApplication>
#include <QProcess>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QProcess myProcess;
    QString program = "lspci -mmnn";
    myProcess.start(program);
    myProcess.waitForFinished();

    QByteArray result = myProcess.readAllStandardOutput ();
    const QString all(result);

    std::cout << all.toStdString() << std::endl;

    return a.exec();
}

