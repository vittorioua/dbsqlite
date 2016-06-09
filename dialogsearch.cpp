#include "dialogsearch.h"
#include "ui_dialogsearch.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlTableModel>
Dialogsearch::Dialogsearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogsearch)
{
    ui->setupUi(this);
}

Dialogsearch::~Dialogsearch()
{
    delete ui;
}
void Dialogsearch::onTable(QString str){
    tablename=str;
}
void Dialogsearch::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button==ui->buttonBox->button(QDialogButtonBox::Ok)){
        QString key=ui->lineEdit->text();
        QString data=ui->comboBox->currentText();
        QSqlQueryModel *model = new QSqlQueryModel;

        model->setQuery("SELECT * FROM "+tablename+" WHERE \""+data+"\"=\""+key+"\";");
        //не срабатывает для группы, причину еще не нашел

        ui->tableView->setModel(model);
    }else{
        close();
    }
}
