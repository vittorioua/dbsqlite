#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>
namespace Ui {
class Dialoglogin;
}

class Dialoglogin : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoglogin(QWidget *parent = 0);
    ~Dialoglogin();
signals:
    void sendLogin(QString login, QString pass, QString dbpass);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Dialoglogin *ui;
};

#endif // DIALOGLOGIN_H
