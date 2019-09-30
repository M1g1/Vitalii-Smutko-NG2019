#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
        connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
        connect(socket,SIGNAL(connected()),this,SLOT(sockConnect()));
        connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisc()));
        connect(ui->Push, &QPushButton::clicked, this, &MainWindow::sendMessage);
        connect(ui->Connect, &QPushButton::clicked, this, &MainWindow::ConnectToServer);
        connect(ui->Disconnect, &QPushButton::clicked, this, &MainWindow::DisconnectFromServer);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::sockDisc()
{
    QMessageBox::information(this, "Information","Сonnection lost!");
    ui->label->setText("Status: Disconnected");
}

void MainWindow::ConnectToServer()
{
       QString ipAdress = ui->ipAdress->text();
       quint16 port = ui->Port->text().QString::toUShort();
       socket->connectToHost(ipAdress,port);
       if (!(socket->waitForConnected(50)))
       {
          QMessageBox::information(this, "Information","Connection not established!");
       }
}

void MainWindow::DisconnectFromServer()
{
    socket->disconnectFromHost();
}

void MainWindow::sockConnect()
{
     QMessageBox::information(this, "Information","Сonnection established!");
     ui->label->setText("Status: Сonnected");
}

void MainWindow::sockReady()
{
    if (socket->waitForConnected(50))
    {
        socket->waitForReadyRead(50);
        ui->textBrowser->setText((ui->textBrowser->toPlainText()) + (socket->readAll()));
    }else
    {
        QMessageBox::information(this, "Information","Connection not established!");
    }
}

void MainWindow::sendMessage()
{
    if (!(ui->YourMessage->text().isEmpty()))
    {
        if (socket->waitForConnected(50))
        {
            socket->waitForReadyRead(50);
            QString message = ui->Name->text() + ": " + ui->YourMessage->text() + "\n";
            socket->write(message.toUtf8());
            ui->YourMessage->clear();
        }else
        {
            QMessageBox::information(this, "Information","Connection not established!");
        }
    }
}
