#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <dialogupdate.h>
#include <dialogsearch.h>
#include <dialog.h>
#include <dialoglogin.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSqlDatabase db;
    DialogUpdate *formd;
    Dialog *form;
    Dialogsearch *forms;
    Dialoglogin *forml;
    QString tablename;
public:
        QSqlTableModel *model;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void sendData(QString str, QString str2, QString str3);
    void sendTable(QString str);
private slots:
    //void onButtonSend();
    void onRefresh();
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

    void on_pushButton_4_clicked(bool checked);

    void on_pushButton_5_clicked(bool checked);

    void on_actionLog_in_triggered();

    void onLogin(QString login, QString pass, QString dbpass);

    void on_pushButton_6_clicked(bool checked);

    void on_pushButton_7_clicked(bool checked);

private:

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
