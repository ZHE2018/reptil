#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(&this->test,SIGNAL(updateState(QString)),this,SLOT(updateStatus(QString)));
    connect(&this->test,SIGNAL(workFinish(QList<QString>)),this,SLOT(on_finished(QList<QString>)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(this->ui->lineEdit_RegData->text()==QString(""))
    {
        ui->log->append(QString("input data RegExp!"));
        return;
    }
    if(this->ui->lineEdit_initUrl->text()==QString(""))
    {
        ui->log->append(QString("input init Url!"));
        return;
    }
    QRegExp reg;
    reg.setPattern(ui->lineEdit_RegData->text());
    this->test.setanalysisDataRegExp(reg);
    reg.setPattern(ui->lineEdit_nextUrl->text());
    this->test.setanalysisNextUrlRegExp(reg);
    this->test.setCurrentUrl(QUrl(ui->lineEdit_initUrl->text()));

    this->test.work();
}

void MainWindow::updateStatus(const QString &msg)
{
    ui->log->append(msg);
}

void MainWindow::on_finished(const QList<QString> &list)
{
    this->ui->log->append("-----------------");
    for(const QString &i:list)
    {
        QString line;
        line=i.section(QString(" "),0,0).section(QString("\""),1,1);
        QRegExp reg("\\[[^\\]]+\\]");
        line=line+QString("@")+i.section(QString("\""),3,3).replace(reg,QString(""));
        this->ui->log->append(line);
    }
}
