#ifndef DIALOGSEARCH_H
#define DIALOGSEARCH_H

#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>
namespace Ui {
class Dialogsearch;
}

class Dialogsearch : public QDialog
{
    Q_OBJECT
    QString tablename;
public:
    explicit Dialogsearch(QWidget *parent = 0);
    ~Dialogsearch();

private slots:
    void onTable(QString str);
    void on_buttonBox_clicked(QAbstractButton *button);
private:
    Ui::Dialogsearch *ui;
};

#endif // DIALOGSEARCH_H
