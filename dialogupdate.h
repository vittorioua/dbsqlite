#ifndef DIALOGUPDATE_H
#define DIALOGUPDATE_H

#include <QDialog>
#include <QAbstractButton>
namespace Ui {
class DialogUpdate;
}

class DialogUpdate : public QDialog
{
    Q_OBJECT
    QString tablename;
public:
    explicit DialogUpdate(QWidget *parent = 0);
    ~DialogUpdate();

private slots:
    void recieveData(QString str, QString str2, QString str3);
    void on_buttonBox_clicked(QAbstractButton *button);
    void onTable(QString str);
signals:
    void refresh();
private:
    Ui::DialogUpdate *ui;
};

#endif // DIALOGUPDATE_H
