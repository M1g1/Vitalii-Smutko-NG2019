#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTcpSocket* socket;

public slots:
    void sendMessage();
    void sockConnect();
    void sockReady();
    void sockDisc();
    void ConnectToServer();
    void DisconnectFromServer();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
