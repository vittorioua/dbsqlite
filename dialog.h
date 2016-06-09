#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QPushButton>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    QString tablename;
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
signals:
    void refresh();
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void onTable(QString str);
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
