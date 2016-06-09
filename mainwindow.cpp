#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "dialogupdate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydb.sqlite");
    db.setPassword("qwerty");
    if(!db.open()){
        QMessageBox::information(this,"Message","Not connected");
    }
    //QString str="create table 'student'('number' integer PRIMARY KEY NOT NULL, 'fio' VARCHAR(36), 'group' integer);";
    /*model = new QSqlTableModel(0, db);
    model->setTable("student2");          // Имя таблицы базы данных.
    model->select();
    ui->tableView->setModel(model);*/
    ui->pushButton->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    formd=new DialogUpdate(this);
    form=new Dialog(this);
    forms=new Dialogsearch(this);
    forml=new Dialoglogin(this);
    //connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(onButtonSend()));
    connect(this,SIGNAL(sendData(QString,QString,QString)),formd,SLOT(recieveData(QString,QString,QString)));
    connect(form,SIGNAL(refresh()),this,SLOT(onRefresh()));
    connect(formd,SIGNAL(refresh()),this,SLOT(onRefresh()));
    connect(forml,SIGNAL(sendLogin(QString, QString,QString)),this,SLOT(onLogin(QString,QString,QString)));
    connect(this,SIGNAL(sendTable(QString)),form,SLOT(onTable(QString)));
    connect(this,SIGNAL(sendTable(QString)),formd,SLOT(onTable(QString)));
    connect(this,SIGNAL(sendTable(QString)),forms,SLOT(onTable(QString)));
    QMessageBox::information(this,"Warnign!","You are working in costumer mod");
    ui->listWidget->addItems(db.tables());
    ui->lineEdit->setText("create table 'student'('number' integer PRIMARY KEY NOT NULL, 'fio' VARCHAR(36), 'group' integer)");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onRefresh(){
    model->setTable(tablename);          // Имя таблицы базы данных.
    model->select();
    ui->tableView->setModel(model);
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    form->setModal(true); // говорим форме что она модальна
    form->exec(); // подтверждаем выполнение
}

void MainWindow::on_pushButton_2_clicked(bool checked)
{
       close();
}

/*void MainWindow::onButtonSend(){
     emit sendData(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0).data(0).toString(),ui->tableView->model()->index(ui->tableView->currentIndex().row(),1).data(0).toString(),ui->tableView->model()->index(ui->tableView->currentIndex().row(),2).data(0).toString());
}*/
void MainWindow::on_pushButton_4_clicked(bool checked)
{
    if(ui->tableView->currentIndex().isValid()){
      QMessageBox* pmbx =new QMessageBox(QMessageBox::Information,"Message","Update it?",QMessageBox::Yes | QMessageBox::No);
      int n = pmbx->exec();
      delete pmbx;
      if (n == QMessageBox::Yes) {
            emit sendData(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0).data(0).toString(),ui->tableView->model()->index(ui->tableView->currentIndex().row(),1).data(0).toString(),ui->tableView->model()->index(ui->tableView->currentIndex().row(),2).data(0).toString());
            formd->setModal(true);
            formd->exec();
    }
    }else QMessageBox::information(this,"Message","Select to update");
}


void MainWindow::on_pushButton_5_clicked(bool checked)
{
    if(ui->tableView->currentIndex().isValid()){
      QMessageBox* pmbx =new QMessageBox(QMessageBox::Information,"Message","Delete it?",QMessageBox::Yes | QMessageBox::No);
      int n = pmbx->exec();
      delete pmbx;
      if (n == QMessageBox::Yes) {
          QSqlQuery q;
          q.prepare("DELETE FROM "+tablename+" where number=:id;");
          q.bindValue(":id",ui->tableView->model()->index(ui->tableView->currentIndex().row(),0).data(0).toString());
          if(!q.exec()){
             QMessageBox::information(this,"Message","Error");
          }
          model = new QSqlTableModel(0, db);
          model->setTable(tablename);          // Имя таблицы базы данных.
          model->select();
          ui->tableView->setModel(model);
      }
    }else QMessageBox::information(this,"Message","Not selected");
}




void MainWindow::on_pushButton_3_clicked(bool checked)
{
    forms->show();
}
void MainWindow::onLogin(QString login, QString pass, QString dbpass){
    if(login=="admin" && pass=="admin" && db.password()==dbpass){
        QMessageBox::information(this,"Message","Log in success");
        ui->pushButton->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->tableView->setDisabled(false);
    }else QMessageBox::information(this,"Message","Something get wrong");
}

void MainWindow::on_actionLog_in_triggered()
{
    forml->exec();
}

void MainWindow::on_pushButton_6_clicked(bool checked)
{
    tablename=ui->listWidget->currentItem()->text();
    model = new QSqlTableModel(0, db);
    model->setTable(tablename);          // Имя таблицы базы данных.
    model->select();
    ui->tableView->setModel(model);
    ui->pushButton_3->setEnabled(true);
    emit sendTable(tablename);
}

void MainWindow::on_pushButton_7_clicked(bool checked)
{
    QSqlQuery q;
    QString str;
    str=ui->lineEdit->text();
    q.prepare(str+";");
    q.exec();
    ui->listWidget->addItems(db.tables());
}
