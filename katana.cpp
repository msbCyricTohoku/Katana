#include "katana.h"
#include "ui_katana.h"
#include <iostream>
#include <string>
#include <QProcess>
#include <QDebug>
#include <QtDebug>
#include <QtPrintSupport/QPrinter>      // printing
#include <QtPrintSupport/QPrintDialog>  // printing
#include <QFileDialog>                  // file open/save dialogs
#include <QFile>                        // file descriptors, IO
#include <QTextStream>                  // file IO
#include <QStandardPaths>               // default open directory
#include <QDateTime>                    // current time
#include <QApplication>                 // quit
#include <QShortcut>

katana::katana(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::katana)
{
    ui->setupUi(this);
    int systemRet = system("rm *.tmp");
    if(systemRet == -1){}

    ui->radioButton->setChecked(true);

    ui->lineEdit->setText("myBackup");
}

katana::~katana()
{
    delete ui;
}


void katana::on_pushButton_5_clicked()
{
    //QString filepath = QFileDialog::getOpenFileName(this, "Choose file", "/home/");
   QString filepath = QFileDialog::getExistingDirectory(this, "Choose file", "/home/");
    if (filepath.isEmpty())
        return;

    const QString qPath15("openedfile.tmp");
    QFile qFile15(qPath15);
    if (qFile15.open(QIODevice::WriteOnly)) {
        QTextStream out15(&qFile15);
        out15 << filepath;
        qFile15.close();
    }

    ui->textBrowser->setText(filepath+" chosen for backup");

}


void katana::on_pushButton_clicked()
{
    // tar -cvzf /home/ben/Desktop/test/mybackup.tar.gz -C /home/ben/Desktop/test .

     QString filepath;

    const QString qPath151("openedfile.tmp");
    QFile qFile151(qPath151);
    if (qFile151.open(QIODevice::ReadOnly)) {
        QTextStream out151(&qFile151);
        filepath = out151.readAll();
        qFile151.close();
    }



   // ui->textBrowser_2->setText(filepath);

    QProcess *process = new QProcess(this);
    connect(process, &QProcess::started, []() {
        qDebug() << "Started!";
    });
    connect(process, &QProcess::readyRead, [this, process]() {
        QTextStream outputStream(process->readAllStandardOutput());
        ui->textBrowser_2->append(outputStream.readAll());
    });
    connect(process, &QProcess::readyReadStandardOutput, [this, process]() {
        QTextStream outputStream(process->readAllStandardOutput());
        ui->textBrowser_2->append(outputStream.readAll());
    });
    connect(process, &QProcess::readyReadStandardError, [this, process]() {
        QTextStream errorStream(process->readAllStandardError());
        ui->textBrowser_2->append(errorStream.readAll());
    });
    connect(process, qOverload<int, QProcess::ExitStatus>(&QProcess::finished), [this,
                                                                                 process](int exitCode,
                                                                                          QProcess::ExitStatus exitStatus) {
      //  ui->textBrowser_2->append(QString::number(exitCode) + " " + QString::number(exitStatus));
        process->deleteLater();
    });
//QString("tar -cvzf")+QString(" /home/ben/Desktop/test/mybackup.tar.gz -C /home/ben/Desktop/test ."));

    QString backupname= ui->lineEdit->text();

    if(ui->radioButton->isChecked())
    {
        process->start("/bin/sh", QStringList() << "-c" << QString("cd ")+filepath+QString("/ && ")+QString("tar -cvzf ")+backupname+QString(".tar.gz ")+QString("./* && du -h ")+backupname+QString(".tar.gz"));

    }

    if(ui->radioButton_3->isChecked()){
        //process->start("/bin/sh", QStringList() << "-c" << QString("tar -cvzf ")+filepath+QString("/")+backupname+QString(".zip")+QString(" -C ")+filepath+QString(" ."));

        process->start("/bin/sh", QStringList() << "-c" << QString("cd ")+filepath+QString("/ && zip -r ")+backupname+QString(".zip ./* && ls"));

    }

    ui->textBrowser_2->insertPlainText("Backup Done!");





}


void katana::on_pushButton_3_clicked()
{
   //  Q_INIT_RESOURCE(katana);

    QMessageBox msgAbout;
    msgAbout.setInformativeText("<span style='text-align: center'><p><b><font size = 20>Katana</font><p><font size = 14>Libre Backup tool</font><p><font size = 14>Version 0.1</font><p><font size = 14>by CYRIC, Tohoku University</font><p>Mehrdad S. Beni & Hiroshi Watabe | 2023</span><span style='text-align: left'><p>A simple lightweight backup tool, part of Kamakura project.</span><p>");
    QPixmap pixAbout;
    pixAbout.load(":resources/katana.png");
    msgAbout.setIconPixmap(pixAbout);
    msgAbout.setStandardButtons(QMessageBox::Close);
    msgAbout.setDefaultButton(QMessageBox::Close);
    msgAbout.exec();

}


void katana::on_pushButton_4_clicked()
{
    QApplication::quit();
}


void katana::on_actionOpen_folder_triggered()
{
    //QString filepath = QFileDialog::getOpenFileName(this, "Choose file", "/home/");
    QString filepath = QFileDialog::getExistingDirectory(this, "Choose file", "/home/");
    if (filepath.isEmpty())
        return;

    const QString qPath15("openedfile.tmp");
    QFile qFile15(qPath15);
    if (qFile15.open(QIODevice::WriteOnly)) {
        QTextStream out15(&qFile15);
        out15 << filepath;
        qFile15.close();
    }

    ui->textBrowser->setText(filepath+" chosen for backup");
}


void katana::on_actionQuit_triggered()
{
    QApplication::quit();

}


void katana::on_actionAbout_triggered()
{
    QMessageBox msgAbout;
    msgAbout.setInformativeText("<span style='text-align: center'><p><b><font size = 20>Katana</font><p><font size = 14>Libre Backup tool</font><p><font size = 14>Version 0.1</font><p><font size = 14>by CYRIC, Tohoku University</font><p>Mehrdad S. Beni & Hiroshi Watabe | 2023</span><span style='text-align: left'><p>A simple lightweight backup tool, part of Kamakura project.</span><p>");
    QPixmap pixAbout;
    pixAbout.load(":resources/katana.png");
    msgAbout.setIconPixmap(pixAbout);
    msgAbout.setStandardButtons(QMessageBox::Close);
    msgAbout.setDefaultButton(QMessageBox::Close);
    msgAbout.exec();
}

